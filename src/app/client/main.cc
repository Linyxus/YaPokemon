#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <include/client/PokemonClient.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    PokemonClient client(&app, QHostAddress::LocalHost, 12345);
    client.auth("xyc", "xycxyc");
    auto users = client.get_users();
    for (auto user : users) {
        qDebug() << user.username;
        for (auto pokemon : user.pokemons) {
            qDebug() << pokemon->temp()->name().c_str() << pokemon->level();
        }
    }

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
