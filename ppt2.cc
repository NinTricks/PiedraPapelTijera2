#include "ppt2.h"
#include <limits>

///////////////////////////////////////JUGADOR

Jugador::Jugador(){
    jugada = 0;
    jugadaPasada = 0;
}

void Jugador::registrarJugador(istream& in, ostream& o, int n){
    o << "Introduzca su nombre: ";
    in >> id;
    o << "Bienvenido al rework de la batalla de las mentes, \"" << id << "\"" << endl;

    id = "JUG" + to_string(n+1) + " " + id;
}

string Jugador::nombreJugador(){
    return id;
}

void Jugador::guardarJugada(int n){
    jugada = n;
}

int Jugador::miJugada(){
    return jugada;
}

int Jugador::miJugadaPasada(){
    return jugadaPasada;
}

void Jugador::actualizarJugadaPasada(){
    jugadaPasada = jugada;
}


///////////////////////////////////////GESTOR
void Gestor::generarJugadores(istream& in, ostream& o){
    limpiarPantalla(o);
    o << "REGISTRO DE JUGADORES" << endl << endl;

    for(int i=0; i<NJUGADORES; i++){
        j[i].registrarJugador(in,o,i);
        o << endl;
    }

    o << "Jugadores registrados, empezando la partida..." << endl;
    system("sleep 2");
}

bool Gestor::seguirManga(istream& in, ostream& o){
    bool tmp = true;
    for(int i=0; i<NJUGADORES && tmp; i++){
        tmp = tmp && (punt[i]<WIN);
    }
    return tmp;
}

void Gestor::printPuntos(istream& in, ostream& o){
    for(int i=0; i<NJUGADORES; i++){
        o << "Puntos de " << j[i].nombreJugador() << ": " << punt[i] << endl;
    }

}

void Gestor::jugada(istream& in, ostream& o, const int n){
    o << "Turno de " << j[n].nombreJugador() << endl;
    o << "1:Piedra, 2:Papel, 3:Tijera" << endl;
    o << "Elige: ";
    int m;
    in >> m;

    j[n].guardarJugada(m);
}


void Gestor::printJugada(istream& in, ostream& o){
    for(int i=0; i<NJUGADORES; i++){
        o << "JUGADA ANTERIOR DE " << j[i].nombreJugador() << endl;
        switch(j[i].miJugadaPasada()){
            case 1:
            o << "Piedra" << endl;
            break;

            case 2:
            o << "Papel" << endl;
            break;

            case 3:
            o << "Tijera" << endl;
            break;

            case 0:
            o << "N\\A" << endl;
            break;
        }
        o << endl;
    }
}

void Gestor::calcPuntos(){//de momento con 2 jugadores
    if((j[0].miJugada() == 1 && j[1].miJugada() == 2)){//piedra vs papel
        punt[1]+=PAPEL;
    }
    else if((j[0].miJugada() == 2 && j[1].miJugada() == 1)){//papel vs piedra
        punt[0]+=PAPEL;
    }
    else if((j[1].miJugada() == 1 && j[0].miJugada() == 3)){//piedra vs tijera
        punt[1]+=PIEDRA;
    }
    else if((j[0].miJugada() == 1 && j[1].miJugada() == 3)){//piedra vs tijera
        punt[0]+=PIEDRA;
    }
    else if((j[0].miJugada() == 2 && j[1].miJugada() == 3)){//papel vs tijera
        punt[1]+=TIJERA;
    }
    else if((j[1].miJugada() == 2 && j[0].miJugada() == 3)){//tijera vs papel
        punt[0]+=TIJERA;
    }
}

void Gestor::actualizarJugadaPasada(){
    for(int i=0; i<NJUGADORES; i++){
        j[i].actualizarJugadaPasada();
    }
}

void Gestor::printVictoria(istream& in, ostream& o){
    bool seguir = true;
    int i;
    for(i = 0; i<NJUGADORES && seguir; i++){
        if(punt[i] >= 10){
            seguir = false;
        }
    }
    i--;
    o << "-------------------GANADOR-------------------" << endl;
    o << j[i].nombreJugador() << endl << endl;
}

//////////////////////////////////////////////////OTROS
void limpiarPantalla(ostream& o){
    cout << "\033[2J\033[1;1H";
}