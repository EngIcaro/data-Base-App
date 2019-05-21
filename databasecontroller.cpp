#include "databasecontroller.h"

DataBaseController::DataBaseController(QObject *parent) : QObject(parent)
{

}

void DataBaseController::inicarBancoDeDados()
{
    Bd *newBd = new Bd();
    newBd->setarBancoDeDados();
    newBd->criarTabelas();
}

void DataBaseController::novoProduto(QString nome, QString valor, QString tipo, QString item)
{
    Bd *newBd = new Bd();
    newBd->adicionarProduto(nome,valor,tipo,item);
}

void DataBaseController::removerProduto(QString nome, QString tipo)
{
    Bd *newBd = new Bd();
    newBd->removerProduto(nome,tipo);
}

QList<QStringList> DataBaseController::consultarProdutos()
{
    Bd *newBd = new Bd();
    return newBd->consultarTabelaProduto();
}
