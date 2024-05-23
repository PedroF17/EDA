/**
 * @file graph.c
 * @author Pedro Faria (a23290@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2024-05-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "graph.h"
#include <stdio.h>

#pragma region Graph

Graph* newGraph(int total){
	Graph* g = (Graph*)malloc(sizeof(Graph*));
	if (g != NULL) {
		g->vertices = calloc(g->totalVert,sizeof(Vertice*));
		g->numVert = 0;
		g->totalVert = total;
	}
	return g;
}

/**
 * @brief This functions creates a new vertice, by firstly allocating enough memory for it and then inserting the correspondent information to it. Aditionally, this struct has a boolean called "visited" to be used on the BFS function, will return true if it has been visited, and false if it hasn't.
 * 
 * @param code Integer. The numeric value of the vertice
 * @param name Char. The name of the vertice
 * @return Vertice* Returns the new, filled out Vertice list.
 */
Vertice* newVertice(int code){
    Vertice* new = (Vertice*)malloc(sizeof(Vertice*));
    if (new==NULL) return NULL;
	new->code = code;
	new->visited = false;
    new->adjacent = NULL;
    return new;
}

bool checkVertice(Graph *g, int code) {
	if (g->vertices == NULL) return false;
	for (int i=0; i<g->numVert; i++) {
		if(g->vertices[i]->code == code) return true;
	}
	return false;
}

Graph* placeVertice(Graph* g, Vertice* new, int* res){
	if(new==NULL)return NULL;
	if(checkVertice(g, new->code)){
		g->vertices = realloc(g->vertices, g->numVert+1 * sizeof(Vertice*));
		g->vertices[g->numVert++] = new;
		*res = 0;
	}return g;
}

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

Graph* clearGraph(Graph* g){
    if (g->vertices == NULL) return NULL;
	for (int i=0; i<g->numVert; i++) {
		clearAdj(g->vertices[i]->adjacent);
		free(g->vertices[i]);
	}
	g->numVert = 0;
	return g;
}

void showAdj(Adj* a){
    if (a == NULL) return;
    printf("\tAdj: %d - (%.0f)\n", a->code, a->weight);
    showAdj(a->next);
}

void showGraphAux(Graph* g){
	if (g->vertices == NULL) return;
	for (int i = 1; i<g->numVert; i++) {
		printf("V: %d\n", g->vertices[i]->code);
		showAdj(g->vertices[i]->adjacent);
	}
}

void showGraph(Graph* g){
    if (g->vertices == NULL) return;
	showGraphAux(g);
}


 #pragma endregion

 #pragma region File management

// int saveAdj() {
// }

// int saveGraph() {
// }

// int loadGraph(){	
// }
#pragma endregion