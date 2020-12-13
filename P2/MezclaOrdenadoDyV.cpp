#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;
using namespace std::chrono;

void MezclaOrdenado (vector<int> V1, int tama1, vector<int> V2, int tama2, vector<int> & result){
  int i1=0, i2=0;
  result.clear();
  
  while(i1<tama1 && i2<tama2){
    if(V1[i1] <= V2[i2]){
      result.push_back(V1[i1]);
      i1++;
    }else{
      result.push_back(V2[i2]);
      i2++;
    }
  }

  if(i1==tama1){
    while(i2 < tama2){
      result.push_back(V2[i2]);
      i2++;
    }
  }

  if(i2==tama2){
    while(i1 < tama1){
      result.push_back(V1[i1]);
      i1++;
    }
  }
}

void OrdenaDyV (vector<int> T[], int principio, int final, vector<int> & result){
  int tama = final - principio;
  vector<int> r1, r2;

  if(tama==0){ //caso base
    if(result.empty())
      result = T[principio];
    else
      MezclaOrdenado(result, result.size(), T[principio], T[principio].size(), result);
  }else{
    OrdenaDyV (T, principio, (principio+final)/2, r1);

    OrdenaDyV (T, ((principio+final)/2)+1, final, r2);

    MezclaOrdenado(r1, r1.size(), r2, r2.size(), result);
  }
}


//CODIGO DADO --------------------------------------

//generador de ejemplor para el problema de mezcla de k vectores ordenados. Para obtener k vectores ordenados de forma creciente cada uno con n elementos, genera un vector de tamaño k*n con todos los enteros entre 0 y kn-1 ordenados. Se lanzan entonces k iteraciones de un algoritmo de muestreo aleatorio de tamaño n para obtener los k vectores. Están ordeados porque el algoritmo de muestreo mantiene el orden

double uniforme() //Genera un número uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C. 
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}


int main(int argc, char * argv[])
{
	
time_point <high_resolution_clock>tantes, tdespues;
duration<double> transcurrido;


  if (argc != 3)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << " <num_vect>" << endl;
      return -1;
    }

  int n = atoi(argv[1]);
  int k=atoi(argv[2]);


int **T;
T =  new int * [k];
  assert(T);

 for (int i = 0; i < k; i++)
      T[i]= new int [n];

int N=k*n;
int * aux = new int[N];
  assert(aux);

srand(time(0));
//genero todos los enteros entre 0 y k*n-1
for (int j=0; j<N; j++) aux[j]=j;

//para cada uno de los k vectores se lanza el algoritmo S (sampling) de Knuth
for (int i=0; i<k; i++) {
   int t=0;
   int m=0;
   while (m<n) {
    double u=uniforme();
    if ((N-t)*u >= (n-m)) t++;
    else {
        T[i][m]=aux[t];
	t++;
	m++;
    }
  }
}

delete [] aux;

//FIN CODIGO DADO -----------------------------------------------



  vector<int> T3[k];
   vector<int> result2;
 
   

  for(int i=0; i<k; i++){
    for(int j=0; j<n; j++)
      T3[i].push_back(T[i][j]);
  }

tantes = high_resolution_clock::now();

  OrdenaDyV(T3, 0, k-1, result2);

tdespues = high_resolution_clock::now();
transcurrido = duration_cast<duration<double>>(tdespues - tantes);
cout<< k << " " <<transcurrido.count()<< endl;

  

}


