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
    const static string TRIGGER_SUCESSO;
    const static string TRIGGER_FALHA;

    const static string VALOR_VALIDO_CODIGO;
    const static string VALOR_VALIDO_NOME;
    const static string VALOR_VALIDO_CLASSE;

    Codigo codigo;
    Texto nome;
    Classe classe;

    bool resultado;

   public:
    bool visualizar(Teste *);
    bool cadastrar(Teste);
    bool editar(Teste);
    bool descadastrar(Codigo);
};

class StubISCasoDeTeste : public ISCasoDeTeste {
   private:
    const static string TRIGGER_FALHA;
    bool resultado;
    CasoDeTeste casodetesteStub;

   public:
    bool visualizar(CasoDeTeste *);
    bool cadastrar(CasoDeTeste);
    bool editar(CasoDeTeste);
    bool descadastrar(Codigo);
};

#endif  // STUBS_H_INCLUDED