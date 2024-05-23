/**
 * @file graph.h
 * @author Pedro Faria (a23290@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2024-05-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #define MAX 10
 #define MAXWEIGHT 9999


#pragma region include
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#pragma region endregion

#pragma region Structs

 typedef struct Adj{
    int code;
    float weight;
    struct Adj* next;
 }Adj;

 typedef struct Vertice{
    int code;
    bool visited;
    char* name;
    struct Adj* adjacent;
    struct Vertice* nextVert;
 }Vertice;

 typedef struct Graph{
    Vertice* vertices;
    Adj* adjs;
    int numVert;
    int totalVert;
 }Graph;

//typedef struct Best {
//    int weight[MAX];
//    int prev[MAX];
//}Best;

#pragma endregion

#pragma region Graph

Graph* newGraph(int total);
Vertice* newVertice(int code, char* name);
Graph* placeVertice(Graph* g, Vertice* newVert, int* res);
bool checkVertice(Graph* g, int code);
bool checkVerticeGraph(Graph* g, int code);
Graph* placeVerticeGraph(Graph* g, Vertice* newVert, int* res);
Adj* clearAdj(Adj* a);
void showAdj(Adj* a);
void showGraphAux(Graph* g);
void showGraph(Graph* g);
Graph* clearGraph(Graph* g);
//int saveAdj(Adj* a, char* fileName, int vertexCodeStart);
//int saveGraph(Vertice* v, char* fileName);
//Vertice* loadAdj(Vertice* v, bool* res);
//Vertice* loadGraph(Vertice* v, char* fileName, bool* res);

