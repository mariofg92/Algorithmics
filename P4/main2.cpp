#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>

#include "laberinto2.h"

using namespace std;
using namespace std::chrono;

// ORIENTACION ->  este = 0, sur = 1, oeste = 2 norte = 3,


bool PuedoMoverme(int ori, const vector<pair<int, int> > & posiciones, pair<int, int> pos, Laberinto & lab){
	bool a_devolver = false;



	if(ori == 3){
		pos.first += -1;
		if (lab[pos] == 1)
			a_devolver = false;
		else
			a_devolver = true;
	}

	if(ori == 1){
		pos.first += 1;
		if (lab[pos] == 1)
			a_devolver = false;
		else
			a_devolver = true;
	}

	if(ori == 0){
		pos.second += 1;
		if (lab[pos] == 1)
			a_devolver = false;
		else
			a_devolver = true;
	}

	if(ori == 2){
		pos.second += -1;
		if (lab[pos] == 1)
			a_devolver = false;
		else
			a_devolver = true;
	}

	for(int i = 0; i < posiciones.size() && a_devolver; i++)
		if(posiciones[i] == pos)
			a_devolver = false;

	return a_devolver;
}

pair<int, int> Avanzar(int ori, pair<int, int> pos){
	if(ori == 3){
		pos.first += -1;
	}

	if(ori == 1){
		pos.first += 1;
	}

	if(ori == 0){
		pos.second += 1;
	}

	if(ori == 2){
		pos.second += -1;
	}

	return pos;
}

void ResolverLaberinto(vector<int> & solucion, vector<pair<int, int> >&posiciones, pair<int, int> posi, Laberinto & labe, bool & fin){
	int movimiento = 0;
	pair<int, int> avance;

	while (movimiento<4 && !fin){
	//Movimiento es 0 = norte, 1 = este, 2 = sur, 3 = oeste

		if (PuedoMoverme(movimiento, posiciones, posi, labe)){
			avance = Avanzar(movimiento, posi);
			solucion.push_back(movimiento);
			posiciones.push_back(avance);

			if(avance == labe.Salida()){
				fin = true;
			}else{
				ResolverLaberinto(solucion, posiciones, avance, labe, fin);
			}
			if(!fin){
				solucion.pop_back();
				posiciones.pop_back();
			}
		}

		movimiento++;
	}
	
}

void ResolverLaberintoMejor(vector<int> & mejor, vector<int> & solucion, vector<pair<int, int> >&posiciones, pair<int, int> posi, Laberinto & labe){
	int movimiento = 0;
	pair<int, int> avance;

	while (movimiento<4){
	//Movimiento es 0 = norte, 1 = este, 2 = sur, 3 = oeste

		if (PuedoMoverme(movimiento, posiciones, posi, labe)){
			avance = Avanzar(movimiento, posi);
			solucion.push_back(movimiento);
			posiciones.push_back(avance);

			if(avance == labe.Salida()){
				if(solucion.size() < mejor.size() || mejor.size() == 0) {

					mejor = solucion;

				}
			} else {
				ResolverLaberintoMejor(mejor, solucion, posiciones, avance, labe);
			}
			solucion.pop_back();
			posiciones.pop_back();
		}

		movimiento++;
	}
	
}

int main(int argc, char * argv[]){


	if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }
    int n = atoi(argv[1]);
	Laberinto prueba(n);
	pair<int, int> mipos(0, 0);
	vector<int> solu, solu2, aux;
	vector<pair<int, int> > posiciones, posiciones2;
	time_point <high_resolution_clock> antes, despues;
	duration <double> transcurrido;
	double media=0;

	bool haySolucion = false;

	for(int i = 0; i< 100; i++ ){
		antes = high_resolution_clock::now();
		ResolverLaberinto(solu, posiciones, mipos, prueba, haySolucion);
		//ResolverLaberintoMejor(solu2, aux, posiciones2, mipos, prueba);
		despues = high_resolution_clock::now();

		transcurrido = duration_cast<duration<double>>(despues-antes);

		prueba.GeneraDeNuevo();
		posiciones.clear();
		posiciones2.clear();
		solu.clear();
		solu2.clear();
	media += transcurrido.count();
    }

    cout << n << " " << media / 100 << endl;
	//ResolverLaberintoMejor(solu2, aux, posiciones2, mipos, prueba);

/*
	cout << prueba << "Solucion: " <<endl;

	if (solu.size()){

		for (int i=0; i < solu.size(); i++){
			if(solu[i]==0)
				cout << "E --> ";
			if(solu[i]==1)
				cout << "S --> ";
			if(solu[i]==2)
				cout << "O --> ";
			if(solu[i]==3)
				cout << "N --> ";
		}
	}else{
		cout << endl << "No hay solucion" << endl;
	}
		

	cout << endl << "MEJOR Solucion: " <<endl;

	if (solu2.size()){

		for (int i=0; i < solu2.size(); i++){
			if(solu2[i]==0)
				cout << "E --> ";
			if(solu2[i]==1)
				cout << "S --> ";
			if(solu2[i]==2)
				cout << "O --> ";
			if(solu2[i]==3)
				cout << "N --> ";
		}
	}else{
		cout << endl << "No hay solucion" << endl;

	}
*/
}
