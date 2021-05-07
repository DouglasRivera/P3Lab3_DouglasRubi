#include <iostream>
#include <conio.h>
#include <string>
#include <random>
#include <time.h>

using namespace std;

int menu();

char** MatrizConObstaculos(int N,int M, int K);


char** MatrizConObstaculos(int N,int M, int K){
	char** Matriz = new char*[N];
	for(int i=0; i<N; i++) {
		Matriz[i] = new char[M];
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			Matriz[i][j] = '-';
		}
	}	
	srand(time(NULL));
	for(int i=0; i<K; i++) {
		int Num_i =  rand()% N;
		int Num_j = rand() % M;
		char m = Matriz[Num_i][Num_j];
		int Camino = '-';
		if(Matriz[Num_i][Num_j]==Camino) {
			Matriz[Num_i][Num_j]='#';
		}
	}
	return Matriz;
}


int main() {


int opcion = menu();
switch (opcion){
	case 1:{
		cout << endl;
	    cout << "Arreglo de Caracteres(Se retorna)" << endl;
	   
	    cout <<endl;
		break;
}
	case 2:{
		  char** matriz;
	      cout << endl;
	      cout << "Matriz de Caracteres(Se retorna)" << endl;
	      cout << "------------........------------" << endl;
				cout<<"Ingrese el Numero de Filas deseadas: "<<endl;
				int N;
				cin>>N;
				cout<<"Ingrese el Numero de Columnas deseadas: "<<endl;
				int M ;
				cin>>M;
				cout<<"Ingrese la cantidad de obstaculos deseados: "<<endl;
				int K;
				cin>>K;
				matriz = MatrizConObstaculos(N,M,K);
				for(int i=0; i<N; i++) {
					cout<<"["; 
					for(int j=0; j<M; j++) {
					cout<<"'"<<matriz[i][j]<<"'";
					}
					cout<<"]"; 
					cout<<endl;
				}
	      cout <<endl;
		break;
	}
	case 3:{
		  cout << endl;
	      cout << "Todo en Uno(Clean screen)" << endl;
	      
	      cout <<endl;
		break;
	}
	case 4:{
		cout << "Saliendo del menu........" << endl;
		
		break;
	}
}

	return 0;
}
int menu() {
	int opcion;
	cout << "------------MENU----------------" << endl;
	cout << "1. Arreglo con Caracteres" << endl;
	cout << "2. Matriz de Caracteres" << endl;
	cout << "3. Ejercicio de Grafica" << endl;
	cout << "4. Opcion de Salida del menu" << endl;
	cout << endl;
	cout << "Ingrese la opcion deseada: ";
	cin >> opcion;
	cout << endl;
	return opcion;
}