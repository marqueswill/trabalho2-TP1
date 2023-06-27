#include "../headers/comandos_apresentacao.h"
#include "../headers/comandos_servicos.h"
#include "../headers/controladoras_apresentacao.h"
#include "../headers/controladoras_servicos.h"
#include "../headers/dominios.h"
#include "../headers/drivers.h"
#include "../headers/entidades.h"
#include "../headers/interfaces.h"
#include "../headers/stubs.h"
#include "../headers/telas.h"
#include "../headers/testes_dominios.h"
#include "../headers/testes_entidades.h"
#include "../headers/testes_integracao.h"
#include "../headers/testes_modulos.h"
#include "comandos_apresentacao.cpp"
#include "comandos_servicos.cpp"
#include "controladoras_apresentacao.cpp"
#include "controladoras_servicos.cpp"
#include "dominios.cpp"
#include "drivers.cpp"
#include "stubs.cpp"
#include "telas.cpp"
#include "testes_dominios.cpp"
#include "testes_entidades.cpp"
#include "testes_integracao.cpp"
#include "testes_modulos.cpp"
#define TESTE
// #define SISTEMA
using namespace std;

int main() {
#ifdef TESTE

    DriverDepuracao driverDepuracao;
    driverDepuracao.executar();

#endif  // TESTE

//----------------------------------------------------------------------------------------------------------------------
#ifdef SISTEMA

#endif  // SISTEMA

    return 0;
}
