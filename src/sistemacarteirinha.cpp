
#include "../include/sistemacarteirinha.h"
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

        //cout << "Informe o CPF: ";
        cin >> cpf;

        //cout << "Informe a identidade: ";
        cin >> identidade;

        //cout << "Informe o nome: ";
        cin.ignore();//ignora o caractere de nova linha pendente
        getline(cin, nome);//para ler a linha inteira e não somente até ' '

        //cout << "Informe o curso: ";
        getline(std::cin, curso);

        //cout << "Informe o nível socioeconômico: ";
        cin >> nivel;

        //cout << "Informe de qual MOP(0 se não morador): ";
        cin >> mop;

        //cout << "Se morador, como esta o vinculo(1 para ativo, 0 para desligado ou não morador): ";
        cin >> vinculoMop;

        if(cpf.size()!=11 ||identidade.size()!=8){//testa se ocorreu algum erro na inserção de dados
            erroCadastro erro;
            erro.matricula = matricula;
        }
        id = matricula; //id da carteirinha será igual a matricula


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

void SistemaCarteirinha::imprimeCarteirinha(string matricula) {
    auto it = alunos.find(matricula);

    if (it != alunos.end()) {
        cout << "A carteirinha pertence há: "<< it->second.getNOME() << endl <<" E possui saldo de: " << it->second.getSALDO() << " reais." << endl;;
    } else {
        cartInexistente erro;
        erro.matricula = matricula;
        throw erro;
    }
}

void SistemaCarteirinha::deleteCarteirinha(string matricula) {
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

bool SistemaCarteirinha::catraca(string ID){
    auto it = alunos.find(ID);
    return it->second.getValidade();
 }

bool SistemaCarteirinha::catracaRU(string ID){
    auto it = alunos.find(ID);
    if(it->second.getValidade())
    {
        switch (it->second.getNIVEL())
        {
        case 1://alunos posicionados no nível 1 não pagam
            break;

        case 2://alunos nivel 2 pagam 1 real
            it->second.setSALDO(-1.0);
            break;

        case 3://alunos nivel 3 pagam 1 real
            it->second.setSALDO(-1.0);
            break;

        case 4://alunos nivel 4-A pagam 2
            it->second.setSALDO(-2.0);
            break;
        
        case 5://alunos nivel 4-B pagam 2,90
            it->second.setSALDO(-2.90);
            break;

        default://alunos em geral
            it->second.setSALDO(-5.60);
            break;
        }
        return true;
    }
    return false;
}

void SistemaCarteirinha::deposito(string ID, float dep)
{
    if(dep < 0)
    {
        valorNeg erro;
        erro.valor = dep;
        erro.ID = ID;
        throw erro;
    }
    auto it = alunos.find(ID);
    if(it==alunos.end())
    {
        cartInexistente e;
        e.matricula = ID;
        throw e;
    }
    if(it->second.getNIVEL() == 1)
    {
        cout << "Não é possível efetuar o depósito, pois o aluno tem acesso gratuito ao RU"<< endl;
    }
    it->second.setSALDO(dep);

    return;
}

SistemaCarteirinha::~SistemaCarteirinha(){};