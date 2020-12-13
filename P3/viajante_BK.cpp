/**
  * @file viajante_BK.cpp
  *	@author Francisco Javier Ortiz Jimenez
  *	@date Enero de 2011
  *
  */

#include <iostream>
#include <vector>

int num_nodos = 0;

using namespace std;

void viajante_BK (vector< vector<double> > &D, vector<int> &A, double &distancia);
void Recursiva(vector< vector<double> > &D, vector<int> &A, vector<int> &A_aux, 
			   double &distancia, double &dis_sol, const int n, const int indice, vector<bool> &Check);
void Rellenar_matriz(vector<vector<double> > &D);
void Imprimir(vector<int> A);
double Calcular_Distancia(const vector<int> &A, const vector<vector<double> > &D);
void Greedy(const vector<vector<double> > &D, const vector<int> &A);
int Calcular_Minimo(const vector<vector<double> > &D, int fil);

int main(int argc, )
{
	int n = 8;	//Tamaño de la matriz
	double distancia; //Solucion: distancia final del recorrido

	vector< vector<double> > D(n, vector<double> (n));
	vector<int> A(n);

	A[0] = 1;
	A[1] = 0;
	A[2] = 0;
	A[3] = 0;
	A[4] = 0;
	A[5] = 0;
	A[6] = 0;
	A[7] = 0;

	Rellenar_matriz(D);

	clock_t antes, despues, total;
	for(int i = 0; i < VECES; i++)
	{

	antes = clock();

	viajante_BK(D, A, distancia);

	despues = clock();

	total += despues - antes;
	}

	cout << (double)total / (CLOCKS_PER_SEC * VECES) << distancia / VECES << << endl;

}


/**	
  *	@brief Calculamos la distancia minima
  * @param D, matriz en la que almacenamos las distancias 
  * @param A, vector solucion de las ciudades visitadas
  *	@param distancia, variable en la que almacenamos la distancia final, la distancia solucion
  */
void viajante_BK (vector< vector<double> > &D, vector<int> &A, double &distancia)
{
	int indice = 1, n = A.size();
	double dis_sol = 0;
	vector<int> A_aux(n);			//Vector para ir almacenando las posibles soluciones
	vector<bool> Check(A.size());	//Vector para almacenar las ciudades que se han visitado
	Check[0] = true;

	Recursiva(D, A, A_aux, distancia, dis_sol, n, indice, Check);

	for(int k = 0; k < n; k++)
		cout << A_aux[k] << "-";
	cout << "DISTANCIA: " << dis_sol << endl;
}


/**	
  *	@brief Calculamos la distancia minima
  * @param D, matriz en la que almacenamos las distancias 
  * @param A, vector en el que almacenamos las posibles soluciones
  * @param A_aux, vector auxiliar en el que almacenamos la solucion final
  *	@param distancia, variable en la que almacenamos la distancia calculada
  *	@param dis_sol, variable en la que almacenamos la distancia final, es decir, la menor distancia
  *	@param n, nos indica el numero de elementos que vamos a visitar
  *	@param indice, posicion de la ciudad en la que se encuentra
  *	@param Check, vector de ciudades recorridas: 1 para las recorridas y 0 para las no recorridas
  */
void Recursiva(vector< vector<double> > &D, vector<int> &A, vector<int> &A_aux, 
			   double &distancia, double &dis_sol, const int n, const int indice, vector<bool> &Check)
{
	num_nodos++;

	//Caso base
	if(indice == n)
	{
		distancia = Calcular_Distancia(A, D);

		if(dis_sol == 0)	//Si distancia solucion no tiene ninguna distancia, introducimos la primera calculada
		{
			dis_sol = distancia;	//Actualizamos la distancia solucion
			A_aux = A;				//Actualizamos el vector solucion
		}

		if(distancia < dis_sol)	//Si la distancia es menor que la distancia solucion 
		{
			dis_sol = distancia;	//Actualizamos la distancia solucion
			A_aux = A;				//Actualizamos el vector solucion
		}
	}
	else
	{
		for(int i = 1; i < n; i++)
		{
			if(Check[i] == false)	//Si la ciudad no se ha visitado ...
			{
				A[indice] = i + 1;
				Check[i] = true;
				Recursiva(D, A, A_aux, distancia, dis_sol, n, indice + 1, Check);
				Check[i] = false;
			}
		}
	}	
}

