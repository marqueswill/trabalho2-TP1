#include "stubs.h"

//----------------------------------------------------------------------------------------------------------------------
const string StubISAutenticacao::VALOR_VALIDO_SENHA = "abc123";
const string StubISAutenticacao::VALOR_VALIDO_MATRICULA = "1234567";
Senha StubISAutenticacao::senhaStub;
Matricula StubISAutenticacao::matriculaStub;

bool StubISAutenticacao::autenticar(Matricula matricula, Senha senha) {
    if (matricula.getValor() == matriculaStub.getValor()) {
        if (senha.getValor() == senhaStub.getValor()) {
            return SUCESSO;
        } else {
            return FALHA;
        }
    } else {
        return FALHA;
    }
}
//----------------------------------------------------------------------------------------------------------------------
const string StubISDesenvolvedor::VALOR_VALIDO_MATRICULA = "1234567";
const string StubISDesenvolvedor::VALOR_VALIDO_NOME = "joazinho123";
const string StubISDesenvolvedor::VALOR_VALIDO_SENHA = "abc123";
const string StubISDesenvolvedor::VALOR_VALIDO_TELEFONE = "+12345678";
Desenvolvedor StubISDesenvolvedor::desenvolvedorStub;
Senha StubISDesenvolvedor::senhaDesenvolvedor;
Telefone StubISDesenvolvedor::telefoneDesenvolvedor;
Matricula StubISDesenvolvedor::matriculaDesenvolvedor;
Texto StubISDesenvolvedor::nomeDesenvolvedor;

bool StubISDesenvolvedor::visualizar(Desenvolvedor* desenvolvedor) {
    if (desenvolvedor->getMatricula().getValor() == desenvolvedorStub.getMatricula().getValor()) {
        desenvolvedor->setNome(nomeDesenvolvedor);
        desenvolvedor->setSenha(senhaDesenvolvedor);
        desenvolvedor->setTelefone(telefoneDesenvolvedor);
    } else {
        return FALHA;
    }
    return SUCESSO;
}

bool StubISDesenvolvedor::cadastrar(Desenvolvedor desenvolvedor) {
    if (desenvolvedor.getMatricula().getValor() == desenvolvedorStub.getMatricula().getValor()) {
        return FALHA;
    } else if (desenvolvedor.getMatricula().getValor() == "") {
        return FALHA;
    }

    return SUCESSO;  // Verificação dos dados já é feita nas telas
}

bool StubISDesenvolvedor::editar(Desenvolvedor desenvolvedor) {
    try {
        if (desenvolvedor.getNome().getValor() != "") {
            StubISDesenvolvedor::nomeDesenvolvedor.setValor(desenvolvedor.getNome().getValor());
            StubISDesenvolvedor::desenvolvedorStub.setNome(StubISDesenvolvedor::nomeDesenvolvedor);
        }
        if (desenvolvedor.getSenha().getValor() != "") {
            StubISDesenvolvedor::senhaDesenvolvedor.setValor(desenvolvedor.getSenha().getValor());
            StubISDesenvolvedor::desenvolvedorStub.setSenha(StubISDesenvolvedor::senhaDesenvolvedor);
        }
        if (desenvolvedor.getTelefone().getValor() != "") {
            StubISDesenvolvedor::telefoneDesenvolvedor.setValor(desenvolvedor.getTelefone().getValor());
            StubISDesenvolvedor::desenvolvedorStub.setTelefone(StubISDesenvolvedor::telefoneDesenvolvedor);
        }
    } catch (invalid_argument& exp) {
        return FALHA;
    }
    return SUCESSO;
}

bool StubISDesenvolvedor::descadastrar(Matricula matricula) {
    if (matricula.getValor() != desenvolvedorStub.getMatricula().getValor()) {
        return FALHA;
    }

    return SUCESSO;  // Verificação dos dados já é feita nas telas
}

//----------------------------------------------------------------------------------------------------------------------
const string StubISTeste::VALOR_VALIDO_CODIGO = "UNB123";
const string StubISTeste::VALOR_VALIDO_NOME = "Modulo Autenticar";
const string StubISTeste::VALOR_VALIDO_CLASSE = "UNIDADE";

Teste StubISTeste::testeStub;
Codigo StubISTeste::codigoTeste;
Texto StubISTeste::nomeTeste;
Classe StubISTeste::classeTeste;

bool StubISTeste::visualizar(Teste* teste) {                                  // Passado apenas com o código
    if (teste->getCodigo().getValor() == testeStub.getCodigo().getValor()) {  // Procura no BD e passa os valores pra cima
        teste->setCodigo(codigoTeste);
        teste->setNome(nomeTeste);
        teste->setClasse(classeTeste);
    } else {
        return FALHA;
    }

    return SUCESSO;
}

bool StubISTeste::cadastrar(Teste teste) {
    if (teste.getCodigo().getValor() == testeStub.getCodigo().getValor()) {
        return FALHA;
    } else if (teste.getCodigo().getValor() == "") {
        return FALHA;
        if (teste.getCodigo().getValor() == testeStub.getCodigo().getValor()) {
            return FALHA;
        } else if (teste.getCodigo().getValor() == "") {
            return FALHA;
        }
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

//----------------------------------------------------------------------------------------------------------------------
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
