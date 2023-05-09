/*
Usando una pila, invertir el contenido de una cadena ingresada por teclado
*/

#include<stack>
#include<iostream>
#include<string>

using namespace std;

int main(){


 stack<string>palabras;
 string cadena, letra;

 //pedimos la cadena

 cout<<"Escribe una cadena: ";
 getline(cin, cadena);

 //con un ciclo for llenamos la pila con la cadena

 for(int i = 0; i<cadena.size(); i++){

    letra = cadena.at(i);
    palabras.push(letra);
 }

 //imprimimos la pila

 while(!palabras.empty()){

    cout<<palabras.top();
    palabras.pop();
 }

   return 0;
 }
