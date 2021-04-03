#include "videosendermessage.h"

VideoSenderMessage::VideoSenderMessage(QJsonObject obj, QObject *parent) :
    QObject(parent)
{
    if( obj.contains( "command" ) ){
        m_command = obj.value( "command" ).toString();
    }

    if( obj.contains( "configuration" ) ){
        m_configuration = VideoSenderConfiguration( obj.value( "configuration" ) );
    }

    if( obj.contains( "stream" ) ){
        m_streamInformation = StreamInformation( obj.value( "stream" ) );
    }
}

VideoSenderMessage::VideoSenderMessage(QObject* parent) :
    QObject(parent)
{}

QString VideoSenderMessage::command() const{
    return m_command;
}

VideoSenderMessage& VideoSenderMessage::setCommand( QString command ){
    m_command = command;
    return *this;
}

VideoSenderConfiguration VideoSenderMessage::configuration() const{
    return m_configuration;
}

VideoSenderConfiguration& VideoSenderMessage::mutuable_configuration(){
    return  m_configuration;
}

QJsonObject VideoSenderMessage::jsonObj(){
    QJsonObject obj;

    if( !m_command.isNull() ){
        obj.insert( "command", m_command );
    }

    obj.insert( "configuration", m_configuration.jsonObj() );

    if( !m_streamInformation.isNull() ){
        obj.insert( "stream", m_streamInformation.jsonObj() );
    }

    return obj;
}

StreamInformation VideoSenderMessage::streaminformation() const {
    return m_streamInformation;
}

StreamInformation& VideoSenderMessage::mutable_streaminformation(){
    return m_streamInformation;
}
