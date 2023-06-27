#include "../headers/controladoras_servicos.h"

using namespace std;

//--------------------------------------------------------------------------------------------
bool CtrlISAutenticacao::autenticar(Matricula matricula, Senha senha) {
    ComandoISLerMatricula comandoLerMatricula(matricula);
    comandoLerMatricula.executar();

    if (comandoLerMatricula.getResultado() != matricula.getValor()) {
        return false;
    }

    ComandoISLerSenha comandoLerSenha(matricula);
    comandoLerSenha.executar();

    return (comandoLerSenha.getResultado() == senha.getValor());
}

//-----------------------------------------------------------------------------------------------
bool CtrlISDesenvolvedor::visualizar(Desenvolvedor *desenvolvedor) {
    try {
        ComandoISVisualizarDesenvolvedor comandoVisualizar(desenvolvedor->getMatricula());
        comandoVisualizar.executar();
        *desenvolvedor = comandoVisualizar.getResultado();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISDesenvolvedor::cadastrar(Desenvolvedor desenvolvedor) {
    try {
        ComandoISLerMatricula comandoLerMatricula(desenvolvedor.getMatricula());
        comandoLerMatricula.executar();

        if (comandoLerMatricula.getResultado() != "NULL") {  // se matrícula já estiver cadastrada
            return false;
        }

        ComandoISCadastrarDesenvolvedor comandoCadastrar(desenvolvedor);
        comandoCadastrar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISDesenvolvedor::editar(Desenvolvedor desenvolvedor) {
    try {
        ComandoISEditarDesenvolvedor comandoEditar(desenvolvedor);
        comandoEditar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISDesenvolvedor::descadastrar(Matricula matricula) {
    try {
        ComandoISDescadastrarDesenvolvedor comandoDescadastrar(matricula);
        comandoDescadastrar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}
//-----------------------------------------------------------------------------------------------
bool CtrlISTeste::visualizar(Teste *teste) {
}
bool CtrlISTeste::cadastrar(Teste teste) {
}
bool CtrlISTeste::editar(Teste teste) {
}
bool CtrlISTeste::descadastrar(Codigo codigo) {
}
//-----------------------------------------------------------------------------------------------
bool CtrlISCasoDeTeste::visualizar(CasoDeTeste *casoDeTeste) {
}
bool CtrlISCasoDeTeste::cadastrar(CasoDeTeste casoDeTeste) {
}
bool CtrlISCasoDeTeste::editar(CasoDeTeste casoDeTeste) {
}
bool CtrlISCasoDeTeste::descadastrar(Codigo codigo) {
}