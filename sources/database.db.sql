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
	"codigo2"	TEXT,
	"data"	TEXT,
	"acao"	TEXT,
	"resposta"	TEXT,
	"resultado"	TEXT,
	PRIMARY KEY("codigo2")
);
CREATE TABLE IF NOT EXISTS "testes" (
	"nome"	TEXT,
	"codigo"	TEXT,
	"classe"	TEXT,
	PRIMARY KEY("codigo")
);
CREATE TABLE IF NOT EXISTS "r_des_casos_testes" (
	"SEQ_RELACIONAL"	INTEGER,
	"matricula"	text,
	"codigo2"	text,
	"codigo"	text,
	FOREIGN KEY("MATRICULA") REFERENCES "DESENVOLVEDORES"("MATRICULA"),
	FOREIGN KEY("CODIGO") REFERENCES "TESTES"("CODIGO"),
	FOREIGN KEY("CODIGO2") REFERENCES "CASODETESTES"("CODIGO2"),
	PRIMARY KEY("SEQ_RELACIONAL")
);
COMMIT;
