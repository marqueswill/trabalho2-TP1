#include "comandos_apresentacao.h"
#include "comandos_servicos.h"
#include "controladoras_apresentacao.h"
#include "controladoras_servicos.h"
#include "dominios.h"
#include "drivers.h"
#include "entidades.h"
#include "interfaces.h"
#include "telas.h"
#include "testes_dominios.h"
#include "testes_entidades.h"
#include "testes_integracao.h"
#include "testes_modulos.h"
#include "builders.h"
// #define TESTE
#include "sqlite3.h"
using namespace std;

int main() {
    BuilderSistema *builder;
    builder = new BuilderSistema();

    CtrlIAInicializacao *ctrlIAInicializao;
    ctrlIAInicializao = builder->construir();

    ctrlIAInicializao->executar();

    delete builder;
    return EXIT_SUCCESS;

}

