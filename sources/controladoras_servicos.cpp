#include "../headers/controladoras_servicos.h"

using namespace std;

//--------------------------------------------------------------------------------------------
bool CtrlISAutenticacao::autenticar(Matricula matricula, Senha senha) {
    ComandoSQLLerMatricula comandoLerMatricula(matricula);
    comandoLerMatricula.executar();

    if (comandoLerMatricula.getResultado() != matricula.getValor()) {  // se não achar matricula informada
        return false;
    }

    ComandoSQLLerSenha comandoLerSenha(matricula);
    comandoLerSenha.executar();

    return (comandoLerSenha.getResultado() == senha.getValor());
}

//-----------------------------------------------------------------------------------------------
bool CtrlISDesenvolvedor::visualizar(Desenvolvedor *desenvolvedor) {
    try {
        ComandoSQLVisualizarDesenvolvedor comandoVisualizar(desenvolvedor->getMatricula());
        comandoVisualizar.executar();
        *desenvolvedor = comandoVisualizar.getResultado();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISDesenvolvedor::cadastrar(Desenvolvedor desenvolvedor) {
    try {
        ComandoSQLLerMatricula comandoLerMatricula(desenvolvedor.getMatricula());
        comandoLerMatricula.executar();

        if (comandoLerMatricula.getResultado() != "NULL") {  // se matrícula já estiver cadastrada
            return false;
        }

        ComandoSQLCadastrarDesenvolvedor comandoCadastrar(desenvolvedor);
        comandoCadastrar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISDesenvolvedor::editar(Desenvolvedor desenvolvedor) {
    try {
        ComandoSQLEditarDesenvolvedor comandoEditar(desenvolvedor);
        comandoEditar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISDesenvolvedor::descadastrar(Matricula matricula) {
    try {
        ComandoSQLDescadastrarDesenvolvedor comandoDescadastrar(matricula);
        comandoDescadastrar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}
//-----------------------------------------------------------------------------------------------
bool CtrlISTeste::visualizar(Teste *teste) {
    try {
        ComandoSQLVisualizarTeste comandoVisualizar(teste->getCodigo());
        comandoVisualizar.executar();
        *teste = comandoVisualizar.getResultado();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISTeste::cadastrar(Teste teste) {
    try {
        ComandoSQLLerCodigoTeste comandoLerCodigo(teste.getCodigo());
        comandoLerCodigo.executar();

        if (comandoLerCodigo.getResultado() != "NULL") {  // se matrícula já estiver cadastrada
            return false;
        }

        ComandoSQLCadastrarTeste comandoCadastrar(teste);
        comandoCadastrar.executar();

    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISTeste::editar(Teste teste) {
    try {
        ComandoSQLEditarTeste comandoEditar(teste);
        comandoEditar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISTeste::descadastrar(Codigo codigo) {
    try {
        ComandoSQLDescadastrarTeste comandoDescadastrar(codigo);
        comandoDescadastrar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------------------------
bool CtrlISCasoDeTeste::visualizar(CasoDeTeste *casoDeTeste) {
    try {
        ComandoSQLVisualizarCasoDeTeste comandoVisualizar(casoDeTeste->getCodigo());
        comandoVisualizar.executar();
        *casoDeTeste = comandoVisualizar.getResultado();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISCasoDeTeste::cadastrar(CasoDeTeste casoDeTeste) {
    try {
        ComandoSQLLerCodigoCasoDeTeste comandoLerCodigo(casoDeTeste.getCodigo());
        comandoLerCodigo.executar();

        if (comandoLerCodigo.getResultado() != "NULL") {  // se matrícula já estiver cadastrada
            return false;
        }

        ComandoSQLCadastrarCasoDeTeste comandoCadastrar(casoDeTeste);
        comandoCadastrar.executar();

    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISCasoDeTeste::editar(CasoDeTeste casoDeTeste) {
    try {
        ComandoSQLEditarCasoDeTeste comandoEditar(casoDeTeste);
        comandoEditar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISCasoDeTeste::descadastrar(Codigo codigo) {
    try {
        ComandoSQLDescadastrarCasoDeTeste comandoDescadastrar(codigo);
        comandoDescadastrar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}