#ifndef CONTROLADORAS_APRESENTACAO_H_INCLUDED
#define CONTROLADORAS_APRESENTACAO_H_INCLUDED

#include <string>

#include "comandos.h"
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "telas.h"

// Declarações de classes controladoras da camada de apresentação e implementações de métodos inline.
//-----------------------------------------------------------------------------------
class CtrlIAInicializacao {
   private:
    IAAutenticacao *ctrlIAAutenticacao;
    IADesenvolvedor *ctrlIADesenvolvedor;
    IATeste *ctrlIATeste;
    IACasoDeTeste *ctrlIACasoDeTeste;

    const static int AUTENTICAR = 1;
    const static int CADASTRAR = 2;
    const static int SAIR = 3;

    const static int DESENVOLVEDOR = 1;
    const static int TESTE = 2;
    const static int CASODETESTE = 3;
    const static int VOLTAR = 4;

   public:
    void executar();
    void setCtrlIAAutenticacao(IAAutenticacao *);
    void setCtrlIADesenvolvedor(IADesenvolvedor *);
    void setCtrlIATeste(IATeste *);
    void setCtrlIACasoDeTeste(IACasoDeTeste *);
};

inline void CtrlIAInicializacao::setCtrlIAAutenticacao(IAAutenticacao *ctrlIAAutenticacao) {
    this->ctrlIAAutenticacao = ctrlIAAutenticacao;
}

inline void CtrlIAInicializacao::setCtrlIADesenvolvedor(IADesenvolvedor *ctrlIADesenvolvedor) {
    this->ctrlIADesenvolvedor = ctrlIADesenvolvedor;
}

inline void CtrlIAInicializacao::setCtrlIATeste(IATeste *ctrlIATeste) {
    this->ctrlIATeste = ctrlIATeste;
}

inline void CtrlIAInicializacao::setCtrlIACasoDeTeste(IACasoDeTeste *ctrlIACasoDeTeste) {
    this->ctrlIACasoDeTeste = ctrlIACasoDeTeste;
}

//-----------------------------------------------------------------------------------

class CtrlIAAutenticacao : public IAAutenticacao {
   private:
    ISAutenticacao *ctrlISAutenticacao;

   public:
    bool autenticar(Matricula *);
};

//-----------------------------------------------------------------------------------
class CtrlIADesenvolvedor : public IADesenvolvedor {
   private:
    const static int CADASTRAR = 8;
    const static int EDITAR = 2;
    const static int VISUALIZAR = 1;
    const static int DESCADASTRAR = 3;
    const static int RETORNAR = 4;

    ISDesenvolvedor *ctrlISDesenvolvedor;
    CmdIADesenvolvedor *comando;

   public:
    void setCtrlISDesenvolvedor(ISDesenvolvedor *);
    void cadastrar();
    void executar(Matricula);
};

inline void CtrlIADesenvolvedor::setCtrlISDesenvolvedor(ISDesenvolvedor *ctrlISDesenvolvedor) {
    this->ctrlISDesenvolvedor = ctrlISDesenvolvedor;
}

//-----------------------------------------------------------------------------------
class CtrlIATeste : public IATeste {
   private:
    const static int VISUALIZAR = 1;
    const static int CADASTRAR = 2;
    const static int EDITAR = 3;
    const static int DESCADASTRAR = 4;
    const static int RETORNAR = 5;

    ISTeste *ctrlISTeste;
    CmdIATeste *comando;

   public:
    void executar(Matricula);
    void setCtrlISTeste(ISTeste *);
};

inline void CtrlIATeste::setCtrlISTeste(ISTeste *ctrlISTeste) {
    this->ctrlISTeste = ctrlISTeste;
}

//-----------------------------------------------------------------------------------
class CtrlIACasoDeTeste : public IACasoDeTeste {
   private:
    const static int VISUALIZAR = 1;
    const static int CADASTRAR = 2;
    const static int EDITAR = 3;
    const static int DESCADASTRAR = 4;
    const static int RETORNAR = 5;

    ISCasoDeTeste *ctrlISCasoDeTeste;
    CmdIACasoDeTeste *comando;

   public:
    void executar(Matricula);
    void setCtrlISCasoDeTeste(ISCasoDeTeste *);
};

inline void CtrlIACasoDeTeste::setCtrlISCasoDeTeste(ISCasoDeTeste *ctrlISCasoDeTeste) {
    this->ctrlISCasoDeTeste = ctrlISCasoDeTeste;
}

#endif  // CONTROLADORAS_APRESENTACAO_H_INCLUDED