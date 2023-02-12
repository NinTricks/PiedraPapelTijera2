#include "ppt2.h"
#include <random>
#include <fstream>

typedef std::mt19937 MyRNG;  // the Mersenne Twister with a popular choice of parameters
uint32_t seed_val;           // populate somehow

MyRNG rng;                   // e.g. keep one global instance (per thread)

const int ITERS = 10;

void initialize(){
    rng.seed(seed_val);
}

void partida(ostream& f){

    Gestor g;

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist3(1,3); // distribution in range [1, 6]


    g.generarIAs();
    while(g.seguirManga(cin,cout)){

        for(int i=0; i<NJUGADORES;i++){
            int jugadote = dist3(rng);
            g.jugadaIA(i,jugadote);
            f << jugadote << ";";
        }

        g.calcPuntos();
        g.actualizarJugadaPasada(); 
    }

    //Fin partida
    
    //g.printPuntos(cin,cout);
    //g.printVictoria(cin,cout);
    int win = g.ganador();
    f << win << ";fin;\n";

}


void rotar(string& s){
    int l = s.length();
    int i = 0;
    char aux;

    while(i<(l/2)*2){
        aux = s[i];
        s[i] = s[i+1];
        s[i+1] = aux;
        i+=2;
    }
}

string recortar(const string& s){
    string res;
    for(int i=0; i<s.length();i+=2){
        res[i/2] = s[i];
    }
    return res;
}

int main(){
    cout << "hola";
    ofstream f;
    f.open("out");
    for(int i=0; i<ITERS;i++){
        partida(f);
    }
    f.close();

    //ANÁLISIS

    ifstream i;
    i.open("out");
    string leido;
    string linea;
    //Trie arbolito;
    
    
    while(!i.eof()){
        linea = "";
        getline(i,leido,';');

        while(leido!="fin"){
            linea += leido;
            getline(i,leido,';');
        }
        getline(i,leido);

        if(linea[linea.length()-1] == 1){//ganador siempre juega 1º
            rotar(linea);
        }
        
        linea.substr(linea.length()-1,1);

    }

    cout << linea << endl;
    linea = recortar(linea);
    cout << linea << endl;

    return 0;
}