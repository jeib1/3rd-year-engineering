#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "concat.h"
//Autor: Juan-Bastian Espinoza Caimanque
uint concat_bits(uint x, int n, uint y, int m) {
//example:
//x: 00000000000000000000000000101
//n: 3
//y: 00000000000000000000000011011
//m: 5
//return: 00000000000000000000010111011
unsigned mask = -1; 
unsigned y_mask = ~(mask<<m); // 0...01...1 con m unos
unsigned x_mask0 = ~(mask<<n); 
unsigned x_mask = x_mask0 << m;  // 0...01...10... con n unos desplazados en m hacia la izq
x <<= m; // x se desplaza en m
x &= x_mask; // se limpia lo que no queremos concatenar
y &= y_mask; 
x |= y;  // union entre nuestrios dos valores ya limpios
return x;
}
