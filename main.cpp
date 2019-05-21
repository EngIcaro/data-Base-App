#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "databasecontroller.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    DataBaseController *base = new DataBaseController;
    base->inicarBancoDeDados();
    base->novoProduto("Executivo de porco","30.50","1","executivos");
    base->novoProduto("Executivo de Galeto","30.50","1","executivos");
    SqlModel sqlModel;
    sqlModel.setQuery(sqlModel.SQL_SELECT);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("baseController", base);
    engine.rootContext()->setContextProperty("sqlModel", &sqlModel);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
