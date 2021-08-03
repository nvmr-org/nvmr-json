#ifndef VIDEOSENDERMESSAGE_H
#define VIDEOSENDERMESSAGE_H

#include <QObject>

#include <QJsonObject>

#include "videosenderconfiguration.h"
#include "streaminformation.h"

class VideoSenderMessage
{
public:
    VideoSenderMessage();
    explicit VideoSenderMessage(QJsonObject obj);

    QString command() const;
    VideoSenderMessage& setCommand( QString command );

    VideoSenderConfiguration configuration() const;
    VideoSenderConfiguration& mutuable_configuration();

    StreamInformation streaminformation() const;
    StreamInformation& mutable_streaminformation();

    QJsonObject jsonObj();
private:
    QString m_command;
    bool m_hasConfiguration;
    VideoSenderConfiguration m_configuration;
    StreamInformation m_streamInformation;
};

#endif // VIDEOSENDERMESSAGE_H
