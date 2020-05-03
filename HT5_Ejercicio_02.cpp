/*EJERCICIO#2
Realice un programa que, dado el peso, la altura;
la edad y el género (M/F) de un grupo de N personas
que pertenecen a un departamento de la república,
obtenga un promedo de peso, altura y edad de esta
población. Los datos deben guardarse de forma ordenada
por edad en un archivo de datos. Así mismo el programa 
debe ser capaz de leer los datos del archivo y generar
un reporte con la media del peso, altura y la edad.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <regex>
#include <iomanip> 
#include<stdlib.h>

using namespace std;
void insertar();
void mp();
void leer();
//void ordenar();

int main(){	
	mp();
	//return 0;	
}
void mp(){
	int resp;
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal "<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Datos "<<"\n";
		cout<<" 2 - Mostrar Reporte de Datos "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			insertar();			
		}
		else if (resp==2){		
			system("CLS");
			leer();
		}
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}
/*void ordenar(){
  // Declaramos la estructura en una variable
  int temp;

  // Creamos un vector para el almacenamiento del archivo
  vector<personas> registros;


    // Ordenamiento
  // Declaracion del objeto para lectura de archivo
  ifstream db_read;
  db_read.open("datos.txt",ios::in);
	
  while(db_read>>temp.edad>>temp.peso>>temp.altura>>temp.genero){
    // Agregamos al vector el contenido del archivo.
    registros.push_back(temp);
  };
  // cerramos archivo.
  db_read.close();
  //Hacemos el ordenamiento del contenido del archivo y el ingreso.
    
  //Ordenamiento de BUBBLESORT por edad
  for(int i=0; i<registros.size(); i++) {
   for(int j=i+1; j<registros.size(); j++)
   {
      // Comparamos la edad
      if(registros[j].edad < registros[i].edad) {
         temp = registros[i];
         registros[i] = registros[j];
         registros[j] = temp;
      }
   }
  } 


    // remplazamos el archivo.
    ofstream db;
    db.open("datos.txt",ios::out);
    
    for (int i=0; i<registros.size(); i++){
      db << registros[i].edad <<"\t"<< registros[i].peso <<"\t"<< registros[i].altura <<"\t"<< registros[i].genero <<endl;
    }
    db.close();
}
*/
void insertar(){
	int n,i,j,temp,edad,peso;
	float altura;
	char genero;
	ofstream db;

	system("CLS");
	//Ingreso de datos
	cout<<"¿Cuantas personas ingresaras?"<<endl;
	cin>>n;
	int personas[n];
	cout<<"<<<<<<<<INGRESO DE DATOS>>>>>>>>>>>> "<<endl<<endl;
	for(i=0;i<n;i++){
		
	cout<<"PERSONA # "<<i+1<<endl<<endl;
		cout<<"Ingrese edad de la persona: "<<endl;
		cin>>edad;
		personas[i] = edad;
		fflush(stdin);
		cout<<"Ingrese peso de la persona: "<<endl;
		cin>>peso;
		personas[i] = peso;
		fflush(stdin);
		cout<<"Ingrese altura de la persona: "<<endl;
		cin>>altura;
		personas[i] = altura;
		fflush(stdin);
		cout<<"Ingrese genero de la persona M/F: "<<endl<<endl;
		cin>>genero;
		personas[i] = genero;
		system("cls");
	}
/*	for(i=0;i<n;i++){//Ciclo para posicion 0
	for(j=i+1;j<n;j++){//Comparar dos casillas (0 y 1)
		if(personas[i]>personas[j]){
			temp=personas[i];//Variable temporal
			personas[i]=personas[j];
			personas[j]=temp;  
		}
	}
	
}*/
	//for(i=0;i<n;i++){
	//cout<<personas[i]<<endl;
//}	
	try {
		db.open("datos.txt",ios::app);
		db<<edad<<"\t"<<peso<<"\t"<<altura<<"\t"<<genero<<endl;   //"|"
		db.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}
	//ordenar();	
}
/*void ordenar(float personas[int n], int n){
	int temp;
		for(int i=1;i<n;i++){//Ciclo para posicion 0
			for(int j=0;j<n-1;j++){//Comparar dos casillas (0 y 1)
				if(personas[j].edad>personas[j+1].edad){
					temp=personas[j];//Variable temporal
					personas[j]=personas[j+1];
					personas[j+1]=temp;  
				}
			}
	
		}
}
*/
void leer(){
	int i,j,temp,n;
	float e,p,a ;
	char g;
	float te=0;
	float tp=0;
	float ta=0;
	float personas[n];	
	string linea;
	
	ifstream db;	
	try{
		db.open("datos.txt",ios::in);	

		cout<<"-----------DATOS DEL ARCHIVO--------------"<<endl<<endl;
		cout<<"------------------------------------------"<<endl;
		cout<<"| EDAD  |"<<"PESO|"<<"ALTURA|"<<"GENERO|"<<endl;	
		cout<<"------------------------------------------"<<endl;	
		while (db>>e>>p>>a>>g){
			cout<<"|  "<<e<<"   |"<<p<<"  | "<<a<<" |  "<<g<<"   |"<<endl;
			i++;
			n+=i;
			te+=e;
			tp+=p;
			ta+=a;
//			system("Pause");
		}		
		db.close();	
		
		//cout<<"\nPromedio Global: "<<suma/i<<endl;
		cout<<"\n------------MEDIA DE LOS DATOS-----------"<<endl<<endl;
		cout<<setprecision(5)<<" EDAD:  "<<te/n-3<<endl;
		cout<<setprecision(5)<<" PESO:  "<<tp/n-3<<endl;
		cout<<setprecision(5)<<" ALTURA: "<<ta/n-3<<endl<<endl;
		/*cout<<"\n\n":
		cout<<"Los datos ordenados por edad son: ";
		ordenar(personas, n):
		leer(personas, n);	*/
		system("Pause");
	}
	catch(exception& X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		cout<<"Error: "<<X.what()<<endl;
		system("Pause");
	}
	
}
