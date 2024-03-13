#include <stuff.h>

Number* NewNumber(int num) {
	Number* aux = (Number*)malloc(sizeof(Number));
	if (aux == NULL) return NULL;
	aux->num = num;
	aux->prox = NULL;
	return aux;
}

bool ShowNumber(Number* n) {
	if (n == NULL) return false;
	printf("%s ", n->num);
	return true;
}

bool ShowED(Number* start) {
	if (start == NULL) return false; // 
	Number* aux = start;
	while (aux != NULL) {
		ShowNumber(aux);
		aux = aux->next;
	}
	return true;
}

Number* PlaceEnd(Number* inicio, Number* new) {
	if (new == NULL) return start; // there's nothing new, return the unchanged list
	if (start == NULL) // there's no list, the new Number will be the new list
		start = new;
	else // the rest
	{
		Number* aux = start;
		while (aux->next != NULL) aux = aux->next; // look for the last Number in the list
		aux->next = new;
	}
	return inicio; //changed list
}
