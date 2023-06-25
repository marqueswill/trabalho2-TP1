#include "../headers/controladoras_servico.h"
#include "../headers/entidades.h"
#include "../headers/telas.h"
#include "comandos_servicos.cpp"
#include "telas.cpp"
using namespace std;

// //--------------------------------------------------------------------------------------------
// // Implementações dos métodos de classes controladoras da camada de serviço.


bool CtrlMSDesenvolvedor::visualizar(Desenvolvedor *desenvolvedor){
Matricula matricula = desenvolvedor->getMatricula();
try{
    ComandoVisualizarDesenvolvedor comandoVisualizar(matricula);
}

catch(EErroPersistencia exp){
    return false;
}

return true;
}

bool CtrlMSDesenvolvedor::cadastrar(Desenvolvedor desenvolvedor){

try{
ComandoCadastrarDesenvolvedor comandoCadastrar(desenvolvedor);
}

catch(EErroPersistencia exp){
    return false;
}

return true;
}

bool CtrlMSDesenvolvedor::editar(Desenvolvedor desenvolvedor){

try{
ComandoEditarDesenvolvedor comandoEditar(desenvolvedor);
}

catch(EErroPersistencia exp){
    return false;
}

return true;
}

bool CtrlMSDesenvolvedor::descadastrar(Matricula matricula){

try{
ComandoDescadastrarDesenvolvedor comandoDescadastrar(matricula);
}

catch(EErroPersistencia exp){
    return false;
}

return true;
}
//-----------------------------------------------------------------------------------------------
bool CtrlMSTeste::cadastrar(Teste teste){

}
bool CtrlMSTeste::editar(Teste teste){

}
bool CtrlMSTeste::visualizar(Teste *teste){

}
bool CtrlMSTeste::descadastrar(Codigo codigo){

}
//-----------------------------------------------------------------------------------------------
bool CtrlMSCasoDeTeste::cadastrar(CasoDeTeste casoDeTeste){

}
bool CtrlMSCasoDeTeste::editar(CasoDeTeste casoDeTeste){

}
bool CtrlMSCasoDeTeste::visualizar(CasoDeTeste *casoDeTeste){

}
bool CtrlMSCasoDeTeste::descadastrar(Codigo codigo){

}