#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include "arbol.h"

int main(int argc, char *argv[]) {
  
  FILE *archivo;
  archivo = fopen(argv[1], "r");

  char letras[1500];
  char aux[256];
    
  if(archivo == NULL){
    printf("Problemas para abrir el fichero\n");
    exit(0);
  }

  fgets(letras, 1500, archivo);

  int i,j,l,m,k;
  arbol **tree = (arbol**) malloc (sizeof(arbol*));

  crearNodo(-1,tree);
  
  k = 1;
  while(feof(archivo)==0){
    i = 0;
    j = 0;
    while (i < 1500 && (int)letras[i] != 10) {
      if ((letras[i] == '(') || (letras[i] == ' ')) {
	if (letras[i+1] == ')') {
	  k++;
	  //Termino el arbol...COmprobar si esta bien estructurado
	  break;
	}
	i++;
      }
      else if (letras[i] == ',') {
	l = 1;
	m = 0;
	while(0 < j) {
	  m = m + ((aux[j-1]-48)*l);
	  l = l*10;
	  j--;
	}
	if (letras[i+1] == ')') {
	  agregarNodo(tree, m, aux, 0);
	}
	i++;
      }
      else if (letras[i] == ')') {
	agregarNodo(tree, m, aux, j);
	i++;
	j = 0;
      }
      else {
	aux[j] = letras[i];
	i++;
	j++;
      }
    }
    fgets(letras, 1500, archivo);
  }  
}
