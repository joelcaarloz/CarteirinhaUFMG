#include "../include/carteirinha.h"
#include <string>
#include <cmath>
#include <iostream>

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

void Carteirinha::atualizar(int nivel, int mop, bool vinculo)
{
    nivel_ = nivel;
    mop_= mop;
    vinculoMop_ = vinculo;
    return;
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

void Carteirinha::setSALDO(float atualiza){
    if(atualiza < 0 && abs(atualiza) > getSALDO() )
    {
        exceptionRecarga e;
        throw e;
    }
    this->saldo_ += atualiza;
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

