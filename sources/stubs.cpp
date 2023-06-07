#include "../headers/stubs.h"

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
const string StubISTeste::VALOR_VALIDO_CODIGO = "UNB123";
const string StubISTeste::VALOR_VALIDO_NOME = "Alexandre2";
const string StubISTeste::VALOR_VALIDO_CLASSE = "FUMACA";

Teste StubISTeste::testeStub;

Codigo StubISTeste::codigo;
Texto StubISTeste::nome;
Classe StubISTeste::classe;

const string StubISTeste::TRIGGER_SUCESSO = VALOR_VALIDO_CODIGO;

bool StubISTeste::visualizar(Teste* teste) {                 // Passado apenas com o código
    if (teste->getCodigo().getValor() != TRIGGER_SUCESSO) {  // Não achou no BD
        resultado = false;
    } else {
        teste->setCodigo(codigo);
        teste->setNome(nome);
        teste->setClasse(classe);
    }

    return resultado;
}

bool StubISTeste::cadastrar(Teste teste) {
    if (teste.getCodigo().getValor() == TRIGGER_SUCESSO) {
        resultado = false;
    }

    return resultado;  // Verificação dos dados já é feita nas telas
}

bool StubISTeste::editar(Teste teste) {
    try {
        if (teste.getNome().getValor() != "") {
            StubISTeste::nome.setValor(teste.getNome().getValor());
            StubISTeste::testeStub.setNome(StubISTeste::nome);
        }
        if (teste.getClasse().getValor() != "") {
            StubISTeste::classe.setValor(teste.getClasse().getValor());
            StubISTeste::testeStub.setClasse(StubISTeste::classe);
        }
    } catch (invalid_argument& exp) {
        resultado = false;
    }

    return resultado;
}

bool StubISTeste::descadastrar(Codigo codigo) {
    if (codigo.getValor() != TRIGGER_SUCESSO) {
        resultado = false;
    }

    return resultado;  // Verificação dos dados já é feita nas telas
}

// //--------------------------------------------------------------------------------------------
// const string StubISCasoDeTeste::TRIGGER_FALHA = "UNB123";

// bool StubISCasoDeTeste::visualizar(CasoDeTeste* casodeteste) {
//     if (casodeteste->getCodigo().getValor() == TRIGGER_FALHA) {
//         resultado = false;
//     } else if (casodeteste->getCodigo().getValor() == TRIGGER_ERRO) {
//         throw runtime_error("Erro de sistema");
//     }

//     return resultado;
// }

// bool StubISCasoDeTeste::cadastrar(CasoDeTeste casodeteste) {
//     if (casodeteste.getCodigo().getValor() == TRIGGER_FALHA) {
//         resultado = false;
//     } else if (casodeteste.getCodigo().getValor() == TRIGGER_ERRO) {
//         throw runtime_error("Erro de sistema");
//     }

//     return resultado;
// }

// bool StubISCasoDeTeste::editar(CasoDeTeste casodeteste) {
//     if (casodeteste.getCodigo().getValor() == TRIGGER_FALHA) {
//         resultado = false;
//     } else if (casodeteste.getCodigo().getValor() == TRIGGER_ERRO) {
//         throw runtime_error("Erro de sistema");
//     }

//     return resultado;
// }

// bool StubISCasoDeTeste::descadastrar(Codigo codigo) {
//     if (codigo.getValor() == TRIGGER_FALHA) {
//         resultado = false;
//     } else if (codigo.getValor() == TRIGGER_ERRO) {
//         throw runtime_error("Erro de sistema");
//     }

//     return resultado;
// }