//
// Created by Yichen Xu on 2020/9/2.
//

#include <QCoreApplication>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDebug>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    // test code: json
    json j;
    j["test"] = "hello, world";
    j["list"] = {1, 2, "3"};
    QString s = j.dump().c_str();
    qDebug() << s;

    // test code: a print-out udp listening server
    auto sock = new QUdpSocket(&app);
    sock->bind(QHostAddress::LocalHost, 4567);
    QObject::connect(sock, &QUdpSocket::readyRead, &app, [sock]() {
        while (sock->hasPendingDatagrams()) {
            auto dgram = sock->receiveDatagram();
            QString s(dgram.data());
            qDebug() << s;
        }
    });

    return QCoreApplication::exec();
}

