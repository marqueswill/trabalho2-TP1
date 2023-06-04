#include "../headers/controladoras_servico.h"
#include "UnidadePersistencia.cpp"
#include "../headers/entidades.h"
#include "../headers/telas.h"
#include "telas.cpp"
using namespace std;
bool CtrlMSDesenvolvedor::descadastrar(Matricula){
Matricula *matricula;
matricula = new Matricula();
Tela_Servico_Desenvolvedor TelaSd;
TelaMensagem TelaMsg;
TelaSd.descadastrar(matricula);
Matricula registernumber = *matricula;
ComandoDescadastrarDesenvolvedor comando(registernumber);

try{
    comando.executar();
}
catch(EErroPersistencia exp){
     char texto3[] = "Houve erro de acesso ao banco de dados. Tente novamente";
     TelaMsg.apresentar(texto3);
}

char texto4[] = "A operação foi efetuada com sucesso. Tecle algo";
TelaMsg.apresentar(texto4);
delete matricula;
}

//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes controladoras da camada de serviço.
