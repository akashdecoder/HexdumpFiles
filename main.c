#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HexConverter/hexConverter.h"
#include "FileOperations/fileOperations.h"
#include "hex.h"
int main(int argc, char* argv[]) {
    FILE *fp,*fp1;
    char charArray[9999];
    char ch;
    long int charCount = 0;
    int lineCount=0;
    int arrayCount=0;
    printf("\n%s\n", argv[1]);
    fp = fopen(argv[1], "rb+");
    fp1 = fopen("hex.h", "w");
    fprintf(fp1, "unsigned char hexUnsignedArray[] = {");
    if(fp!=NULL){
        while((ch = getc(fp)) != EOF){
            charArray[charCount++] = ch;
        }
        for(int i=0;i<charCount;i++){
            lineCount++;
            fprintf(fp1, "0x%s", hexConvert((int)charArray[i]));
            if(i==charCount-1)
                break;
            fprintf(fp1, ", ");
            if(lineCount == 16){
                lineCount = 0;
                fprintf(fp1, "\n");
            }
        }
    } else{
        printf("\nCannot Open the File\n");
    }
    fprintf(fp1, "};");
    fclose(fp1);
    printf("\nThe size of the File %s: %ld bytes", argv[1], sizeOfFile(argv[1]));
    printf("\n");

    printf("\t00\t");
    for(int i=1;i<16;i++){
        printf("0%s\t",hexConvert(i));
    }
    printf("\n");
    int p=0;
    while(p<charCount){
        printf("0%s\t",hexConvert(arrayCount));
        for(int i=0;i<16;i++){
            printf("%s\t", hexConvert(hexUnsignedArray[p++]));
            arrayCount++;
        }
        printf("\n");
        if(p == charCount-1){
            break;
        }
    }
    int rowOffset1 = hexToDecimal(argv[2]);
    int colOffset1 = hexToDecimal(argv[3]);
    int offset1 = colOffset1 + rowOffset1;
    printf("\n");
    int rowOffset2 = hexToDecimal(argv[4]);
    int colOffset2 = hexToDecimal(argv[5]);
    int offset2 = colOffset2 + rowOffset2;
    printf("Values from offset[%s][%s] to offset[%s][%s] are: \n", argv[2], argv[3], argv[4], argv[5]);
    printf("\t00\t");
    for(int i=1;i<16;i++){
        printf("0%s\t",hexConvert(i));
    }
    printf("\n");
    int c=colOffset1;
    printf("0%s",hexConvert(rowOffset1));
    if(colOffset1 > 0){
        for(int i=0;i<atoi(argv[3]); i++){
            printf("\t");
        }
    }
    while(offset1 <= offset2){
        for(int i=c; i<16; i++){
            printf("\t%s", hexConvert(hexUnsignedArray[offset1++]));
            if(offset1 > offset2){
                break;
            }
        }
        printf("\n");
        c = 0;
        if(offset1 > offset2){
            break;
        }
        rowOffset1+=16;
        printf("0%s",hexConvert((rowOffset1)));
    }
    printf("\n");
    return 0;
}