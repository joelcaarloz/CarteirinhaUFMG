
#include "../include/carteirinha.h"
#include <string>
#include <iostream>

using namespace std;

SistemaCarteirinha::SistemaCarteirinha(){};


void SistemaCarteirinha::newCarteirinha(string matricula){
     if (alunos.find(matricula) != alunos.end()) {
        cartExistente e;
        e.matricula = matricula;
        throw e;
    } else {
        string id, cpf, identidade, nome, curso;
        int nivel, mop;
        bool vinculoMop;

        cout << "Informe o CPF: ";
        cin >> cpf;

        cout << "Informe a identidade: ";
        cin >> identidade;

        cout << "Informe o nome: ";
        cin.ignore();//ignora o caractere de nova linha pendente
        getline(cin, nome);//para ler a linha inteira e não somente até ' '

        cout << "Informe o curso: ";
        getline(std::cin, curso);

        cout << "Informe o nível socioeconômico: ";
        cin >> nivel;

        cout << "Informe de qual MOP(0 se não morador): ";
        cin >> mop;

        cout << "Se morador, como esta o vinculo(1 para ativo, 0 para desligado): ";
        cin >> vinculoMop;

        if(cpf.size()!=11 ||identidade.size()!=9){//testa se ocorreu algum erro na inserção de dados
            erroCadastro erro;
            erro.matricula = matricula;
        }
        id = cpf.substr(0,4) + matricula.substr(4,8); //gera o código da id da carteirinha


        Carteirinha novaCarteirinha(id, cpf, identidade, nome, curso, nivel, mop, vinculoMop);
        alunos[matricula] = novaCarteirinha;
        cout << "Nova carteirinha criada para a matrícula " << matricula << endl;

        return;
    }
}

void SistemaCarteirinha::atualizaCarteirinha(string matricula)
{
    auto it = alunos.find(matricula);
    if (it == alunos.end())
    {
        cartInexistente erro;
        erro.matricula = matricula;
        throw erro;
    }
    
    

    int novoNivel, novaMop;
    bool novoVinculoMop;

    cout << "Informe o novo nível socioeconômico: ";
    cin >> novoNivel;

    cout << "Informe a nova MOP (0 se não morador): ";
    cin >> novaMop;

    cout << "Informe o novo vínculo MOP (1 para ativo, 0 para desligado): ";
    cin >> novoVinculoMop;

    
    it->second.atualizar(novoNivel, novaMop, novoVinculoMop);

    cout << "Carteirinha atualizada com sucesso para a matrícula " << matricula << endl;
    
    return;
}

Carteirinha* SistemaCarteirinha::buscaCarteirinha(string matricula) {
    auto it = alunos.find(matricula);

    if (it != alunos.end()) {
        return &(it->second);
    } else {
        cartInexistente erro;
        erro.matricula = matricula;
        throw erro;
    }
}

void SistemaCarteirinha::deleteCadastro(string matricula) {
    auto it = alunos.find(matricula);

    if (it != alunos.end()) {
        alunos.erase(it);
        cout << "Carteirinha excluída para a matrícula " << matricula << endl;
    } else {
        cartInexistente erro;
        erro.matricula = matricula;
        throw erro;
    }
}

SistemaCarteirinha::~SistemaCarteirinha(){};