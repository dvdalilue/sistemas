#include <stdbool.h>

int potencia( int x, int y ) {
  int i = 0;
  int pot = 1;

  while( i < y )
    {  // Abre while
      pot = pot*x;
      i++;
    }  // Cierra while 

  return (pot);
}  /* Cierra potencia*/


void imprimir(bool p,int arbol[], int length) {
  if (p == true) {
    int i = 0;
    while (i < length) {
      if (arbol[i] != 0) {
	printf("%d ", arbol[i]);
      }
      i++;
    }
    printf("\n");
  }
  else {
    printf("incompleto\n");
  }
}


void inicializar(int ch[], int length) {
  int i;
  i = 0;
  while (i < length) {
    ch[i] = 0;
    i++;  
  }
}

int posicion(int niv, char pos[]) {
  int ini;
  int fin;
  int tam;
  int k;
  tam = potencia(2,niv);
  ini = (tam - 1);
  fin = (ini + tam - 1);
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


int piso(float d) {
  int i = 0;
  while (i <= d) {
    i++;
  }
  return i;
}
