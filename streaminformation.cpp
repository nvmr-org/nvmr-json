#include "streaminformation.h"

StreamInformation::StreamInformation() :
    m_isNull( true ),
    m_port( 0 ){}

StreamInformation::StreamInformation(QJsonValue val) :
    m_isNull( true ),
    m_port( 0 )
{
    if( !val.isObject() ){
        return;
    }

    QJsonObject obj = val.toObject();
    m_isNull = false;

    m_port = obj.value( "port" ).toInt();
}

int StreamInformation::port() const {
    return m_port;
}

void StreamInformation::setPort( int port ){
    m_port = port;
    if( m_port <= 0 ){
        m_isNull = true;
    }else if( m_port >= 65535 ){
        m_isNull = true;
    }else{
        m_isNull = false;
    }
}

bool StreamInformation::isNull() const {
    return m_isNull;
}

QJsonObject StreamInformation::jsonObj() const {
    QJsonObject obj;

    obj.insert( "port", m_port );

    return obj;
}
