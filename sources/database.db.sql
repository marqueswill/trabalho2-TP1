BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "desenvolvedores" (
	"nome"	TEXT,
	"matricula"	TEXT,
	"senha"	TEXT,
	"telefone"	TEXT,
	PRIMARY KEY("matricula")
);
CREATE TABLE IF NOT EXISTS "testes" (
	"nome"	TEXT,
	"codigo"	TEXT,
	"classe"	TEXT,
	"matricula"	TEXT,
	PRIMARY KEY("codigo"),
	FOREIGN KEY("matricula") REFERENCES "desenvolvedores"
);
CREATE TABLE IF NOT EXISTS "casodetestes" (
	"nome"	TEXT,
	"codigo"	TEXT,
	"data"	TEXT,
	"acao"	TEXT,
	"resposta"	TEXT,
	"resultado"	TEXT,
	"codigotestes"	TEXT,
	PRIMARY KEY("codigo"),
	FOREIGN KEY("codigotestes") REFERENCES "testes"("codigo")
);
COMMIT;
