#include "../headers/comandos_apresentacao.h"

//--------------------------------------------------------------------------------------------
void CmdIADesenvolvedorVisualizar::executar(ISDesenvolvedor* ctrlISDesenvolvedor) {
    telaDesenvolvedor.visualizar(&desenvolvedor);
    resultado = ctrlISDesenvolvedor->visualizar(&desenvolvedor);
    if (resultado) {
        telaDesenvolvedor.mostrar(desenvolvedor);
    } else {
        telaMensagem.apresentar("Desenvolvedor informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void CmdIADesenvolvedorCadastrar::executar(ISDesenvolvedor* ctrlISDesenvolvedor) {
    telaDesenvolvedor.cadastrar(&desenvolvedor);
    resultado = ctrlISDesenvolvedor->cadastrar(desenvolvedor);
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Desenvolvedor informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void CmdIADesenvolvedorEditar::executar(ISDesenvolvedor* ctrlISDesenvolvedor) {
    telaDesenvolvedor.editar(&desenvolvedor);
    desenvolvedor.setMatricula(matricula);
    resultado = ctrlISDesenvolvedor->editar(desenvolvedor);
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Desenvolvedor informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void CmdIADesenvolvedorDescadastrar::executar(ISDesenvolvedor* ctrlISDesenvolvedor) {
    telaDesenvolvedor.descadastrar(&matricula);
    desenvolvedor.setMatricula(matricula);
    resultado = ctrlISDesenvolvedor->descadastrar(matricula);
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Desenvolvedor informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

//--------------------------------------------------------------------------------------------
void CmdIATesteVisualizar::executar(ISTeste* ctrlISTeste) {
    telaTeste.visualizar(&teste);                 // Pede o código do teste ao usuário.
    resultado = ctrlISTeste->visualizar(&teste);  // Pesquisa no banco de dados e coloca os valores.
    if (resultado) {
        telaTeste.mostrar(teste);  // Mostra os valores.
    } else {
        telaMensagem.apresentar("Teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void CmdIATesteCadastrar::executar(ISTeste* ctrlISTeste) {
    telaTeste.cadastrar(&teste);                // Solicita dados do teste ao usuário. .
    resultado = ctrlISTeste->cadastrar(teste);  // Registra no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Teste cadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Não foi possível cadastrar teste. Pressione qualquer tecla para continuar.");
    }
}

void CmdIATesteEditar::executar(ISTeste* ctrlISTeste) {
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

void CmdIATesteDescadastrar::executar(ISTeste* ctrlISTeste) {
    telaTeste.descadastrar(&codigo);                // Pede o código do teste ao usuário.
    resultado = ctrlISTeste->descadastrar(codigo);  // Socilita descadastramento do banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Teste descadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

//--------------------------------------------------------------------------------------------
void CmdIACasoDeTesteVisualizar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    telaCasoDeTeste.visualizar(&casoDeTeste);                 // Pede o código do teste ao usuário.
    resultado = ctrlISCasoDeTeste->visualizar(&casoDeTeste);  // Pesquisa no banco de dados e coloca os valores.
    if (resultado) {
        telaCasoDeTeste.mostrar(casoDeTeste);  // Mostra os valores.
    } else {
        telaMensagem.apresentar("Caso de teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void CmdIACasoDeTesteCadastrar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    telaCasoDeTeste.cadastrar(&casoDeTeste);                // Solicita dados do teste ao usuário. .
    resultado = ctrlISCasoDeTeste->cadastrar(casoDeTeste);  // Registra no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Caso de teste cadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Não foi possível cadastrar caso de teste. Pressione qualquer tecla para continuar.");
    }
}

void CmdIACasoDeTesteEditar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
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
