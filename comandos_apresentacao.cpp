#include "comandos_apresentacao.h"
#include <iostream>
//----------------------------------------------------------------------------------------------------------------------
bool ComandoIAAutenticacaoAutenticar::executar(ISAutenticacao* ctrlISAutenticacao) {
    telaAutenticacao.autenticar(matricula, &senha);
    Matricula login = *matricula;
    resultado = ctrlISAutenticacao->autenticar(login, senha);
    if(resultado){
        return resultado;
    }
    else{
         telaAutenticacao.autenticar(matricula, &senha);
    }
    return resultado;
}


//----------------------------------------------------------------------------------------------------------------------
void ComandoIADesenvolvedorVisualizar::executar(ISDesenvolvedor* ctrlISDesenvolvedor) {
    desenvolvedor.setMatricula(matricula);  // Já tem a matricula, desenvolvedor só pode visualizar os próprios dados

    resultado = ctrlISDesenvolvedor->visualizar(&desenvolvedor);
    if (resultado) {
        telaDesenvolvedor.mostrar(desenvolvedor);
    } else {
        telaMensagem.apresentar("Desenvolvedor informado nao foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIADesenvolvedorCadastrar::executar(ISDesenvolvedor* ctrlISDesenvolvedor) {
        telaDesenvolvedor.cadastrar(&desenvolvedor);
        resultado = ctrlISDesenvolvedor->cadastrar(desenvolvedor);
        if (resultado) {
            telaMensagem.apresentar("Operacao realizada com sucesso. Pressione qualquer tecla para continuar.");
        } else {
            telaMensagem.apresentar("Nao foi possivel cadastrar desenvolvedor. Pressione qualquer tecla para continuar.");
        }
    }

void ComandoIADesenvolvedorEditar::executar(ISDesenvolvedor* ctrlISDesenvolvedor) {
    desenvolvedor.setMatricula(matricula);
    desenvolvedor.setNome(nome);
    desenvolvedor.setSenha(senha);
    desenvolvedor.setTelefone(telefone);
    resultado = ctrlISDesenvolvedor->visualizar(&desenvolvedor);
    telaDesenvolvedor.editar(&desenvolvedor);
    resultado = ctrlISDesenvolvedor->editar(desenvolvedor);

    if (resultado) {
        telaMensagem.apresentar("Operacao realizada com sucesso. Pressione qualquer tecla para continuar.");
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
            telaMensagem.apresentar("Operacao realizada com sucesso. Pressione qualquer tecla para continuar.");
        } else {
            telaMensagem.apresentar("Não foi possivel descadastrar desenvolvedor. Pressione qualquer tecla para continuar.");
        }
    } else {
        telaMensagem.apresentar("Informe apenas matricula do desenvolvedor logado. Pressione qualquer tecla para continuar.");
    }
}

//----------------------------------------------------------------------------------------------------------------------
void ComandoIATesteVisualizar::executar(ISTeste* ctrlISTeste) {
    telaTeste.visualizar(&teste);
    teste.setMatricula(matricula);              // Pede o código do teste ao usuário.
    resultado = ctrlISTeste->visualizar(&teste);  // Pesquisa no banco de dados e coloca os valores.
    if (resultado) {
        telaTeste.mostrar(teste);  // Mostra os valores.
    } else {
        telaMensagem.apresentar("Teste informado não foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIATesteCadastrar::executar(ISTeste* ctrlISTeste) {
    teste.setMatricula(matricula);
    telaTeste.cadastrar(&teste);
    resultado = ctrlISTeste->cadastrar(teste);  // Registra no banco de dados.
    if (resultado) {
            telaMensagem.apresentar("Teste cadastrado com sucesso. Pressione qualquer tecla para continuar.");
        } else {
            telaMensagem.apresentar("Nao foi possível cadastrar teste. Pressione qualquer tecla para continuar.");
        }
}

void ComandoIATesteEditar::executar(ISTeste* ctrlISTeste) {
    teste.setMatricula(matricula);
    telaTeste.visualizar(&teste);
    Teste *teste_confirmacao;
    teste_confirmacao = new Teste();
    teste_confirmacao->setCodigo(teste.getCodigo());               
    resultado = ctrlISTeste->visualizar(teste_confirmacao);  // Verifica se está no banco de dados.
    if (resultado) {
        delete teste_confirmacao;
        telaTeste.editar(&teste);  // Solicita novos dados ao usuário.
        resultado = ctrlISTeste->editar(teste);
        if (resultado) {                 // Substitui novas informaçoes no banco de dados.
            telaMensagem.apresentar("Operacao realizada com sucesso. Pressione qualquer tecla para continuar.");  // Pesquisa no banco de dados e coloca os valores.
        } else {
            telaMensagem.apresentar("Nao foi possível editar teste. Pressione qualquer tecla para continuar.");
        }
    } else {
        delete teste_confirmacao;
        telaMensagem.apresentar("Teste informado nao foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIATesteDescadastrar::executar(ISTeste* ctrlISTeste) {
    Teste *ptrTeste;
    ptrTeste = new Teste();
    ptrTeste->setMatricula(matricula);
    telaTeste.descadastrar(&codigo);
    ptrTeste->setCodigo(codigo);
    if(resultado = ctrlISTeste->visualizar(ptrTeste)){
        delete ptrTeste;
        resultado = ctrlISTeste->descadastrar(codigo);  // Socilita descadastramento do banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Teste descadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Teste informado nao foi encontrado. Pressione qualquer tecla para continuar.");
    }
    }
    else{
        delete ptrTeste;
         telaMensagem.apresentar("Teste informado nao foi encontrado. Pressione qualquer tecla para continuar.");
    }                // Pede o código do teste ao usuário.
}

//----------------------------------------------------------------------------------------------------------------------
void ComandoIACasoDeTesteVisualizar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    casoDeTeste.setMatricula(matricula);
    telaCasoDeTeste.visualizar(&casoDeTeste);                 // Pede o código do teste ao usuário.
    resultado = ctrlISCasoDeTeste->visualizar(&casoDeTeste);  // Pesquisa no banco de dados e coloca os valores.
    if (resultado) {
        telaCasoDeTeste.mostrar(casoDeTeste);  // Mostra os valores.
    } else {
        telaMensagem.apresentar("Caso de teste informado nao foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIACasoDeTesteCadastrar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    casoDeTeste.setMatricula(matricula); 
    telaCasoDeTeste.cadastrar(&casoDeTeste);  
    resultado = ctrlISCasoDeTeste->cadastrar(casoDeTeste);  // Registra no banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Caso de teste cadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        cout << casoDeTeste.getCodigoTestes().getValor();
        getch();
        telaMensagem.apresentar("Nao foi possivel cadastrar caso de teste. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIACasoDeTesteEditar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    casoDeTeste.setMatricula(matricula);
    telaCasoDeTeste.visualizar(&casoDeTeste);
    CasoDeTeste *casodeteste_confirmacao;
    casodeteste_confirmacao = new CasoDeTeste();
    casodeteste_confirmacao->setCodigo(casoDeTeste.getCodigo());               
    resultado = ctrlISCasoDeTeste->visualizar(casodeteste_confirmacao);  // Verifica se está no banco de dados.                 // Obtém código do teste que será editado
    if (resultado) {
        delete casodeteste_confirmacao;
        telaCasoDeTeste.editar(&casoDeTeste);  // Solicita novos dados ao usuário.
        resultado = ctrlISCasoDeTeste->editar(casoDeTeste);
        if (resultado) {                 // Substitui novas informaçoes no banco de dados.
            telaMensagem.apresentar("Operacao realizada com sucesso. Pressione qualquer tecla para continuar.");  // Pesquisa no banco de dados e coloca os valores.
        } else {
            telaMensagem.apresentar("Nao foi possivel editar caso de teste. Pressione qualquer tecla para continuar.");
        }
    } else {
        delete casodeteste_confirmacao;
        telaMensagem.apresentar("Caso de teste informado nao foi encontrado. Pressione qualquer tecla para continuar.");
    }
}

void ComandoIACasoDeTesteDescadastrar::executar(ISCasoDeTeste* ctrlISCasoDeTeste) {
    CasoDeTeste *ptrCasoDeTeste;
    ptrCasoDeTeste = new CasoDeTeste();
    ptrCasoDeTeste->setMatricula(matricula);
    casoDeTeste.setMatricula(matricula);
    telaCasoDeTeste.descadastrar(&codigo);
    ptrCasoDeTeste->setCodigo(codigo);
    if(resultado = ctrlISCasoDeTeste->visualizar(ptrCasoDeTeste)){
     delete ptrCasoDeTeste;
     resultado = ctrlISCasoDeTeste->descadastrar(codigo);  // Socilita descadastramento do banco de dados.
    if (resultado) {
        telaMensagem.apresentar("Caso de teste descadastrado com sucesso. Pressione qualquer tecla para continuar.");
    } else {
        telaMensagem.apresentar("Caso de teste informado nao foi encontrado. Pressione qualquer tecla para continuar.");
    }
    }
    else{
        delete ptrCasoDeTeste;
        telaMensagem.apresentar("Caso de teste informado nao foi encontrado. Pressione qualquer tecla para continuar.");
    }                // Pede o código do teste ao usuário.

}
