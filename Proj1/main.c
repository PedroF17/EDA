/**
 * @file main.c
 * @author Pedro Faria (a23290@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2024-03
 */

#include "stuff.h"

int main(){
ED* startED = NULL;

startED = ReadFile(startED, "matrix.txt");

ReplaceNumberInLine(startED->startLine, 19, 21);
ShowED(startED);

RemoveAll(startED);
}

