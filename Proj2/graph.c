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

 Vertex* newGraph(){
    return NULL;
 }

 Vertex* newVertex(){
    Vertex* new = (Vertex*)malloc(sizeof(Vertex));
    if (new==NULL) return NULL;
    new->code = code;
    new->next = NULL;
    new->adjacent = NULL;
    return new;
 }

 Vertex* placeVertex(Vertex* v, Vertex* new, bool* res){
    if (v == NULL) {
		v = new;
		*res = true;
		return v;
	}
	else
	{
		Vertex* aux = v;
		Vertex* prev = aux;
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

void showGraph(Vertex* v){
    if (v == NULL) return;
    printf("V: %d - %s\n", v->code,v->name);
    showAdj(v->adjacent);
    showGraph(v->next);
}

Vertex* clearGraph(Vertex* v){
    if (v == NULL) return NULL;
	Vertex* aux = NULL;
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

 int saveGraph(Vertex* v, char* fileName) {

	if (v == NULL) return -1;
	FILE* fp;
	int r;
	fp = fopen(fileName, "wb");
	if (fp == NULL) return -2;

	Vertex* aux = v;
	VertexFile auxFile;	//estrutura de vertice para gravar em ficheiro
	while (aux != NULL) {
		auxFile.code = aux->code;
		//strcpy(auxFile.cidade, aux->cidade);
		fwrite(&auxFile, 1, sizeof(VertexFile), fp);
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

//check this
Vertex* loadAdj(Vertex* v, bool* res) {
	*res = false;
	FILE* fp;
	if (g == NULL) return -1;
	AdjFile aux;
	Vertex* auxGraph = g;
	while (auxGraph) {
		fp = fopen(auxGraph->cidade, "rb");
		if (fp != NULL) {
			while (fread(&aux, 1, sizeof(AdjFile), fp)) {
				g = InsereAdjacenteVerticeCod(g, aux.codeStart, aux.codeEnd, aux.weight, res);
			}
			fclose(fp);
		}
		auxGraph = auxGraph->next;
	}
	return g;
}

Vertex* loadGraph(Vertex* v, char* fileName, bool* res) {
	*res = false;
	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL) return NULL;

	VertexFile aux;
	Vertex* new;
	while (fread(&aux, 1, sizeof(VertexFile), fp)) {
		new = newVertex(aux.cidade, aux.code);
		v = placeVertex(v, new, res);
	}
	fclose(fp);
	return v;
}

#pragma endregion