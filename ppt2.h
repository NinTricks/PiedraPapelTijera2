#include <string>
#include <iostream>


const int WIN = 10;
const int PIEDRA = 4;
const int PAPEL = 2;
const int TIJERA = WIN;
const int NJUGADORES = 2;

using namespace std;

class Jugador{
    private:
    string id;
    int jugada, jugadaPasada;//1 piedra, 2 papel, 3 tijera

    public:
    Jugador();
    void registrarJugador(istream& i, ostream& o, int n);
    string nombreJugador();
    void guardarJugada(int n);
    int miJugada();
    int miJugadaPasada();
    void actualizarJugadaPasada();


};

class Gestor{
    private:
    Jugador j[NJUGADORES];
    int punt[NJUGADORES];
    

    public:
    Gestor();
    void generarJugadores(istream& i, ostream& o);
    bool seguirManga(istream& i,ostream& o);
    void printPuntos(istream& i,ostream& o);
    void jugada(istream& in, ostream& o, const int n);
    void printJugada(istream& in, ostream& o);
    void calcPuntos();
    void actualizarJugadaPasada();
    void printVictoria(istream& in, ostream& o);
};

void limpiarPantalla(ostream& o);