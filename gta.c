#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define FILAS 12
#define COLUMNAS 24

char mapa[FILAS][COLUMNAS] = {
    "########################",
    "#P......A......#......G#",
    "#..............#.......#",
    "#......#.......#.......#",
    "#......#...............#",
    "#......#######.........#",
    "#..............A.......#",
    "#.....#..........#.....#",
    "#.....#....C.....#.....#",
    "#.................#....#",
    "#......................#",
    "########################"
};

int jugadorX = 1, jugadorY = 1;
int tieneAuto = 0;

void dibujarMapa() {
    system("cls");
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }

    printf("\nControles: W A S D para moverse, Q para salir.");
    if (tieneAuto)
        printf("\n¡Tenés un auto! Llévalo al garage (G).\n");
    else
        printf("\nObjetivo: Robá un auto (A).\n");
}

void moverJugador(int dx, int dy) {
    int nuevaX = jugadorX + dx;
    int nuevaY = jugadorY + dy;

    char destino = mapa[nuevaX][nuevaY];

    if (destino == '#') return; // Pared

    if (destino == 'A') {
        tieneAuto = 1;
        printf("\n¡Robaste un auto!\n");
        _getch();
    }

    if (destino == 'C' && !tieneAuto) {
        printf("\nLa policía te ignora... por ahora.\n");
        _getch();
    } else if (destino == 'C' && tieneAuto) {
        printf("\n¡Te arrestaron por robo de auto!\n");
        exit(0);
    }

    if (destino == 'G' && tieneAuto) {
        printf("\n¡Entregaste el auto robado! Misión completada.\n");
        exit(0);
    }

    mapa[jugadorX][jugadorY] = '.'; // Deja el suelo
    jugadorX = nuevaX;
    jugadorY = nuevaY;
    mapa[jugadorX][jugadorY] = 'P'; // Nueva posición
}

int main() {
    char tecla;

    while (1) {
        dibujarMapa();
        tecla = _getch();

        switch(tecla) {
            case 'w': moverJugador(-1, 0); break;
            case 's': moverJugador(1, 0); break;
            case 'a': moverJugador(0, -1); break;
            case 'd': moverJugador(0, 1); break;
            case 'q': return 0;
        }
    }

    return 0;
}
