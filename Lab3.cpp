#include <iostream>
#include <conio.h>
#include <string>
#include <random>
#include <time.h>

using namespace std;

int menu();
char* lecturaCadena(int);
void printCadena(char*, int);
int ArregloDescomprimido(char*, int);
string indexNum(char);
char** MatrizConObstaculos(int N,int M, int K);

char* lecturaCadena(int size) {
    char* array;
    array = new char[size];
    char var = 0;
    for (int i = 0; i < size; i++) {
        cout << "Ingrese el indice " << "[ " << i << " ] :";
        cin >> var;
        array[i] = var;
    }
    return array;
}

void printCadena(char* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << "[ " << array[i] << " ]";
    }
    cout << endl << endl;
}

int ArregloDescomprimido(char* &array, int size, char* &newArray) {
    int totalSize = 0;
    string num = "";
    int* numbers;
    numbers = new int[size];
    //contador para numbers
    int contador = 0;
    for (int i = 0; i < size; i++) {
        char var = array[i];
        if ((int) var >= 48 && (int) var <= 57) {\
            num += indexNum(var);
        }
        else {
            totalSize += stoi(num);
            numbers[contador] = stoi(num);
            contador++;
            num.clear();
        }
    }
    //el nuevo arreglo
    newArray = new char [totalSize];
    //contador con los numeros del array
    contador = 0;
    //nuevo contador para newArray
    int count = 0;
    //for principal llena el nuevo arreglo con los nuevos caracteres
    for (int i = 0; i < size; i++) {
        char var = array[i];
        if ((int)var >= 65 && (int)var <= 90) {
            int tempSize = numbers[contador];
            int flag = 0;
            
            while (flag < tempSize) {
                newArray[count] = var;
                flag++;
                count++;
            }
            contador++;
        }
    }
    //delete de numbers
    if (numbers != 0) {
        delete[] numbers;
        numbers = 0;
    }
    cout << "Este es el arreglo" << endl << endl;
    printCadena(newArray, totalSize);
    
    if(newArray != 0){
        delete[] newArray;
        newArray = 0;
    }
    return totalSize;
}


string indexNum(char var) {
    switch ((int) var) {
        case 48:
        {
            return "0";
        }
        case 49:
        {
            return "1";
        }
        case 50:
        {
            return "2";
        }
        case 51:
        {
            return "3";
        }
        case 52:
        {
            return "4";
        }
        case 53:
        {
            return "5";
        }
        case 54:
        {
            return "6";
        }
        case 55:
        {
            return "7";
        }
        case 56:
        {
            return "8";
        }
        case 57:
        {
            return "9";
        }
    }
}
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
	int size = 0;
    cout << "Ingrese el size de la cadena a ingresar: ";
    cin >> size;
    cout << endl << endl;

    char* array;
    char* newArray;

    array = lecturaCadena(size);

    cout << ArregloDescomprimido(array, size, newArray) << endl;
    
    if(array != 0){
        delete[] array;
        array = 0;
    }

    return 0;		
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
					cout<<"'"
					<<matriz[i][j]<<"'";
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
	      	cout<<"Ingrese el Numero de Filas deseadas: "<<endl;
				
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
	cout << "-----------|||MENU|||------------" << endl;
	cout << "1. Arreglo con Caracteres" << endl;
	cout << "2. Matriz con Obstaculos" << endl;
	cout << "3. Ejercicio de Grafica" << endl;
	cout << "4. Opcion de Salida del menu" << endl;
	cout << "------------|||||||||------------" << endl;
	cout << endl;
	cout << "Ingrese la opcion deseada: ";
	cin >> opcion;
	cout << endl;
	return opcion;
}