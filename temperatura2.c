#include <stdio.h>
#include <stdlib.h>

double f_a_c(double a) {
    return (a - 32) * 5 / 9;
}

int main(int argc, char *argv[]) {
    int tipo = atoi(argv[1]);
    char uni = argv[2][0];
    double temp = atof(argv[3]);
    double temp_c = (uni == 'f') ? f_a_c(temp) : temp;

    if (tipo == 1) {
        printf("Temperatura corporal en celsius: %.2f\n", temp_c);
        if (temp_c < 35) {
            printf("¡Tenés hipotermia!\n");
        } else if (temp_c <= 37.5) {
            printf("Tenés temperatura normal\n");
        } else {
            printf("¡Tenés fiebre!\n");
        }
    } else if (tipo == 0) {
        printf("Temperatura ambiental en celsius: %.2f\n", temp_c);
        if (temp_c < 10) {
            printf("Hace frío, ¡abrigate!\n");
        } else if (temp_c < 25) {
            printf("Está re lindo, salí con una remera y short\n");
        } else {
            printf("Hace calor, ¡andá a tomar un helado!\n");
        }
    } else {
        printf("Error: tipo inválido. Usá 1 para corporal o 0 para ambiental.\n");
    }

    return 0;
}