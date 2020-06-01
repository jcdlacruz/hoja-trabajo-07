#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>
#include <ctime>

using namespace std;

struct Registro01{
    int dia;
    int transporte;
    int empresa;
    int hotel;
    int duracion;
    Registro01* apuntador;
};

struct Registro01* head;

void agregarRegistro01(){
	Registro01:
		ofstream archivo;
		string nombreArchivo;
		fflush(stdin);
		system("CLS");
		cout<<"Archivo default: viajes.txt"<<endl;
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

		int registros01 = 0;

        cout<<"Ingrese cantidad de registros a guardar: "<<endl;
        cin>>registros01;

		if(registros01 < 1){
			cout<<"Debe ingresar una cantidad valida. Intente de nuevo."<<endl;
			system("Pause");
			goto Registro01;
		}

		head = NULL;
		int bandera = 0;
		int dia01;
		int transporte01;
		int empresa01;
		int hotel01;
		int duracion01;
		float cambio = 7.80;

        cout<<"Tipo de cambio por $1: "<<cambio<<endl;
		for(int i = 0; i < registros01; i ++){
            bandera = 0;
            system("cls");

            struct Registro01* temp = new Registro01();

            cout<<"Datos para el viajero: "<<i+1<<endl;

            cin.ignore();
            cout<<"Ingrese dia de viaje: "<<endl;
            cin>>dia01;

            if(dia01 < 1 || dia01 > 31){
                cout<<"Debe ingresar una cantidad valida. Intente de nuevo."<<endl;
                i = i - 1;
                system("Pause");
                bandera = 1;
            }

            if (bandera == 0){
                cout<<endl;
                cout<<"                                      |                  Tipo              |"<<endl;
                cout<<"Opcion   |   Empresa de transporte    |   Servicio Normal |   Servicio VIP |"<<endl;
                cout<<" 1       |   Empresa A                |   $150.00         |   $230.00      |"<<endl;
                cout<<" 2       |   Empresa B                |   $200.00         |   $300.00      |"<<endl;
                cout<<" 3       |   Empresa C                |   $100.00         |   N/A          |"<<endl;
                cout<<endl;

                cout<<"Seleccione empresa a cargo del viaje: "<<endl;
                cin>>empresa01;

                if(empresa01 < 1 || empresa01 > 3){
                    cout<<"Debe ingresar una opcion valida. Intente de nuevo."<<endl;
                    i = i - 1;
                    system("Pause");
                    bandera = 1;
                }

                if(bandera == 0){
                    cout<<endl;
                    cout<<"   Servicio Normal |   Servicio VIP |"<<endl;
                    if(empresa01 == 1){cout<<"   $150.00         |   $230.00      |"<<endl;}
                    if(empresa01 == 2){cout<<"   $200.00         |   $300.00      |"<<endl;}
                    if(empresa01 == 3){cout<<"   $100.00         |   N/A          |"<<endl;}
                    cout<<endl;

                    cout<<"Seleccione tipo de servicio del transporte (1 - Normal / 2 - VIP): "<<endl;
                    cin>>transporte01;

                    if(transporte01 < 1 || transporte01 > 2){
                        cout<<"Debe ingresar una opcion valida. Intente de nuevo."<<endl;
                        i = i - 1;
                        system("Pause");
                        bandera = 1;
                    }

                    if(empresa01 == 3 && transporte01 == 2){
                        cout<<"Servicio no valido. Intente de nuevo."<<endl;
                        i = i - 1;
                        system("Pause");
                        bandera = 1;
                    }

                    if(bandera == 0){
                        cout<<endl;
                        cout<<"Opcion   |   Hotel    |   Precio x noche "<<endl;
                        cout<<" 1       |   Hotel A  |   $20.00         "<<endl;
                        cout<<" 2       |   Hotel B  |   $30.00         "<<endl;
                        cout<<" 3       |   Hotel C  |   $30.00         "<<endl;
                        cout<<endl;

                        cout<<"Seleccione hotel: "<<endl;
                        cin>>hotel01;

                        if(hotel01 < 1 || hotel01 > 3){
                            cout<<"Debe ingresar una opcion valida. Intente de nuevo."<<endl;
                            i = i - 1;
                            system("Pause");
                            bandera = 1;
                        }

                        if(bandera == 0){
                            cout<<endl;
                            cout<<"Ingrese cantidad de dias de duracion del viaje: "<<endl;
                            cin>>duracion01;

                            if(duracion01 < 3){
                                cout<<"Debe ingresar una cantidad valida, duracion minima 3 dias. Intente de nuevo."<<endl;
                                i = i - 1;
                                system("Pause");
                                bandera = 1;
                            }

                            if(bandera == 0){
                                temp->dia = dia01;
                                temp->transporte = transporte01;
                                temp->empresa = empresa01;
                                temp->hotel = hotel01;
                                temp->duracion = duracion01;
                                temp->apuntador = NULL;
                                if(head != NULL)
                                    temp->apuntador = head;
                                head = temp;
                            }
                        }
                    }
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

        struct Registro01* temp = head;
        while(temp != NULL ){
            archivo<<temp->dia<<'\t'
            <<temp->transporte<<'\t'
            <<temp->empresa<<'\t'
            <<temp->hotel<<'\t'
            <<temp->duracion<<endl;
            temp = temp->apuntador;
        }

        archivo.close();

        cout<<"Registros agregados exitosamente."<<endl;
};

void reporte01(){
	 fflush(stdin);
	 system("CLS");

	 int dia01 = 0;
     int transporte01 = 0;
     int empresa01 = 0;
     int hotel01 = 0;
     int duracion01 = 0;
     float cambio = 7.80;

     int sumHotel = 0;
     int sumEmpresa = 0;
     int cont = 0;
     float porcentaje;

     int sumATipoN = 0;
     int sumBTipoN = 0;
     int sumCTipoN = 0;

     int sumATipoV = 0;
     int sumBTipoV = 0;
     int sumCTipoV = 0;

     int sumHotelA = 0;
     int sumHotelB = 0;
     int sumHotelC = 0;
     float totalHotel;
     string mensaje;

	 struct Registro01* temp = head;
     while(temp != NULL ){
         cont++;
         dia01 = temp->dia;
         transporte01 = temp->transporte;
         empresa01 = temp->empresa;
         hotel01 = temp->hotel;
         duracion01 = temp->duracion;
         temp = temp->apuntador;

         if(hotel01 == 2 || hotel01 == 3){sumHotel++;}
         if(empresa01 == 1){sumEmpresa++;}

         if(empresa01 == 1 && transporte01 == 1){sumATipoN++;}
         if(empresa01 == 1 && transporte01 == 2){sumATipoV++;}
         if(empresa01 == 2 && transporte01 == 1){sumBTipoN++;}
         if(empresa01 == 2 && transporte01 == 2){sumBTipoV++;}
         if(empresa01 == 3 && transporte01 == 1){sumCTipoN++;}

         if(hotel01 == 1){sumHotelA++;}
         if(hotel01 == 2){sumHotelB++;}
         if(hotel01 == 3){sumHotelC++;}
     }

     porcentaje = ((float)sumEmpresa/(float)cont)*100;

     totalHotel = ((float)sumHotelA*20)*cambio;
     mensaje = "Hotel A";

     if((((float)sumHotelB*30)*cambio) > totalHotel){
        totalHotel = ((float)sumHotelB*30)*cambio;
        mensaje = "Hotel B";
     }

     if((((float)sumHotelC*30)*cambio) > totalHotel){
        totalHotel = ((float)sumHotelC*30)*cambio;
        mensaje = "Hotel C";
     }

	 system("CLS");
	 cout<<"*Trabajando con datos en memoria."<<endl;
	 cout<<"------------------------"<<endl;
	 cout<<"        Reporte         "<<endl;
	 cout<<"------------------------"<<endl;
	 cout<<" Total de pasajeros: "<<cont<<endl;
	 cout<<" Tipo de cambio: "<<cambio<<endl;
     cout<<"------------------------"<<endl;
     cout<<"- Cuantos viajeros van a un hotel de $30.00: "<<sumHotel<<endl;
	 cout<<"- Del total de viajeros, cual fue el porcentaje de viajeros que eligieron viajar en Empresa A: "<<porcentaje<<"%"<<endl;
	 cout<<"- Cual sera el ingreso total de dinero en quetzales que recauda cada empresa de transporte "<<endl;
     cout<<"   separado por tipo de servicio: "<<endl;
     cout<<"-----------------------------------------------------------------------"<<endl;
     cout<<"                             |          Total recaudado en Q      |"<<endl;
     cout<<"|   Empresa de transporte    |   Servicio Normal |   Servicio VIP |"<<endl;
     cout<<"|   Empresa A                |   Q"<<(((float)sumATipoN*150)*cambio)<<"         |   Q"<<(((float)sumATipoV*230)*cambio)<<"      |"<<endl;
     cout<<"|   Empresa B                |   Q"<<(((float)sumBTipoN*200)*cambio)<<"         |   Q"<<(((float)sumBTipoV*300)*cambio)<<"      |"<<endl;
     cout<<"|   Empresa C                |   Q"<<(((float)sumCTipoN*100)*cambio)<<"         |   N/A      |"<<endl;
     cout<<endl;
     cout<<"- Cual fue el hotel que recaudo mas ingresos en Quetzales y a cuanto asciende el monto:"<<endl;
     cout<<" --"<<mensaje<<", total recaudado : Q"<<totalHotel<<endl;
};
