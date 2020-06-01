#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>

using namespace std;

struct Registro02{
    string codigo;
    string nombre;
    string puesto;
    int departamento;
    float salario;
    Registro02* apuntador02;
};

struct Registro02* head02;

void agregarRegistro02(){
	Registro02:
		ofstream archivo;
		string nombreArchivo;
		fflush(stdin);
		system("CLS");
		cout<<"Archivo default: planilla.txt"<<endl;
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

		int registros02 = 0;

        cout<<"Ingrese cantidad de registros a guardar: "<<endl;
        cin>>registros02;

		if(registros02 < 1){
			cout<<"Debe ingresar una cantidad valida. Intente de nuevo."<<endl;
			system("Pause");
			goto Registro02;
		}

		head02 = NULL;
		int bandera = 0;
		string codigo02;
		string nombre02;
		string puesto02;
		int departamento02;
		float salario02;

		for(int i = 0; i < registros02; i ++){
            bandera = 0;
            system("cls");

            struct Registro02* temp02 = new Registro02();

            cout<<"Datos para el empleado: "<<i+1<<endl;

            cin.ignore();
            cout<<"Ingrese codigo del empleado: "<<endl;
            getline(cin,codigo02);

            cin.ignore();
            cout<<"Ingrese nombre del empleado: "<<endl;
            getline(cin,nombre02);

            cin.ignore();
            cout<<"Ingrese puesto del empleado: "<<endl;
            getline(cin,puesto02);

            cout<<endl;
            cout<<"Opcion   |   Departamento    "<<endl;
            cout<<" 1       |   Gerencia        "<<endl;
            cout<<" 2       |   Administracion  "<<endl;
            cout<<" 3       |   Produccion      "<<endl;
            cout<<endl;

            cout<<"Seleccione departamento al que pertenece el empleado: "<<endl;
            cin>>departamento02;

            if(departamento02 < 1 || departamento02 > 3){
                cout<<"Debe ingresar una opcion valida. Intente de nuevo."<<endl;
                i = i - 1;
                system("Pause");
                bandera = 1;
            }

            if(bandera == 0){
                cout<<"Ingrese salario del empleado: "<<endl;
                cin>>salario02;

                if(salario02 < 1){
                    cout<<"Debe ingresar una cantidad valida. Intente de nuevo."<<endl;
                    i = i - 1;
                    system("Pause");
                    bandera = 1;
                }

                if(bandera == 0){
                    codigo02 = regex_replace(codigo02, regex("\\s+"), "_");
                    codigo02 = regex_replace(codigo02, regex("\\W+"), "");

                    nombre02 = regex_replace(nombre02, regex("\\s+"), "_");
                    nombre02 = regex_replace(nombre02, regex("\\W+"), "");

                    puesto02 = regex_replace(puesto02, regex("\\s+"), "_");
                    puesto02 = regex_replace(puesto02, regex("\\W+"), "");

                    temp02->codigo = codigo02;
                    temp02->nombre = nombre02;
                    temp02->puesto = puesto02;
                    temp02->departamento = departamento02;
                    temp02->salario = salario02;
                    temp02->apuntador02 = NULL;
                    if(head02 != NULL)
                        temp02->apuntador02 = head02;
                    head02 = temp02;
                }
            }
		}

		archivo.open(nombreArchivo.c_str(),ios::trunc);
		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		system("CLS");

		struct Registro02* temp02 = head02;
        while(temp02 != NULL ){
            archivo<<temp02->codigo<<'\t'
            <<temp02->nombre<<'\t'
            <<temp02->puesto<<'\t'
            <<temp02->departamento<<'\t'
            <<temp02->salario<<endl;
            temp02 = temp02->apuntador02;
        }

		archivo.close();

		cout<<"Registros agregados exitosamente."<<endl;
};

void reporte02(){
	 fflush(stdin);
	 system("CLS");

	 string codigo02;
     string nombre02;
     string puesto02;
     int departamento02;
     float salario02;
     string mensaje;
     int cont = 0;
     float total;

     system("CLS");
     cout<<"*Trabajando con datos en memoria."<<endl;
	 cout<<"------------------------"<<endl;
	 cout<<"        Reporte         "<<endl;
	 cout<<"------------------------"<<endl;
	 struct Registro02* temp02 = head02;
     while(temp02 != NULL ){
         cont++;
         codigo02 = temp02->codigo;
         nombre02 = temp02->nombre;
         puesto02 = temp02->puesto;
         departamento02 = temp02->departamento;
         salario02 = temp02->salario;
         temp02 = temp02->apuntador02;

         total = total + salario02;

         codigo02 = regex_replace(codigo02, regex("_"), " ");
         nombre02 = regex_replace(nombre02, regex("_"), " ");
         puesto02 = regex_replace(puesto02, regex("_"), " ");

         if(departamento02 == 1){mensaje = "Gerencia";}
         if(departamento02 == 2){mensaje = "Administracion";}
         if(departamento02 == 3){mensaje = "Produccion";}

         cout<<cont<<" | Codigo: "<<codigo02<<" | Nombre: "<<nombre02<<" | Puesto: "<<puesto02<<" | Departamento: "<<mensaje<<" | Salario: Q"<<salario02<<" |"<<endl;
     }
     cout<<endl;
     cout<<"Total en planilla: Q"<<total<<endl;
};
