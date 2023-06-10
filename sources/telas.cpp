#include "../headers/telas.h"

//--------------------------------------------------------------------------------------------
void TelaMensagem::apresentar(string mensagem) {
    initscr();
    getmaxyx(stdscr, linha, coluna);

    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", mensagem.c_str());

    noecho();
    getch();
    echo();

    endwin();
}

//--------------------------------------------------------------------------------------------
void TelaInicial::apresentar(int *campo) {
    // Mensagens a serem apresentadas na tela inicial
    string texto1 = "Selecione um dos serviços: ";
    string texto2 = "1 - Acessar sistema.";
    string texto3 = "2 - Cadastrar desenvolvedor.";
    string texto4 = "3 - Encerrar execução do sistema.";
    string texto5 = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5.c_str());

    noecho();
    *campo = getch() - 48;
    echo();

    endwin();
}

//--------------------------------------------------------------------------------------------
void TelaUsuarioLogado::apresentar(int *campo) {
    string texto1 = "Selecione um dos servicos : ";
    string texto2 = "1 - Serviços relacionados a desenvolvedor.";
    string texto3 = "2 - Serviços relacionados a teste.";
    string texto4 = "3 - Serviços relacionados a caso de teste.";
    string texto5 = "4 - Encerrar sessão.";
    string texto6 = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5.c_str());
    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6.c_str());

    echo();
    *campo = getch() - 48;
    noecho();

    endwin();
}

//--------------------------------------------------------------------------------------------
void TelaDesenvolvedor::selecionar(int *campo) {
    string texto1 = "Selecione o servico desejado : ";
    string texto2 = "1 - Visualizar dados de desenvolvedor";
    string texto3 = "2 - Editar dados de desenvolvedor";
    string texto4 = "3 - Descadastrar desenvolvedor";
    string texto5 = "4 - Encerrar sessão.";
    string texto6 = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", texto1.c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    mvprintw(linha / 4 + 2, coluna / 4, "%s", texto3.c_str());
    mvprintw(linha / 4 + 3, coluna / 4, "%s", texto4.c_str());
    mvprintw(linha / 4 + 4, coluna / 4, "%s", texto5.c_str());
    mvprintw(linha / 4 + 5, coluna / 4, "%s", texto6.c_str());

    echo();
    *campo = getch() - 48;
    noecho();

    endwin();
}
void TelaDesenvolvedor::visualizar(Desenvolvedor *desenvolvedor){
    string titulo1 = "Informe matricula do desenvolvedor.";
    string texto1 = "Matricula";
    string textoErro;

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4 + texto1.size(), " : ");

    echo();
    getstr(matriculaDesenvolvedor);
    noecho();

    try {
        matricula.setValor(matriculaDesenvolvedor);
        desenvolvedor->setMatricula(matricula);
    } catch (invalid_argument &exp) {
        textoErro = "Valor de código inválido. Pressione qualquer tecla para continuar.";
        mvprintw(linha / 4 + 3, coluna / 4, "%s", textoErro.c_str());
    };

    endwin();
}    

// void TelaDesenvolvedor::cadastrar(Desenvolvedor *desenvolvedor) {
//     string texto1 = "Por favor, preencha os espaços com os seus dados:";
//     string texto2 = "Nome      : ";
//     string texto3 = "Matrícula : ";
//     string texto4 = "Telefone  : ";
//     string texto5 = "Senha     : ";

//     getmaxyx(stdscr, linha, coluna);
//     clear();

//     mvprintw(linha / 4, coluna / 4, "%s", texto1.c_str());
//     echo();

//     mvprintw(linha / 4 + 2, coluna / 4, "%s", texto2.c_str());
//     getstr(nomeDesenvolvedor);

//     mvprintw(linha / 4 + 4, coluna / 4, "%s", texto3.c_str());
//     getstr(matriculaDesenvolvedor);

//     mvprintw(linha / 4 + 6, coluna / 4, "%s", texto4.c_str());
//     getstr(telefoneDesenvolvedor);

//     mvprintw(linha / 4 + 8, coluna / 4, "%s", texto5.c_str());
//     getstr(senhaDesenvolvedor);

//     noecho();

