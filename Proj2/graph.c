/**
 * @file graph.c
 * @author Pedro Faria (a23290@alunos.ipca.pt)
 * @brief 
 * @version 0.5
 * @date May 2024
 */

#include "graph.h"
#include <stdio.h>

#pragma region Graph

/**
 * @brief Create a new Graph. 
 * 
 * @param total Integer. The total number of Vertices on the Graph.
 * @return Graph* Returns the created Graph.
 */
Graph* newGraph(int total){
	Graph* g = (Graph*)malloc(sizeof(Graph));
	if (g != NULL) {
		g->vertices = NULL;
		g->numVert = 0;
		g->totalVert = total;
	}
	return g;
}

#pragma region Vertices

/**
 * @brief This function creates a new vertice, by firstly allocating enough memory for it and then inserting the correspondent information to it. Aditionally, this struct has a boolean called "visited" to be used on the BFS function, will return true if it has been visited, and false if it hasn't.
 * 
 * @param code Integer. The numeric value of the vertice
 * @param name Char. The name of the vertice
 * @return Vertice* Returns the new, filled out Vertice list.
 */
Vertice* newVertice(int code, char* name){
    Vertice* new = (Vertice*)malloc(sizeof(Vertice));
    if (new==NULL) return NULL;
	new->code = code;
	new->name = name;
	new->visited = false;
    new->adjacent = NULL;
    return new;
}

/**
 * @brief This function is used to check if a vertice is already in the matrix, by going through the linked list and comparing the integer value with the one received.
 * 
 * @param g Graph. 
 * @param code Integer. The number that is prompted to be checked.
 * @return true if there is a Vertice with the same value as the "code" received.
 * @return false if there isn't a Vertice with the same value.
 */
Graph* checkVertice(Graph *g, int code) {
	if (g->vertices == NULL) return false;
	Vertice* aux = g->vertices;
	while(aux){	
		if (aux->code == code) return true;
	}
	return false;
}

/**
 * @brief This function is used to check if a Vertice is already in the matrix, by going through the linked list and comparing the name of the Vertice with the one received.
 * 
 * @param g Graph.
 * @param name Char. The name of the Vertice.
 * @return true if there is a Vertice with the same name of the name received.
 * @return false if there isn't a Vertice with the same name.
 */
Graph* checkVerticeName(Graph *g, char* name){
	if (g->vertices == NULL) return false;
	Vertice* aux = g->vertices;
	while(aux){
		if (strcmp(g->vertices->name, name) == 0) return true;
	}
	return false;
}

/**
 * @brief This function is used to insert a given Vertice to an already existing Graph. This is done by firstly checking if there is any Vertices in the Graph, if there isn't, the new Vertice is placed at the start of the Graph. If there's already Vertices in the Graph, the function will go through the Graph until it finds the last Vertice in the Graph. After that, the new Vertice is inserted inside of the Graph
 * 
 * @param g Graph.
 * @param new Vertice, the new Vertice to be placed inside of the Graph
 * @return Graph* returns the changed Graph
 */
Graph* placeVertice(Graph* g, Vertice* new){
	if(new == NULL || checkVertice(g, new->code)) return g;
	// if(checkVertice(g, new->code)){
	// 	g->vertices = realloc(g->vertices, g->numVert+1 * sizeof(Vertice*));
	// 	g->vertices[g->numVert++] = new;
	// 	*res = 0;
	// }return g;
	if(g->vertices == NULL){
		g->vertices = new;
		return g;
	}else{
		Vertice* aux = g->vertices;
		Vertice* prev = aux;
		while(aux != NULL){
			prev = aux;
			aux = aux->nextVert;
		}
		new = aux;
		prev->nextVert = new;
	}
	return g;
}

#pragma endregion

/**
 * @brief This function is used to count the number of paths that exist between two Vertices in the Graph using their code values.
 * 
 * @param g Graph. 
 * @param start Integer. The value of the first Vertice.
 * @param end Integer. The value of the last Vertice.
 * @param count Integer. A counter to measure how many paths are there.
 * @return int Returns the number of paths between the two Vertices.
 */
int countPaths(Graph *g, int start, int end, int count){
	if (g == NULL) return 0;

	if (start == end) return (++count);
	else {
		Graph* aux = checkVertice(g, start);
		Adj* a = aux->adjs;
		while (a) {
			Graph* g = checkVertice(g, a->code);
			count = countPaths(g, g->vertices->code, end, count);
			a = a->next;
		}
	}
	return count;
}

/**
 * @brief This function is used to count the number of paths that exist between two Vertices in the Graph using their name.
 * 
 * @param g Graph. 
 * @param start Char. The name of the first Vertice.
 * @param end Char. The name of the last Vertice.
 * @param count Integer. A counter to measure how many paths are there.
 * @return int Returns the number of paths between the two Vertices.
 */
int countPathsName(Graph* g, char* start, char* end, int count){
	int s = checkVerticeName(g, start);
	int e = checkVerticeName(g, end);
	return countPaths(g, s, e, 0);
}

#pragma region Ajacencies

/**
 * @brief This function creates a new Adjacency.
 * 
 * @param code Integer.
 * @param weight Float. The weight of the Adjacency.
 * @return Adj* Returns the new Adjacency.
 */
Adj* newAdj(int code, float weight){
	Adj* new = (Adj*)calloc(1, sizeof(Adj));
	if (new == NULL) return NULL;
	new->code = code;
	new->weight = weight;
	new->next = NULL;
	return new;
}

