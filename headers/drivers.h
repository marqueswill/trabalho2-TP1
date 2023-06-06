#ifndef DRIVERS_H_INCLUDED
#define DRIVERS_H_INCLUDED

#include <ncurses.h>

#include "dominios.h"
#include "entidades.h"
#include "telas.h"
#include "testes_dominios.h"
#include "testes_entidades.h"

//--------------------------------------------------------------------------------------------
class Drivers {
   public:
    void showResult(bool, string, int);
    virtual void executar() = 0;
};

//--------------------------------------------------------------------------------------------
class DriverDepuracao {
   private:
    const static int TESTE_UNITARIO = 1;
    const static int TESTE_INTEGRACAO = 2;
    const static int TESTE_FUMACA = 3;
    const static int TESTE_SISTEMA = 4;
    const static int SAIR = 5;

   public:
    void executar();
};

//--------------------------------------------------------------------------------------------
class DriverTestesUnitarios : public Drivers {
   private:
    const static int DOMINIOS = 1;
    const static int ENTIDADES = 2;
    const static int MODULOS = 3;
    const static int SAIR = 4;

   public:
    void executar();
};

//--------------------------------------------------------------------------------------------
class DriverTestesDominios : public Drivers {
   private:
    TUClasse testeClasse;
    TUCodigo testeCodigo;
    TUData testeData;
    TUMatricula testeMatricula;
    TUResultado testeResultado;
    TUSenha testeSenha;
    TUTelefone testeTelefone;
    TUTexto testeTexto;

   public:
    void executar();
};

//--------------------------------------------------------------------------------------------
class DriverTestesEntidades : public Drivers {
   private:
    TUDesenvolvedor testeDesenvolvedor;
    TUTeste testeTeste;
    TUCasoDeTeste testeCasoDeTeste;

   public:
    void executar();
};

//--------------------------------------------------------------------------------------------
class DriverTestesModulos : public Drivers {
   private:
   public:
    void executar();
};

//--------------------------------------------------------------------------------------------
class DriverTestesIntegracao : public Drivers {
   private:
   public:
    void executar();
};

#endif  // DRIVERS_H_INCLUDED
