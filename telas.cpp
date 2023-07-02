#include "telas.h"
#include <iostream>
//----------------------------------------------------------------------------------------------------------------------
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

//----------------------------------------------------------------------------------------------------------------------
void TelaInicial::selecionar(int *campo) {
    // Mensagens a serem apresentadas na tela inicial
    string titulo1 = "Selecione um dos servicos.";
    vector<string> texto1 = {"1 - Acessar sistema.",
                             "2 - Cadastrar desenvolvedor.",
                             "3 - Encerrar execucao do sistema.",
                             "Escolha uma opcao : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}

//----------------------------------------------------------------------------------------------------------------------
void TelaAutenticacao::autenticar(Matricula *matricula, Senha *senha) {
    string titulo1 = "Preencha os seguintes campos.";
    vector<string> texto1{"Matricula",
                          "Senha"};
    string textoErro = "Valor inválido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();

    mvprintw(linha / 4 + 1, coluna / 4 + texto1[0].size() + 1, " : ");
    getstr(matriculaAutenticacao);

    mvprintw(linha / 4 + 2, coluna / 4 + texto1[0].size() + 1, " : ");
    getstr(senhaAutenticacao);

    noecho();

    int l = 4;
    try {
        matricula->setValor(matriculaAutenticacao);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[0]).c_str());
        l++;
    }

    try {
        senha->setValor(senhaAutenticacao);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[1]).c_str());
        l++;
    }

    echo();
    getch();
    noecho();
    endwin();
}
//----------------------------------------------------------------------------------------------------------------------
void TelaUsuarioLogado::selecionar(int *campo) {
    string titulo1 = "Selecione um dos servicos. ";
    vector<string> texto1{"1 - Servicos relacionados a desenvolvedor.",
                          "2 - Servicos relacionados a teste.",
                          "3 - Servicos relacionados a caso de teste.",
                          "4 - Encerrar sessao.",
                          "Escolha uma opcao : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}

//----------------------------------------------------------------------------------------------------------------------
void TelaDesenvolvedor::mostrar(Desenvolvedor desenvolvedor) {
    string titulo1 = "Valores atuais do desenvolvedor.";
    vector<string> texto1{"Matricula : ",
                          "Nome      : ",
                          "Telefone  : ",
                          "Senha     : "};

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
    mvprintw(linha / 4 + 6, coluna / 4, "%s", "");
    getch();

    endwin();
}

void TelaDesenvolvedor::selecionar(int *campo) {
    string titulo1 = "Selecione o servico desejado.";
    vector<string> texto1{"1 - Visualizar dados de desenvolvedor",
                          "2 - Editar dados de desenvolvedor",
                          "3 - Descadastrar desenvolvedor",
                          "4 - Retornar.",
                          "Escolha uma opcao : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}

// void TelaDesenvolvedor::visualizar(Desenvolvedor *desenvolvedor) {
//     string titulo1 = "Informe matricula do desenvolvedor.";
//     string texto1 = "Matricula";
//     string textoErro = "Valor invalido para atributo ";

//     initscr();
//     getmaxyx(stdscr, linha, coluna);
//     clear();

//     mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

//     mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto1 + " : ").c_str());

//     echo();
//     getstr(matriculaDesenvolvedor);
//     noecho();

//     try {
//         matricula.setValor(matriculaDesenvolvedor);
//         desenvolvedor->setMatricula(matricula);
//     } catch (invalid_argument &exp) {
//         mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1).c_str());
//     };

//     endwin();
// }

void TelaDesenvolvedor::cadastrar(Desenvolvedor *desenvolvedor) {
    string titulo1 = "Por favor, preencha os espacos com os seus dados.";
    vector<string> texto1{"Matricula",
                          "Nome",
                          "Telefone",
                          "Senha"};

    string textoErro = "Valor invalido para atributo ";

    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();

    mvprintw(linha / 4 + 1, coluna / 4 + texto1[0].size() + 1, " : ");
    getstr(matriculaDesenvolvedor);

    mvprintw(linha / 4 + 2, coluna / 4 + texto1[0].size() + 1, " : ");
    getstr(nomeDesenvolvedor);

    mvprintw(linha / 4 + 3, coluna / 4 + texto1[0].size() + 1, " : ");
    getstr(telefoneDesenvolvedor);

    mvprintw(linha / 4 + 4, coluna / 4 + texto1[0].size() + 1, " : ");
    getstr(senhaDesenvolvedor);

    noecho();

    int l = 5;
    try {
        matricula.setValor(matriculaDesenvolvedor);
        desenvolvedor->setMatricula(matricula);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[0]).c_str());
        l++;
    }
    try {
        nome.setValor(nomeDesenvolvedor);
        desenvolvedor->setNome(nome);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[1]).c_str());
        l++;
    }
    try {
        telefone.setValor(telefoneDesenvolvedor);
        desenvolvedor->setTelefone(telefone);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[2]).c_str());
        l++;
    }
    try {
        senha.setValor(senhaDesenvolvedor);
        desenvolvedor->setSenha(senha);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[3]).c_str());
        l++;
    }

    noecho;
    getch();
    endwin();
}

