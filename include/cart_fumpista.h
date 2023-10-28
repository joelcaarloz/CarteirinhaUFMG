#ifndef CART_FUMPISTA_H_
#define CART_FUMPISTA_H_
#include "Carteirinha.h"
//MOP = Moradias Ouro Preto

class Cart_Fumpista : public Carteirinha{
    public:
    int nivel; //representa o nivel socioeconomico do aluno assistido
    int mop; // representa a mop em que ele mora, se não morador mop = 0
    bool vinculo_mop;// representa se o vinculo com a mop está ativo ou não, se morador

    private:
    //construtores
    Cart_Fumpista();
    Cart_Fumpista(long int matricula);

    //atualizar dados
    void setNivel();
    void setMop();
    void setVinculo_mop();

    //imprimir dados do fumpista
    void imprimirFumpista();

    //desligamento do aluno como fumpista
    void deletarFumpista();

    //retorna os dados da carteirinha de fumpista solicitada
    Carteirinha getCart_Fumpista(long int procura);

    //destrutor
    ~Cart_Fumpista();




};
#endif