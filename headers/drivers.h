#ifndef DRIVERS_H_INCLUDED
#define DRIVERS_H_INCLUDED

#include <ncurses.h>

#include "dominios.h"
#include "entidades.h"
#include "testes_dominios.h"
#include "testes_entidades.h"

/* Em teoria aqui deveriam ficar os testes dos módulos, mas meu plano
é criar drivers que executem os testes. Ex: driverTestesDominios, driverTestesEntidades,
driverTestesApresentacao, driverTestesIntegracao
 */
class Drivers {
   public:
    void showResult(bool, string);
    virtual void executar() = 0;
};

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

class DriverTestesEntidades : public Drivers {
   private:
    TUDesenvolvedor testeDesenvolvedor;
    TUTeste testeTeste;
    TUCasoDeTeste testeCasoDeTeste;

   public:
    void executar();
};

#endif  // DRIVERS_H_INCLUDED
