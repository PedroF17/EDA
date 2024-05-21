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

 typedef struct Vertex{
    int code;
    bool visited;
    struct Vertex* next;
    struct Adj* adjacent;
 }Vertex;

 typedef struct VertexFile{
    int code;
 }VertexFile;

 #define MAX 10
 #define MAXWEIGHT 9999

typedef struct Best {
    int weight[MAX];
    int prev[MAX];
}Best;

#pragma endregion

#pragma region Graph

Vertex* newVertex();
Vertex* newGraph();
Vertex* placeVertex(Vertex* v, Vertex* newVert, bool* res);
Adj* clearAdj(Adj* a);
void showAdj(Adj* a);
void showGraph(Vertex* v);
Vertex* clearGraph(Vertex* v);
int saveAdj(Adj* a, char* fileName, int vertexCodeStart);
int saveGraph(Vertex* v, char* fileName);
Vertex* loadAdj(Vertex* v, bool* res);
Vertex* loadGraph(Vertex* v, char* fileName, bool* res);