void TelaDesenvolvedor::editar(Desenvolvedor *desenvolvedor) {
    string titulo1 = "Informe o campo do desenvolvedor para ser editado.";
    vector<string> texto1{"1 - Nome.",
                          "2 - Telefone.",
                          "3 - Senha.",
                          "",
                          "4 - Salvar.",
                          "5 - Cancelar.",
                          "Escolha uma opcao : "};

    string titulo2 = "Informe novo valor.";
    vector<string> texto2{"Nome",
                          "Telefone",
                          "Senha"};
    string textoErro = "Valor invalido para atributo ";

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
        campo = getch() - '0';
        noecho();

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo2.c_str());
        switch (campo) {
            case 1:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[0] + " : ").c_str());
                echo();
                getstr(nomeDesenvolvedor);
                noecho();

                try {
                    nome.setValor(nomeDesenvolvedor);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[0]).c_str());
                    noecho();
                    getch();
                }
                break;

            case 2:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[1] + " : ").c_str());
                echo();
                getstr(telefoneDesenvolvedor);
                noecho();

                try {
                    telefone.setValor(telefoneDesenvolvedor);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[1]).c_str());
                    noecho();
                    getch();
                }
                break;

            case 3:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[2] + " : ").c_str());
                echo();
                getstr(senhaDesenvolvedor);
                noecho();

                try {
                    senha.setValor(senhaDesenvolvedor);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[2]).c_str());
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
                telaMensagem.apresentar("Opcao invalida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
};

void TelaDesenvolvedor::descadastrar(Matricula *matricula) {
    string titulo1 = "Confirme sua matricula para confirmar o descadastramento.";
    string texto1 = "Matricula";
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", (titulo1).c_str());
    mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto1 + " : ").c_str());

    echo();
    getstr(matriculaDesenvolvedor);
    noecho();

    try {
        matricula->setValor(matriculaDesenvolvedor);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1).c_str());
        noecho();
        getch();
    };
    endwin();
}

//----------------------------------------------------------------------------------------------------------------------
void TelaTeste::mostrar(Teste teste) {
    string titulo1 = "Valores atuais do teste.";
    vector<string> texto1{"Codigo : ",
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
    string titulo1 = "Selecione um dos servicos.";
    vector<string> texto1{"1 - Visualizar teste.",
                          "2 - Cadastrar teste.",
                          "3 - Editar teste.",
                          "4 - Descadastrar teste.",
                          "5 - Retornar."};
    string texto2 = "Escolha uma opcao : ";

    initscr();
    getmaxyx(stdscr, linha, coluna);

    clear();
    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }
    mvprintw(linha / 4 + 7, coluna / 4, "%s", texto2.c_str());

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}

