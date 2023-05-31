#include <cstdlib>
#include <iostream>
#include <string>
#include <conio.h>
#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
using namespace std;
class Tela{
    public:
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Acessar sistema.";
    string texto3 = "2 - Cadastrar desenvolvedor.";
    string texto4 = "3 - Encerrar execução do sistema.";

    // Mensagens a serem apresentadas na tela de usuário logado.
    string texto5 = "Selecione um dos servicos : ";
    string texto6 = "1 - Selecionar serviços relacionados a desenvolvedor.";
    string texto7 = "2 - Selecionar serviços relacionados a teste.";
    string texto8 = "3 - Selecionar serviços relacionados a caso de teste.";
    string texto9 = "4 - Encerrar sessão.";

    string texto10 = "Falha na autenticacao. Digite algo para continuar.";
    int campo;                        // Campo de entrada.
    int linha, coluna; 
    bool apresentar = true;               // Dados sobre tamanho da tela.
};
class Tela_Inicial: public Tela{
    public:
    void selecionar_servicos_inicial();
    void falha_autenticacao();
    void selecionar_servicos_logado();
};

class Tela_Desenvolvedor: public Tela{
    public:
    void cadastrar_desenvolvedor();
    void falha_cadastro();
    void selecionar_servicos_desenvolvedor();
    void descadastrar_desenvolvedor();
};
