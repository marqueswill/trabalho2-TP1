#include <locale.h>
#include <ncurses.h>

#include "../headers/comandos.h"
#include "../headers/controladoras_apresentacao.h"
#include "../headers/dominios.h"
#include "../headers/drivers.h"
#include "../headers/entidades.h"
#include "../headers/interfaces.h"
#include "../headers/stubs.h"
#include "../headers/telas.h"
#include "../headers/testes_modulos.h"
#include "comandos.cpp"
#include "controladoras_apresentacao.cpp"
#include "dominios.cpp"
#include "drivers.cpp"
#include "entidades.cpp"
#include "stubs.cpp"
#include "telas.cpp"
#include "testes_dominios.cpp"
#include "testes_entidades.cpp"
#include "testes_modulos.cpp"

// #define TESTE
#define SISTEMA
using namespace std;

int main() {
#ifdef TESTE

    DriverDepuracao driverDepuracao;
    driverDepuracao.executar();

#endif  // TESTE

#ifdef SISTEMA

#endif  // SISTEMA
    TUIATeste TUMAT;
    TUMAT.executar();

    return 0;
}
