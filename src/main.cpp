#include <iostream>
#include "../include/carteirinha.h"

using namespace std;


int main()
{
    std::string id = "1234";
    std::string cpf = "12345678901";
    std::string identidade = "987654321";
    std::string nome = "Joao Silva";
    std::string curso = "Engenharia";
    int nivel = 1;
    int mop = 123;
    bool vinculoMop = true;
    Carteirinha teste(id, cpf, identidade, nome, curso, nivel, mop, vinculoMop);
    std::cout << "ID: " << teste.getID() << std::endl;
    std::cout << "CPF: " << teste.getCPF() << std::endl;
    std::cout << "Identidade: " << teste.getIDENTIDADE() << std::endl;
    std::cout << "Nome: " << teste.getNOME() << std::endl;
    std::cout << "Curso: " << teste.getCURSO() << std::endl;
    std::cout << "Saldo: " << teste.getSALDO() << std::endl; // A função de acesso ao saldo não estava no código original
    std::cout << "Validade: " << teste.getValidade() << std::endl;
    std::cout << "Nível Socioeconômico: " << teste.getNIVEL() << std::endl;
    std::cout << "Vínculo com MOP: " << teste.getMOP() << std::endl;
    teste.setSALDO(10.00);
    std::cout << "Saldo atualizado: " << teste.getSALDO() << std::endl;
}