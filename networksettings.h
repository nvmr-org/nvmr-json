#ifndef NETWORKSETTINGS_H
#define NETWORKSETTINGS_H

#include <QJsonObject>
#include <QJsonValue>

class NetworkSettings
{
public:
    NetworkSettings();
    NetworkSettings( QJsonValue val );

    QString udpHost() const;
    NetworkSettings& setUdpHost( QString host );

    int udpPort() const;
    NetworkSettings& setUdpPort( int port );

    bool broadcast() const;
    void setBroadcast( bool broadcast );

    QJsonObject jsonObj() const;

private:
    QString m_udpHost;
    int m_port;
    bool m_broadcast;
};

#endif // NETWORKSETTINGS_H
