#include <stdio.h>
#include <stdlib.h>

void funcion(void) {
    static int x = 0; /*La variable estatica conserva su valor entre sus invocaciones*/
    x++;
    printf("%d\n", x);
}

int main(void)
{
    funcion(); /* Despues de la primera ejecucion, x mantiene el valor igual a 1, que fue resultado de x++.*/
    funcion(); /* Cuando se utilice por segunda vez, se va a sumar 1 a x (siendo x=1); se imprimira 2 y quedara guardado x=2*/
    funcion(); /* El procediemiento anterior se repite en todos los llamados siguientes a funcion()*/
    funcion();
    funcion(); 

    return EXIT_SUCCESS;
}



