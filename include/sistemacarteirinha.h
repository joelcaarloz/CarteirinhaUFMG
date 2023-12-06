#ifndef SISTEMACARTEIRINHA_H_
#define SISTEMACARTEIRINHA_H_
#include "../include/carteirinha.h"

#include <string>
#include <map>

struct valorNeg{
    string ID;
    float valor;
};
struct cartExistente {
    string matricula;
};
struct cartInexistente {
    string matricula;
};
struct erroCadastro {
    string matricula;
};

using namespace std;
class SistemaCarteirinha {
private:
    map<string, Carteirinha> alunos; // Cada carteirinha é associada a matrícula, que é única

public:
    // Construtor, inicializa o sistema vazio
    SistemaCarteirinha();

    // Inicializa uma nova carteirinha
    // Pré-condição: a carteirinha não deve existir
    void newCarteirinha(string matricula);

    // Atualiza situação socioeconomica do aluno, pois só esses dados são mutáveis
    // Pré-condição: a carteirinha deve existir
    void atualizaCarteirinha(string matricula);

    // Busca por uma carteirinha específica
    // Pré-condição: a carteirinha deve existir
    void imprimeCarteirinha(string matricula);

    // Apaga carteirinha de um aluno
    // Pré-condição: a carteirinha deve existir
    void deleteCarteirinha(string matricula);

    //implementação do funcionamento das catracas 
    bool catraca(string ID);

    //catraca do ru
    bool catracaRU(string ID);

    //metodo para deposito
    //Pré-condição: deve ser um valor positivo
    void deposito(string ID, float dep);

    // Destrutor de todas as carteirinhas
    ~SistemaCarteirinha();

    // Outras funções conforme necessário...

};

#endif