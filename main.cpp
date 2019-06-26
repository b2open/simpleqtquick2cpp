#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "myclass.h"


/**
 * @refemce https://doc.qt.io/qt-5/qtqml-cppintegration-exposecppattributes.html#
 */


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QQuickStyle::setStyle("Material");

    QGuiApplication app(argc, argv);

    QScopedPointer<MyClass> myClass(new MyClass());

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("MyClass", myClass.data());
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
