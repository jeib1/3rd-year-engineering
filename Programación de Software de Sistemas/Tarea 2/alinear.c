#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "alinear.h"

void alinear_der(char *str) {
    int tmp;
    int n = 0;
    int s = strlen(str);
    if (s == 0 || s==1) {
      return;
    }
    str = str+s-1;
    if (*str != 32) {
        str = str-s+1;
        return;
    }
    while (*str == 32) {
        n++;
        if (n==s) {
            return;
        }
        str--;
    }
    int k = s-n-1;
    str= str+n;
    while (k != 0) {
        str=str-n;
        tmp = *str;
        *str = 32;
        str = str + n;
        *str = tmp;
        str--;
        k--;
    }    
    str=str-n;
    tmp = *str;
    *str = 32; 
    str = str + n;
    *str = tmp;
    str=str-n;    
    return;
}

char *alineacion_der(char *str) {
    int s = strlen(str);
    char *res= malloc(s+1);
    res = res+s;
    *res = 0;
    str = str+s-1;
    if (s == 0) {
      return res;
    }
    res = res-s;
    int n = 0;
    int tmp;
    int k;
    int j;
    while (*str == 32) {
      n++; 
      if (n==s) {
            break;
      }
      str--;
    }
    str = str-s+n+1;
    k = s-n;
    j = k;
    while (n!=0) {
      *res = 32;
      n--;
      res++;
    }
    while (k!=0) {
      tmp = *str;
      *res = tmp;
      res++;
      str++;
      k--;
    }
    str=str-j;
    res = res-s;
    return res;
}
