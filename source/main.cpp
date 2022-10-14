#include "../headers/rlutil.h"
#include "../headers/funciones.h"
#include "../headers/dosJugadores.h"
#include "../headers/unJugador.h"

int main() {
    //PARA PUNTERO
    int posY = 5;
    int posX = 8;
    int caracter = 175;

    //PARA MOV. PUNTERO
    int posY_Inicial = 5;
    int posY_Final = 9;
    //int posX_Inicial = 10;
    //int posX_Final = 10;
    int salto = 2;

    int ANTICLS=0;

    char jugadores[2][35];
    int puntaje[2];
    vecZero(puntaje, 2);
    puntaje[1]=15;

    while (true) {
        rlutil::hidecursor();


        if (ANTICLS==1) {
            rlutil::cls();
            ANTICLS = 0;
        }


        label("UN JUGADOR", 10, 5);
        label("DOS JUGADORES", 10, 7);
        label("SALIR", 10, 9);

        labelInt(caracter, posX, posY);

        int key = rlutil::getkey();
        //up    14
        //down  15
        //enter 1

        switch (key) {
            case 14:
                punteroArriba(posX, posY, caracter, posY_Inicial, salto);
                break;
            case 15:
                punteroAbajo(posX, posY, caracter, posY_Final, salto);
                break;
            case 1:
                switch (posY) {
                    case 5:
                        //TODAVIA NO FUNCIONA EL INGRESO DE NOMBRES
                        petNombre(jugadores, 1);
                        unJugador(ANTICLS, jugadores, puntaje);
                        break;
                    case 7:
                        petNombre(jugadores, 2);
                        dosJugadores(ANTICLS, jugadores, puntaje);
                        break;
                    case 9:
                        return 0;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}