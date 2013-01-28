#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "funcion.h"


int main(int argc, char *argv[]) {

  FILE *archivo;
  archivo = fopen(argv[1], "r");

  char letras[100];
  char aux[99];
    
  if(archivo == NULL){
    printf("Problemas para abrir el fichero\n");
    exit(2);
  }

  fgets(letras, 100, archivo);

  int i,j,l,m,k;
  float w;
  k = 0;
  bool p = true;
  int arbol[256];
  inicializar(arbol,256);

  while(feof(archivo)==0){
    i = 0;
    j = 0;
    while (i < 100 && (int)letras[i] != 10) {
      if ((letras[i] == '(') || (letras[i] == ' ')) {
	if (letras[i+1] == ')') {
	  j = 1;
	  while(j < k) {
	    if (arbol[j] != 0) {
	      w = ((float)(j-1))/2;
	      l = (int)w;
	      if (arbol[l] == 0) {
		p = false;
	      }
	    }
	    j++;
	  }
	  imprimir(p,arbol,256);
	  inicializar(arbol,256);
	  k = 0;
	  j = 0;
	  i = 100;
	}
	i++;
      }
      else if (letras[i] == ',') {
	l = 1;
	m = 0;
	while(0 < j) {
	  m = m + ((aux[j-1]-48)*l);
	  l = l*10;
	  j = j-1;
	}
	if (letras[i+1] == ')') {
	  arbol[0] = m;
	  i++;
	}
	i++;
      }
      else if (letras[i] == ')') {
	l = posicion(j,aux);
	if (k < l) {
	  k = l;
	}
	if (arbol[l] != 0){
	  p = false;
	}
	arbol[l] = m;
	i++;
	j = 0;
      }
      else {
	aux[j] = letras[i];
	i++;
	j++;
      }
    }
    fgets(letras, 100, archivo);
  }
}
