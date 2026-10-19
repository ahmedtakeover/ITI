#include <stdio.h>




int strlen(char *s){
    int i = 0;
    while (s[i] != '\0' )
    {
        i++;
    }
    return i;
}


void strcpy(char *dest, char *src){
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    
}



void strncpy(char *dest, char *src,int n){
    int i = 0;
    while (i < n)
    {
        dest[i] = src[i];
        i++;
    }
    
    
}
