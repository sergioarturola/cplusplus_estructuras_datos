/*
almacenar en una pila 5 elementos enteros y realizar la suma como se indica
ej. si los elementos dados son 10 5 3 12 4
la suma debe de ser
3+0 = 3
5+12 = 17
10+4 = 14
almacenar el resultado en otra pila y mostrar los datos de manera ascendente
3 14 17
*/

#include<iostream>
#include<stack>
using namespace std;

//funcion para mostrar los datos de la pila de manera ascendente
void sortPila(stack<int> pila);

int main(){

    stack<int> numeros;
    stack<int> result;
    stack<int> reversa;


    const int size_stack = 5;
    int primero, utlimo, suma;
    int n;

    for(int i = 0; i<size_stack; i++){
        cout<<"Ingresa numero["<<i<<"]: "; cin>>n;
        numeros.push(n);
    }

    //realizando copia de numeros para invertir pila
    stack<int> copia(numeros);

    while(!numeros.empty()){
        reversa.push(numeros.top());
        numeros.pop();
    }


    cout<<"-------- Operaciones ---------"<<endl;
    while(!reversa.empty()){

            if(reversa.size()==2){//despues de llegar a la mitad se rompe ya que no tiene sentido seguir iterando
              break;
            }
            else if(reversa.size() == 3){//si llega a la mitad no se suma nada

                cout<<reversa.top()<<" + 0"<<endl;
                result.push(reversa.top());
                reversa.pop();
                copia.pop();
            }
            else{//operaciones de extremos

                suma = reversa.top() + copia.top();
                result.push(suma);
                cout<<reversa.top()<<" + "<<copia.top()<<endl;
                reversa.pop();
                copia.pop();
         }
    }

    //llamando a la funcion
    sortPila(result);

    return 0;
}

void sortPila(stack<int> pila){
    int temp;
    const int sizeStack = pila.size();
    int pilaArray[sizeStack], i = 0;

        while(!pila.empty()){
        pilaArray[i] = pila.top();
        pila.pop();
        i++;
    }

    //recorriendo el array para acomodar pila por metodo burbuja
    for (int i = 0; i < sizeStack - 1; i++) {
        for (int j = i + 1; j < sizeStack; j++) {
            if (pilaArray[i] > pilaArray[j]) {
                temp = pilaArray[i];
                    pilaArray[i] = pilaArray[j];
                    pilaArray[j] = temp;
                  }
                }
            }


    //mosttando el resultado
    cout<<"---Resultado ordenado--"<<endl;
    for( int k = 0; k< sizeStack; k++){
        cout<<pilaArray[k]<<" ";
    }

}