//     try {
//         nome.setValor(nomeDesenvolvedor);}
//         catch(invalid_argument &exp){
//             noecho();
//             getch();
//         }
//         try{matricula.setValor(matriculaDesenvolvedor);}
//         catch(invalid_argument &exp){
//             noecho();
//             getch();
//         }
//         try{telefone.setValor(telefoneDesenvolvedor);}
//         catch(invalid_argument &exp){
//             noecho();
//             getch();
//         }
//         senha.setValor(senhaDesenvolvedor);
//         desenvolvedor->setNome(nome);
//         desenvolvedor->setMatricula(matricula);
//         desenvolvedor->setTelefone(telefone);
//         desenvolvedor->setSenha(senha);
//     endwin();
// }
void TelaDesenvolvedor::mostrar(Desenvolvedor desenvolvedor) {
    string titulo1 = "Valores atuais do desenvolvedor.";
    vector<string> texto1{"Matricula : ",
                          "Nome   : ",
                          "Telefone : ",
                          "Senha: "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    texto1[0] += desenvolvedor.getMatricula().getValor();
    texto1[1] += desenvolvedor.getNome().getValor();
    texto1[2] += desenvolvedor.getTelefone().getValor();
    texto1[3] += desenvolvedor.getSenha().getValor();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    noecho();
    mvprintw(linha / 4 + 4, coluna / 4, "%s", "");
    getch();

    endwin();
}

void TelaDesenvolvedor::editar(Desenvolvedor *desenvolvedor){
    string titulo1 = "Informe o campo do desenvolvedor para ser editado:";
    vector<string> texto1{"1 - Nome.",
                          "2 - Telefone.",
                          "3 - Senha.",
                          "",
                          "4 - Salvar.",
                          "5 - Cancelar.",
                          "Escolha uma opção: "};

    string titulo2 = "Informe novo valor.";
    vector<string> texto2{"Nome : ",
                          "Telefone : ",
                          "Senha : "};
    string textoErro = "Valor inválido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);

    bool apresentar = true;
    while (apresentar) {
        int campo;

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
        for (int i = 0; i < texto1.size(); i++) {
            mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
        }

        echo();
        campo = getch() - 48;
        noecho();

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo2.c_str());
        switch (campo) {
            case 1:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2[0].c_str());
                echo();
                getstr(nomeDesenvolvedor);
                noecho();

                try {
                    nome.setValor(nomeDesenvolvedor);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1[0]).c_str());
                    noecho();
                    getch();
                }
                break;

            case 2:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2[1].c_str());
                echo();
                getstr(telefoneDesenvolvedor);
                noecho();

                try {
                    telefone.setValor(telefoneDesenvolvedor);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1[1]).c_str());
                    noecho();
                    getch();
                }
                break;

            case 3:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2[2].c_str());
                echo();
                getstr(senhaDesenvolvedor);
                noecho();

                try {
                    senha.setValor(senhaDesenvolvedor);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1[2]).c_str());
                    noecho();
                    getch();
                    noecho();
                    getch();
                }
                break;

            case 4:
                desenvolvedor->setNome(nome);
                desenvolvedor->setTelefone(telefone);
                desenvolvedor->setSenha(senha);
                apresentar = false;
                break;

            case 5:
                apresentar = false;
                break;

            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
};

void TelaDesenvolvedor::descadastrar(Matricula *matricula) {
    string texto1 = "Preencha os seguintes campos: ";
    string texto2 = "Matrícula: ";
    string texto3 = "Matrícula informada inválida. Pressione qualquer tecla para continuar.";
    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();
    mvprintw(linha / 4, coluna / 4, "%s", texto1.c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2.c_str());
    echo();
    getstr(matriculaDesenvolvedor);
    noecho();
    try {
        matricula->setValor(matriculaDesenvolvedor);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", texto3.c_str());
        echo();
        getch();
        noecho();
    };
    endwin();
}