void TelaTeste::visualizar(Teste *teste) {
    string titulo1 = "Informe codigo do teste.";
    string texto1 = "Codigo";
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto1 + " : ").c_str());

    echo();
    getstr(codigoTeste);
    noecho();

    try {
        codigo.setValor(codigoTeste);
        teste->setCodigo(codigo);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1).c_str());
    };

    endwin();
}

void TelaTeste::cadastrar(Teste *teste) {
    string titulo1 = "Preencha os seguintes campos.";
    vector<string> texto1{"Codigo",
                          "Nome",
                          "Classe"};
    string textoErro = "Valor invalido para atributo ";

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

    noecho;
    getch();
    endwin();
}

void TelaTeste::editar(Teste *teste) {
    string titulo1 = "Informe o campo do teste para ser editado.";
    vector<string> texto1{"1 - Nome.",
                          "2 - Classe.",
                          "",
                          "3 - Salvar.",
                          "4 - Cancelar.",
                          "Escolha uma opcao : "};

    string titulo2 = "Informe novo valor.";
    vector<string> texto2{"Nome",
                          "Classe"};
    string textoErro = "Valor invalido para atributo ";

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
        campo = getch() - '0';
        noecho();

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo2.c_str());
        switch (campo) {
            case 1:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[0] + " : ").c_str());
                echo();
                getstr(nomeTeste);
                noecho();

                try {
                    nome.setValor(nomeTeste);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[0]).c_str());

                    noecho();
                    getch();
                }
                break;

            case 2:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[1] + " : ").c_str());
                echo();
                getstr(classeTeste);
                noecho();

                try {
                    classe.setValor(classeTeste);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[1]).c_str());

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
                telaMensagem.apresentar("Opcao invalida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
};

void TelaTeste::descadastrar(Codigo *codigo) {
    string titulo1 = "Informe codigo do teste para descadastramento.";
    string texto1 = "Codigo";
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto1 + " : ").c_str());

    echo();
    getstr(codigoTeste);
    noecho();

    try {
        codigo->setValor(codigoTeste);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto1).c_str());
        echo();
        getch();
        noecho();
    };

    endwin();
}

//----------------------------------------------------------------------------------------------------------------------
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
                          "5 - Retornar.",
                          "Escolha uma opcao : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    noecho();
    *campo = getch() - '0';
    echo();

    endwin();
}

void TelaCasoDeTeste::visualizar(CasoDeTeste *casoDeTeste) {
    string titulo1 = "Informe codigo do caso de teste.";
    string texto1 = "Codigo";
    string textoErro = "Valor invalido para atributo ";

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());

    mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto1 + " : ").c_str());

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
                          "Resultado",
                          "Teste"};
    string textoErro = "Valor invalido para atributo ";

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

    mvprintw(linha / 4 + 7, coluna / 4 + texto1[5].size() + 1, " : ");
    getstr(codigotestesCasoDeTeste);

    noecho();

    int l = 9;
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
    }
    try {
        codigotestes.setValor(codigotestesCasoDeTeste);
        casoDeTeste->setCodigoTestes(codigotestes);
    } catch (invalid_argument &exp) {
        mvprintw(linha / 4 + l, coluna / 4, "%s", (textoErro + texto1[6]).c_str());
        l++;
    };

    noecho;
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
                          "Escolha uma opcao : "};

    string titulo2 = "Informe novo valor.";
    vector<string> texto2{"Nome",
                          "Data",
                          "Acao",
                          "Resposta",
                          "Resultado"};
    string textoErro = "Valor invalido para atributo ";

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
        campo = getch() - '0';
        noecho();

        clear();
        mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo2.c_str());
        switch (campo) {
            case 1:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[0] + " : ").c_str());
                echo();
                getstr(nomeCasoDeTeste);
                noecho();

                try {
                    nome.setValor(nomeCasoDeTeste);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[0]).c_str());
                    noecho();
                    getch();
                }
                break;

            case 2:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[1] + " : ").c_str());
                echo();
                getstr(dataCasoDeTeste);
                noecho();

                try {
                    data.setValor(dataCasoDeTeste);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[1]).c_str());
                    noecho();
                    getch();
                }
                break;

            case 3:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[2] + " : ").c_str());
                echo();
                getstr(acaoCasoDeTeste);
                noecho();

                try {
                    acao.setValor(acaoCasoDeTeste);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[2]).c_str());
                    noecho();
                    getch();
                    noecho();
                    getch();
                }
                break;

            case 4:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[3] + " : ").c_str());
                echo();
                getstr(respostaCasoDeTeste);
                noecho();

                try {
                    resposta.setValor(respostaCasoDeTeste);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[3]).c_str());
                    noecho();
                    getch();
                }
                break;

            case 5:
                mvprintw(linha / 4 + 1, coluna / 4, "%s", (texto2[4] + " : ").c_str());
                echo();
                getstr(resultadoCasoDeTeste);
                noecho();

                try {
                    resultado.setValor(resultadoCasoDeTeste);
                } catch (invalid_argument &exp) {
                    mvprintw(linha / 4 + 3, coluna / 4, "%s", (textoErro + texto2[4]).c_str());
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
                telaMensagem.apresentar("Opcao invalida. Pressione qualquer tecla para continuar.");
                break;
        }
    }
};

