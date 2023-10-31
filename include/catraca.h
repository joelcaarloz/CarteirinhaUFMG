#ifndef CATRACA_H_
#define CATRACA_H_


#include "carteirinha.h"
#include <iostream>

class Catraca{
    public:
    long int id;
    std::string comando;
    bool libera_trava;

    private:
    //construtor
    Catraca();

    //reseta comando e libera_trava
    void resetDados();
    
    //atualiza comando
    void setComando(std::string novo_comando);

    //atualiza libera_trava
    void libera_Trava(bool novo_libera_trava);

    //funcionamento catracas básicas
    bool catracasBasicas(Catraca& busca);

    //funcionamento catracas do RU
    bool catracasRu(Catraca& busca);

    //funcionamento catracas do RU
    bool catracasMorabus(Catraca& busca);

    //imprimi dados básicos
    void imprimirDadosBasicos();

    //reseta o numero de acesso ao RU
    void resetarAcessosRU(Carteirinha& resetar);

    //pagamento no ru
    void executarPagamento(Carteirinha& atualizar, float valor);

    //detrutor
    ~Catraca();
    
    
};




#endif