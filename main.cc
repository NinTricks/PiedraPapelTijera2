#include "ppt2.h"

int main(){
    Gestor g;

    g.generarJugadores(cin,cout);
    limpiarPantalla(cout);
    while(g.seguirManga(cin,cout)){
        for(int i=0; i<NJUGADORES;i++){
            g.printJugada(cin,cout);
            g.printPuntos(cin,cout);
            cout << endl << endl;
            g.jugada(cin, cout, i);
            limpiarPantalla(cout);  
        }
        g.calcPuntos();
        g.actualizarJugadaPasada();
        limpiarPantalla(cout);  
    }
    g.printPuntos(cin,cout);
    g.printVictoria(cin,cout);

    return 0;
}