#include <iostream>
#include <telas.h>
#include "controladoras.h"

#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED
;
class Comandos_Desenvolvedor{
    public:
    Texto nome;
    Matricula matricula;
    Telefone telefone;
    Senha senha;
    void Cadastrar_Desenvolvedor(Desenvolvedor*,string, string, string, string);
};
#endif  // COMANDOS_H_INCLUDED