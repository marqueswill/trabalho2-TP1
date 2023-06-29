#include "comandos_apresentacao.h"
#include "comandos_servicos.h"
#include "controladoras_apresentacao.h"
#include "controladoras_servicos.h"
#include "dominios.h"
#include "drivers.h"
#include "entidades.h"
#include "interfaces.h"
#include "stubs.h"
#include "telas.h"
#include "testes_dominios.h"
#include "testes_entidades.h"
#include "testes_integracao.h"
#include "testes_modulos.h"
#include "sqlite3.h"
#define TESTE
// #define SISTEMA
using namespace std;

int main(int argc, char *argv[]) {
#ifdef TESTE

    DriverDepuracao driverDepuracao;
    driverDepuracao.executar();

#endif  // TESTE

//----------------------------------------------------------------------------------------------------------------------
#ifdef SISTEMA

#endif  // SISTEMA

    return EXIT_SUCCESS;
}
