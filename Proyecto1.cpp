#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<fstream>
#include<stdlib.h>

using namespace std;

struct alumno
{
	string carne;
	string nombre;
	string correo;
	string seccion;
	int cicloEscolar;
	char estado;
	float promedio;
};

void reAlumno();
void buAlumno();
void modAlumno();

int main()
{
	int opc;
	char opcion='1';
	
	while (opcion=='1')
	{
		system("cls");
		cout<<endl;
		cout<<"\t\t\t              PROYECTO I           "<<endl<<endl;
		cout<<"\t\t\t\t1. Registrar Alumno"<<endl;
		cout<<"\t\t\t\t2. Buscar Alumno"<<endl;
		cout<<"\t\t\t\t3. Modificar Datos de Alumno"<<endl<<endl;
		cout<<"\t\t\t\tIngrese una opcion:  ";
		cin>>opc;
		
		while(opc<=0||opc>3)
		{
			cout<<"\n\t\t\t\tOpcion Invalida"<<endl;
			cout<<"\t\t\t\tIngrese una opcion:  ";
			cin>>opc;
		}
		
		switch (opc)
		{
			case 1:
				reAlumno();
				break;
			
			case 2:
				buAlumno();
				break;
		}
		
		cout<<"\n\t\t\t\tPresione '1' para volver al menu "<<endl;
		cout<<"\t\t\t\tPresione '2' para salir ";
		cout<<"\n\n\t\t\t\t";
		cin>>opcion;
	}
		
}

void reAlumno()
{
	system("cls");
	alumno a;
	ifstream archivos;
	ofstream archivo;
	char opcion='1';
	string carne1;
	
	
	cout<<endl<<endl<<endl;

	do
	{
		system("cls");
		int r1=0;
		archivos.open("Alumnos.txt", ios::in);
		archivo.open("Alumnos.txt",ios::app);
		
		cout<<"\t\t\t\tIngrese Carne del alumno:     ";
		cin>>a.carne;

		while(getline(archivos, carne1))
		{
			if(carne1.find(a.carne) !=string::npos)
			{
				cout<<"\n\t\t\t\tNumero de carne repetido"<<endl;
				r1=1;
			}	
			
		}
		archivos.close();	
	
		if(r1==0)
		{
			cout<<"\t\t\t\tIngrese Nombre del alumno:    ";
			cin>>a.nombre;
			cout<<"\t\t\t\tIngrese Correo del alumno:    ";
			cin>>a.correo;
			cout<<"\t\t\t\tIngrese Seccion del alumno:   ";
			cin>>a.seccion;
			cout<<"\t\t\t\tIngrese Ciclo Escolar:        ";
			cin>>a.cicloEscolar;
			cout<<"\t\t\t\tIngrese Estado del alumno:    ";
			cin>>a.estado;
			cout<<"\t\t\t\tIngrese Promedio del alumno:  ";
			cin>>a.promedio;
			
			
			archivo<<"Carne:         "<<a.carne<<endl;
			archivo<<"Nombre:        "<<a.nombre<<endl;
			archivo<<"Correo:        "<<a.correo<<endl;
			archivo<<"Seccion:       "<<a.seccion<<endl;
			archivo<<"Ciclo Escolar: "<<a.cicloEscolar<<endl;
			archivo<<"Estado:        "<<a.estado<<endl;
			archivo<<"Promedio:      "<<a.promedio<<endl<<endl;					
		}			
		
			
		archivo.close();		
		
		cout<<endl<<endl;						
		cout<<"\n\t\t\t\tIngrese 1 para registrar alumno"<<endl;
		cout<<"\t\t\t\tIngrese 2 para mas opciones";
		cout<<"n\n\\t\t\t\t";
		cin>>opcion;
		
	}while(opcion=='1');
	
		
}

void buAlumno()
{
	alumno a;
	ifstream lec;
	string noCarne, cicloEscolar, estado, promedio;
	int r=0;
	char opcion1='1';
	
	do 
	{
		system("cls");
		lec.open("Alumnos.txt", ios::in);
		
		cout<<endl<<endl<<endl;
		cout<<"\t\t\t\tDigite el numero de 'Carne' a buscar: ";
		cin>>noCarne;
		cout<<endl;
			
		while(getline(lec, a.carne))
		{
			if(a.carne.find(noCarne) !=string::npos)
			{
				cout<<"\t\t\t\t"<<a.carne<<endl;
				getline(lec, a.nombre);
				cout<<"\t\t\t\t"<<a.nombre<<endl;
				getline(lec, a.correo);
				cout<<"\t\t\t\t"<<a.correo<<endl;
				getline(lec, a.seccion);
				cout<<"\t\t\t\t"<<a.seccion<<endl;
				getline(lec, cicloEscolar);
				cout<<"\t\t\t\t"<<cicloEscolar<<endl;
				getline(lec, estado);
				cout<<"\t\t\t\t"<<estado<<endl;
				getline(lec, promedio);
				cout<<"\t\t\t\t"<<promedio<<endl;
				r=1;
			}
		}
		
		if (r==0)
		{
			cout<<noCarne<<"\t\t\t\tNumero de 'Carne' NO REGISTRADO"<<endl;
		}
		
		lec.close();
			
		cout<<"\n\t\t\t\tPresione '1' para buscar otro registro "<<endl;
		cout<<"\t\t\t\tPresione '2' para mas opciones ";
		cout<<"\n\n\t\t\t\t";
		cin>>opcion1;
		
	}while (opcion1=='1');
}








