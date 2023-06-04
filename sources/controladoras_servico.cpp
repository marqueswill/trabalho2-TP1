#include "../headers/controladoras_servico.h"
#include "UnidadePersistencia.cpp"
#include "../headers/entidades.h"
#include "../headers/telas.h"
#include "telas.cpp"
using namespace std;
bool CtrlMSDesenvolvedor::descadastrar(Matricula){
Matricula matricula;
Tela_Servico_Desenvolvedor TelaSd;
TelaSd.descadastrar(*matricula);
ComandoDescadastrarDesenvolvedor comando(matricula);

try{
    comando.executar();
}
catch(EErroPersistencia exp){
     char texto3[] = "Houve erro de acesso ao banco de dados. Tente novamente";
     TelaSd.apresentar(texto3);
    clear();
    mvprintw(linha/4,coluna/4,"%s", texto3);
    return;
}

char texto4[] = "A operação foi efetuada com sucesso. Tecle algo";
clear();
mvprintw(linha/4,coluna/4,"%s", texto);

noecho();
getch();
echo();
}

//--------------------------------------------------------------------------------------------
// Implementações dos métodos de classes controladoras da camada de serviço.
