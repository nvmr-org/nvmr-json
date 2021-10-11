#ifndef VIDEOSETTINGS_H
#define VIDEOSETTINGS_H

#include <QJsonObject>
#include <QJsonValue>
#include <QString>

class VideoSettings
{
public:
    VideoSettings();
    VideoSettings( QJsonValue val );

    int id() const;
    VideoSettings& setId( int id );

    QString name() const;
    VideoSettings& setName( QString name );

    int width() const;
    VideoSettings& setWidth( int width );

    int height() const;
    VideoSettings& setHeight( int height );

    int configInterval() const;
    VideoSettings& setConfigInterval( int interval );

    int pt() const;
    VideoSettings& setPt( int pt );

    int framerate() const;
    VideoSettings& setFramerate( int framerate );

    int rotation() const;
    VideoSettings& setRotation( int rotation );

    QJsonObject jsonObj() const;

private:
    int m_id;
    QString m_name;
    int m_width;
    int m_height;
    int m_configInterval;
    int m_pt;
    int m_framerate;
    int m_rotation;
};

#endif // VIDEOSETTINGS_H
