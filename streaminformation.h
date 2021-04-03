#ifndef STREAMINFORMATION_H
#define STREAMINFORMATION_H

#include <QJsonObject>

class StreamInformation
{
public:
    StreamInformation();
    StreamInformation(QJsonValue obj);

    int port() const;
    void setPort( int port );

    bool isNull() const;

    QJsonObject jsonObj() const;

private:
    bool m_isNull;
    int m_port;
};

#endif // STREAMINFORMATION_H
