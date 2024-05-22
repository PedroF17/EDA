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

#pragma region Graph

Vertice* newGraph(){
	return NULL;
}

/**
 * @brief This functions creates a new vertice, by firstly allocating enough memory for it and then inserting the correspondent information to it. Aditionally, this struct has a boolean called "visited" to be used on the BFS function, will return true if it has been visited, and false if it hasn't.
 * 
 * @param code Integer. The numeric value of the vertice
 * @param name Char. The name of the vertice
 * @return Vertice* Returns the new, filled out Vertice list.
 */
 Vertice* newVertice(int code, char* name){
    Vertice* new = (Vertice*)malloc(sizeof(Vertice));
    if (new==NULL) return NULL;
    new->name = name;
	new->code = code;
	new->visited = false;
    new->next = NULL;
    new->adjacent = NULL;
    return new;
 }

Vertice* placeVertice(Vertice* v, Vertice* new, bool* res){
    if (v == NULL) {
		v = new;
		*res = true;
		return v;
	} else{
		Vertice* aux = v;
		Vertice* prev = aux;
		if (aux == v) {
			new->next = v;
			v = new;
		}
		else
		{
			new->next = aux;
			prev->next = new;
		}
		*res = true;
	}
	return v;
}

Adj* clearAdj(Adj* a){
    if (a == NULL) return NULL;
	Adj* aux = NULL;
	while (a) {
		if (a->next != NULL)
			aux = a->next;
		free(a);
		a = aux;
		aux = NULL;
    }
}

void showAdj(Adj* a){
    if (a == NULL) return;
    printf("\tAdj: %d - (%.0f)\n", a->codeAdj, a->weightAdj);
    showAdj(a->next);
}

void showGraph(Vertice* v){
    if (v == NULL) return;
    printf("V: %d - %s\n", v->code,v->name);
    showAdj(v->adjacent);
    showGraph(v->next);
}

Vertice* clearGraph(Vertice* v){
    if (v == NULL) return NULL;
	Vertice* aux = NULL;
	while (v) {
		if (v->next)
			aux = v->next;
		v->adjacent = clearAdj(v->adjacent);
		free(v);
		v = aux;
		aux = NULL;
	}
	return v;
 }

 #pragma endregion

 #pragma region File management

int saveAdj(Adj* a, char* fileName, int vertexCodeStart) {
	FILE* fp;
	if (a == NULL) return -2;
	fp = fopen(fileName, "wb");
	if (fp == NULL) return -1;

	Adj* aux = a;
	AdjFile auxFile;
	while (aux) {
		auxFile.codeStart = aux->codeAdj;
		auxFile.codeEnd = vertexCodeStart;
		auxFile.weight = aux->weightAdj;
		fwrite(&auxFile, 1, sizeof(AdjFile), fp);
		aux = aux->next;
	}
	fclose(fp);
	return 1;
}

 int saveGraph(Vertice* v, char* fileName) {

	if (v == NULL) return -1;
	FILE* fp;
	int r;
	fp = fopen(fileName, "wb");
	if (fp == NULL) return -2;

	Vertice* aux = v;
	VerticeFile auxFile;	//estrutura de vertice para gravar em ficheiro
	while (aux != NULL) {
		auxFile.code = aux->code;
		//strcpy(auxFile.cidade, aux->cidade);
		fwrite(&auxFile, 1, sizeof(VerticeFile), fp);
		//Pode gravar de imediato as adjacencias!
		if (aux->adjacent) {
			r = saveAdj(aux->adjacent,fileName, aux->code);
			if (r <0) break;
		}
		aux = aux->next;
	}
	fclose(fp);
	return 1;
}

#pragma endregion