#include "libreria.h"
#include "libreria2.h"

int main(){
    NUEVA_ESTRUCTURA nuevo;
    ESTRUCTURA_NUEVA2 nuevo2;
    printf("%d\n",CONSTANTE);
    nuevo.cont = 1;
    hola();
    cambiar_cont(&nuevo);
    printf("%d\n", nuevo.cont);
}
