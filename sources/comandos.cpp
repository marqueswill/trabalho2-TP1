#include "../headers/comandos.h"

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
void CmdIATesteVisualizar::executar(ISTeste* ctrlISTeste) {
    telaTeste.apresentar(&codigo);  // Pede o código do teste ao usuário.
    teste.setCodigo(codigo);

    resultado = ctrlISTeste->visualizar(&teste);  // Pesquisa no banco de dados e coloca os valores.
    if (resultado) {
        telaTeste.apresentar(teste);  // Mostra os valores.
    } else {
        telaMensagem.apresentar("Teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void CmdIATesteCadastrar::executar(ISTeste* ctrlISTeste) {
    telaTeste.apresentar(&teste);  // Solicita dados do teste ao usuário. .

    resultado = ctrlISTeste->cadastrar(teste);  // Registra no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Teste cadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Não foi possível cadastrar teste. Pressione qualquer tecla para continuar.");
    }
}

void CmdIATesteEditar::executar(ISTeste* ctrlISTeste) {
    telaTeste.apresentar(&teste);  // Solicita novas informações ao usuário.

    resultado = ctrlISTeste->editar(teste);  // Substitui novas informaçoes no banco de dados.
    if (ctrlISTeste->visualizar(&teste)) {   // Obtem novos valores no BD.
        telaTeste.apresentar(teste);
    } else {
        telaMensagem.apresentar("Não foi possível editar teste. Pressione qualquer tecla para continuar.");
    }
}

void CmdIATesteDescadastrar::executar(ISTeste* ctrlISTeste) {
    telaTeste.apresentar(&codigo);  // Pede o código do teste ao usuário.

    resultado = ctrlISTeste->descadastrar(codigo);  // Socilita descadastramento do banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Teste descadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

//--------------------------------------------------------------------------------------------
void CmdIACasoDeTesteVisualizar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    telaCasoDeTeste.apresentar(&codigo);  // Pede o código do teste ao usuário.
    casodeteste.setCodigo(codigo);

    resultado = ctrlISCasoDeTeste->visualizar(&casodeteste);  // Pesquisa no banco de dados.
    if (resultado) {
        telaCasoDeTeste.apresentar(casodeteste);
    } else {
        telaMensagem.apresentar("Caso de teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void CmdIACasoDeTesteCadastrar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    telaCasoDeTeste.apresentar(&casodeteste);  // Solicita dados do teste ao usuário. .

    resultado = ctrlISCasoDeTeste->cadastrar(casodeteste);  // Registra no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Caso de teste cadastrado scom sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Não foi possível cadastrar caso de teste. Pressione qualquer tecla para continuar.");
    }
}

void CmdIACasoDeTesteEditar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    telaCasoDeTeste.apresentar(&casodeteste);  // Solicita novas informações ao usuário.

    resultado = ctrlISCasoDeTeste->editar(casodeteste);  // Substitui novas informaçoes no banco de dados.
    if (resultado) {
        telaCasoDeTeste.apresentar(casodeteste);
    } else {
        telaMensagem.apresentar("Não foi possível editar caso de teste. Pressione qualquer tecla para continuar.");
    }
}

void CmdIACasoDeTesteDescadastrar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    telaCasoDeTeste.apresentar(&codigo);  // Pede o código do teste ao usuário.

    resultado = ctrlISCasoDeTeste->descadastrar(codigo);  // Socilita descadastramento do banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Caso de teste cadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}