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
}

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

    return obj;
}
