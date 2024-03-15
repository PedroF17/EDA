#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stuff.h"

Number * NewNumber(int num){
    Number* aux = (Number*)malloc(sizeof(Number));
    if (aux==NULL) return NULL;
    aux->next = NULL;
    aux->num = num;
    return aux;
}

ED * NewED(Number* Number){
    ED* auxED = (ED*)malloc(sizeof(ED));
    if (auxED == NULL) return NULL;
    auxED->numbers = Number;
    return auxED;
}

Number* PlaceNumber(Number* start, Number* newentry) {
	if (newentry == NULL) return NULL;
	Number* aux = start;
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = newentry;
	return start;
}

bool ShowNumber(Number* n){
    if (n == NULL) return false;
    printf("%d ", n->num);
    return true;
}

bool ShowAll(Number* start){
    if(start == NULL) return false;
    Number* aux = start;
    while (aux){
        ShowNumber(aux);
        aux = aux->next;
    }
    return true;
}

bool SaveBinary (char* filename, ED* numbers){
    FILE* f;
    ED e;

    if (numbers==NULL || strlen(filename)) return false;
    f = fopen(filename, "wb");
    if (f == NULL) return false;

    ED* aux = numbers;
    while(aux){
        e.numbers->num = aux->next;
        fwrite(&e,1,sizeof(ED), f);
        aux->numbers = aux->numbers->next;
    }
    fclose(f);
    return true;
}

ED* LoadBinary(char* filename, bool* res) {
	FILE* f;
	f = fopen(filename, "rb");
	if (f == NULL) {
		*res = false; 
		return NULL;
	}
	ED e;
	ED* start = NULL; 
	ED* aux;
	while (fread(&e, 1, sizeof(Number), f)) {
		aux = NewNumber(e.numbers->num);
		start = PlaceNumber(start, aux);
	}
	fclose(f);
	return start;
}

bool SaveFile(char* filename, Number* start) {
	FILE* f;
	if (start == NULL) return false;
	f = fopen(filename, "w");
	Number* aux = start;
	while (aux) {
		fprintf(f,"%d;\n", aux->num);
		aux = aux->next;
	}
	fclose(f);

	return true;
}

Number* LoadFile(char* filename, bool* r) {
	Number* start = NULL;
	FILE* f;
	f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	Number * aux;
	int num;
	while (!feof(f)) {
		//fscanf(f, "%[^;];%d\n", p.nome, &p.idade);
		//aux = CriaPessoa(p.nome, p.idade);
		int col=fscanf(f, "%d;", &num);
		aux = NewNumber(num);
		start = PlaceNumber(start, aux);
	}
	fclose(f);
	return start;
}