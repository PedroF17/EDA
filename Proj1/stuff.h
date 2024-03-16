/**
 * @file stuff.h
 * @author Pedro Faria (a23290@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2024-03
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Line{
    int num;
    struct Line* next;
}Line;

typedef struct ED{
    Line * startLine;
    struct ED * next;
}ED;

Line * NewLine(int num);
ED * NewED(Line* Line);
bool ShowLine(Line* n);
bool ShowED(ED* ED);
Line* PlaceIntLine(Line* startLine, int newentry);
ED* PlaceLineED(ED* startED, Line* startLine);
ED* ReadFile(ED* startED, const char *path);
char** splitString(char *string, const char *delim);
ED* RemoveAll(ED* startED);