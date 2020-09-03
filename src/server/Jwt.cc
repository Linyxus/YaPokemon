//
// Created by Yichen Xu on 2020/9/3.
//

#include <include/server/Jwt.h>
#include <QMessageAuthenticationCode>
#include <QString>
#include <QList>

QByteArray encode_jwt(const json& payload, const QByteArray& secret) {
    QByteArray payload_base64 = QByteArray::fromStdString(payload.dump()).toBase64();
    json header;
    header["alg"] = "hs256";
    header["typ"] = "jwt";
    QByteArray header_base64 = QByteArray::fromStdString(header.dump()).toBase64();
    QByteArray sig = QMessageAuthenticationCode::hash(header_base64 + "." + payload_base64, secret,
                                                      QCryptographicHash::Sha256).toBase64();
    return header_base64 + "." + payload_base64 + "." + sig;
}

bool verify_jwt(const QByteArray &jwt, const QByteArray &secret) {
    auto l = jwt.split('.');
    assert(l.length() == 3);
    QByteArray header_base64 = l[0];
    QByteArray payload_base64 = l[1];
    QByteArray sig_base64 = l[2];

    QByteArray sig = QMessageAuthenticationCode::hash(header_base64 + "." + payload_base64, secret,
                                                      QCryptographicHash::Sha256).toBase64();
    return sig == sig_base64;
}

json decode_jwt(const QByteArray &jwt) {
    auto l = jwt.split('.');
    assert(l.length() == 3);
    QByteArray payload_base64 = QByteArray::fromBase64(l[1]);

    return json::parse(payload_base64.constData());
}