//--------------------------------------------------------------------------------------------
void TelaTeste::mostrar(Teste teste) {
    string titulo1 = "Valores atuais do teste.";
    vector<string> texto1{"Código : ",
                          "Nome   : ",
                          "Classe : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    texto1[0] += teste.getCodigo().getValor();
    texto1[1] += teste.getNome().getValor();
    texto1[2] += teste.getClasse().getValor();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    noecho();
    mvprintw(linha / 4 + 4, coluna / 4, "%s", "");
    getch();

    endwin();
}

void TelaTeste::selecionar(int *campo) {
    string titulo1 = "Selecione um dos servicos : ";
    vector<string> texto1{"1 - Visualizar teste.",
                          "2 - Cadastrar teste.",
                          "3 - Editar teste.",
                          "4 - Descadastrar teste.",
                          "5 - Encerrar sessão."};
    string texto2 = "Escolha uma opção: ";

    initscr();
    getmaxyx(stdscr, linha, coluna);

    clear();
    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }
    mvprintw(linha / 4 + 7, coluna / 4, "%s", texto2.c_str());

    echo();
    *campo = getch() - 48;
    noecho();

    endwin();
}

void TelaTeste::visualizar(Teste *teste) {
    string titulo1 = "Informe código do teste.";
    string texto1 = "Codigo";
    string textoErro;

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4 + texto1.size(), " : ");

    echo();
    getstr(codigoTeste);
    noecho();

    try {
        codigo.setValor(codigoTeste);
        teste->setCodigo(codigo);
    } catch (invalid_argument &exp) {
        textoErro = "Valor de código inválido. Pressione qualquer tecla para continuar.";
        mvprintw(linha / 4 + 3, coluna / 4, "%s", textoErro.c_str());
    };

    endwin();
}

void TelaTeste::cadastrar(Teste *teste) {
    string titulo1 = "Preencha os seguintes campos.";
    vector<string> texto1{"Codigo",
                          "Nome",
                          "Classe"};
    string textoErro = "Valor inválido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();

    mvprintw(linha / 4 + 1, coluna / 4 + texto1[2].size() + 1, " : ");
    getstr(codigoTeste);

    mvprintw(linha / 4 + 2, coluna / 4 + texto1[2].size() + 1, " : ");
    getstr(nomeTeste);

    mvprintw(linha / 4 + 3, coluna / 4 + texto1[2].size() + 1, " : ");
    getstr(classeTeste);

    noecho();

    int l = 5;
    try {
        codigo.setValor(codigoTeste);
        teste->setCodigo(codigo);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[0]).c_str());
        l++;
    }

    try {
        nome.setValor(nomeTeste);
        teste->setNome(nome);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[1]).c_str());
        l++;
    }

    try {
        classe.setValor(classeTeste);
        teste->setClasse(classe);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[2]).c_str());
        l++;
    }

    echo();
    getch();
    noecho();

    endwin();
}

void TelaTeste::editar(Teste *teste) {
    string titulo1 = "Informe o campo do teste para ser editado:";
    vector<string> texto1{"1 - Nome.",
                          "2 - Classe.",
                          "",
                          "3 - Salvar.",
                          "4 - Cancelar.",
                          "Escolha uma opção: "};

    string titulo2 = "Informe novo valor.";
    vector<string> texto2{"Nome: ",
                          "Classe: "};
    string textoErro;

    initscr();
    getmaxyx(stdscr, linha, coluna);

    bool apresentar = true;
    while (apresentar) {
        int campo;

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
        for (int i = 0; i < texto1.size(); i++) {
            mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
        }

        echo();
        campo = getch() - 48;
        noecho();

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo2.c_str());
        switch (campo) {
            case 1:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2[0].c_str());
                echo();
                getstr(nomeTeste);
                noecho();

                try {
                    nome.setValor(nomeTeste);
                } catch (invalid_argument &exp) {
                    textoErro = "Valor de nome inválido. Pressione qualquer tecla para continuar";
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", textoErro.c_str());

                    noecho();
                    getch();
                }
                break;

            case 2:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2[1].c_str());
                echo();
                getstr(classeTeste);
                noecho();

                try {
                    classe.setValor(classeTeste);
                } catch (invalid_argument &exp) {
                    textoErro = "Valor de classe inválido. Pressione qualquer tecla para continuar";
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", textoErro.c_str());

                    noecho();
                    getch();
                }
                break;

            case 3:
                teste->setNome(nome);
                teste->setClasse(classe);
                apresentar = false;
                break;

            case 4:
                apresentar = false;
                break;

            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
};

