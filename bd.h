#ifndef BD_H
#define BD_H
#include "QSqlDatabase"
#include <QSqlError>
#include <QSqlQuery>
#include <QObject>
#include <QDebug>
#include <QString>
#include <QSqlQueryModel>
#include <QtSql>

class Bd : public QObject
{

    Q_OBJECT
public:
    explicit Bd(QObject *parent = nullptr);
    void setarBancoDeDados    ();
    void criarTabelas           ();

    void adicionarProduto       (QString nome, QString valor, QString tipo, QString item);
    void removerProduto         (QString nome, QString tipo);

    void adicionarCompra        (QString data, QString valor, QString pagamento);
    void removerCompra          (QString data, QString valor);

    void adicionarCompraProduto (QString complemento, int eCompra, int eProduto);
    void removerCompraProduto   (int eCompra);
    QList<QStringList> consultarTabelaProduto ();

   //void setarChaveEstrangeira(Livro *livro, int novaChave);
   // void editarEstudante(Estudante *estudante);
   // void editarLivro(Livro *livro);
   //QQmlObjectListModel<Estudante> capturarEstudantes();
   // QQmlObjectListModel<Estudante> capturarLivros();
private:

    QSqlDatabase m_bancoDeDados;

    //BANCO DE PRODUTOS
    const QString TABELA_PRODUTOS = "produtos";


    //COLUNAS DO BANCO DE PRODUTOS
    const QString CHAVE_ID_PRODUTO = "idProduto";
    const QString CHAVE_NOME       = "nome";
    const QString CHAVE_VALOR      = "valor";
    const QString CHAVE_TIPO       = "tipo";
    const QString CHAVE_ITEM_LISTA = "item";


    //BANCO DE COMPRAS
    const QString TABELA_COMPRAS = "livros";


    //COLUNAS DO BANCO DE COMPRAS
    const QString CHAVE_ID_COMPRA    = "idCompra";
    const QString CHAVE_DATA         = "data";
    const QString CHAVE_VALOR_COMPRA = "valor";
    const QString CHAVE_PAGAMENTO    = "pagamento";

    //BANCO DE COMPRA_PRODUTO
    const QString TABELA_COMPRA_PRODUTO     = "compraProduto";

    //COLUNAS DO BANCO COMPRA_PRODUTO
    const QString CHAVE_ID_COMPRA_PRODUTO   = "idCompraProduto";
    const QString CHAVE_COMPLEMENTO         = "complemento";
    const QString CHAVE_ESTRANGEIRA_COMPRA  = "eCompra";
    const QString CHAVE_ESTRANGEIRA_PRODUTO = "eProduto";
    //
signals:

public slots:
};

#endif // BD_H

