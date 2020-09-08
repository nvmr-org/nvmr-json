#ifndef VIDEOSENDERCONFIGURATION_H
#define VIDEOSENDERCONFIGURATION_H

#include <QJsonValue>
#include <QJsonObject>

#include "videosettings.h"
#include "networksettings.h"

class VideoSenderConfiguration
{
public:
    explicit VideoSenderConfiguration(QJsonValue obj);
    VideoSenderConfiguration();

    bool isNull() const;

    QString uuid() const;
    VideoSenderConfiguration& setUuid( QString uuid );

    VideoSettings videoSettings() const;
    VideoSettings& mutable_videoSettings();

    NetworkSettings networkSettings() const;
    NetworkSettings& mutable_networkSettings();

    QJsonObject jsonObj() const;

private:
    bool m_isNull;
    QString m_uuid;
    VideoSettings m_videoSettings;
    NetworkSettings m_networkSettings;
};

#endif // VIDEOSENDERCONFIGURATION_H
