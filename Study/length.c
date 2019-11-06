#include <stdio.h>
#include "length.h"

int length(char *arr) {
    int len = 0;
    for(int i=0; arr[i] != '\0'; i++) {
        len++;
    }
    return len;
}