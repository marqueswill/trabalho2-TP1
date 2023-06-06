#include "../headers/stubs.h"

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
bool StubISTeste::visualizar(Teste* teste) {
    string TRIGGER_SUCESSO = "UnB123";
    string TRIGGER_FALHA = "UnB321";
    string TRIGGER_ERRO = "123ABC";

    Codigo codigo;
    codigo = teste->getCodigo();

    if (codigo.getValor() == TRIGGER_SUCESSO) {       // Código no BD
        resultado = true;                             //
    } else if (codigo.getValor() == TRIGGER_FALHA) {  // Código não está no BD
        resultado = false;                            //
    } else if (codigo.getValor() == TRIGGER_ERRO) {   // Código inválido
        throw runtime_error("Erro de sistema");
    }

    return resultado;
}

bool StubISTeste::cadastrar(Teste teste) {
    Codigo codigo;
    Texto nome;
    Classe classe;

    codigo = teste.getCodigo();
    nome = teste.getNome();
    classe = teste.getClasse();
}

bool StubISTeste::editar(Teste teste) {
}

bool StubISTeste::descadastrar(Codigo codigo) {
    string TRIGGER_SUCESSO = "UnB123";
    string TRIGGER_FALHA = "UnB321";
    string TRIGGER_ERRO = "123ABC";

    if (codigo.getValor() == TRIGGER_SUCESSO) {
        resultado = true;
    } else if (codigo.getValor() == TRIGGER_FALHA) {
        resultado = false;
    } else if (codigo.getValor() == TRIGGER_ERRO) {
        throw runtime_error("Erro de sistema");
    }

    return resultado;
}

//--------------------------------------------------------------------------------------------
bool StubISCasoDeTeste::visualizar(CasoDeTeste* casodeteste) {
}

bool StubISCasoDeTeste::cadastrar(CasoDeTeste casodeteste) {
}

bool StubISCasoDeTeste::editar(CasoDeTeste casodeteste) {
}

bool StubISCasoDeTeste::descadastrar(Codigo codigo) {
}