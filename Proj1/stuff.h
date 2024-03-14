/**
*/
#include <stdbool.h>

typedef struct Number{
    int num;
    struct Number * next;
}Number;

typedef struct ED{
    Number * numbers;
}ED;

Number * NewNumber(int num);