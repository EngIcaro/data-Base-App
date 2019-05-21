#include "bd.h"
Bd::Bd(QObject *parent): QObject(parent)
{

}


void Bd::setarBancoDeDados()
{
    if(!QSqlDatabase::isDriverAvailable("QSQLITE")){
        qDebug() << "Error: sql não está desponível";
    }
    m_bancoDeDados = QSqlDatabase::addDatabase("QSQLITE");
    m_bancoDeDados.setDatabaseName("teste1.Bd");
    if(!m_bancoDeDados.open()){
        qDebug() << m_bancoDeDados.lastError().text();
    }
}


void Bd::criarTabelas()
{
    QSqlQuery query; // UMA VARIAVEL QUE CONSULTA/ MEXE COM O BANCO DE DADOS. ela precisa ser declarado depois que o Bd for aberto

    QString CRIAR_TABELA_PRODUTO = "CREATE TABLE IF NOT EXISTS "
            + TABELA_PRODUTOS
            + "("
            + CHAVE_ID_PRODUTO + " INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
            + CHAVE_NOME  	   + " VARCHAR(100) NOT NULL,"
            + CHAVE_VALOR      + " VARCHAR(100) NOT NULL,"
            + CHAVE_TIPO 	   + " VARCHAR(10) NOT NULL,"
            + CHAVE_ITEM_LISTA + " VARCHAR(100) NOT NULL "
            + ")";
    if(!query.exec(CRIAR_TABELA_PRODUTO)){
        qDebug() << query.lastError().text() << " BD[01] ";
    }

    QString CRIAR_TABELA_COMPRAS = "CREATE TABLE IF NOT EXISTS "
            + TABELA_COMPRAS
            + "("
            + CHAVE_ID_COMPRA        	+ " INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
            + CHAVE_DATA          	    + " VARCHAR(100) NOT NULL,"
            + CHAVE_VALOR_COMPRA        + " VARCHAR(100) NOT NULL,"
            + CHAVE_PAGAMENTO          	+ " VARCHAR(100) NOT NULL "
            + ")";


    if(!query.exec(CRIAR_TABELA_COMPRAS)){
        qDebug() << query.lastError().text() << " BD[02] ";
    }

    QString CRIAR_TABELA_COMPRA_PRODUTO = "CREATE TABLE IF NOT EXISTS "
            + TABELA_COMPRA_PRODUTO
            + "("
            + CHAVE_ID_COMPRA_PRODUTO   + " INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
            + CHAVE_COMPLEMENTO         + " VARCHAR(250) NOT NULL,"
            + CHAVE_ESTRANGEIRA_COMPRA  + " INTEGER NOT NULL,"
            + CHAVE_ESTRANGEIRA_PRODUTO + " INTEGER NOT NULL,"
            + " FOREIGN KEY ("+CHAVE_ESTRANGEIRA_PRODUTO+") REFERENCES "+ TABELA_PRODUTOS +"("+CHAVE_ID_PRODUTO+"),"
            + " FOREIGN KEY ("+CHAVE_ESTRANGEIRA_COMPRA+") REFERENCES "+ TABELA_COMPRAS +"("+CHAVE_ID_COMPRA+"));";

    if(!query.exec(CRIAR_TABELA_COMPRA_PRODUTO)){
        qDebug() << query.lastError().text() << " BD[03] ";
    }
}


void Bd::adicionarProduto(QString nome, QString valor, QString tipo, QString item)
{
    QSqlQuery query;
    QString NOVO_PRODUTO = "INSERT INTO "
            + TABELA_PRODUTOS
            + " ("
            + CHAVE_NOME  	   + ","
            + CHAVE_VALOR      + ","
            + CHAVE_TIPO 	   + ","
            + CHAVE_ITEM_LISTA +
            + ")"
            + "VALUES('%1','%2','%3','%4')";

    if(!query.exec(QString(NOVO_PRODUTO).arg(nome).arg(valor).arg(tipo).arg(item))){
        qDebug() << query.lastError().text() << " BD[04] ";
    }
    if(!query.exec("SELECT * FROM " + TABELA_PRODUTOS)){
        qDebug() << query.lastError().text() << " BD[05] ";
    }

    while(query.next()){
        qDebug() << "passou ";
        qDebug() << query.value(CHAVE_NOME).toString();
        qDebug() << query.value(CHAVE_VALOR).toString();
        qDebug() << query.value(CHAVE_TIPO).toString();
        qDebug() << query.value(CHAVE_ITEM_LISTA).toString();
    }

}

void Bd::removerProduto(QString nome, QString tipo)
{
    QSqlQuery query;
    QString REMOVER_PRODUTO = "DELETE FROM "
            + TABELA_PRODUTOS
            + " WHERE "
            + CHAVE_NOME + "='%1'"
            +" AND "
            + CHAVE_TIPO + "='%2'";


    if(!query.exec(QString(REMOVER_PRODUTO).arg(nome).arg(tipo))){
        qDebug() << query.lastError().text() << " BD[06] ";
    }

    /*if(!query.exec("SELECT * FROM " + TABELA_PRODUTOS)){
        qDebug() << query.lastError().text() << " BD[05] ";
    }

     while(query.next()){
        qDebug() << "passou ";
        qDebug() << query.value(CHAVE_NOME).toString();
        qDebug() << query.value(CHAVE_VALOR).toString();
        qDebug() << query.value(CHAVE_TIPO).toString();
        qDebug() << query.value(CHAVE_ITEM_LISTA).toString();
    }*/
}


