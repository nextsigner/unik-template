#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "uk.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<UK>("uk", 1, 0, "UK");
    engine.load(QUrl(QLatin1String("main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
