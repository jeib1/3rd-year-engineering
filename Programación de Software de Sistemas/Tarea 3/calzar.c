#include <stdio.h>
#include <stdlib.h>

#include "calzar.h"

int calzar(Nodo *a, Nodo **ppat) {
  Nodo *p = *ppat;
  if(a == NULL) {
    return 0;
  }
  if(*ppat == NULL) {
    *ppat = a;
    return 1;
  }
  if(a->x != p->x) {
    return 0;
  }
  if(a->x == p->x) {
    if(p->izq != NULL) {
      calzar(a->izq, &p->izq);
    }    
    if(p->izq == NULL) {
      p->izq = a->izq;
    }
    if(p->der != NULL) {
      return calzar(a->der, &p->der);
    }
    if(p->der == NULL) {
      p->der = a->der;
    }
  }
  return 1;
}

