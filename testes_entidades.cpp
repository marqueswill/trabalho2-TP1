#include "testes_entidades.h"

using namespace std;

//----------------------------------------------------------------------------------------------------------------------
// TESTE DESENVOLVEDOR
const string TUDesenvolvedor::VALOR_VALIDO_NOME = "joaozinho123";
const string TUDesenvolvedor::VALOR_VALIDO_MATRICULA = "1234567";
const string TUDesenvolvedor::VALOR_VALIDO_SENHA = "abc123";
const string TUDesenvolvedor::VALOR_VALIDO_TELEFONE = "+1234567";

void TUDesenvolvedor::setUp() {
    desenvolvedor = new Desenvolvedor();
    estado = SUCESSO;
}

void TUDesenvolvedor::tearDown() {
    delete desenvolvedor;
}

void TUDesenvolvedor::testarValorValido() {
    Matricula matricula;
    matricula.setValor(VALOR_VALIDO_MATRICULA);
    desenvolvedor->setMatricula(matricula);
    if (desenvolvedor->getMatricula().getValor() != VALOR_VALIDO_MATRICULA) {
        estado = FALHA;
    }

    Texto nome;
    nome.setValor(VALOR_VALIDO_NOME);
    desenvolvedor->setNome(nome);
    if (desenvolvedor->getNome().getValor() != TUDesenvolvedor::VALOR_VALIDO_NOME) {
        estado = FALHA;
    }

    Senha senha;
    senha.setValor(VALOR_VALIDO_SENHA);
    desenvolvedor->setSenha(senha);
    if (desenvolvedor->getSenha().getValor() != VALOR_VALIDO_SENHA) {
        estado = FALHA;
    }

    Telefone telefone;
    telefone.setValor(VALOR_VALIDO_TELEFONE);
    desenvolvedor->setTelefone(telefone);
    if (desenvolvedor->getTelefone().getValor() != VALOR_VALIDO_TELEFONE) {
        estado = FALHA;
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Teste CasoDeTeste
const string TUCasoDeTeste::VALOR_VALIDO_NOME = "mariazinha1";
const string TUCasoDeTeste::VALOR_VALIDO_DATA = "14/AGO/2003";
const string TUCasoDeTeste::VALOR_VALIDO_ACAO = "correr uma maratona";
const string TUCasoDeTeste::VALOR_VALIDO_RESPOSTA = "Chorar muito";
const string TUCasoDeTeste::VALOR_VALIDO_RESULTADO = "APROVADO";

void TUCasoDeTeste::setUp() {
    casoDeTeste = new CasoDeTeste();
    estado = SUCESSO;
}

void TUCasoDeTeste::tearDown() {
    delete casoDeTeste;
}

void TUCasoDeTeste::testarValorValido() {
    Texto nome;
    nome.setValor(VALOR_VALIDO_NOME);
    casoDeTeste->setNome(nome);
    if (casoDeTeste->getNome().getValor() != VALOR_VALIDO_NOME) {
        estado = FALHA;
    }

    Data data;
    data.setValor(VALOR_VALIDO_DATA);
    casoDeTeste->setData(data);
    if (casoDeTeste->getData().getValor() != VALOR_VALIDO_DATA) {
        estado = FALHA;
    }

    Texto acao;
    acao.setValor(VALOR_VALIDO_ACAO);
    casoDeTeste->setAcao(acao);
    if (casoDeTeste->getAcao().getValor() != VALOR_VALIDO_ACAO) {
        estado = FALHA;
    }

    Texto resposta;
    resposta.setValor(VALOR_VALIDO_RESPOSTA);
    casoDeTeste->setResposta(resposta);
    if (casoDeTeste->getResposta().getValor() != VALOR_VALIDO_RESPOSTA) {
        estado = FALHA;
    }

    Resultado resultado;
    resultado.setValor(VALOR_VALIDO_RESULTADO);
    casoDeTeste->setResultado(resultado);
    if (casoDeTeste->getResultado().getValor() != VALOR_VALIDO_RESULTADO) {
        estado = FALHA;
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Teste de Teste
const string TUTeste::VALOR_VALIDO_CODIGO = "VSC021";
const string TUTeste::VALOR_VALIDO_NOME = "Alexandre2";
const string TUTeste::VALOR_VALIDO_CLASSE = "FUMACA";

void TUTeste::setUp() {
    teste = new Teste();
    estado = SUCESSO;
}

void TUTeste::tearDown() {
    delete teste;
}

void TUTeste::testarValorValido() {
    Codigo codigo;
    codigo.setValor(VALOR_VALIDO_CODIGO);
    teste->setCodigo(codigo);
    if (teste->getCodigo().getValor() != VALOR_VALIDO_CODIGO) {
        estado = FALHA;
    }

    Texto nome;
    nome.setValor(VALOR_VALIDO_NOME);
    teste->setNome(nome);
    if (teste->getNome().getValor() != VALOR_VALIDO_NOME) {
        estado = FALHA;
    }

    Classe classe;
    classe.setValor(VALOR_VALIDO_CLASSE);
    teste->setClasse(classe);
    if (teste->getClasse().getValor() != VALOR_VALIDO_CLASSE) {
        estado = FALHA;
    }
}
