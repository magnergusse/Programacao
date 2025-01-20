//
// Created by MAGNER GUSSE on 1/24/2022.
//
#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include <vector>
#include<cmath>
using namespace std;

struct PontoAcesso{
int edificio,piso, sala;

};
struct IDTime{
PontoAcesso access;
    int IDcard, hour, minute, second;
    int day, month, year;
};

int menu();
PontoAcesso lePontoAcesso();
void leRegistoAcesso(const IDTime&);
void listagem(vector<IDTime> &armazenar);
void guardarnoficheiro(vector<IDTime> &guardar);
void imprimirporedificio(vector<IDTime>&guardar);
void imprimirpordata(vector<IDTime>&guardar);
vector<IDTime>guardar;


int main(){
    cout<<"Magner Gusse, 110180"<<endl;
ofstream ficheiro;
IDTime Person;
            int opcao;//opcao a escolher no menu

            do {
        opcao=menu();

        switch (opcao) {
            case(1): {
                leRegistoAcesso(Person);break;
                };
            case(2):{
                listagem(guardar);break;

                case(3):{
                    imprimirporedificio(guardar);break;
                }
                case (4):{
                    imprimirpordata(guardar);break;
                }

                case(5):{
                    guardarnoficheiro(guardar);break;
                }
            }

        }
                if (opcao==0){
                    cout<<"Bye bye :(";}
    }while(opcao!=0);




return 0;
}

int menu(){int opcao;
    cout<< "Bem vindo!\n";
    cout<<"1-Novo Acesso\n";
    cout<<"2-Listagem de acessos\n";
    cout<<"3-listagem de Acessos por edificio \n";
    cout<<"4-Listagem de acessos por data/hora\n";
    cout<<"5-Guardar registos\n";
    cout<<"0-Terminar O Programa\n";
    cout<<"Choice->";cin >>opcao;

    return opcao;
}


unsigned int LeIDCartao(){//ler Cartao ID
    int IDCard;//numero do cartao
    do {
        cout << "Inserir ID do cartao: ";
        cin >>IDCard;//iserir numero do cartao

    }while(IDCard>=255);//repetir sempre que nao cumprir a condicao

    return IDCard;
    }

PontoAcesso lePontoAcesso(){
    PontoAcesso pontodecesso;
    do {
        cout << "Edificio: ";
        cin >> pontodecesso.edificio;
    } while (pontodecesso.edificio>24 );//repetir ate que Sala seja menor que 24
    do{
        cout << "Piso: ";
        cin >> pontodecesso.piso;
    }while(pontodecesso.piso>4);//repetir ate que piso seja menor que 4

        cout << "Sala: ";
        cin >> pontodecesso.sala;//sala pode ser de qualquer valor



return pontodecesso;
}

void leRegistoAcesso(const IDTime&){IDTime data;

    cout<<"Acess point:\n";
    do {
        cout << "Edificio: ";
        cin >> data.access.edificio;
    } while (data.access.edificio>24 );//repetir ate que Sala seja menor que 24
    do{
        cout << "Piso: ";
        cin >> data.access.piso;
    }while(data.access.piso>4);//repetir ate que piso seja menor que 4

    cout << "Sala: ";
    cin >> data.access.sala;//sala pode ser de qualquer valor

do {
    cout << "ID:";
    cin >> data.IDcard;
    if(data.IDcard>255){//ID deve ser menor que 255
        cout<<"Invalid number\n";}
}while(data.IDcard>255);
do {
    cout << "Date: \n";
    cout<<"Day:";cin >> data.day;
    cout<<"Month:";cin>> data.month;
    cout<<"Year:";cin>> data.year;
    if (data.day>31 || data.month>12 || data.year<2000){//dias devem ser menore que 31, meses menores que 12 e anos maiores que 2000
        cout<<"Invalid date, try again\n";}
} while (data.day>31 || data.month>12 || data.year<2000);

do {
    cout << "InsertTime: \n";
    cout<<"hour:";cin >> data.hour;
    cout<<"Minutes:";cin>> data.minute;
    cout<<"Seconds:";cin>> data.second;

    if (data.hour>=24 || data.minute>=60 || data.second>=60){
        cout<<"Invalid Time, try again \n";
    }
    }while(data.hour>=24 || data.minute>=60 || data.second>=60);

guardar.push_back(data);


}

