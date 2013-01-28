#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"



//Nodo del arbol.
void crearNodo(int primElem, arbol **t) {

  //**tree = (arbol) malloc (sizeof(arbol));
  //t = (arbol**) malloc (sizeof(arbol*));
  *t = (arbol*) malloc (sizeof(arbol));
  //int *i = (int*) malloc (sizeof(int));

  (**t).num = primElem;
  (**t).izq = NULL;
  (**t).der = NULL;
  (**t).padre = NULL;
}


//Nada seguro de lo que hago aqui.
bool agregarNodo (arbol **tree, int elem, char pos[], int nivel) {
  arbol *aux, *hijoaux;
  aux = (*tree);
  int i;
  i = 0;
  while (i < nivel) {
    if (i != nivel - 1) {
      if (pos[i]=='I') {
	if (aux->izq != NULL) {
	  aux = (*aux).izq;
	} else if (aux->izq == NULL) {
	  crearNodo(-1,&hijoaux);
	  hijoaux->padre = (aux);
	  aux->izq = hijoaux; 
	}
      } else if (pos[i] == 'D') {
	if (aux->der != NULL) {
	  aux = (*aux).der;
	} else if (aux->der == NULL) {
	  crearNodo(-1,&hijoaux);
	  hijoaux->padre = (aux);
	  aux->der = hijoaux; 
	}
	 
      } 
    }      

    else if (i == nivel - 1) {
      if (pos[i]=='I') {
	if (aux->izq != NULL) {
	  if(aux -> num == -1) {
	    aux -> num = elem;
	  }
	  else {
	    return false;
	  }
	}
	else if (aux->izq == NULL) {
	  crearNodo(elem,&hijoaux);
	  hijoaux->padre = (aux);
	  aux->izq = hijoaux; 
	}
      }
      else if (pos[i] == 'D') {
	if (aux->der != NULL) {
	  if(aux -> num == -1) {
	    aux -> num = elem;
	  }
	  else {
	    return false;
	  }
	}
	else if (aux->der == NULL) {
	  crearNodo(elem,&hijoaux);
	  hijoaux->padre = (aux);
	  aux->der = hijoaux; 
	}
      }
    }
    i++;
  }

  int coontar(arbol **t) {
    
  }

}



 	 






	
	
	 

