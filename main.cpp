#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <openglitem.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    app.setAttribute(Qt::AA_UseDesktopOpenGL);
    qmlRegisterType<OpenGLItem>("an.OpenGLItem", 1, 0, "OpenGLItem");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
