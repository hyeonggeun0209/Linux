#include <stdio.h>
#include "reverse.h"

void reverse(char *arr, int len, int a) {
    if(a == len)
        return;
    else
    {
        reverse(arr, len, a+1);
        printf("%c", arr[a]);
    }
    
}