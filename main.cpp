#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "jsonwatcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<JSONWatcher>("fernando.quick", 1, 0, "JSWatcher");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    //JSONWatcher *json;
    //json = new JSONWatcher();

    //json->statusTest();

    return app.exec();
}
