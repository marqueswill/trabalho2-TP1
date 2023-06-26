#ifndef TESTES_INTEGRACAO_H_INCLUDED
#define TESTES_INTEGRACAO_H_INCLUDED

#include "controladoras_apresentacao.h"
#include "controladoras_servico.h"
#include "stubs.h"

class TIApresentacao {
   public:
    void executar();
};

class TIAutenticacao {
   public:
    void executar();
};

class TIDesenvolvedor {
   public:
    void executar();
};

class TITeste {
   public:
    void executar();
};

class TICasoDeTeste {
   public:
    void executar();
};

#endif  // TESTES_INTEGRACAO_H_INCLUDED