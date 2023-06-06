#include "../headers/stubs.h"

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
const string StubISTeste::TRIGGER_SUCESSO = "UNB123";
const string StubISTeste::TRIGGER_FALHA = "XYZ123";

const string StubISTeste::VALOR_VALIDO_CODIGO = "VSC021";
const string StubISTeste::VALOR_VALIDO_NOME = "Alexandre2";
const string StubISTeste::VALOR_VALIDO_CLASSE = "FUMACA";

bool StubISTeste::visualizar(Teste* teste) {
    if (teste->getCodigo().getValor() == TRIGGER_SUCESSO) {  // Achou no BD.
        codigo.setValor(VALOR_VALIDO_CODIGO);
        nome.setValor(VALOR_VALIDO_NOME);
        classe.setValor(VALOR_VALIDO_CLASSE);

        teste->setCodigo(codigo);
        teste->setNome(nome);
        teste->setClasse(classe);
        resultado = true;
    } else if (teste->getCodigo().getValor() == TRIGGER_FALHA) {  // Não achou no BD.
        resultado = false;
    }

    return resultado;
}

bool StubISTeste::cadastrar(Teste teste) {
    if (teste.getCodigo().getValor() == TRIGGER_SUCESSO) {
        resultado = true;
    } else if (teste.getCodigo().getValor() == TRIGGER_FALHA) {
        resultado = false;
    }

    return resultado;
}

bool StubISTeste::editar(Teste teste) {
    codigo = teste.getCodigo();
    nome = teste.getNome();
    classe = teste.getClasse();

    if (codigo.getValor() == TRIGGER_SUCESSO) {  // Achou no BD.
        resultado = true;
    } else if (codigo.getValor() == TRIGGER_FALHA) {  // Não achou no BD.
        resultado = false;
    }
    return resultado;
}

bool StubISTeste::descadastrar(Codigo codigo) {
    if (codigo.getValor() == TRIGGER_SUCESSO) {
        resultado = true;
    } else if (codigo.getValor() == TRIGGER_FALHA) {
        resultado = false;
    }

    return resultado;
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