#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>

using namespace std;

struct Registro03{
    string codigo;
    string nombre;
    int horas;
    int departamento;
    int minutos;
    Registro03* apuntador03;
};

struct Registro03* head03;

void agregarRegistro03(){
	Registro03:
		ofstream archivo;
		string nombreArchivo;
		fflush(stdin);
		system("CLS");
		cout<<"Archivo default: horas.txt"<<endl;
		cout<<"Indique nombre de archivo: ";
		getline(cin,nombreArchivo);
		archivo.open(nombreArchivo.c_str(),ios::app);

		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		archivo.close();

		fflush(stdin);
		system("CLS");

		int registros03 = 0;

        cout<<"Ingrese cantidad de registros a guardar: "<<endl;
        cin>>registros03;

		if(registros03 < 1){
			cout<<"Debe ingresar una cantidad valida. Intente de nuevo."<<endl;
			system("Pause");
			goto Registro03;
		}

		//Registro03 lista[registros03];
		head03 = NULL;
		int bandera = 0;
		string codigo03;
		string nombre03;
		int horas03;
		int departamento03;
		int minutos03;

		for(int i = 0; i < registros03; i ++){
            bandera = 0;
            system("cls");

            struct Registro03* temp03 = new Registro03();

            cout<<"Datos para el empleado: "<<i+1<<endl;

            cin.ignore();
            cout<<"Ingrese codigo del empleado: "<<endl;
            getline(cin,codigo03);

            cin.ignore();
            cout<<"Ingrese nombre del empleado: "<<endl;
            getline(cin,nombre03);

            cout<<endl;
            cout<<"Ingrese horas semanales trabajadas por el empleado: "<<endl;
            cin>>horas03;

            if(horas03 < 1 ){
                cout<<"Debe ingresar una cantidad valida. Intente de nuevo."<<endl;
                i = i - 1;
                system("Pause");
                bandera = 1;
            }

            if(bandera == 0){
                cout<<endl;
                cout<<"Opcion   |   Departamento    "<<endl;
                cout<<" 1       |   Contabilidad        "<<endl;
                cout<<" 2       |   Sistemas  "<<endl;
                cout<<" 3       |   Logistica      "<<endl;
                cout<<endl;

                cout<<"Seleccione departamento al que pertenece el empleado: "<<endl;
                cin>>departamento03;

                if(departamento03 < 1 || departamento03 > 3){
                    cout<<"Debe ingresar una opcion valida. Intente de nuevo."<<endl;
                    i = i - 1;
                    system("Pause");
                    bandera = 1;
                }

                if(bandera == 0){
                    cout<<"Ingrese minutos de llegada tarde del empleado: "<<endl;
                    cin>>minutos03;

                    if(minutos03 < 0 ){
                        cout<<"Debe ingresar una cantidad valida. Intente de nuevo."<<endl;
                        i = i - 1;
                        system("Pause");
                        bandera = 1;
                    }

                    if(bandera == 0){
                        codigo03 = regex_replace(codigo03, regex("\\s+"), "_");
                        codigo03 = regex_replace(codigo03, regex("\\W+"), "");

                        nombre03 = regex_replace(nombre03, regex("\\s+"), "_");
                        nombre03 = regex_replace(nombre03, regex("\\W+"), "");

                        /*lista[i].codigo = codigo03;
                        lista[i].nombre = nombre03;
                        lista[i].horas = horas03;
                        lista[i].departamento = departamento03;
                        lista[i].minutos = minutos03;*/
                        temp03->codigo = codigo03;
                        temp03->nombre = nombre03;
                        temp03->horas = horas03;
                        temp03->departamento = departamento03;
                        temp03->minutos = minutos03;
                        temp03->apuntador03 = NULL;
                        if(head03 != NULL)
                            temp03->apuntador03 = head03;
                        head03 = temp03;
                    }
                }
            }
		}

		archivo.open(nombreArchivo.c_str(),ios::app);
		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		system("CLS");

		/*for(int i = 0; i < registros03; i ++){
            archivo<<lista[i].codigo<<'\t'
            <<lista[i].nombre<<'\t'
            <<lista[i].horas<<'\t'
            <<lista[i].departamento<<'\t'
            <<lista[i].minutos<<endl;
		}*/
		struct Registro03* temp03 = head03;
        while(temp03 != NULL ){
            archivo<<temp03->codigo<<'\t'
            <<temp03->nombre<<'\t'
            <<temp03->horas<<'\t'
            <<temp03->departamento<<'\t'
            <<temp03->minutos<<endl;
            temp03 = temp03->apuntador03;
        }

		archivo.close();

		cout<<"Registros agregados exitosamente."<<endl;
};