void Rellenar_matriz(vector<vector<double> > &D)
{
/*    D[0][1] = 8;D[0][2] = 9;D[0][3] = 17;D[0][4] = 2;
    D[1][0] = 8;D[1][2] = 2;D[1][3] = 11;D[1][4] = 5;
    D[2][0] = 9;D[2][1] = 2;D[2][3] = 1;D[2][4] = 1;
    D[3][0] = 17;D[3][1] = 11;D[3][2] = 1;D[3][4] = 2;
    D[4][0] = 2;D[4][1] = 5;D[4][2] = 1;D[4][3] = 2;*/

    D[0][1] = 8;D[0][2] = 9;D[0][3] = 17;D[0][4] = 2;D[0][5] = 1;D[0][6] = 7;D[0][7] = 3;
    D[1][0] = 8;D[1][2] = 2;D[1][3] = 11;D[1][4] = 5;D[1][5] = 9;D[1][6] = 8;D[1][7] = 1;
    D[2][0] = 9;D[2][1] = 2;D[2][3] = 1;D[2][4] = 1;D[2][5] = 6;D[2][6] = 8;D[2][7] = 2;
    D[3][0] = 17;D[3][1] = 11;D[3][2] = 1;D[3][4] = 2;D[3][5] = 9;D[3][6] = 2;D[3][7] = 8;
    D[4][0] = 2;D[4][1] = 5;D[4][2] = 1;D[4][3] = 2;D[4][5] = 6;D[4][6] = 23;D[4][7] = 8;
    D[5][0] = 1;D[5][1] = 9;D[5][2] = 6;D[5][3] = 9;D[5][4] = 6;D[5][6] = 9;D[5][7] = 4;
    D[6][0] = 7;D[6][1] = 8;D[6][2] = 8;D[6][3] = 2;D[6][4] = 23;D[6][5] = 9;D[6][7] = 1;
    D[7][0] = 3;D[7][1] = 1;D[7][2] = 2;D[7][3] = 8;D[7][4] = 8;D[7][5] = 4;D[7][6] = 1;

}

void Imprimir(vector<int> A)
{
	for(int i = 0; i < A.size(); i++)
		cout << A[i] << "-";
	cout << endl;
}


/**	
  *	@brief Calculamos la distancia del vector que le pasamos
  * @param A, vector solucion de las ciudades visitadas
  * @param D, matriz en la que almacenamos las distancias 
  *	@return la distancia total calculada del vector A
  */
double Calcular_Distancia(const vector<int> &A, const vector<vector<double> > &D)
{
	double salida = 0;

	for(int i = 0; i < A.size(); i++)
		if(i < A.size() - 1)
			salida = salida + D[A[i]-1][A[i+1]-1];
		else
			salida = salida + D[A[i]-1][0];	//Distancia desde la ultima ciudad visitada al inicio del trayecto

	return salida;
}

//Cogemos la ciudad que mas cerca nos pille
void Greedy(const vector<vector<double> > &D, const vector<int> &A)
{
	double salida = 0;
	int res;
	vector <int> Check(A.size());

	Check[0] = 1;	

	for(int i = 0; i < A.size(); i++)
	{
		res = Calcular_Minimo(D, i);
		salida = salida + D[i][res];
	}
	cout << "DISTANCIA: " << salida << endl;
}

int Calcular_Minimo(const vector<vector<double> > &D, int fil)
{
	int minimo, ind;
	bool primero = true;

	for(int i = 0; i < D.size(); i++)
	{
		if(i != fil)
		{
			if(primero)
			{
				minimo = D[fil][i];
				ind = i;
				primero = false;
			}
			if(D[fil][i] < minimo)
			{
				minimo = D[fil][i];
				ind = i;
			}
		}
	}

	return ind;
}
