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
ED * NewED(Number* Number);
Number* PlaceNumber(Number* start, Number* new);
bool SaveBinary (char* filename, ED* numbers);
ED* LoadBinary(char* filename, bool* res);