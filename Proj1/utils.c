/**
 * @file utils.c
 * @author Pedro Faria (a23290@alunos.ipca.pt)
 * @brief 
 * @version 0.1
 * @date 2024-03
 */

#include "stuff.h"

/**
 * @brief This function is used to split a string wherever a certain delimiter is found. Currently this is spewing out a segmentation fault but I'm working on fixing it...
 * 
 * @param string String. The string to split
 * @param delim  String. The character(s) that seperate each value needed to split.
 * @return char** Returns the strings seperated.
 */

char** splitString(char *string, const char *delim) {
    char **tokens = (char**) malloc(sizeof(char*)*128);
    int index = 0;
    int len = strlen(string);

    len--;
    if (string[len-1]==13) 
        len--;
    string[len] = '\0';    

    tokens[index++] = &string[0];
    for(int i=0; i < len; i++) {
        if( string[i] == delim[0] ) {
            string[i] = '\0';
            if( i < len - 1 ) {
                tokens[index++] = &string[i] + 1;
            }           
        }
    }
    return tokens;
}

/**
 * @brief This function clears everything from memory, to prevent memory leaks. This is used at the end of the main function.
 * 
 * @param startED Linked list ED. The beginning of the ED list that hosts the first number of each Line and the memory address for the next Line.
 */

ED* RemoveAll(ED* startED) {
	ED* aux = startED;
	if (aux->next == NULL) {
		free(aux);
		return NULL;
	}
	ED* t;
	while (aux->next) {
		t = aux->next;
		free(aux);
		aux = t;
	}
	return NULL;
}