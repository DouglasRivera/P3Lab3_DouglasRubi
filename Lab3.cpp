#include <iostream>
#include <ctime>
#include <math.h>
#include <cstdlib>
using namespace std;

int menu();

 /*void EjerTrianguloPascal();
 void EjerDesviacion();
 void EjerGrafico();*/



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
	      cout << endl;
	      cout << "Matriz de Caracteres(Se retorna)" << endl;
	      
	      cout <<endl;
		break;
	}
	case 3:{
		  cout << endl;
	      cout << "Todo en Uno(Grafico de Barra)" << endl;
	      
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
	cout << "----MENU----" << endl;
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