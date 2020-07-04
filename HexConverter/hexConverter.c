#include "hexConverter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *hexConvert(int d){
    static char hex[100];
    int q, r;
    int i, j=0;
    q = d;
    while (q != 0){
        r = q % 16;
        if(r < 10)
            hex[j++] = 48 + r;
        else
            hex[j++] = 55 + r;
        q = q / 16;
    }
    hex[j] = '\0';
    static char hex1[100];
    int count =0;
    for(i =strlen(hex)-1;i>=0;i--)
        hex1[count++] = hex[i];
    hex1[count] = '\0';
    return hex1;
}

char *binaryConvert(int d){
    static char bin[100];
    static char revbin[100];
    int r,q;
    int count=0;
    int i=0;

    while(d>0){
        r = d%2;
        bin[i++] = 48+r;
        d=d/2;
    }
    bin[i] = '\0';
    for(int i=strlen(bin)-1;i>=0;i--){
        revbin[count++] = bin[i];
    }
    revbin[count] = '\0';
    return revbin;
}

char *binaryToHexConverter(long long d){
    int hexCount[] = {0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111};
    long long temp;
    int index=0, count =0;
    static char hex[100];
    static char hexrev[100];
    int digit;

    temp = d;
    while (temp != 0){
        digit = temp % 10000;
        for(int i=0;i<16;i++){
            if(hexCount[i] == digit){
                if(i < 10){
                    hex[index] = i + 48;
                } else{
                    hex[index] = i + 55;
                }
                index++;
                break;
            }
        }
        temp /= 10000;
    }
    hex[index] = '\0';
    for(int i =strlen(hex)-1;i>=0;i--)
        hexrev[count++] = hex[i];
    hexrev[count] = '\0';
    return hexrev;
}

int hexToDecimal(char hex[]){
    int len = strlen(hex);
    int base = 1;
    int dec_val = 0;
    for (int i=len-1; i>=0; i--){
        if (hex[i]>='0' && hex[i]<='9'){
            dec_val += (hex[i] - 48)*base;
            base = base * 16;
        }
        else if (hex[i]>='A' && hex[i]<='F'){
            dec_val += (hex[i] - 55)*base;
            base = base*16;
        }
    }
    return dec_val;
}


