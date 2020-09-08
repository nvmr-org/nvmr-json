#include "videosenderconfiguration.h"

VideoSenderConfiguration::VideoSenderConfiguration(QJsonValue val) :
    m_isNull( true )
{
    if( !val.isObject() ){
        return;
    }

    QJsonObject obj = val.toObject();
    m_isNull = false;

    m_uuid = obj.value( "device-uuid" ).toString();

    m_videoSettings = VideoSettings( obj.value( "video" ) );
    m_networkSettings = NetworkSettings( obj.value( "network" ) );
}

VideoSenderConfiguration::VideoSenderConfiguration() :
    m_isNull( true ) {

}

bool VideoSenderConfiguration::isNull() const{
    return m_isNull;
}

QString VideoSenderConfiguration::uuid() const{
    return m_uuid;
}

VideoSenderConfiguration& VideoSenderConfiguration::setUuid( QString uuid ){
    m_uuid = uuid;
    return *this;
}

NetworkSettings VideoSenderConfiguration::networkSettings() const{
    return m_networkSettings;
}

NetworkSettings& VideoSenderConfiguration::mutable_networkSettings(){
    return m_networkSettings;
}

QJsonObject VideoSenderConfiguration::jsonObj() const{
    QJsonObject obj;

    obj.insert( "device-uuid", m_uuid );
    obj.insert( "video", m_videoSettings.jsonObj() );
    obj.insert( "network", m_networkSettings.jsonObj() );

    return obj;
}
