#include <stdio.h>
#include <string.h>
#include "my_header.h"

unsigned int matching(const char* pattern, FILE *file) { 
    int i = 0; int j = 0;
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    char buf[2 * size];
    char *ptr = buf; char *ptr1 = buf;
    fseek(file, 0, SEEK_SET);
    while(!feof(file)) {
        fgets(ptr1,1000,file);
        while(buf[i] != '\n') {
            i++;
        }
        ptr1 = &buf[i];
    }
    while(strstr(ptr,pattern) != NULL) {
        j++;
        ptr = strstr(ptr,pattern);
        ptr++;
    }
    return j;
}