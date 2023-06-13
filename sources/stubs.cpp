#include "../headers/stubs.h"

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
const string StubISTeste::VALOR_VALIDO_CODIGO = "UNB123";
const string StubISTeste::VALOR_VALIDO_NOME = "Modulo Autenticar";
const string StubISTeste::VALOR_VALIDO_CLASSE = "UNIDADE";

Teste StubISTeste::testeStub;
Codigo StubISTeste::codigoTeste;
Texto StubISTeste::nomeTeste;
Classe StubISTeste::classeTeste;

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
    if (teste.getCodigo().getValor() == testeStub.getCodigo().getValor()) {
        return FALHA;
    } else if (teste.getCodigo().getValor() == "") {
        return FALHA;
    }

    return SUCESSO;  // Verificação dos dados já é feita nas telas
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
        return FALHA;
    }

    return SUCESSO;
}

bool StubISTeste::descadastrar(Codigo codigo) {
    if (codigo.getValor() != testeStub.getCodigo().getValor()) {
        return FALHA;
    }

    return SUCESSO;  // Verificação dos dados já é feita nas telas
}

// //--------------------------------------------------------------------------------------------
const string StubISCasoDeTeste::VALOR_VALIDO_CODIGO = "UNB123";
const string StubISCasoDeTeste::VALOR_VALIDO_NOME = "Metodo validar";
const string StubISCasoDeTeste::VALOR_VALIDO_DATA = "14/AGO/2003";
const string StubISCasoDeTeste::VALOR_VALIDO_ACAO = "Comparar valores";
const string StubISCasoDeTeste::VALOR_VALIDO_RESPOSTA = "Processo finalizado";
const string StubISCasoDeTeste::VALOR_VALIDO_RESULTADO = "APROVADO";

CasoDeTeste StubISCasoDeTeste::casoDeTesteStub;

Codigo StubISCasoDeTeste::codigoCasoDeTeste;
Texto StubISCasoDeTeste::nomeCasoDeTeste;
Data StubISCasoDeTeste::dataCasoDeTeste;
Texto StubISCasoDeTeste::acaoCasoDeTeste;
Texto StubISCasoDeTeste::respostaCasoDeTeste;
Resultado StubISCasoDeTeste::resultadoCasoDeTeste;

bool StubISCasoDeTeste::visualizar(CasoDeTeste* casoDeTeste) {                            // Passado apenas com o código
    if (casoDeTeste->getCodigo().getValor() == casoDeTesteStub.getCodigo().getValor()) {  // Não achou no BD
        casoDeTeste->setCodigo(codigoCasoDeTeste);
        casoDeTeste->setNome(nomeCasoDeTeste);
        casoDeTeste->setAcao(acaoCasoDeTeste);
        casoDeTeste->setData(dataCasoDeTeste);
        casoDeTeste->setResposta(respostaCasoDeTeste);
        casoDeTeste->setResultado(resultadoCasoDeTeste);
    } else {
        return FALHA;
    }

    return SUCESSO;
}

bool StubISCasoDeTeste::cadastrar(CasoDeTeste casoDeTeste) {
    if (casoDeTeste.getCodigo().getValor() == casoDeTesteStub.getCodigo().getValor()) {
        return FALHA;
    } else if (casoDeTeste.getCodigo().getValor() == "") {
        return FALHA;
    }

    return SUCESSO;  // Verificação dos dados já é feita nas telas
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
        return FALHA;
    }

    return SUCESSO;
}

bool StubISCasoDeTeste::descadastrar(Codigo codigo) {
    if (codigo.getValor() != casoDeTesteStub.getCodigo().getValor()) {
        return FALHA;
    }

    return SUCESSO;  // Verificação dos dados já é feita nas telas
}