#include "videosettings.h"

VideoSettings::VideoSettings() :
    m_id( -1 ),
    m_width( -1 ),
    m_height( -1 ),
    m_configInterval( -1 ),
    m_pt( -1 ),
    m_framerate( -1 ){

}

VideoSettings::VideoSettings( QJsonValue val ) :
    VideoSettings() {
    if( !val.isObject() ){
        return;
    }

    QJsonObject obj = val.toObject();
    m_id = obj.value( "id" ).toInt();
    m_name = obj.value( "name" ).toString();
    m_width = obj.value( "width" ).toInt();
    m_height = obj.value( "height" ).toInt();
    m_configInterval = obj.value( "config-interval" ).toInt();
    m_pt = obj.value( "pt" ).toInt();
    m_framerate = obj.value( "framerate" ).toInt();
}

int VideoSettings::id() const{
    return m_id;
}

VideoSettings& VideoSettings::setId( int id ){
    m_id = id;
    return *this;
}

QString VideoSettings::name() const{
    return m_name;
}

VideoSettings& VideoSettings::setName( QString name ){
    m_name = name;
    return *this;
}

int VideoSettings::width() const{
    return m_width;
}

VideoSettings& VideoSettings::setWidth( int width ){
    m_width = width;
    return *this;
}

int VideoSettings::height() const{
    return m_height;
}

VideoSettings& VideoSettings::setHeight( int height ){
    m_height = height;
    return *this;
}

int VideoSettings::configInterval() const{
    return m_configInterval;
}

VideoSettings& VideoSettings::setConfigInterval( int interval ){
    m_configInterval = interval;
    return *this;
}

int VideoSettings::pt() const{
    return m_pt;
}

VideoSettings& VideoSettings::setPt( int pt ){
    m_pt = pt;
    return *this;
}

int VideoSettings::framerate() const{
    return m_framerate;
}

VideoSettings& VideoSettings::setFramerate( int framerate ){
    m_framerate = framerate;
    return *this;
}

QJsonObject VideoSettings::jsonObj() const{
    QJsonObject obj;

    obj.insert( "id", m_id );
    obj.insert( "name", m_name );
    obj.insert( "width", m_width );
    obj.insert( "height", m_height );
    obj.insert( "config-interval", m_configInterval );
    obj.insert( "pt", m_pt );
    obj.insert( "framerate", m_framerate );

    return obj;
}
