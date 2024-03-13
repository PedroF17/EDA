#pragma region include
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma endregion

typedef struct Number{
    int num;
    struct Number* next;
}Number;

typedef struct ED{
    Number n;
    struct ED* next;
}