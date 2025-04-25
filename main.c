#include <stdio.h>
#include <stdlib.h>

double promedio(double a, double b, double c){

    return (a+b+c)/3;

}

int main(int argc, char *argv[]){

    double a= atof(argv [1]);
    double b= atof (argv [2]);
    double c= atof (argv[3]);
    double prom= promedio(a,b,c);
    printf("el promedio de los tres numeros es: %d",prom);
    return 0;
}
