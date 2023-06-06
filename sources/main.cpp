#include <locale.h>

#include "../headers/drivers.h"
#include "dominios.cpp"
#include "drivers.cpp"
#include "entidades.cpp"
#include "telas.cpp"
#include "testes_dominios.cpp"
#include "testes_entidades.cpp"

#define TESTE

using namespace std;

int main() {
#ifdef TESTE

    DriverDepuracao driverDepuracao;
    driverDepuracao.executar();

#endif  // TESTE

    return 0;
}
