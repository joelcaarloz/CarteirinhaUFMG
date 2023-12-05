#include <iostream>
#include <string>
#include "../include/carteirinha.h"


using namespace std;


int main()
{
    char sistema;
    cout << "s para sistema de carteirinhas e c para catracas" << endl;
    cin >> sistema;
    SistemaCarteirinha users;
    if(sistema == 's')
    {
        string matricula;
        char oper;
        while(1)
        {
            cin >> oper;
            if(oper == 'n'){
                cout << "digite a matricula: " << endl; 
                cin >> matricula;
                users.newCarteirinha(matricula);
        }
    }

}
}