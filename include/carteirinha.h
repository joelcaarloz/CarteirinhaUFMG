#ifndef CARTEIRINHA_H_
#define CARTEIRINHA_H_

#include <string>
#include "Cart_Fumpista.h"

class Carteirinha{
    private:
    //usando long int, pois em sistemas de 32 bits int representa até 9 casas
    long int id; //ID da carteirinha
    long int matricula; 
    long int cpf;
    long int identidade;
    std::string nome;
    std::string curso;
    float saldo; //saldo na carteirinha
    bool valida; //indica se a carteirinha está válida
    struct Acessos{
        bool cafe;
        bool almoco;
        bool janta;
    };
    Acessos acessos_ru;

    public:
    //construtor
    Carteirinha();

    //construtor
    Carteirinha(long int matricula);

    //atualiza algum dado da carteirinha
    void atualizaCarteirinha();

    //verifica validade da carteirinha
    bool validadeCarteirinha(bool validar);

    //imprimi os dados de carteirinha 
    void imprimirDados();

    //atualiza o valor de saldo
    void setSaldo(float add);

    //cadastra o aluno como fumpista
    void tornarFumpista(const Cart_Fumpista& atualizar, Carteirinha& apagar);

    //imprimi o saldo disponivel
    void imprimirSaldo();

    //bloqueia a carteirinha --> nesse metódo a carteirinha não pode mais ser desbloqueada e a id é apagada
    void bloquearCarteirinha();

    //exclui a carteirinha 
    void deletarCarteirinha();

    //retorna os dados da carteirinha solicitada
    Carteirinha getCarteirinha(long int procura);

    //destrutor
    ~Carteirinha();
};

#endif