void TelaTeste::descadastrar(Codigo *codigo) {
    string titulo1 = "Informe código do teste para descadastramento.";
    string texto1 = "Código";
    string textoErro;

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4 + texto1.size(), " : ");
    echo();
    getstr(codigoTeste);
    noecho();

    try {
        codigo->setValor(codigoTeste);
    } catch (invalid_argument &exp) {
        textoErro = "Valor de código inválido. Pressione qualquer tecla para continuar.";
        mvprintw(linha / 4 + 3, coluna / 4, "%s", textoErro.c_str());
        echo();
        getch();
        noecho();
    };

    endwin();
}

//--------------------------------------------------------------------------------------------
void TelaCasoDeTeste::mostrar(CasoDeTeste casoDeTeste) {
    string titulo1 = "Valores atuais do caso de teste.";
    vector<string> texto1{"Codigo    : ",
                          "Nome      : ",
                          "Data      : ",
                          "Acao      : ",
                          "Resposta  : ",
                          "Resultado : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    texto1[0] += casoDeTeste.getCodigo().getValor();
    texto1[1] += casoDeTeste.getNome().getValor();
    texto1[2] += casoDeTeste.getData().getValor();
    texto1[3] += casoDeTeste.getAcao().getValor();
    texto1[4] += casoDeTeste.getResposta().getValor();
    texto1[5] += casoDeTeste.getResultado().getValor();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    mvprintw(linha / 4 + 8, coluna / 4, "%s", "");
    noecho();
    getch();

    endwin();
}

void TelaCasoDeTeste::selecionar(int *campo) {
    string titulo1 = "Selecione um dos servicos : ";
    vector<string> texto1{"1 - Visualizar caso de teste.",
                          "2 - Cadastrar caso de teste.",
                          "3 - Editar caso de teste.",
                          "4 - Descadastrar caso de teste.",
                          "5 - Encerrar sessão.",
                          "Escolha uma opção: "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    noecho();
    *campo = getch() - 48;
    echo();

    endwin();
}

void TelaCasoDeTeste::visualizar(CasoDeTeste *casoDeTeste) {
    string titulo1 = "Informe código do caso de teste.";
    string texto1 = "Codigo";
    string textoErro = "Valor inválido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4 + texto1.size(), ": ");

    echo();
    getstr(codigoCasoDeTeste);
    noecho();

    try {
        codigo.setValor(codigoCasoDeTeste);
        casoDeTeste->setCodigo(codigo);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1).c_str());
    };

    endwin();
}

void TelaCasoDeTeste::cadastrar(CasoDeTeste *casoDeTeste) {
    string titulo1 = "Preencha os seguintes campos.";
    vector<string> texto1{"Codigo",
                          "Nome",
                          "Data",
                          "Acao",
                          "Resposta",
                          "Resultado"};
    string textoErro = "Valor inválido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();

    mvprintw(linha / 4 + 1, coluna / 4 + texto1[5].size() + 1, " : ");
    getstr(codigoCasoDeTeste);

    mvprintw(linha / 4 + 2, coluna / 4 + texto1[5].size() + 1, " : ");
    getstr(nomeCasoDeTeste);

    mvprintw(linha / 4 + 3, coluna / 4 + texto1[5].size() + 1, " : ");
    getstr(dataCasoDeTeste);

    mvprintw(linha / 4 + 4, coluna / 4 + texto1[5].size() + 1, " : ");
    getstr(acaoCasoDeTeste);

    mvprintw(linha / 4 + 5, coluna / 4 + texto1[5].size() + 1, " : ");
    getstr(respostaCasoDeTeste);

    mvprintw(linha / 4 + 6, coluna / 4 + texto1[5].size() + 1, " : ");
    getstr(resultadoCasoDeTeste);

    noecho();

    int l = 8;
    try {
        codigo.setValor(codigoCasoDeTeste);
        casoDeTeste->setCodigo(codigo);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[0]).c_str());
        l++;
    }

    try {
        nome.setValor(nomeCasoDeTeste);
        casoDeTeste->setNome(nome);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[1]).c_str());
        l++;
    }

    try {
        data.setValor(dataCasoDeTeste);
        casoDeTeste->setData(data);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[2]).c_str());
        l++;
    }

    try {
        acao.setValor(acaoCasoDeTeste);
        casoDeTeste->setAcao(acao);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[3]).c_str());
        l++;
    }

    try {
        resposta.setValor(respostaCasoDeTeste);
        casoDeTeste->setResposta(resposta);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[4]).c_str());
        l++;
    }

    try {
        resultado.setValor(resultadoCasoDeTeste);
        casoDeTeste->setResultado(resultado);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[5]).c_str());
        l++;
    };

    noecho();
    getch();

    endwin();
}

