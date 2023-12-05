#include "../include/carteirinha.h"
#include <string>

using namespace std;

Carteirinha::Carteirinha(){
    
}

Carteirinha::Carteirinha(string& id, string& cpf, string& identidade, string& nome, string& curso, int nivel, int mop, bool vinculo_mop){
   id_ = id;
   cpf_ = cpf;
   identidade_ =  identidade;
   nome_ = nome;
   curso_ = curso;
   saldo_ = 0.00;
   valida_ = true;
   nivel_ = nivel;
   mop_ = mop;
   vinculoMop_ = vinculo_mop;
}

string Carteirinha::getID() const {
    return id_;
}

string Carteirinha::getCPF() const {
    return cpf_; 
}

string Carteirinha::getIDENTIDADE() const { 
    return identidade_;
}

string Carteirinha::getNOME() const {
    return nome_;
}

string Carteirinha::getCURSO() const { 
    return curso_; 
}

float Carteirinha::getSALDO() const { 
    return saldo_; 
}

void Carteirinha::setSALDO(float recarga){
    if(recarga < 0)
    {
        exceptionRecarga e;
        throw e;
    }
    saldo_ += recarga;
    return;

}
bool Carteirinha::getValidade() const { 
    return valida_; 
}
int Carteirinha::getNIVEL() const{ 
    return nivel_; 
}

bool Carteirinha::getMOP() const { 
    return vinculoMop_; 
}

Carteirinha::~Carteirinha(){};

