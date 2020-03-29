#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "appcore.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    AppCore appCore;    // Создаём ядро приложения

    QQmlContext *context = engine.rootContext();    // Создаём корневой контекст
    /* Загружаем объект в контекст для установки соединения,
     * а также определяем имя, по которому будет происходить соединение
     * */
    context->setContextProperty("appCore", &appCore);

    // И загружаем в него исходники qml
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));

    return app.exec();
}
