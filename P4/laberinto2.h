#ifndef _LABERINTO2_H_
#define _LABERINTO2_H_

#include <iostream>
#include <vector>

using namespace std;


class Laberinto{
	private:
		int tama;
		pair<int, int> entrada;
		pair<int, int> salida;

		vector<vector<int> > lab; //0 si no hay muro, 1 si si lo hay

	public:
		Laberinto(int n);

		pair<int, int> Salida(){
			return salida;
		}

		int Tamanio(){
			return tama;
		}

		const vector<int> & operator[](int a) const{
			return lab[a];
		}
		/*Laberinto & operator=(Laberinto & laber){
			tama = laber.tama;
			entrada = laber.entrada;
			salida = laber.salida;

			lab = laber.lab;
		}*/

		void GeneraDeNuevo();
		
		int operator[](pair<int, int> pos) const;

		friend ostream & operator<<(ostream & os, Laberinto & l);	
};

#endif
