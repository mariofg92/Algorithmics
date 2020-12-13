#include <iostream>
#include <cstdlib>
#include <vector>

#include "laberinto2.h"

using namespace std;



Laberinto::Laberinto(int n){ //La entrada y la salida son siempre casillas libres
	tama = n;
	entrada = make_pair(0, 0);
	salida = make_pair(n-1, n-1);


	vector<int> aux;
	int filas = 0;

	srandom(time(0)); //Para que los numeros sean realmente aleatorios

	if (n > 2){ //Consideramos tama minimo de laberinto 3

		//Relleno la primera fila (la 0):

		aux.push_back(0); //Laberinto(0,0) = 0

		for (int i=1; i<n; i++){
			aux.push_back(random()%2);
		}

		lab.push_back(aux);

		filas++;

		aux.clear();

		//Relleno las siguientes:

		do{
			for (int i=0; i<n; i++){
				aux.push_back(random()%2);
			}
			lab.push_back(aux);

			filas++;

			aux.clear();
		}while(filas < n-1); //Rellena desde la fila 1 a la n-2

		//Relleno la ultima fila (n-1)

		for (int i=0; i<n-1; i++){
			aux.push_back(random()%2);
		}
		aux.push_back(0); //Laberinto(n-1,n-1) = 0

		lab.push_back(aux);

	}

}

/*Laberinto::Laberinto(int n){
	tama = n;
	entrada = make_pair(0, 0);
	salida = make_pair(n-1, n-1);


	vector<int> aux;
	int filas = 0;
	int elemento;

	do{
			for (int i=0; i<n; i++){
				cin >> elemento;
				aux.push_back(elemento);
			}

			cout << endl;
			lab.push_back(aux);

			filas++;

			aux.clear();
	}while(filas < n);
}*/

void Laberinto::GeneraDeNuevo(){
	lab.clear();

	vector<int> aux;
	int filas = 0;


	if (tama > 2){ //Consideramos tama minimo de laberinto 3

		//Relleno la primera fila (la 0):

		aux.push_back(0); //Laberinto(0,0) = 0

		for (int i=1; i<tama; i++){
			aux.push_back(random()%2);
		}

		lab.push_back(aux);

		filas++;

		aux.clear();

		//Relleno las siguientes:

		do{
			for (int i=0; i<tama; i++){
				aux.push_back(random()%2);
			}
			lab.push_back(aux);

			filas++;

			aux.clear();
		}while(filas < tama-1); //Rellena desde la fila 1 a la n-2

		//Relleno la ultima fila (n-1)

		for (int i=0; i<tama-1; i++){
			aux.push_back(random()%2);
		}
		aux.push_back(0); //Laberinto(n-1,n-1) = 0

		lab.push_back(aux);

	}
}

int Laberinto::operator[](pair<int, int> pos) const{ /* si le pasamos una pos
	no valida devuelve 1 */
	if (pos.first >= 0 && pos.first < tama && pos.second >= 0 && pos.second < tama)
		return lab[pos.first][pos.second];
	else
		return 1;
}

ostream & operator<<(ostream & os, Laberinto & l){
	os << endl << "Tama: " << l.tama << endl;
	os << "Entrada: (" << l.entrada.first << " , " << l.entrada.second << ")" << endl;
	os << "Salida: (" << l.salida.first << " , " << l.salida.second << ")" << endl;

	os << endl;
	for(int i=0; i< l.lab.size(); i++){
		for (int j = 0; j < l.lab[i].size(); j++)
		{
			os << l.lab[i][j] << " ";
		}
		os << endl;
	}

	os << endl;

	return os;
}

/*int main(){
	Laberinto prueba(5);
	Posicion pos;

	pos.datos = make_pair(-1,3);

	cout << prueba[pos.datos] << " " << prueba[3][3];

	cout << prueba;
}*/
