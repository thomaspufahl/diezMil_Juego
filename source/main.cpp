#include "../headers/rlutil.h"
#include "../headers/funcionesEstilo.h"
#include "../headers/funciones.h"
#include "../headers/dosJugadores.h"
#include "../headers/unJugador.h"


int main() {
    //PARA PUNTERO
    int posY = 5;
    int posX = 8;
    // »
    int caracter = 175;

    //PARA MOV. PUNTERO
    int posY_Inicial = 5;
    int posY_Final = 9;
    int salto = 2;

    //BANDERA DE CLS
    //evita hacer cls siempre que cambie de opcion
    int condicionCls=0;

    //DATOS DE JUGADORES
    char jugadores[2][35];
    int puntaje[2];
    int turno;
    //inicializa el puntaje en 0
    vecZero(puntaje, 2);

    //ESTILO DE LA CONSOLA
    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::setColor(rlutil::WHITE);
    rlutil::cls();
    bordeMenu();

    while (true) {
        rlutil::hidecursor();
        antiCls(condicionCls);
        turno=0;
        vecZero(puntaje, 2);

        bordeMenu();
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
                        petNombre(jugadores, 1);
                        unJugador(condicionCls, jugadores, 1, puntaje, turno);
                        break;
                    case 7:
                        petNombre(jugadores, 2);
                        dosJugadores(condicionCls, jugadores, puntaje, turno);
                        break;
                    case 9:
                        //SALIR
                        return 0;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}