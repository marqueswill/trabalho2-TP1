#include "../headers/controladoras_servicos.h"

using namespace std;

//--------------------------------------------------------------------------------------------
bool CtrlISAutenticacao::autenticar(Matricula matricula, Senha senha) {
    ComandoLerMatricula lerMatricula(matricula);
    if (lerMatricula.getResultado() == matricula.getValor()) {
        ComandoLerSenha lerSenha(matricula);
        if (lerSenha.getResultado() == senha.getValor()) {
            return true;
        }
    }

    return false;
}

//-----------------------------------------------------------------------------------------------
bool CtrlISDesenvolvedor::cadastrar(Desenvolvedor desenvolvedor) {
    ComandoLerMatricula lerMatricula(desenvolvedor.getMatricula());
    if (lerMatricula.getResultado() == "") {
        return false;
    } else {
        ComandoCadastrarDesenvolvedor comandoCadastrar(desenvolvedor);
        return true;
    }

    return false;
}

bool CtrlISDesenvolvedor::visualizar(Desenvolvedor *desenvolvedor) {
    Matricula matricula = desenvolvedor->getMatricula();

    ComandoVisualizarDesenvolvedor comandoVisualizar(matricula);
    try {
        comandoVisualizar.executar();
        desenvolvedor = &comandoVisualizar.getResultado();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISDesenvolvedor::editar(Desenvolvedor desenvolvedor) {
    try {
        ComandoEditarDesenvolvedor comandoEditar(desenvolvedor);
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISDesenvolvedor::descadastrar(Matricula matricula) {
    try {
        ComandoDescadastrarDesenvolvedor comandoDescadastrar(matricula);
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}
//-----------------------------------------------------------------------------------------------
bool CtrlISTeste::cadastrar(Teste teste) {
}
bool CtrlISTeste::editar(Teste teste) {
}
bool CtrlISTeste::visualizar(Teste *teste) {
}
bool CtrlISTeste::descadastrar(Codigo codigo) {
}
//-----------------------------------------------------------------------------------------------
bool CtrlISCasoDeTeste::cadastrar(CasoDeTeste casoDeTeste) {
}
bool CtrlISCasoDeTeste::editar(CasoDeTeste casoDeTeste) {
}
bool CtrlISCasoDeTeste::visualizar(CasoDeTeste *casoDeTeste) {
}
bool CtrlISCasoDeTeste::descadastrar(Codigo codigo) {
}