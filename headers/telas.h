#ifndef TELAS_H_INCLUDED
#define TELAS_H_INCLUDED

#include <stdlib.h>
#include <string.h>

#include "curses.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

class Telas {
   public:
    int linha, coluna;
    bool execucao = true;
};

class TelaMensagem : public Telas {
   public:
    void apresentar(string);
};

class TelaInicial : public Telas {
   public:
    void apresentar(int *campo);  // Método que retorna a opção escolhida.
};

class TelaUsuarioLogado : public Telas {
   public:
    void apresentar(int *campo);  // Método que retorna a opção escolhida.
};

class TelaAutenticacao : public Telas {
   private:
    string texto1 = "Falha na autenticacao. Digite algo para continuar.";

   public:
    void apresentar(Matricula *, Senha *);
};

class TelaDesenvolvedor : public Telas {
   public:
    void apresentar(Desenvolvedor *);
    void apresentar(int *campo);
};

#endif  // TELAS_H_INCLUDED