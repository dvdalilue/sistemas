#include "potencia.h"

int posicion(int niv, char pos[]) {
  int ini;
  int fin;
  int tam;
  int k;
  tam = potencia(2,niv);
  ini = (tam - 1);
  fin = (ini + tam - 1);
  printf ("Tam:%d, ini:%d, fin:%d \n",tam, ini , fin);
  k = 0;
  while ((k < niv) && (tam != 1)) {
    tam = (tam/2);
    if (pos[k] == 'I') {
      fin = (ini+tam-1);
    }
    else if (pos[k] == 'D') {
      ini = (fin-tam+1);
    }
    k++;
  }
  return ini;
} 
