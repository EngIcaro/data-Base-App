#ifndef DATABASECONTROLLER_H
#define DATABASECONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <bd.h>

class DataBaseController : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseController(QObject *parent = nullptr);

    void inicarBancoDeDados();

    Q_INVOKABLE void novoProduto(QString nome, QString valor, QString tipo, QString item);
    Q_INVOKABLE void removerProduto(QString nome, QString tipo);

    QList<QStringList> consultarProdutos();
   // Q_PROPERTY(
signals:
    void resetProperty();

public slots:


};

class SqlModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    SqlModel(QObject* parent = 0)
        : QSqlQueryModel(parent)
    {
        roleNamesHash.insert(Qt::UserRole,      QByteArray("idProduto"));
        roleNamesHash.insert(Qt::UserRole + 1,  QByteArray("nome"));
        roleNamesHash.insert(Qt::UserRole + 2,  QByteArray("valor"));
        roleNamesHash.insert(Qt::UserRole + 3,  QByteArray("tipo"));
        roleNamesHash.insert(Qt::UserRole + 4,  QByteArray("item"));
    }
   Q_INVOKABLE void refresh(){
        this->setQuery(SQL_SELECT);
    }
    QVariant data(const QModelIndex& index, int role) const
    {
        if(role < Qt::UserRole)
            return QSqlQueryModel::data(index, role);

        QSqlRecord r = record(index.row());
        return r.value(role - Qt::UserRole);
    }

    QHash<int, QByteArray> roleNames() const { return roleNamesHash; }
    //char* SQL_SELECT() const {return "ola";}
    const char* SQL_SELECT = "SELECT * FROM produtos";
private:
    QHash<int, QByteArray> roleNamesHash;
};

#endif // DATABASECONTROLLER_H
