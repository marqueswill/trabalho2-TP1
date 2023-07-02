#include "controladoras_servicos.h"

using namespace std;
//--------------------------------------------------------------------------------------------
bool CtrlISAutenticacao::autenticar(Matricula matricula, Senha senha) {
    ComandoSQLLerMatricula comandoLerMatricula(matricula);
    comandoLerMatricula.executar();
    if (comandoLerMatricula.getResultado() != matricula.getValor()) {
        // se não achar matricula informada
        return false;
    }

    ComandoSQLLerSenha comandoLerSenha(matricula);
    comandoLerSenha.executar();

    return (comandoLerSenha.getResultado() == senha.getValor());
}

//----------------------------------------------------------------------------------------------------------------------
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

        if (comandoLerMatricula.getResultado() != "NULL") {
            // se matrícula já estiver cadastrada
            return false;
        }
        if (
            desenvolvedor.getMatricula().getValor().empty() or
            desenvolvedor.getNome().getValor().empty() or
            desenvolvedor.getSenha().getValor().empty() or
            desenvolvedor.getTelefone().getValor().empty()) {
            return false;
        }

        ComandoSQLCadastrarDesenvolvedor comandoCadastrar(desenvolvedor);
        comandoCadastrar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }
    //
    return true;
}

bool CtrlISDesenvolvedor::editar(Desenvolvedor desenvolvedor) {
    try {
        if (
            desenvolvedor.getMatricula().getValor().empty() or
            desenvolvedor.getNome().getValor().empty() or
            desenvolvedor.getSenha().getValor().empty() or
            desenvolvedor.getTelefone().getValor().empty()) {
            return false;
        }
        ComandoSQLEditarDesenvolvedor comandoEditar(desenvolvedor);
        comandoEditar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISDesenvolvedor::descadastrar(Matricula matricula) {
    try {
        ComandoSQLContarTeste contarTeste(matricula);
        ComandoSQLContarCasoDeTeste contarCasoDeTeste(matricula);
        ComandoSQLDescadastrarDesenvolvedor comandoDescadastrar(matricula);
        ComandoSQLDeletarTeste deletarTeste(matricula);
        ComandoSQLDeletarCasoDeTeste deletarCasoDeTeste(matricula);
        contarTeste.executar();
        if (contarTeste.getResultado() > 0) {
            contarCasoDeTeste.executar();
            if (contarCasoDeTeste.getResultado() > 0) {
                deletarCasoDeTeste.executar();
            }
            deletarTeste.executar();
            comandoDescadastrar.executar();
        } else {
            comandoDescadastrar.executar();
        }
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}
//----------------------------------------------------------------------------------------------------------------------
bool CtrlISTeste::visualizar(Teste *teste) {
    try {
        ComandoSQLLerCodigoTeste lerCodigo(teste->getCodigo());
        lerCodigo.executar();
        if (lerCodigo.getResultado() == "NULL") {
            return false;
        }
        Matricula matricula_confirmacao = teste->getMatricula();
        ComandoSQLAutenticarTeste autenticarTeste(matricula_confirmacao);
        autenticarTeste.executar();
        list<string> testes = autenticarTeste.getResultado();
        if (testes.empty()) {
            return false;
        }
        string codigo;
        bool erro = true;
        while (!testes.empty()) {
            codigo = testes.back();
            testes.pop_back();
            Codigo codigoteste = teste->getCodigo();
            if (codigo == codigoteste.getValor()) {
                erro = false;
                break;
            }
        }
        if (erro) {
            return false;
        }

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
        if (
            teste.getClasse().getValor().empty() or
            teste.getNome().getValor().empty() or
            teste.getMatricula().getValor().empty() or
            teste.getCodigo().getValor().empty()) {
            return false;
        }
        ComandoSQLLerCodigoTeste comandoLerCodigo(teste.getCodigo());
        comandoLerCodigo.executar();
        if (comandoLerCodigo.getResultado() != "NULL") {
            // se não achar codigo informado
            return false;
        }
        ComandoSQLCadastrarTeste comandoCadastrarTeste(teste);
        comandoCadastrarTeste.executar();

    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISTeste::editar(Teste teste) {
    try {
        if (
            teste.getClasse().getValor().empty() or
            teste.getNome().getValor().empty() or
            teste.getMatricula().getValor().empty() or
            teste.getCodigo().getValor().empty()) {
            return false;
        }
        ComandoSQLLerCodigoTeste lerCodigo(teste.getCodigo());
        lerCodigo.executar();
        if (lerCodigo.getResultado() == "NULL") {
            return false;
        }

        ComandoSQLEditarTeste comandoEditar(teste);
        comandoEditar.executar();
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

bool CtrlISTeste::descadastrar(Codigo codigo) {
    try {
        ComandoSQLContarCasoDeTeste contarCasoDeTeste(codigo);
        ComandoSQLDescadastrarTeste comandoDescadastrar(codigo);
        ComandoSQLDeletarCasoDeTeste deletarCasoDeTeste(codigo);
        contarCasoDeTeste.executar();
        if (contarCasoDeTeste.getResultado() > 0) {
            deletarCasoDeTeste.executar();
            comandoDescadastrar.executar();
        } else {
            comandoDescadastrar.executar();
        }
    } catch (EErroPersistencia &exp) {
        return false;
    }

    return true;
}

//----------------------------------------------------------------------------------------------------------------------
bool CtrlISCasoDeTeste::visualizar(CasoDeTeste *casoDeTeste) {
    try {
        ComandoSQLLerCodigoCasoDeTeste lerCodigo(casoDeTeste->getCodigo());
        lerCodigo.executar();
        if (lerCodigo.getResultado() == "NULL") {
            return false;
        }
        ComandoSQLAutenticarCasoDeTeste autenticar(casoDeTeste->getMatricula());
        autenticar.executar();
        list<string> casotestes = autenticar.getResultado();
        if (casotestes.empty()) {
            return false;
        }
        string codigo;
        bool erro = true;
        while (!casotestes.empty()) {
            codigo = casotestes.back();
            casotestes.pop_back();
            Codigo codigoteste = casoDeTeste->getCodigo();
            if (codigo == codigoteste.getValor()) {
                erro = false;
                break;
            }
        }
        if (erro) {
            return false;
        }
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
        if (
            casoDeTeste.getAcao().getValor().empty() or
            casoDeTeste.getNome().getValor().empty() or
            casoDeTeste.getMatricula().getValor().empty() or
            casoDeTeste.getCodigo().getValor().empty() or
            casoDeTeste.getData().getValor().empty() or
            casoDeTeste.getCodigoTestes().getValor().empty() or
            casoDeTeste.getResposta().getValor().empty() or
            casoDeTeste.getResultado().getValor().empty()) {
            return false;
        }
        ComandoSQLLerCodigoCasoDeTeste lerCodigo(casoDeTeste.getCodigo());
        ComandoSQLAutenticarTeste autenticarTeste(casoDeTeste.getMatricula());
        ComandoSQLContarCasoDeTeste comandoSQLContarCasoDeTeste(casoDeTeste.getCodigoTestes());
        autenticarTeste.executar();
        list<string> testes = autenticarTeste.getResultado();
        if (testes.empty()) {
            return false;
        }
        string codigo;
        bool erro = true;
        while (!testes.empty()) {
            codigo = testes.back();
            testes.pop_back();
            if (codigo == casoDeTeste.getCodigoTestes().getValor()) {
                erro = false;
                break;
            }
        }
        if (erro) {
            return false;
        }
        comandoSQLContarCasoDeTeste.executar();
        int contagem = comandoSQLContarCasoDeTeste.getResultado();
        if (contagem > 9) {
            return false;
        }
        lerCodigo.executar();
        if (lerCodigo.getResultado() != "NULL") {
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
        ComandoSQLLerCodigoCasoDeTeste lerCodigo(casoDeTeste.getCodigo());
        lerCodigo.executar();
        if (lerCodigo.getResultado() == "NULL") {
            return false;
        }

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
