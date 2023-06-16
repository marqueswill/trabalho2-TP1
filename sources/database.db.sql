BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "desenvolvedores" (
	"nome"	TEXT,
	"matricula"	TEXT,
	"senha"	TEXT,
	"telefone"	TEXT,
	PRIMARY KEY("matricula")
);
CREATE TABLE IF NOT EXISTS "casodetestes" (
	"nome"	TEXT,
	"codigo"	TEXT,
	"data"	TEXT,
	"acao"	TEXT,
	"resposta"	TEXT,
	"resultado"	TEXT,
	PRIMARY KEY("codigo")
);
CREATE TABLE IF NOT EXISTS "testes" (
	"nome"	TEXT,
	"codigo"	TEXT,
	"classe"	TEXT,
	PRIMARY KEY("codigo")
);
COMMIT;
