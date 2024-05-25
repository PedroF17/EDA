/**
 * @file main.c
 * @author Pedro Faria (a23290@alunos.ipca.pt)
 * @brief 
 * @version 0.5
 * @date May 2024
 */

#include "graph.h"
#include <stdio.h>

int main() {


    Graph* g = newGraph(100);

    Vertice* v1 = newVertice(1, "v1");
    Vertice* v2 = newVertice(2, "v2");
    Vertice* v3 = newVertice(3, "v3");
    Vertice* v4 = newVertice(4, "v4");

	int res;

	g = placeVertice(g, v1);
	g = placeVertice(g, v2);
	g = placeVertice(g, v3);
	g = placeVertice(g, v4);

	printf("%d", g->vertices->code);

	showGraph(g);

    // int res;
	// g = placeVertice(g, v1, &res);
    // g = placeVertice(g, v2, &res);
    // g = placeVertice(g, v3, &res);
    // g = placeVertice(g, v4, &res);


	// printf("Graph:\n");
	// showGraph(g);

    // clearGraph(g);

	// showGraph(g);

    // free(g);

    return 0;
}