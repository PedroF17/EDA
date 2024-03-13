/**
 * @file func.c
 * @author Pedro Faria (a23290@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2024-03 
 */
#include "stuff.h"
/**
 * @brief 
 * 
 * @param num 
 * @return Number* 
 */
Number* NewNumber(int num) {
	Number* aux = (Number*)malloc(sizeof(Number));
	if (aux == NULL) return NULL;
	aux->num = num;
	aux->next = NULL;
	return aux;
}
/**
 * @brief Quick function to show the number n inside the struct Number
 * 
 * @param n The number inside of the struct Number.
 * @return true if the number exists, will print the number inside of the struct Number.
 * @return false if the number doesn't exist.
 */
bool ShowNumber(Number* n) {
	if (n == NULL) return false;
	printf("%d ", n->num);
	return true;
}
/**
 * @brief This function will show the entire list, recursively going through all of the number n of each struct Number inside of the struct ED, using an auxiliary variable aux.
 * 
 * @param start The first number on the list, with this you can check the entire list using the point inside of the struct Number.
 * @return true if there's a list to show
 * @return false if the list doesn't exist (start == NULL) 
 */
bool ShowED(Number* start) {
	if (start == NULL) return false; // 
	Number* aux = start;
	while (aux != NULL) {
		ShowNumber(aux);
		aux = aux->next;
	}
	return true;
}
/**
 * @brief 
 * 
 * @param start 
 * @param new 
 * @return Number* 
 */
Number* PlaceEnd(Number* start, Number* newnum) {
	if (newnum == NULL) return start; // there's nothing new, return the unchanged list
	if (start == NULL) // there's no list, the new Number will be the new list
		start = newnum;
	else // the rest
	{
		Number* aux = start;
		while (aux->next != NULL) aux = aux->next; // look for the last Number in the list
		aux->next = newnum;
	}
	return start; //changed list
}
