#include "comandos_apresentacao.h"

//----------------------------------------------------------------------------------------------------------------------
bool ComandoIAAutenticacaoAutenticar::executar(ISAutenticacao* ctrlISAutenticacao) {
    telaAutenticacao.autenticar(matricula, &senha);
    Matricula login = *matricula;
    resultado = ctrlISAutenticacao->autenticar(login, senha);
    return resultado;
}

//----------------------------------------------------------------------------------------------------------------------
void ComandoIADesenvolvedorVisualizar::executar(ISDesenvolvedor* ctrlISDesenvolvedor) {
    desenvolvedor.setMatricula(matricula);  // Já tem a matricula, desenvolvedor só pode visualizar os próprios dados
    resultado = ctrlISDesenvolvedor->visualizar(&desenvolvedor);
    if (resultado) {
        telaDesenvolvedor.mostrar(desenvolvedor);
    } else {
        telaMensagem.apresentar("Desenvolvedor informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIADesenvolvedorCadastrar::executar(ISDesenvolvedor* ctrlISDesenvolvedor) {
    telaDesenvolvedor.cadastrar(&desenvolvedor);
    resultado = ctrlISDesenvolvedor->cadastrar(desenvolvedor);
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Nao foi possível cadastrar desenvolvedor. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIADesenvolvedorEditar::executar(ISDesenvolvedor* ctrlISDesenvolvedor) {
    telaDesenvolvedor.editar(&desenvolvedor);
    desenvolvedor.setMatricula(matricula);
    resultado = ctrlISDesenvolvedor->editar(desenvolvedor);
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Nao foi possivel editar dados de desenvolvedor. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIADesenvolvedorDescadastrar::executar(ISDesenvolvedor* ctrlISDesenvolvedor) {
    Matricula matriculaConfirmacao;
    telaDesenvolvedor.descadastrar(&matriculaConfirmacao);
    if (matriculaConfirmacao.getValor() == matricula.getValor()) {
        resultado = ctrlISDesenvolvedor->descadastrar(matricula);
        if (resultado) {
            telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
        } else {
            telaMensagem.apresentar("Não foi possível descadastrar desenvolvedor. Pressione qualquer tecla para continuar.");
        }
    } else {
        telaMensagem.apresentar("Informe apenas matricula do desenvolvedor logado. Pressione qualquer tecla para continuar.");
    }
}

//----------------------------------------------------------------------------------------------------------------------
void ComandoIATesteVisualizar::executar(ISTeste* ctrlISTeste) {
    telaTeste.visualizar(&teste);                 // Pede o código do teste ao usuário.
    resultado = ctrlISTeste->visualizar(&teste);  // Pesquisa no banco de dados e coloca os valores.
    if (resultado) {
        telaTeste.mostrar(teste);  // Mostra os valores.
    } else {
        telaMensagem.apresentar("Teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIATesteCadastrar::executar(ISTeste* ctrlISTeste) {
    telaTeste.cadastrar(&teste);                // Solicita dados do teste ao usuário. .
    resultado = ctrlISTeste->cadastrar(teste);  // Registra no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Teste cadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Não foi possível cadastrar teste. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIATesteEditar::executar(ISTeste* ctrlISTeste) {
    telaTeste.visualizar(&teste);                 // Obtém código do teste que será editado
    resultado = ctrlISTeste->visualizar(&teste);  // Verifica se está no banco de dados e coloca os valores.

    if (resultado) {
        telaTeste.editar(&teste);  // Solicita novos dados ao usuário.

        if (ctrlISTeste->editar(teste)) {                 // Substitui novas informaçoes no banco de dados.
            resultado = ctrlISTeste->visualizar(&teste);  // Pesquisa no banco de dados e coloca os valores.
        } else {
            telaMensagem.apresentar("Não foi possível editar teste. Pressione qualquer tecla para continuar.");
        }
    } else {
        telaMensagem.apresentar("Teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIATesteDescadastrar::executar(ISTeste* ctrlISTeste) {
    telaTeste.descadastrar(&codigo);                // Pede o código do teste ao usuário.
    resultado = ctrlISTeste->descadastrar(codigo);  // Socilita descadastramento do banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Teste descadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

//----------------------------------------------------------------------------------------------------------------------
void ComandoIACasoDeTesteVisualizar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    telaCasoDeTeste.visualizar(&casoDeTeste);                 // Pede o código do teste ao usuário.
    resultado = ctrlISCasoDeTeste->visualizar(&casoDeTeste);  // Pesquisa no banco de dados e coloca os valores.
    if (resultado) {
        telaCasoDeTeste.mostrar(casoDeTeste);  // Mostra os valores.
    } else {
        telaMensagem.apresentar("Caso de teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIACasoDeTesteCadastrar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    telaCasoDeTeste.cadastrar(&casoDeTeste);                // Solicita dados do teste ao usuário. .
    resultado = ctrlISCasoDeTeste->cadastrar(casoDeTeste);  // Registra no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Caso de teste cadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Não foi possível cadastrar caso de teste. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIACasoDeTesteEditar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    telaCasoDeTeste.visualizar(&casoDeTeste);                 // Obtém código do teste que será editado
    resultado = ctrlISCasoDeTeste->visualizar(&casoDeTeste);  // Verifica se está no banco de dados e coloca os valores.

    if (resultado) {
        telaCasoDeTeste.editar(&casoDeTeste);  // Solicita novos dados ao usuário.

        if (ctrlISCasoDeTeste->editar(casoDeTeste)) {                 // Substitui novas informaçoes no banco de dados.
            resultado = ctrlISCasoDeTeste->visualizar(&casoDeTeste);  // Pesquisa no banco de dados e coloca os valores.
        } else {
            telaMensagem.apresentar("Não foi possível editar caso de teste. Pressione qualquer tecla para continuar.");
        }
    } else {
        telaMensagem.apresentar("Caso de teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIACasoDeTesteDescadastrar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    telaCasoDeTeste.descadastrar(&codigo);                // Pede o código do teste ao usuário.
    resultado = ctrlISCasoDeTeste->descadastrar(codigo);  // Socilita descadastramento do banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Caso de teste descadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Caso de teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}
