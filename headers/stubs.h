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
    bool resultado;

   public:
    bool visualizar(Teste *);
    bool cadastrar(Teste);
    bool editar(Teste);
    bool descadastrar(Codigo);
};

class StubISCasoDeTeste : public ISCasoDeTeste {
   private:
    bool resultado;

   public:
    bool visualizar(CasoDeTeste *);
    bool cadastrar(CasoDeTeste);
    bool editar(CasoDeTeste);
    bool descadastrar(Codigo);
};

#endif  // STUBS_H_INCLUDED