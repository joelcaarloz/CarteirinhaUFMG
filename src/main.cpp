#include <iostream>
#include <string>
#include "../include/carteirinha.h"
#include "../include/sistemacarteirinha.h"

struct interrupt{};

using namespace std;


int main()
{
    string matricula;//pode ser tanto a matricula quanto ID da carteirinha
    char opera;
    SistemaCarteirinha users;
    bool para = false;
    float dep = 0.0;
    while(!para)
    {
        try
        {
            cin >> matricula;//Digite o número da matricula ou aproxime a carteirinha
            cin >> opera;//Digite a operação que deseja realizar
            switch (opera)
            {
                case 'n':
                    users.newCarteirinha(matricula);
                    break;

                case 'a':
                    users.atualizaCarteirinha(matricula);
                    break;

                case 'i':
                    users.imprimeCarteirinha(matricula);
                    break;

                case 'd':
                    users.deleteCarteirinha(matricula);
                    break;

                case 'c':
                    users.catraca(matricula);
                    break;

                case 'r':
                    users.catracaRU(matricula);
                    break;

                case 's':
                    cin >> dep;//valor a ser depositado
                    users.deposito(matricula, dep);
                    dep = 0.0;
                    break;
        
                default:
                    interrupt stop;
                    throw stop;
            }
        }
        catch(interrupt e)
        {
            para = true;
        }

        catch(valorNeg e)
        {
            cout << "O valor " << e.valor << " é negativo, por isso não pode ser somado ao saldo da carteirinha: " << e.ID << endl;
        }
        catch(cartExistente e)
        {
            cout << "A carteirinha de ID: " << e.matricula << " já existe e está cadastrada no sistema" << endl;
        }
        catch(cartInexistente e)
        {
            cout << "A carteirinha de ID: " << e.matricula << " não existe e não está cadastrada no sistema" << endl;
        }
        catch(erroCadastro e)
        {
            cout << "Não foi possível efetuar o cadastro, por favor tente novamente" << endl;
        }
        catch(exceptionRecarga e)
        {
            cout << "Saldo insuficiente, tente recarregar antes de realizar essa operação"<< endl;
        }
    }
    
    cout << "Sistema encerrado" << endl;;

}