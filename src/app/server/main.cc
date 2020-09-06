//
// Created by Yichen Xu on 2020/9/2.
//

#include <QCoreApplication>
#include <include/server/PokemonServer.h>
#include <QNetworkDatagram>
#include <QDebug>
#include <include/server/Jwt.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);
    srand(time(NULL));

    PokemonServer server(&app, 12345);

    return QCoreApplication::exec();
}

