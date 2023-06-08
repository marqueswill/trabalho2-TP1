#include "../headers/stubs.h"

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
const string StubISTeste::VALOR_VALIDO_CODIGO = "UNB123";
const string StubISTeste::VALOR_VALIDO_NOME = "Alexandre2";
const string StubISTeste::VALOR_VALIDO_CLASSE = "FUMACA";

Teste StubISTeste::testeStub;

Codigo StubISTeste::codigoTeste;
Texto StubISTeste::nomeTeste;
Classe StubISTeste::classeTeste;

const string StubISTeste::TRIGGER_SUCESSO = VALOR_VALIDO_CODIGO;

bool StubISTeste::visualizar(Teste* teste) {                 // Passado apenas com o código
    if (teste->getCodigo().getValor() != TRIGGER_SUCESSO) {  // Não achou no BD
        resultado = false;
    } else {
        teste->setCodigo(codigoTeste);
        teste->setNome(nomeTeste);
        teste->setClasse(classeTeste);
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
            StubISTeste::nomeTeste.setValor(teste.getNome().getValor());
            StubISTeste::testeStub.setNome(StubISTeste::nomeTeste);
        }
        if (teste.getClasse().getValor() != "") {
            StubISTeste::classeTeste.setValor(teste.getClasse().getValor());
            StubISTeste::testeStub.setClasse(StubISTeste::classeTeste);
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
const string StubISCasoDeTeste::VALOR_VALIDO_CODIGO = "UNB123";
const string StubISCasoDeTeste::VALOR_VALIDO_NOME = "mariazinha1";
const string StubISCasoDeTeste::VALOR_VALIDO_DATA = "14/AGO/2003";
const string StubISCasoDeTeste::VALOR_VALIDO_ACAO = "correr uma maratona";
const string StubISCasoDeTeste::VALOR_VALIDO_RESPOSTA = "Chorar muito";
const string StubISCasoDeTeste::VALOR_VALIDO_RESULTADO = "APROVADO";

CasoDeTeste StubISCasoDeTeste::casoDeTesteStub;

Codigo StubISCasoDeTeste::codigoCasoDeTeste;
Texto StubISCasoDeTeste::nomeCasoDeTeste;
Data StubISCasoDeTeste::dataCasoDeTeste;
Texto StubISCasoDeTeste::acaoCasoDeTeste;
Texto StubISCasoDeTeste::respostaCasoDeTeste;
Resultado StubISCasoDeTeste::resultadoCasoDeTeste;

const string StubISCasoDeTeste::TRIGGER_SUCESSO = VALOR_VALIDO_CODIGO;

bool StubISCasoDeTeste::visualizar(CasoDeTeste* casoDeTeste) {     // Passado apenas com o código
    if (casoDeTeste->getCodigo().getValor() != TRIGGER_SUCESSO) {  // Não achou no BD
        resultado = false;
    } else {
        casoDeTeste->setCodigo(codigoCasoDeTeste);
        casoDeTeste->setNome(nomeCasoDeTeste);
        casoDeTeste->setAcao(acaoCasoDeTeste);
        casoDeTeste->setData(dataCasoDeTeste);
        casoDeTeste->setResposta(respostaCasoDeTeste);
        casoDeTeste->setResultado(resultadoCasoDeTeste);
    }

    return resultado;
}

bool StubISCasoDeTeste::cadastrar(CasoDeTeste casoDeTeste) {
    if (casoDeTeste.getCodigo().getValor() == TRIGGER_SUCESSO) {
        resultado = false;
    }

    return resultado;  // Verificação dos dados já é feita nas telas
}

bool StubISCasoDeTeste::editar(CasoDeTeste casoDeTeste) {
    try {
        if (casoDeTeste.getNome().getValor() != "") {
            StubISCasoDeTeste::nomeCasoDeTeste.setValor(casoDeTeste.getNome().getValor());
            StubISCasoDeTeste::casoDeTesteStub.setNome(StubISCasoDeTeste::nomeCasoDeTeste);
        }
        if (casoDeTeste.getData().getValor() != "") {
            StubISCasoDeTeste::dataCasoDeTeste.setValor(casoDeTeste.getData().getValor());
            StubISCasoDeTeste::casoDeTesteStub.setData(StubISCasoDeTeste::dataCasoDeTeste);
        }
        if (casoDeTeste.getAcao().getValor() != "") {
            StubISCasoDeTeste::acaoCasoDeTeste.setValor(casoDeTeste.getAcao().getValor());
            StubISCasoDeTeste::casoDeTesteStub.setAcao(StubISCasoDeTeste::acaoCasoDeTeste);
        }
        if (casoDeTeste.getResposta().getValor() != "") {
            StubISCasoDeTeste::respostaCasoDeTeste.setValor(casoDeTeste.getResposta().getValor());
            StubISCasoDeTeste::casoDeTesteStub.setResposta(StubISCasoDeTeste::respostaCasoDeTeste);
        }
        if (casoDeTeste.getResultado().getValor() != "") {
            StubISCasoDeTeste::resultadoCasoDeTeste.setValor(casoDeTeste.getResultado().getValor());
            StubISCasoDeTeste::casoDeTesteStub.setResultado(StubISCasoDeTeste::resultadoCasoDeTeste);
        }
    } catch (invalid_argument& exp) {
        resultado = false;
    }

    return resultado;
}

bool StubISCasoDeTeste::descadastrar(Codigo codigo) {
    if (codigo.getValor() != TRIGGER_SUCESSO) {
        resultado = false;
    }

    return resultado;  // Verificação dos dados já é feita nas telas
}