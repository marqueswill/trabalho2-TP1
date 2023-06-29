#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.h"

//----------------------------------------------------------------------------------------------------------------------
class StubISAutenticacao : public ISAutenticacao {
   private:
    static Matricula matriculaStub;
    static Senha senhaStub;

    const static string VALOR_VALIDO_MATRICULA;
    const static string VALOR_VALIDO_SENHA;

    const static bool SUCESSO = true;
    const static bool FALHA = false;

    bool resultado;

   public:
    StubISAutenticacao() {
        matriculaStub.setValor(VALOR_VALIDO_MATRICULA);
        senhaStub.setValor(VALOR_VALIDO_SENHA);
    }
    bool autenticar(Matricula, Senha);
};

//----------------------------------------------------------------------------------------------------------------------
class StubISDesenvolvedor : public ISDesenvolvedor {
   private:
    static Desenvolvedor desenvolvedorStub;
    static Matricula matriculaDesenvolvedor;
    static Texto nomeDesenvolvedor;
    static Senha senhaDesenvolvedor;
    static Telefone telefoneDesenvolvedor;

    const static string VALOR_VALIDO_MATRICULA;
    const static string VALOR_VALIDO_NOME;
    const static string VALOR_VALIDO_SENHA;
    const static string VALOR_VALIDO_TELEFONE;

    const static bool SUCESSO = true;
    const static bool FALHA = false;

    bool resultado;

   public:
    StubISDesenvolvedor() {
        matriculaDesenvolvedor.setValor(VALOR_VALIDO_MATRICULA);
        nomeDesenvolvedor.setValor(VALOR_VALIDO_NOME);
        senhaDesenvolvedor.setValor(VALOR_VALIDO_SENHA);
        telefoneDesenvolvedor.setValor(VALOR_VALIDO_TELEFONE);

        desenvolvedorStub.setMatricula(matriculaDesenvolvedor);
        desenvolvedorStub.setNome(nomeDesenvolvedor);
        desenvolvedorStub.setSenha(senhaDesenvolvedor);
        desenvolvedorStub.setTelefone(telefoneDesenvolvedor);
    }
    bool visualizar(Desenvolvedor *);
    bool cadastrar(Desenvolvedor);
    bool editar(Desenvolvedor);
    bool descadastrar(Matricula);
};

//----------------------------------------------------------------------------------------------------------------------
class StubISTeste : public ISTeste {
   private:
    static Teste testeStub;

    static Codigo codigoTeste;
    static Texto nomeTeste;
    static Classe classeTeste;

    const static string VALOR_VALIDO_CODIGO;
    const static string VALOR_VALIDO_NOME;
    const static string VALOR_VALIDO_CLASSE;

    const static bool SUCESSO = true;
    const static bool FALHA = false;

    bool resultado;

   public:
    StubISTeste() {
        codigoTeste.setValor(VALOR_VALIDO_CODIGO);
        nomeTeste.setValor(VALOR_VALIDO_NOME);
        classeTeste.setValor(VALOR_VALIDO_CLASSE);

        testeStub.setCodigo(codigoTeste);
        testeStub.setNome(nomeTeste);
        testeStub.setClasse(classeTeste);
    };

    bool visualizar(Teste *);
    bool cadastrar(Teste);
    bool editar(Teste);
    bool descadastrar(Codigo);
};

//----------------------------------------------------------------------------------------------------------------------
class StubISCasoDeTeste : public ISCasoDeTeste {
   private:
    static CasoDeTeste casoDeTesteStub;

    static Codigo codigoCasoDeTeste;
    static Texto nomeCasoDeTeste;
    static Data dataCasoDeTeste;
    static Texto acaoCasoDeTeste;
    static Texto respostaCasoDeTeste;
    static Resultado resultadoCasoDeTeste;

    const static string VALOR_VALIDO_CODIGO;
    const static string VALOR_VALIDO_NOME;
    const static string VALOR_VALIDO_DATA;
    const static string VALOR_VALIDO_ACAO;
    const static string VALOR_VALIDO_RESPOSTA;
    const static string VALOR_VALIDO_RESULTADO;

    const static bool SUCESSO = true;
    const static bool FALHA = false;

   public:
    StubISCasoDeTeste() {
        codigoCasoDeTeste.setValor(VALOR_VALIDO_CODIGO);
        nomeCasoDeTeste.setValor(VALOR_VALIDO_NOME);
        dataCasoDeTeste.setValor(VALOR_VALIDO_DATA);
        acaoCasoDeTeste.setValor(VALOR_VALIDO_ACAO);
        respostaCasoDeTeste.setValor(VALOR_VALIDO_RESPOSTA);
        resultadoCasoDeTeste.setValor(VALOR_VALIDO_RESULTADO);

        casoDeTesteStub.setCodigo(codigoCasoDeTeste);
        casoDeTesteStub.setNome(nomeCasoDeTeste);
        casoDeTesteStub.setData(dataCasoDeTeste);
        casoDeTesteStub.setAcao(acaoCasoDeTeste);
        casoDeTesteStub.setResposta(respostaCasoDeTeste);
        casoDeTesteStub.setResultado(resultadoCasoDeTeste);
    }

    bool visualizar(CasoDeTeste *);
    bool cadastrar(CasoDeTeste);
    bool editar(CasoDeTeste);
    bool descadastrar(Codigo);
};

#endif  // STUBS_H_INCLUDED
