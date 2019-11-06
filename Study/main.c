#include "my_header.h"
#include <stdio.h>
#include <string.h>

const char *pattern = "Happy families are all alike;";

int main(){

    FILE *file = fopen("input_8.txt", "r");

    printf("%d\n", matching(pattern, file));

    fclose(file);

    return 0;
}
