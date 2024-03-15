#include "stuff.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
Number *n;
Number *start=NULL;    
n = (Number*)malloc(sizeof(Number));
if(start==NULL) start = n;

n = NewNumber(14);
start = PlaceNumber(start, n);



}





