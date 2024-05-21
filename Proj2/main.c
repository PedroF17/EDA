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

	Vertex *graph = newGraph();

	Vertex* newVert = newVertex("test", total);
	if (newVert != NULL){
		graph = placeVertex(graph,newVert, &res);
		total++;
	}
	showGraph(graph);
 }