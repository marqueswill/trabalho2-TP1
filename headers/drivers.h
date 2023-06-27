#ifndef DRIVERS_H_INCLUDED
#define DRIVERS_H_INCLUDED

#include "testes_dominios.h"
#include "testes_entidades.h"
#include "testes_integracao.h"
#include "testes_modulos.h"

//----------------------------------------------------------------------------------------------------------------------
class Drivers {
   public:
    void showResult(bool, string, int);
    virtual void executar() = 0;
};

//----------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------
class DriverTestesUnitarios : public Drivers {
   private:
    const static int DOMINIOS = 1;
    const static int ENTIDADES = 2;
    const static int MODULOS = 3;
    const static int RETORNAR = 4;

   public:
    void executar();
};

//----------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------
class DriverTestesEntidades : public Drivers {
   private:
    TUDesenvolvedor testeDesenvolvedor;
    TUTeste testeTeste;
    TUCasoDeTeste testeCasoDeTeste;

   public:
    void executar();
};

//----------------------------------------------------------------------------------------------------------------------
class DriverTestesModulos : public Drivers {
   private:
    const static int AUTENTICACAO = 1;
    const static int DESENVOLVEDOR = 2;
    const static int TESTE = 3;
    const static int CASODETESTE = 4;
    const static int RETORNAR = 5;

   public:
    void executar();
};

//----------------------------------------------------------------------------------------------------------------------
class DriverTestesIntegracao : public Drivers {
   private:
    const static int CAMADA_APRESENTACAO = 1;
    const static int SUBSISTEMA_AUTENTICACAO = 2;
    const static int SUBSISTEMA_DESENVOLVEDOR = 3;
    const static int SUBSISTEMA_TESTE = 4;
    const static int SUBSISTEMA_CASODETESTE = 5;
    const static int RETORNAR = 6;

   public:
    void executar();
};

#endif  // DRIVERS_H_INCLUDED
