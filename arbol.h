//arbol.h

#ifndef binary_tree
#define binary_tree


typedef struct tree {
	int num;
	struct tree* izq;
	struct tree* der;
	struct tree* padre;
} arbol;

void crearNodo(int primElem, arbol **t);
bool agregarNodo(arbol **tree, int elem, char pos[], int nivel);


#endif
