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


#pragma region #include
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#pragma region endregion

#pragma region Structs

 typedef struct Adj{
    int codeAdj;
    float weightAdj;
    struct Adj *next;
 }Adj;

 typedef struct AdjFile{
    int codeStart;
    int codeEnd;
    float weight;
 }AdjFile;

 typedef struct Vertice{
    int code;
    char* name;
    bool visited;
    struct Vertice* next;
    struct Adj* adjacent;
 }Vertice;

 typedef struct VerticeFile{
    int code;
 }VerticeFile;

typedef struct Graph{
   Vertice* startGraph;
   int numVert;
   int totalVert;
}Graph;

//typedef struct Best {
//    int weight[MAX];
//    int prev[MAX];
//}Best;

#pragma endregion

#pragma region Graph

Vertice* newVertice(int code, char* name);
Vertice* newGraph();
Vertice* placeVertice(Vertice* v, Vertice* newVert, bool* res);
Adj* clearAdj(Adj* a);
void showAdj(Adj* a);
void showGraph(Vertice* v);
Vertice* clearGraph(Vertice* v);
int saveAdj(Adj* a, char* fileName, int vertexCodeStart);
int saveGraph(Vertice* v, char* fileName);
Vertice* loadAdj(Vertice* v, bool* res);
Vertice* loadGraph(Vertice* v, char* fileName, bool* res);

