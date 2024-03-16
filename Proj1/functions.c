/**
 * @file functions.c
 * @author Pedro Faria (a23290@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2024-03
 */

#include <stdio.h>
#include <stdbool.h>
#include "stuff.h"

/**
 * @brief This function will create a new line by adding it to the linked list Line, allocating memory for it, and replacing the integer inside of the list with the one provided.
 * 
 * @param num Integer. The number that will be added.
 * @return Line* Returns the new linked list Line.
 */
Line * NewLine(int num){
	Line* aux = (Line*)malloc(sizeof(Line));
    if (aux==NULL) return NULL;
    aux->next = NULL;
    aux->num = num;
    return aux;
}
/**
 * @brief This function will go through the whole linked list Line, by verifying if the next number in the list exists. Once the variable aux reaches the end of the list, place the new number in the previous spot. 
 * 
 * @param startLine Linked list Line. The beginning of the Line that hosts the first number and the memory address of the other numbers.
 * @param newentry Integer. The number that will be added at the end of the Line.
 * @return Line* Returns the new linked list.
 */
Line* PlaceIntLine(Line* startLine, int newentry) {
	if (newentry < -1) return NULL;
	Line* aux = startLine;
		while (aux->next != NULL)
			aux = aux->next;
		aux->num = newentry;
	return aux;
}
/**
 * @brief This function can do two things. If there isn't a list defined, the new Line will become the start of the new ED (A linked list made of Lines). If there's a list, it will go through the Lines until it reaches the last position, where the pointer for the next one is NULL. Once it reaches the last position, place the new Line in the previous position.
 * 
 * @param startED Linked list ED. The beginning of the ED list that hosts the first number of each Line and the memory address for the next Line.
 * @param startLine Linked list Line. The beginning of the Line that hosts the first number and the memory address of the other numbers.
 * @return ED* Returns the new linked list.
 */
ED* PlaceLineED(ED* startED, Line* startLine){
	if(startED == NULL){
		startED->startLine = startLine;
		return startED;
	}
	ED* aux = startED;
		while (aux->next != NULL)
			aux = aux->next;
		aux->startLine = startLine;
	return aux;
}
/**
 * @brief This function will go through the Line, sending the integer inside of the current position to stdout. This will stop once it reaches the final position.
 * 
 * @param startLine Linked list Line. The beginning of the Line that hosts the first number and the memory address of the other numbers.
 * @return true True if it managed to go through the line and reach the final position.
 * @return false False if there isn't a Line.
 */
bool ShowLine(Line* startLine){
    if (startLine == NULL) return false;
	Line* aux = startLine;
	do{
		printf("%d ", aux->num);
		aux = aux->next;		
	} while(aux->next != NULL);
    return true;
}
/**
 * @brief This function will go through the list ED, calling the function ShowLine to print each Line. This will stop once it reaches the final position.
 * 
 * @param startED Linked list ED. The beginning of the ED list that hosts the first number of each Line and the memory address for the next Line.
 * @return true True if it managed to go through the list and reach the final position.
 * @return false False if there isn't a list.
 */
bool ShowED(ED* startED){
    if(startED == NULL) return false;
    ED* aux = startED;
	do{
		ShowLine(aux->startLine);
        aux = aux->next;
	} while (aux->next != NULL);
    return true;
}
/**
 * @brief This function will look for a certain number inside of a list Line, and change it with the provided integer in the variable 'newentry'.
 * 
 * @param startLine Linked list Line. The beginning of the Line that hosts the first number and the memory address of the other numbers.
 * @param newentry Integer. The number that will be added at the end of the Line.
 * @return Line* Returns the new linked list.
 */
Line* ReplaceNumberInLine(Line* startLine, int newentry){
	if(startLine==NULL || newentry < 0) return startLine;
	Line* aux = startLine;
	while (aux != NULL && aux->num, newentry < 0){
		aux = aux->next;

		if ((aux->num = newentry)){
			aux->num = newentry;
		}
	}
	return startLine;
}

ED* ReplaceNumberInED(ED* startED, int newentry){
	//todo
}

/**
 * @brief This function is used to read a matrix from a file. This uses an auxiliary function called splitString. The way this works is by reading each line as a string and splitting it wherever a comma is found. Currently giving out a segmentation fault (how kind).
 * 
 * @param startED Linked list ED. The beginning of the ED list that hosts the first number of each Line and the memory address for the next Line.
 * @param path String. The file path of the text file containing the matrix.
 * @return ED* 
 */
ED* ReadFile(ED* startED, const char *path) {
    FILE *fp;
	int counter;
    char line[128];

    fp = fopen(path, "r");
    if (fp == NULL) return 0;
    while (fgets(line, sizeof(line), fp)) {
		
		char* temp = strdup(line);
		char** lineArray = splitString(temp, ",");
		int sizeArray = sizeof(lineArray)/sizeof(lineArray[0]);
		Line * lineFile = NewLine(atoi(lineArray[0]));
		for(int i=1; i<sizeArray; i++){
		PlaceIntLine(lineFile, atoi(lineArray[i]));
		PlaceLineED(startED, lineFile);
		}
		free (temp);
		free (lineArray);
    }
	
    fclose(fp);
    return startED;
}
