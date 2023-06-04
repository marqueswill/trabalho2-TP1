#include "comandos.h"

#include "telas.h"

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
void CmdIATesteVisualizar::executar(ISTeste* ctrlISTeste) {
    try {
        telaTeste.visualizar(&teste);  // Pede o código do teste ao usuário.
    } catch (invalid_argument& exp) {
        telaMensagem.apresentar("Código informado inválido. Pressione qualquer tecla para continuar.");
    };

    resultado = ctrlISTeste->visualizar(&teste);  // Pesquisa no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void CmdIATesteCadastrar::executar(ISTeste* ctrlISTeste) {
    try {
        telaTeste.cadastrar(&teste);  // Solicita dados do teste ao usuário. .
    } catch (invalid_argument& exp) {
        telaMensagem.apresentar("Dados informado(s) inválido(s). Pressione qualquer tecla para continuar.");
    };

    resultado = ctrlISTeste->cadastrar(teste);  // Registra no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Não foi possível cadastrar teste. Pressione qualquer tecla para continuar.");
    }
}

void CmdIATesteEditar::executar(ISTeste* ctrlISTeste) {
    try {
        telaTeste.editar(&teste);  // Solicita novas informações ao usuário.
    } catch (invalid_argument& exp) {
        telaMensagem.apresentar("Dados informado(s) inválido(s). Pressione qualquer tecla para continuar.");
    };

    resultado = ctrlISTeste->editar(teste);  // Substitui novas informaçoes no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Não foi possível editar teste. Pressione qualquer tecla para continuar.");
    }
}

void CmdIATesteDescadastrar::executar(ISTeste* ctrlISTeste) {
    try {
        telaTeste.descadastrar(&teste);  // Pede o código do teste ao usuário.
        codigo = teste.getCodigo();
    } catch (invalid_argument& exp) {
        telaMensagem.apresentar("Código informado inválido. Pressione qualquer tecla para continuar.");
    };

    resultado = ctrlISTeste->descadastrar(codigo);  // Socilita descadastramento do banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

//--------------------------------------------------------------------------------------------
void CmdIACasoDeTesteVisualizar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    try {
        telaCasoDeTeste.visualizar(&casodeteste);  // Pede o código do teste ao usuário.
    } catch (invalid_argument& exp) {
        telaMensagem.apresentar("Código informado inválido. Pressione qualquer tecla para continuar.");
    };

    resultado = ctrlISCasoDeTeste->visualizar(&casodeteste);  // Pesquisa no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Caso de teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void CmdIACasoDeTesteCadastrar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    try {
        telaCasoDeTeste.cadastrar(&casodeteste);  // Solicita dados do teste ao usuário. .
    } catch (invalid_argument& exp) {
        telaMensagem.apresentar("Dados informado(s) inválido(s). Pressione qualquer tecla para continuar.");
    };

    resultado = ctrlISCasoDeTeste->cadastrar(casodeteste);  // Registra no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Não foi possível cadastrar caso de teste. Pressione qualquer tecla para continuar.");
    }
}

void CmdIACasoDeTesteEditar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    try {
        telaCasoDeTeste.editar(&casodeteste);  // Solicita novas informações ao usuário.
    } catch (invalid_argument& exp) {
        telaMensagem.apresentar("Dados informado(s) inválido(s). Pressione qualquer tecla para continuar.");
    };

    resultado = ctrlISCasoDeTeste->editar(casodeteste);  // Substitui novas informaçoes no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Não foi possível editar caso de teste. Pressione qualquer tecla para continuar.");
    }
}

void CmdIACasoDeTesteDescadastrar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    try {
        telaCasoDeTeste.descadastrar(&casodeteste);  // Pede o código do teste ao usuário.
        codigo = casodeteste.getCodigo();
    } catch (invalid_argument& exp) {
        telaMensagem.apresentar("Código informado inválido. Pressione qualquer tecla para continuar.");
    };

    resultado = ctrlISCasoDeTeste->descadastrar(codigo);  // Socilita descadastramento do banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Operação realizada com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}
void CmdIADevCadastrar::executar(ISDesenvolvedor* ISDesenvolvedor){

}