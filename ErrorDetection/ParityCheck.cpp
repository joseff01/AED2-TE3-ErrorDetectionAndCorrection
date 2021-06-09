#include <vector>
#include <iostream>
using namespace std;

void parityChecker(vector<int> lista) //EVEN PARITY
{
    int numberOfOnes=0;
    for (vector<int>::iterator i = lista.begin(); i != lista.end(); ++i)
        if(*i == 1){ numberOfOnes++;}

    if(numberOfOnes%2 == 0)
        cout << "no hay error"<<endl;
    else
    cout << "Hay un error con el numero de paridad"<<endl;
}

void parityGenerator(vector<int> lista) 
{
    int numberOfOnes = 0;
    for (vector<int>::iterator i = lista.begin(); i != lista.end(); ++i)
        if(*i == 1){ numberOfOnes++;}

    if(numberOfOnes%2 == 0)
    lista.push_back(0);
    else
    lista.push_back(1);

    parityChecker(lista);

}


int main()
{
    vector<int> lista{1,1};  
    parityGenerator(lista);

}


