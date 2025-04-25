#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int repartirCarta() {
    int carta = rand() % 13 + 1;
    if (carta > 10) return 10;
    if (carta == 1) return 11;
    return carta;
}

void mostrarMano(int mano[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("%d ", mano[i]);
    }
    printf("\n");
}

int sumarMano(int mano[], int cantidad) {
    int suma = 0, ases = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += mano[i];
        if (mano[i] == 11) ases++;
    }
    while (suma > 21 && ases > 0) {
        suma -= 10;
        ases--;
    }
    return suma;
}

int main() {
    srand(time(NULL));

    int saldo = 1000;  // Saldo inicial
    int apuesta;
    char jugar = 's';

    while (jugar == 's' || jugar == 'S') {
        printf("\nSaldo actual: $%d\n", saldo);

        // Verificar si hay dinero
        if (saldo <= 0) {
            printf("Te has quedado sin dinero. Juego terminado.\n");
            break;
        }

        // Pedir apuesta
        do {
            printf("Ingresa tu apuesta: $");
            scanf("%d", &apuesta);
            if (apuesta > saldo || apuesta <= 0) {
                printf("Apuesta inválida. Debe ser entre 1 y %d.\n", saldo);
            }
        } while (apuesta > saldo || apuesta <= 0);

        int jugador[10], banca[10];
        int cantJugador = 0, cantBanca = 0;
        char opcion;

        // Primeras cartas
        jugador[cantJugador++] = repartirCarta();
        jugador[cantJugador++] = repartirCarta();
        banca[cantBanca++] = repartirCarta();
        banca[cantBanca++] = repartirCarta();

        printf("Tu mano: ");
        mostrarMano(jugador, cantJugador);
        printf("Total: %d\n", sumarMano(jugador, cantJugador));
        printf("Carta visible de la banca: %d\n", banca[0]);

        // Turno del jugador
        do {
            printf("Quieres otra carta? (s/n): ");
            scanf(" %c", &opcion);
            if (opcion == 's' || opcion == 'S') {
                jugador[cantJugador++] = repartirCarta();
                printf("Tu mano: ");
                mostrarMano(jugador, cantJugador);
                printf("Total: %d\n", sumarMano(jugador, cantJugador));
            }
        } while ((opcion == 's' || opcion == 'S') && sumarMano(jugador, cantJugador) < 21);

        int totalJugador = sumarMano(jugador, cantJugador);

        if (totalJugador > 21) {
            printf("Te pasaste de 21. Pierdes $%d.\n", apuesta);
            saldo -= apuesta;
        } else {
            // Turno de la banca
            printf("\nTurno de la banca...\n");
            printf("Mano de la banca: ");
            mostrarMano(banca, cantBanca);
            printf("Total: %d\n", sumarMano(banca, cantBanca));

            while (sumarMano(banca, cantBanca) < 17) {
                banca[cantBanca++] = repartirCarta();
                printf("La banca toma una carta.\n");
                printf("Mano de la banca: ");
                mostrarMano(banca, cantBanca);
                printf("Total: %d\n", sumarMano(banca, cantBanca));
            }

            int totalBanca = sumarMano(banca, cantBanca);

            // Resultado
            if (totalBanca > 21 || totalJugador > totalBanca) {
                printf("\nGanaste! Ganas $%d.\n", apuesta);
                saldo += apuesta;
            } else if (totalJugador == totalBanca) {
                printf("\nEmpate. Tu saldo no cambia.\n");
            } else {
                printf("\nPerdiste. Pierdes $%d.\n", apuesta);
                saldo -= apuesta;
            }
        }

        // Continuar jugando
        printf("\nSaldo actual: $%d\n", saldo);
        printf("Quieres seguir jugando? (s/n): ");
        scanf(" %c", &jugar);
    }

    printf("\nJuego finalizado. Saldo final: $%d\n", saldo);

    return 0;
}