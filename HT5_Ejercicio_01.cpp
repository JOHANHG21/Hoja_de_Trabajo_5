/*
EJERCICIO #1
En una libreria se venden 4 modelos diferentes de cuadernos,
con los siguientes precios:
*Modelo#1 - Q10.00
*Modelo#2 - Q15.00
*Modelo#3 - Q18.50
*Modelo#4 - Q25.00

Por otra parte, se tiene informacion sobre las ventas realizadas
durante los últimos 30 días, estos movimientos se deben de guardar
en un archivo de la siguiente forma:
DIA1, MOD, CANT
DIA2, MOD, CANT
.....
DIA30,MOD,CANT
DIAi:Variable que representa el día que se efectúo la venta i(1-30)
MOD: Variable que representa el código de Modelo que se vendió (1-4)
CANT= Variable que representa la cantidad de unidades vendidas.

El programa debe ser capaz de:
*Modificar el número de unidades vendidas, solicitando al usuario
el día y código de artículo (Modificacion del archivo)
*Eliminacion de un día específico de venta (Modificacion del archivo)
*Calcula el total recaudado por modelo en los 30 días
*Calcular cual fue el modelo que se vendió mas en los 30 dias
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <regex>
#include <iomanip> 

using namespace std;
void insertar();
void mp();
void leer();
void eliminar();
void modificar();

int main(){	
	mp();
	//return 0;	
}
void mp(){
	int resp;
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal de la LIBRERIA"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Venta "<<"\n";
		cout<<" 2 - Mostrar Reporte de Ventas "<<"\n";
		cout<<" 3 - Eliminar Registro"<<"\n";
		cout<<" 4 - Modificar Registro"<<"\n";
		cout<<" 5 - Salir"<<"\n";
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
		else if (resp==3){		
			system("CLS");
			eliminar();	
		}			
		else if (resp==4){
			system("CLS");
			modificar();
		}
		else if (resp==5)
			break;
		else 
			break;
		
	} while(resp!=5);	
}
void insertar(){
	//declaracion de variables
	int dia,modelo,cantidad;
	float precio,op;
	ofstream db;

	system("CLS");
	//Ingreso de datos
	cout<<"*** Ingreso de Ventas ***\n\n";
	cout<<"Ingrese el dia en que se efectuo la venta: "<<endl;
	cin>>dia;
	fflush(stdin);
	cout<<"Ingrese el Modelo: "<<"(#1 AL #4)"<<endl;
	cin>>modelo;
	fflush(stdin);	
	cout<<"Ingrese la cantidad de cuadernos: "<<endl;
	cin>>cantidad;
		if (modelo ==1){
		precio = 10.00;
		op = precio*cantidad; 	
	}
	else if (modelo ==2){
		precio = 15.00;
		op = precio*cantidad; 
	} else if (modelo ==3){
		precio = 18.50;
		op = precio*cantidad;  
	}
	else if (modelo ==4){
		precio = 25.00;
		op = precio*cantidad;  
	}
	try {
		db.open("libreria.txt",ios::app);
		db<<dia<<"\t"<<modelo<<"\t"<<cantidad<<"\t"<<op<<endl;   //"|"
		db.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}	
}
void leer(){
	int i,mayorm;
	float d,m,c,op=0;
	float tm1=0;
	float tm2=0;
	float tm3=0;
	float tm4=0;	
	string linea;
	float suma= 0;
	int mayorop = -1;
	
	ifstream db;	
	try{
		db.open("libreria.txt",ios::in);	

		cout<<"-----------DATOS DEL ARCHIVO--------------"<<endl<<endl;
		cout<<"| DIA  |"<<"MODELO|"<<"CANTIDAD|"<<"TOTAL Q.|"<<endl;		
		while (db>>d>>m>>c>>op){
			cout<<"|  "<<d<<"  |"<<"\t|"<<m<<"|"<<"\t|"<<c<<"|"<<"\t|"<<op<<"|"<<endl;
			i++;
			if (m==1){
				tm1+=op;
			}else if (m==2){
				tm2+=op;
			}else if (m==3){
				tm3+=op;
			}else if (m==4){
				tm4+=op;
			}						
			//suma+=c;
			if (op>mayorop){
				mayorop=op;
				mayorm =m;
			}
//			system("Pause");
		}		
		db.close();	
		
		//cout<<"\nPromedio Global: "<<suma/i<<endl;
		cout<<"\n------------DESGLOCE POR MODELO-----------"<<endl<<endl;
		cout<<setprecision(5)<<" MODELO #1   "<<tm1<<endl;
		cout<<setprecision(5)<<" MODELO #2   "<<tm2<<endl;
		cout<<setprecision(5)<<" MODELO #3   "<<tm3<<endl;
		cout<<setprecision(5)<<" MODELO #4   "<<tm4<<endl<<endl;
		cout<<"El modelo mas vendido fue el MODELO #"<<mayorm<<endl<<endl;
		//cout<<" - Con una venta de: "<<setw(3)<<mayorop;
		system("Pause");
	}
	catch(exception& X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		cout<<"Error: "<<X.what()<<endl;
		system("Pause");
	}
	
}
void eliminar(){
	ifstream db_a; //archivo anterior
	ofstream db_n; //archivo nuevo
	int aux,dia,modelo,cantidad,flag;
	float op;
	remove("Temporal.txt");
	
	db_a.open("libreria.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese dia que desea borrar: "<<endl;
	cin>>aux;
	
	while (db_a>>dia>>modelo>>cantidad>>op){
		if(aux==dia){
			cout<<"Registro Eliminado...."<<endl;
			flag =1;
		}			
		else if(aux!=dia)
			db_n<<dia<<"\t"<<modelo<<"\t"<<cantidad<<"\t"<<op<<endl;
		//aux=0;
		//oid=0;					
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("libreria.txt");
		rename("Temporal.txt","libreria.txt");
	}	
	system("Pause");
}
void modificar(){
	ifstream db_a; //archivo anterior
	ofstream db_n; //archivo nuevo
	int aux,dia,modelo,ocantidad,icantidad,flag;
	float op;
	char respuesta;
	remove("Temporal.txt");
	
	db_a.open("libreria.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese el que del cual modificara informacion: "<<endl;
	cin>>aux;
	do {
		cout<<"Ingrese cantidad a modificar: "<<endl;
		cin>>icantidad;
		cout<<"\n\nEsta Seguro? S/N";
		cin>>respuesta;
		cout<<"\n"<<endl;
		respuesta = toupper(respuesta);		
	} while (respuesta!='S');	
	
	//leer archivo anterior
	while (db_a>>dia>>modelo>>ocantidad>>op){
		if(aux==dia){
			db_n<<dia<<"\t"<<modelo<<"\t"<<icantidad<<"\t"<<op<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;
		}			
		else if(aux!=dia)
			db_n<<dia<<"\t"<<modelo<<"\t"<<ocantidad<<"\t"<<op<<endl;
		//aux=0;
		//oid=0;					
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("libreria.txt");
		rename("Temporal.txt","libreria.txt");
	}	
	system("Pause");
}
