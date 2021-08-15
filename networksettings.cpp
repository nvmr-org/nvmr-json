#include "networksettings.h"

NetworkSettings::NetworkSettings() :
    m_port( 0 ),
    m_broadcast( false ){

}

NetworkSettings::NetworkSettings( QJsonValue val ){
    if( !val.isObject() ){
        return;
    }

    QJsonObject obj = val.toObject();
    m_udpHost = obj.value( "udp-host" ).toString();
    m_port = obj.value( "udp-port" ).toInt();
    m_broadcast = obj.value( "broadcast" ).toBool();
}

QString NetworkSettings::udpHost() const{
    return m_udpHost;
}

NetworkSettings& NetworkSettings::setUdpHost( QString host ){
    m_udpHost = host;
    return *this;
}

int NetworkSettings::udpPort() const{
    return m_port;
}

NetworkSettings& NetworkSettings::setUdpPort( int port ){
    m_port = port;
    return *this;
}

QJsonObject NetworkSettings::jsonObj() const{
    QJsonObject obj;

    obj.insert( "udp-host", m_udpHost );
    obj.insert( "udp-port", m_port );
    obj.insert( "broadcast", m_broadcast );

    return obj;
}

bool NetworkSettings::broadcast() const {
    return m_broadcast;
}

void NetworkSettings::setBroadcast( bool broadcast ){
    m_broadcast = broadcast;
}