/**
 * @brief This function will check if the code received conflicts with one of an Adjacency. 
 * 
 * @param a Adjacency.
 * @param code Integer. The value to check.
 * @return true if there's an Adjacency with the same code as the one provided.
 * @return false if there isn't an Adjacency with the code received.
 */
bool checkAdj(Adj* a, int code){
	if (a == NULL) return false;
	if (a->code == code) return true;
	return checkAdj(a->next, code);
}

/**
 * @brief This function is used to insert a new Adjacency in the Graph.
 * 
 * @param a Adjacency.
 * @param new Adjacency. The new Adjacency.
 * @param res Boolean. The result of the function. True if it placed the new Adjacency, false if it didn't.
 * @return Adj* Returns the new changed Adjacency.
 */
Adj* placeAdj(Adj* a, Adj* new, bool* res){
	*res = false;
	if (new == NULL) return a;
	if (checkAdj(a, new->code) == true) return a;
	*res = true;		
	if (a == NULL) {
		a = new;
		return a;
	}
	new->next = a;
	a = new;
	return a;
}

/**
 * @brief This function is the main function to add an Adjacency. It uses placeAdj to insert an Adjacency to a Vertice.
 * 
 * @param g Graph. The Graph where the Adjacency will be placed.
 * @param start Char. The name of the first Vertice.
 * @param end Char. The name of the last Vertice.
 * @param weight Float. The weight of the Adjacency.
 * @param res Boolean. The result of the function. True if the Adjacency is inserted, false if it isn't.
 * @return Graph* Returns the new changed Graph.
 */
Graph* placeAdjVertice(Graph* g, char* start, char* end, float weight, bool* res){
	*res = false;
	if (g == NULL) return g;
	Graph* aux = checkVerticeName(g, start);
	int code = checkVertice(g, end);
	//Vertice* e = checkVertice(g, end);
	
	if (aux == NULL || code<0) return g;

	if (checkAdj(aux->adjs, code) == true) 
		return g;
	*res = true;
	Adj* new = newAdj(code, weight);
	aux->adjs = placeAdj(aux->adjs, new, res);
	return g;
}

/**
 * @brief This function is used to clear an Adjacency, using the free command.
 * 
 * @param a Adjacency. The Adjacency to be cleared.
 * @return Adj* Returns the cleared Adjacency.
 */
Adj* clearAdj(Adj* a){
    if (a == NULL) return NULL;
	Adj* aux = a;	
	Adj* prev = NULL;
	while (a) {
		if (a->next != NULL)		
			aux = a->next;
		free(a);
		a = aux;
		aux = NULL;
    }
	return a;	
}

/**
 * @brief This function is used to clear the Graph created. This will clear all the Vertices and their associated Ajacencies, using the clearAdj funciton.
 * 
 * @param g Graph. The Graph to be cleared.
 * @return Graph* Returns the cleared Graph.
 */
Graph* clearGraph(Graph* g){
    if (g->vertices == NULL) return NULL;
	// for (int i=0; i<g->numVert; i++) {
	// 	clearAdj(g->vertices[i]->adjacent);
	// 	free(g->vertices[i]);
	// }
	// g->numVert = 0;
	Vertice* aux = g->vertices;
	Vertice* next = NULL;
	while(aux){
		if(aux->nextVert != NULL){
			next = aux->nextVert;
		}
		free(aux);
		clearAdj(aux->adjacent);
		aux = next;
	}
	return g;
}

/**
 * @brief This function is used to print out the Adjacencies of a Vertice
 * 
 * @param a Adjacency. The Adjacency to be shown in the terminal.
 */
void showAdj(Adj* a){
    if (a == NULL) return;
    printf("\tAdj: %d - (%.0f)\n", a->code, a->weight);
    showAdj(a->next);
}

/**
 * @brief This function is used to show the Graph created, by printing the name, code and Adjacencies of a Vertice.
 * 
 * @param g Graph. The Graph to be shown in the terminal.
 */
void showGraph(Graph* g){
	if (g->vertices == NULL) return;
	// for (int i = 1; i<g->numVert; i++) {
	// 	printf("%s\n", g->vertices[i]->name);
	// 	printf("V: %d\n", g->vertices[i]->code);
	// 	showAdj(g->vertices[i]->adjacent);
	// }
	Vertice* aux = g->vertices;
	while(aux->nextVert != NULL){
		printf("%s\n", g->vertices->name);
		printf("V: %d\n", g->vertices->code);
		showAdj(g->vertices->adjacent);
		aux = aux->nextVert;
	}
}

#pragma endregion

/**
 * @brief This function is used to go through all of the available paths and finding a path between two codes of different Vertices. If it found one, it prints it out in the terminal. Currently not implemented.
 * 
 * @param g Graph. The Graph that has the Vertices to look for.
 * @param start Integer. The code of the starting Vertice
 * @param end Integer. The code of the ending Vertice
 * @return true if there's a path between the two Vertices.
 * @return false if a path between the Vertices wasn't found.
 */
bool BFS(Graph* g, int start, int end){}

#pragma endregion

 #pragma region File management

/**
 * @brief This function reads the matrix from a text file and inserts it on a Graph. Currently not implemented.
 * 
 * @param filename Char. The name of the text file.
 * @return Graph* Returns the Graph found in the text file.
 */
Graph* readGraph(char* filename){
	
	Graph* g = NULL;
	FILE* fp;
	fp = fopen(filename, "r");
	
	int numLines;
	int numColumns;
	char seperator;
	//TODO
	return g;
}

#pragma endregion