void listagem(vector<IDTime> &armazenar){
    cout<<"Ponto de Acesso."<<"ID Cartao,"<<"Data/"<<"Hora"<<endl;
    for(IDTime c: armazenar){
        cout<<setfill('0')<<setw(2)<<fixed<<c.access.edificio<<'.';//imprimir edificio
        cout<<setfill('0')<<setw(2)<<fixed<<c.access.piso<<'.';//piso
        cout<<setfill('0')<<setw(3)<<fixed<<c.access.sala<<'.';//sala

        cout<<c.IDcard<<',';//Imprimir ID card sem qualquer preenchimento antes


        cout<<setfill('0')<<setw(2)<<fixed<<c.day<<'/';//imprimir dia
        cout<<setfill('0')<<setw(2)<<fixed<<c.month<<'/';//mes
        cout<<setfill('0')<<setw(4)<<fixed<<c.year<<'/';//ano

        cout<<setfill('0')<<setw(2)<<fixed<<c.hour<<':';//hora
        cout<<setfill('0')<<setw(2)<<fixed<<c.minute<<':';//minuto
        cout<<setfill('0')<<setw(2)<<fixed<<c.second<<'.';//segundo
    cout<<endl;//terminar a linha par cada vez que imprime os dados
    }


}

void guardarnoficheiro(vector<IDTime> &guardar){

    ofstream ficheiro;
    string filename;//nome doficheiro a guardar

    do{
        cout<<"create/ open a file\".txt\" \n";
        cout<<"filename: ";cin>>filename;//inserir nome do ficheiro
        ficheiro.open(filename);//abrir oficheiro

        if(ficheiro.is_open()){
            cout<< "file created\n";}

        else if(!ficheiro.is_open()){//se falhar a abertura ou criacao
            cout<<"Try again";
        }
    }while(!ficheiro.is_open());//enquanto o ficheiro nao abrir

    ficheiro<<"Ponto de Acesso,  "<<"ID Cartao,  "<<"Data,  "<<"Hora"<<endl;
    for(IDTime c: guardar){
        ficheiro<<setfill('0')<<setw(2)<<fixed<<c.access.edificio<<'.';//imprimir edificio
        ficheiro<<setfill('0')<<setw(2)<<fixed<<c.access.piso<<'.';//piso
        ficheiro<<setfill('0')<<setw(3)<<fixed<<c.access.sala<<'.';//sala

        ficheiro<<c.IDcard<<',';//Imprimir ID card sem qualquer preenchimento antes


        ficheiro<<setfill('0')<<setw(2)<<fixed<<c.day<<'/';//imprimir dia
        ficheiro<<setfill('0')<<setw(2)<<fixed<<c.month<<'/';//mes
        ficheiro<<setfill('0')<<setw(4)<<fixed<<c.year<<'/';//ano

        ficheiro<<setfill('0')<<setw(2)<<fixed<<c.hour<<':';//hora
        ficheiro<<setfill('0')<<setw(2)<<fixed<<c.minute<<':';//minuto
        ficheiro<<setfill('0')<<setw(2)<<fixed<<c.second<<'.';//segundo
        ficheiro<<endl;//terminar a linha par cada vez que imprime os dados


    }

}

void imprimirporedificio(vector<IDTime>&guardar){PontoAcesso ver_edificio;
    ver_edificio=lePontoAcesso();//ver apenas o ponto de acesso e guardar na outra variavel

    for(IDTime c: guardar){//iterar o vetor inteiro
            if(c.access.edificio==ver_edificio.edificio){//se o edificio coincidir com o edificio do input imprimir
                                                            //se coincidir imprimir
                cout<<setfill('0')<<setw(2)<<fixed<<c.access.edificio<<'.';//imprimir edificio
                cout<<setfill('0')<<setw(2)<<fixed<<c.access.piso<<'.';//piso
                cout<<setfill('0')<<setw(3)<<fixed<<c.access.sala<<'.';//sala

                cout<<c.IDcard<<',';//Imprimir ID card sem qualquer preenchimento antes

                cout<<setfill('0')<<setw(2)<<fixed<<c.day<<'/';//imprimir dia
                cout<<setfill('0')<<setw(2)<<fixed<<c.month<<'/';//mes
                cout<<setfill('0')<<setw(4)<<fixed<<c.year<<'/';//ano

                cout<<setfill('0')<<setw(2)<<fixed<<c.hour<<':';//hora
                cout<<setfill('0')<<setw(2)<<fixed<<c.minute<<':';//minuto
                cout<<setfill('0')<<setw(2)<<fixed<<c.second<<'.';//segundo
                cout<<endl;//terminar a linha par cada vez que imprime os dados

            }
    }

}

