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
#include <stdio.h>

//  int main(){
// 	static int total = 0;
// 	bool res;

// 	Graph *graph = newGraph(100);

// 	Vertice* newVert = newVertice(1);
// 	if (newVert != NULL){	
// 		graph = placeVertice(graph, newVert, &res);
// 		total++;
// 	}
// 	showGraph(graph);
// 	printf("Graph shown!");
// 	clearGraph(graph);
// 	printf("Graph cleared!");

//  }

int main() {


    Graph* g = newGraph(100);

    // Create some vertices and add them to the graph
    Vertice* v1 = newVertice(1);
    Vertice* v2 = newVertice(2);
    Vertice* v3 = newVertice(3);
    Vertice* v4 = newVertice(4);

	showGraph(g);

    int res;
	g = placeVertice(g, v1, &res);
    g = placeVertice(g, v2, &res);
    g = placeVertice(g, v3, &res);
    g = placeVertice(g, v4, &res);


	printf("Graph:\n");
	showGraph(g);

    clearGraph(g);

	showGraph(g);

    free(g);

    return 0;
}