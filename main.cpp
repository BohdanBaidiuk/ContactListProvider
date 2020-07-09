#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include "clplist.h"
#include "clpmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<CLPModel>("CLP",1,0,"CLPModel");
    qmlRegisterUncreatableType<CLPList>("CLP",1,0,"CLPList",QStringLiteral("CLPList shod not be created in qml"));

    CLPList clpList;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("clpList"),&clpList);
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
