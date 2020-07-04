#include "fileOperations.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
long int sizeOfFile(char file_name[]){
    FILE *fp = fopen(file_name, "r");

    if(fp == NULL){
        printf("File not found");
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    long int res = ftell(fp);

    fclose(fp);
    return res;
}