#include "dominios.h"
#include "entidades.h"
//Declaração das Interfaces
using namespace std;
class IADesenvolvedor{
    public:
    virtual void Cadastrar() throw(runtime_error) = 0;
    virtual void Executar(Matricula) = 0;
    virtual ~IADesenvolvedor(){}
};
class ISDesenvolvedor
{
    public:
    virtual bool Cadastrar_(Desenvolvedor) throw(runtime_error) = 0;
    virtual bool Descadastrar(Matricula) throw(runtime_error) = 0;
    virtual bool Visualizar(Desenvolvedor *) throw(runtime_error) = 0;
    virtual bool Editar(Desenvolvedor) throw(runtime_error) = 0;
    virtual ~ISDesenvolvedor(){}
};
