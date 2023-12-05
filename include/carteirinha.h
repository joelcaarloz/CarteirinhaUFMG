#ifndef CARTEIRINHA_H_
#define CARTEIRINHA_H_

#include <string>
#include <map>


using namespace std;
//MOP = Moradias Ouro Preto
//tipo para tratamento de excessões na recarga do saldo
struct exceptionRecarga{
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


class Carteirinha{
    private:
    //usando long int, pois em sistemas de 32 bits int representa até 9 casas
    //dados pessoais do aluno
    string id_; //ID da carteirinha
    string cpf_;
    string identidade_;
    string nome_;
    string curso_;
    float saldo_; //saldo na carteirinha
    bool valida_; //indica se a carteirinha está válida
    //dados adicionais se o aluno for fumpista
    int nivel_; //representa o nivel socioeconomico do aluno assistido
    int mop_; // representa a mop em que ele mora, se não morador mop = 0
    bool vinculoMop_;// se mopeano(morador), representa se o vinculo com a mop está ativo ou não

    public:

    //construtor, inicializa a carteirinha vazia
    Carteirinha();

    //construtor, inicializa todos os dados da carteirinha
    Carteirinha(string& id, string& cpf, string& identidade, string& nome, string& curso, int nivel, int mop, bool vinculo_mop);

    //atualiza situação socioeconomica do aluno
    void atualizar(int nivel, int mop, bool vinculo);

    //retorna a id da carteirinha
    string getID() const;

    //retorna o cpf vinculado a carteirinha
    string getCPF() const;

    //retorna a identidade vinculada a carteirinha 
    string getIDENTIDADE() const;

    //retorna o nome do aluno vinculado a carteirinha
    string getNOME() const;

    //retorna o curso do aluno vinculado a carteirinha
    string getCURSO() const;

    //retorna o saldo presente na carteirinha
    float getSALDO() const;

    //recarrega o valor da carteirinha
    //Pré-condição: o valor de recarga não pode ser negativo
    void setSALDO(float recarga);

    //retorna se a carteirinha é valida
    bool getValidade() const;

    //retorna nível socioeconomico do aluno
    int getNIVEL() const;

    //retorna situação com a mop
    bool getMOP() const;

    //destrutor
    ~Carteirinha();

};

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
    Carteirinha* buscaCarteirinha(string matricula);

    // Apaga carteirinha de um aluno
    // Pré-condição: a carteirinha deve existir
    void deleteCadastro(string matricula);

    // Destrutor de todas as carteirinhas
    ~SistemaCarteirinha();

    // Outras funções conforme necessário...

};

#endif