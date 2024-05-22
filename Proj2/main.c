/**
 * @file main.c
 * @author Pedro Faria (a23290@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2024-05-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #include "graph.h"

 int main(){
	static int total = 0;
	bool res;

	Vertice *graph = newGraph();

	Vertice* newVert = newVertice(1,"teste");
	Vertice* newVert = newVertice(2,"teste");
	Vertice* newVert = newVertice(3,"teste");
	if (newVert != NULL){	
		graph = placeVertice(graph,newVert, &res);
		total++;
	}
	showGraph(graph);
	printf("Graph shown!");
	clearGraph(graph);
	showGraph(graph);
	printf("Graph cleared!");

 }