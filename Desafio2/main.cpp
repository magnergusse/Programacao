#include <iostream>
#include <string>
#include<cmath>
using namespace std;
void Menu(){
    string Opcao1="1-Ler nova medida de um sensor";
    string opcao2="2-Imprimir valor das medias";
    string opcao3="3-Imprimir hora e temperatura de leitura mais elevada";
    string opcao4="4-Histograma de temperaturas";
    string opcao5="5-Guardar ultima medida";
    string opcao6="6-Imprimir Mmedidas guardadas em Memoria";
    string opcao0="0-Terminar O Programa\n";
cout<<Opcao1<<endl<<opcao2<<endl<<opcao3<<endl<<opcao4<<endl<<opcao5<<endl<<opcao6<<opcao0;
};
//Opcao 1
void opcao1(){
    int i=0;
    int temperatura, hora;
do{
cout<<"Temperatura:";
cin>>temperatura;}while(temperatura<-40 || temperatura>+40);//Inserir temperatura
double temperaturas[]{};
for(; i<temperaturas[i]; i++) {
do {
cout<<"Hora:";
cin >> hora; }while (hora < 0 || hora > 23);//Inserir hora
}
}
//Opcao2
double opcao2(){

    int nr_de_vezes=0; double count=0;
    double arr_temperraturas[]{};
    for (int i=0;i<50; i++){
        cin>>arr_temperraturas[i];
        if (arr_temperraturas[i]<-40 || arr_temperraturas[i]>+40) break;
        count+=arr_temperraturas[i];//somar as temperaturas inserdas
        nr_de_vezes+=1;//contar numero de elementos
    }
    double media = count/nr_de_vezes ;
    cout<<"Media dos Valores:";
    return media;
}
//Opcao3
void opcao3(){
double maiorvalor_temp = 0, maiorvalor_hora = 0;
double arr_temperraturas[]{}, arr_horas[]{};//Armazenar Horas e temperaturas
for (int i = 0; i < 100; i++) {
cout << "temperatura";
cin >> arr_temperraturas[i];//Inserir temperatura
if (arr_temperraturas[i] < -40 || arr_temperraturas[i] > +40) break;

cout << "hora";
cin >> arr_horas[i];//Inserir hora
if (arr_horas[i] < 0 || arr_horas[i] > 23) break;

if (arr_temperraturas[i] > arr_temperraturas[i - 1]) {
maiorvalor_temp = arr_temperraturas[i];
}
if (arr_horas[i] > arr_horas[i - 1]) {
maiorvalor_hora = arr_horas[i];
}
}
cout << "Maior hora:" << maiorvalor_hora << endl;
cout << "Maior temperatura:" << maiorvalor_temp;
}
int main() {
    int opcao;
    //a)
    cout<<"Nome: Magner Ndlhovu Macario Gusse\n"<<"Nmec: 110180\n";
    Menu();
    cout<<"escolha a opcao:";cin>>opcao;
    if(opcao==1){opcao1();Menu();cin>>opcao;}
    else if(opcao==2){ opcao2();Menu();cin>>opcao;}
    else if(opcao==3){opcao3();Menu();cin>>opcao;}
    else if(opcao==0){cout<<"fim";}




    return 0;
}