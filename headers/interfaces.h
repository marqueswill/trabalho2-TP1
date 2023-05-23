#include "dominios.h"
#include "entidades.h"
//Declaração das Interfaces
using namespace std;
class IADesenvolvedor
{
    public:
    virtual void Cadastrar() throw(runtime_error) = 0;
    virtual void Descadastrar(Desenvolvedor) throw(runtime_error) = 0;
    virtual void Visualizar(Desenvolvedor) throw(runtime_error) = 0;
    virtual void Editar(Desenvolvedor) throw(runtime_error) = 0;
    virtual ~IADesenvolvedor(){}
};
