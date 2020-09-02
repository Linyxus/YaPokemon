//
// Created by Yichen Xu on 2020/9/2.
//

#include <QCoreApplication>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QDebug>

using namespace std;

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

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

