#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "interfaces.h"

class StubISAutenticacao : public ISAutenticacao {
   private:
   public:
};

class StubISDesenvolvedor : public ISDesenvolvedor {
   private:
   public:
};

class StubISTeste : public ISTeste {
   private:
    static Teste testeStub;

    static Codigo codigo;
    static Texto nome;
    static Classe classe;

    const static string VALOR_VALIDO_CODIGO;
    const static string VALOR_VALIDO_NOME;
    const static string VALOR_VALIDO_CLASSE;

    const static string TRIGGER_SUCESSO;

    bool resultado = true;

   public:
    StubISTeste() {
        codigo.setValor(VALOR_VALIDO_CODIGO);
        nome.setValor(VALOR_VALIDO_NOME);
        classe.setValor(VALOR_VALIDO_CLASSE);

        testeStub.setCodigo(codigo);
        testeStub.setNome(nome);
        testeStub.setClasse(classe);
    };

    bool visualizar(Teste *);
    bool cadastrar(Teste);
    bool editar(Teste);
    bool descadastrar(Codigo);
};

class StubISCasoDeTeste : public ISCasoDeTeste {
   private:
    const static string TRIGGER_FALHA;
    bool resultado;
    CasoDeTeste casoDeTesteStub;

   public:
    bool visualizar(CasoDeTeste *);
    bool cadastrar(CasoDeTeste);
    bool editar(CasoDeTeste);
    bool descadastrar(Codigo);
};

#endif  // STUBS_H_INCLUDED