void TelaCasoDeTeste::editar(CasoDeTeste *casoDeTeste) {
    string titulo1 = "Informe o campo do teste para ser editado:";
    vector<string> texto1{"1 - Nome.",
                          "2 - Data.",
                          "3 - Acao.",
                          "4 - Resposta.",
                          "5 - Resultado.",
                          "",
                          "6 - Salvar.",
                          "7 - Cancelar.",
                          "Escolha uma opção: "};

    string titulo2 = "Informe novo valor.";
    vector<string> texto2{"Nome : ",
                          "Data : ",
                          "Acao : ",
                          "Resposta : ",
                          "Resultado : "};
    string textoErro = "Valor inválido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);

    bool apresentar = true;
    while (apresentar) {
        int campo;

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
        for (int i = 0; i < texto1.size(); i++) {
            mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
        }

        echo();
        campo = getch() - 48;
        noecho();

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo2.c_str());
        switch (campo) {
            case 1:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2[0].c_str());
                echo();
                getstr(nomeCasoDeTeste);
                noecho();

                try {
                    nome.setValor(nomeCasoDeTeste);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1[0]).c_str());
                    noecho();
                    getch();
                }
                break;

            case 2:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2[1].c_str());
                echo();
                getstr(dataCasoDeTeste);
                noecho();

                try {
                    data.setValor(dataCasoDeTeste);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1[1]).c_str());
                    noecho();
                    getch();
                }
                break;

            case 3:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2[2].c_str());
                echo();
                getstr(acaoCasoDeTeste);
                noecho();

                try {
                    acao.setValor(acaoCasoDeTeste);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1[2]).c_str());
                    noecho();
                    getch();
                    noecho();
                    getch();
                }
                break;

            case 4:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2[3].c_str());
                echo();
                getstr(respostaCasoDeTeste);
                noecho();

                try {
                    resposta.setValor(respostaCasoDeTeste);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1[3]).c_str());
                    noecho();
                    getch();
                }
                break;

            case 5:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", texto2[4].c_str());
                echo();
                getstr(resultadoCasoDeTeste);
                noecho();

                try {
                    resultado.setValor(resultadoCasoDeTeste);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1[4]).c_str());
                    noecho();
                    getch();
                    noecho();
                    getch();
                }
                break;

            case 6:
                casoDeTeste->setNome(nome);
                casoDeTeste->setAcao(acao);
                casoDeTeste->setData(data);
                casoDeTeste->setResposta(resposta);
                casoDeTeste->setResultado(resultado);
                apresentar = false;
                break;

            case 7:
                apresentar = false;
                break;

            default:
                TelaMensagem telaMensagem;
                telaMensagem.apresentar("Opção inválida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
};

void TelaCasoDeTeste::descadastrar(Codigo *codigo) {
    string titulo1 = "Informe código do caso de teste para descadastramento.";
    string texto1 = "Código";
    string textoErro = "Valor inválido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", texto1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4 + texto1.size(), " : ");
    echo();
    getstr(codigoCasoDeTeste);
    noecho();

    try {
        codigo->setValor(codigoCasoDeTeste);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1).c_str());
        noecho();
        getch();
    };

    endwin();
}
//--------------------------------------------------------------------------------------------
void TelaDepuracao::selecionar(int *campo) {
    string titulo1 = "Selecione tipo de teste a ser executado : ";
    vector<string> texto1{"1 - Executar testes unitários.",
                          "2 - Executar testes de integração.",
                          "3 - Executar testes fumaça.",
                          "4 - Executar testes sistema.",
                          "5 - Encerrar depuração.",
                          "Digite a opção: "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();
    *campo = getch() - 48;
    noecho();

    endwin();
}

void TelaTestesUnitarios::selecionar(int *campo) {
    string titulo1 = "Selecione unidades de teste: ";
    vector<string> textos{"1 - Executar testes domínios.",
                          "2 - Executar testes entidades.",
                          "3 - Executar testes módulos.",
                          "4 - Retornar.",
                          "Digite a opção: "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < textos.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", textos[i].c_str());
    }

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}
