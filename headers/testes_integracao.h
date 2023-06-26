#ifndef TESTES_INTEGRACAO_H_INCLUDED
#define TESTES_INTEGRACAO_H_INCLUDED

#include "controladoras_apresentacao.h"
#include "controladoras_servico.h"
#include "stubs.h"

class TIApresentacao {
   public:
    void executar();
};

class TISubAutenticacao {
   public:
    void executar();
};

class TISubDesenvolvedor {
   public:
    void executar();
};

class TISubTeste {
   public:
    void executar();
};

class TISubCasoDeTeste {
   public:
    void executar();
};

#endif  // TESTES_INTEGRACAO_H_INCLUDED