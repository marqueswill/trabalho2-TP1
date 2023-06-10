// #include "../headers/controladoras_servico.h"

#include "../headers/entidades.h"
#include "../headers/telas.h"
#include "..\headers\comandos.h"
#include "UnidadePersistencia.cpp"
#include "telas.cpp"
#include "..\headers\controladoras_servico.h"
using namespace std;
bool CtrlMSDesenvolvedor::descadastrar(Matricula matricula){
ComandoDescadastrarDesenvolvedor comando(matricula);

try{
    comando.executar();
}
catch(EErroPersistencia exp){
    TelaMsg.apresentar("Houve erro de acesso ao banco de dados. Tente novamente");
}
TelaMsg.apresentar("A operação foi efetuada com sucesso. Tecle algo");
}

// //--------------------------------------------------------------------------------------------
// // Implementações dos métodos de classes controladoras da camada de serviço.