#include <iostream>
#include "interfaces.h"
using namespace std;

class cntrlIADesenvolvedor: public IADesenvolvedor{
private:
ISDesenvolvedor *cntrlISDesenvolvedor;
Matricula matricula;
public:
Matricula *matricula;
Desenvolvedor *desenvolvedor;
void Cadastrar() throw(runtime_error);
void Executar(Matricula);
~cntrlIADesenvolvedor();
};

class cntrlISDesenvolvedor: public ISDesenvolvedor{
public:
bool Cadastrar(Desenvolvedor);
bool Visualizar(Desenvolvedor *);
bool Editar(Desenvolvedor);
cntrlISDesenvolvedor();
};