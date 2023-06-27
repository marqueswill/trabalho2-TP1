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
    try {
        ComandoISVisualizarTeste comandoVisualizar(teste->getCodigo());
        comandoVisualizar.executar();
        *teste = comandoVisualizar.getResultado();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISTeste::cadastrar(Teste teste) {
    try {
        ComandoISLerCodigoTeste comandoLerCodigo(teste.getCodigo());
        comandoLerCodigo.executar();

        if (comandoLerCodigo.getResultado() != "NULL") {  // se matrícula já estiver cadastrada
            return false;
        }

        ComandoISCadastrarTeste comandoCadastrar(teste);
        comandoCadastrar.executar();

    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISTeste::editar(Teste teste) {
    try {
        ComandoISEditarTeste comandoEditar(teste);
        comandoEditar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISTeste::descadastrar(Codigo codigo) {
    try {
        ComandoISDescadastrarTeste comandoDescadastrar(codigo);
        comandoDescadastrar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------------------------
bool CtrlISCasoDeTeste::visualizar(CasoDeTeste *casoDeTeste) {
    try {
        ComandoISVisualizarCasoDeTeste comandoVisualizar(casoDeTeste->getCodigo());
        comandoVisualizar.executar();
        *casoDeTeste = comandoVisualizar.getResultado();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISCasoDeTeste::cadastrar(CasoDeTeste casoDeTeste) {
    try {
        ComandoISLerCodigoCasoDeTeste comandoLerCodigo(casoDeTeste.getCodigo());
        comandoLerCodigo.executar();

        if (comandoLerCodigo.getResultado() != "NULL") {  // se matrícula já estiver cadastrada
            return false;
        }

        ComandoISCadastrarCasoDeTeste comandoCadastrar(casoDeTeste);
        comandoCadastrar.executar();

    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISCasoDeTeste::editar(CasoDeTeste casoDeTeste) {
    try {
        ComandoISEditarCasoDeTeste comandoEditar(casoDeTeste);
        comandoEditar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISCasoDeTeste::descadastrar(Codigo codigo) {
    try {
        ComandoISDescadastrarCasoDeTeste comandoDescadastrar(codigo);
        comandoDescadastrar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}