void TelaCasoDeTeste::descadastrar(Codigo *codigo) {
    string titulo1 = "Informe codigo do caso de teste para descadastramento.";
    string texto1 = "Codigo";
    string textoErro = "Valor invalido para atributo ";

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
//----------------------------------------------------------------------------------------------------------------------
void TelaDepuracao::selecionar(int *campo) {
    string titulo1 = "Selecione tipo de teste a ser executado : ";
    vector<string> texto1{"1 - Executar testes unitarios.",
                          "2 - Executar testes integracao.",
                          "3 - Executar testes fumaca.",
                          "4 - Executar testes sistema.",
                          "5 - Encerrar depuracao.",
                          "Digite a opcao : "};

    initscr();
    getmaxyx(stdscr, linha, coluna);
    clear();

    mvprintw(linha / 4 + 0, coluna / 4, "%s", titulo1.c_str());
    for (int i = 0; i < texto1.size(); i++) {
        mvprintw(linha / 4 + i + 1, coluna / 4, "%s", texto1[i].c_str());
    }

    echo();
    *campo = getch() - '0';
    noecho();

    endwin();
}

void TelaTestesUnitarios::selecionar(int *campo) {
    string titulo1 = "Selecione unidades de teste: ";
    vector<string> textos{"1 - Executar testes dominios.",
                          "2 - Executar testes entidades.",
                          "3 - Executar testes modulos.",
                          "4 - Retornar.",
                          "Digite a opcao : "};

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

void TelaTestesModulos::selecionar(int *campo) {
    string titulo1 = "Selecione modulo a ser testado :";
    vector<string> textos{"1 - Modulo Apresentacao Autenticacao.",
                          "2 - Modulo Apresentacao Desenvolvedor.",
                          "3 - Modulo Apresentacao Teste.",
                          "4 - Modulo Apresentacao CasoDeTeste.",
                          "5 - Retornar.",
                          "Digite a opcao : "};

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

void TelaTestesIntegracao::selecionar(int *campo) {
    string titulo1 = "Selecione teste integração :";
    vector<string> textos{"1 - Integração entre modulos da camada de Apresentacao.",
                          "2 - Integração entre modulos do subsistema Autenticacao.",
                          "3 - Integração entre modulos do subsistema Desenvolvedor.",
                          "4 - Integração entre modulos do subsistema Teste.",
                          "5 - Integração entre modulos do subsistema CasoDeTeste.",
                          "6 - Retornar.",
                          "Digite a opcao : "};

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