void Bd::adicionarCompra(QString data, QString valor, QString pagamento)
{
    QSqlQuery query;
    QString NOVA_COMPRA = "INSERT INTO "
            + TABELA_COMPRAS
            + "("
            + CHAVE_DATA	        + ","
            + CHAVE_VALOR_COMPRA 	+ ","
            + CHAVE_PAGAMENTO	    +
            + ")"
            + "VALUES('%1','%2','%3')";

    if(!query.exec(QString(NOVA_COMPRA).arg(data).arg(valor).arg(pagamento))){
        qDebug() << query.lastError().text() << " BD[07] ";
    }

    query.exec("SELECT * FROM " + TABELA_COMPRAS);

    while(query.next()){
        qDebug() << query.value(CHAVE_DATA).toString();
        qDebug() << query.value(CHAVE_VALOR_COMPRA).toString();
        qDebug() << query.value(CHAVE_PAGAMENTO).toString();
//        qDebug() << query.value(CHAVE_ID_FISICO).toString();
        //qDebug() << query.value(CHAVE_DATA_ALUGADO).toString();
    }

}

void Bd::removerCompra(QString data, QString valor)
{
    QSqlQuery query;
    QString REMOVER_COMPRA = "DELETE FROM "
            + TABELA_COMPRAS
            + " WHERE "
            + CHAVE_DATA  + "='%1'"
            + " AND "
            + CHAVE_VALOR + "='%2'";

    if(!query.exec(QString(REMOVER_COMPRA).arg(data).arg(valor))){
        qDebug() << query.lastError().text() << " BD[08] ";
    }

   /* if(!query.exec("SELECT * FROM " + TABELA_COMPRAS)){
        qDebug() << query.lastError().text() << " BD[09] ";
    }

     while(query.next()){
        qDebug() << "passou ";
        qDebug() << query.value(CHAVE_DATA).toString();
        qDebug() << query.value(CHAVE_VALOR_COMPRA).toString();
        qDebug() << query.value(CHAVE_PAGAMENTO).toString();
    }*/
}

void Bd::adicionarCompraProduto(QString complemento, int eCompra, int eProduto)
{
    QSqlQuery query;
    QString NOVA_COMPRA_PRODUTO = "INSERT INTO "
            + TABELA_COMPRA_PRODUTO
            + "("
            + CHAVE_COMPLEMENTO         + ","
            + CHAVE_ESTRANGEIRA_COMPRA  + ","
            + CHAVE_ESTRANGEIRA_PRODUTO +
            + ")"
            + "VALUES('%1','%2','%3')";

    if(!query.exec(QString(NOVA_COMPRA_PRODUTO).arg(complemento).arg(eCompra).arg(eProduto))){
        qDebug() << query.lastError().text() << " BD[07] ";
    }

  /*   if(!query.exec("SELECT * FROM " + TABELA_COMPRA_PRODUTO)){
         qDebug() << query.lastError().text() << " BD[09] ";
     }

      while(query.next()){
         qDebug() << "passou ";
         qDebug() << query.value(CHAVE_COMPLEMENTO).toString();
         qDebug() << query.value(CHAVE_ESTRANGEIRA_COMPRA).toString();
         qDebug() << query.value(CHAVE_ESTRANGEIRA_PRODUTO).toString();
      }*/
}

void Bd::removerCompraProduto(int eCompra)
{
    QSqlQuery query;
    QString REMOVER_COMPRA_PRODUTO = "DELETE FROM "
            + TABELA_COMPRA_PRODUTO
            + " WHERE "
            + CHAVE_ESTRANGEIRA_COMPRA + "='%1'";

    if(!query.exec(QString(REMOVER_COMPRA_PRODUTO).arg(eCompra))){
        qDebug() << query.lastError().text() << " BD[08] ";
    }

    if(!query.exec("SELECT * FROM " + TABELA_COMPRA_PRODUTO)){
        qDebug() << query.lastError().text() << " BD[09] ";
    }

     while(query.next()){
        qDebug() << "passou ";
        qDebug() << query.value(CHAVE_COMPLEMENTO).toString();
        qDebug() << query.value(CHAVE_ESTRANGEIRA_COMPRA).toString();
        qDebug() << query.value(CHAVE_ESTRANGEIRA_PRODUTO).toString();
     }
}

QList<QStringList> Bd::consultarTabelaProduto()
{
    QSqlQuery query;
    QString CONSULTA = "SELECT * FROM " + TABELA_PRODUTOS;
    if(!query.exec(CONSULTA)){
        qDebug() << query.lastError().text() << " BD[10] ";
    }
    QStringList linhaProdutos;
  //  QList<QStringList> tabelaProdutos;
    QList<QStringList> dataList;
    while(query.next()){
        linhaProdutos.append(query.value(CHAVE_ID_PRODUTO).toString());
        linhaProdutos.append(query.value(CHAVE_NOME).toString());
        linhaProdutos.append(query.value(CHAVE_VALOR).toString());
        linhaProdutos.append(query.value(CHAVE_TIPO).toString());
        linhaProdutos.append(query.value(CHAVE_ITEM_LISTA).toString());
        linhaProdutos.append(linhaProdutos);
//        qDebug() << query.value(CHAVE_ID_PRODUTO).toString();
//        qDebug() << query.value(CHAVE_NOME).toString();
//        qDebug() << query.value(CHAVE_VALOR).toString();
//        qDebug() << query.value(CHAVE_TIPO).toString();
//        qDebug() << query.value(CHAVE_ITEM_LISTA).toString();
        dataList.append(linhaProdutos);
        linhaProdutos.clear();
    }
    return dataList;
}
