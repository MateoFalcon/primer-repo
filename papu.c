#include <stdio.h>
#include <stdlib.h>

int mult(int a, int b){

    return a*b;
}

int main(int argc, char *argv[]){

    if (argc != 4) {
        printf("Uso: %s <tipo_cliente> <precio> <cantidad>\n", argv[0]);
        return 1;
    }
    char tc= argv[1][0];
    int precio= atoi(argv [2]);
    int cant= atoi(argv [3]);
    int pf= mult(precio,cant);
    if (tc=='n'){
        printf("el precio final es: %d\n", pf);
    } else if(tc=='f'){
        int pff= pf*0.95;
        printf("el precio final es: %d\n", pff);
    }else if (tc=='v'){
        int pfv= pf*0.80;
        printf("el precio final es: %d\n", pfv);
    }else if(tc=='e'){
        int pfe= pf*1.10;
        printf("el precio final es: %d\n", pfe);
    }
    return 0;
}