void imprimirpordata(vector<IDTime>&guardar){
    int day, month, year;
    do {
        cout << "Date: \n";
        cout<<"Day:";cin >> day;
        cout<<"Month:";cin>>month;
        cout<<"Year:";cin>> year;
        if (day>31 ||month>12 || year<2000){//dias devem ser menore que 31, meses menores que 12 e anos maiores que 2000
            cout<<"Invalid date, try again\n";}
    } while (day>31 || month>12 ||year<2000);
    for(IDTime c: guardar){
        if(c.year>year){//se o ano inserido for menor que o ano em 'c'

            cout<<setfill('0')<<setw(2)<<fixed<<c.access.edificio<<'.'<<setfill('0')<<setw(2)<<fixed<<c.access.piso<<'.';
            cout<<setfill('0')<<setw(3)<<fixed<<c.access.sala<<'.';//sala

            cout<<c.IDcard<<',';//Imprimir ID card sem qualquer preenchimento antes
            //imprimir data
            cout<<setfill('0')<<setw(2)<<fixed<<c.day<<'/'<<setfill('0')<<setw(2)<<fixed<<c.month<<'/';
            cout<<setfill('0')<<setw(4)<<fixed<<c.year<<'/';//ano
            //imprimir tempo
            cout<<setfill('0')<<setw(2)<<fixed<<c.hour<<':';//hora
            cout<<setfill('0')<<setw(2)<<fixed<<c.minute<<':';//minuto
            cout<<setfill('0')<<setw(2)<<fixed<<c.second<<'.';//segundo
            cout<<endl;//terminar a linha par cada vez que imprime os dados

        }

        else if(c.year==year){//se o ano for igual verificar e imprimir por meses
            if (c.month>month){
                cout<<setfill('0')<<setw(2)<<fixed<<c.access.edificio<<'.'<<setfill('0')<<setw(2)<<fixed<<c.access.piso<<'.';
                cout<<setfill('0')<<setw(3)<<fixed<<c.access.sala<<'.';//sala

                cout<<c.IDcard<<',';//Imprimir ID card sem qualquer preenchimento antes
                //imprimir data
                cout<<setfill('0')<<setw(2)<<fixed<<c.day<<'/'<<setfill('0')<<setw(2)<<fixed<<c.month<<'/';
                cout<<setfill('0')<<setw(4)<<fixed<<c.year<<'/';//ano
                //imprimir tempo
                cout<<setfill('0')<<setw(2)<<fixed<<c.hour<<':';//hora
                cout<<setfill('0')<<setw(2)<<fixed<<c.minute<<':';//minuto
                cout<<setfill('0')<<setw(2)<<fixed<<c.second<<'.';//segundo
                cout<<endl;//terminar a linha par cada vez que imprime os dados



            }
            else if(c.month==month){//se meses coincidem verificar dia
                if (c.day>day){
                    cout<<setfill('0')<<setw(2)<<fixed<<c.access.edificio<<'.'<<setfill('0')<<setw(2)<<fixed<<c.access.piso<<'.';
                    cout<<setfill('0')<<setw(3)<<fixed<<c.access.sala<<'.';//sala

                    cout<<c.IDcard<<',';//Imprimir ID card sem qualquer preenchimento antes
                    //imprimir data
                    cout<<setfill('0')<<setw(2)<<fixed<<c.day<<'/'<<setfill('0')<<setw(2)<<fixed<<c.month<<'/';
                    cout<<setfill('0')<<setw(4)<<fixed<<c.year<<'/';//ano
                    //imprimir tempo
                    cout<<setfill('0')<<setw(2)<<fixed<<c.hour<<':';//hora
                    cout<<setfill('0')<<setw(2)<<fixed<<c.minute<<':';//minuto
                    cout<<setfill('0')<<setw(2)<<fixed<<c.second<<'.';//segundo
                    cout<<endl;//terminar a linha par cada vez que imprime os dados
                }

            }

        }

        else{cout<<"No Date inserted after that";}

    }




}