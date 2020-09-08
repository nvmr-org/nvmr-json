#ifndef VIDEOSENDERMESSAGE_H
#define VIDEOSENDERMESSAGE_H

#include <QObject>

#include <QJsonObject>

#include "videosenderconfiguration.h"

class VideoSenderMessage : public QObject
{
    Q_OBJECT
public:
    explicit VideoSenderMessage(QJsonObject obj, QObject *parent = nullptr);

    QString command() const;
    VideoSenderMessage& setCommand( QString command );

    VideoSenderConfiguration configuration() const;
    VideoSenderConfiguration& mutuable_configuration();

    QJsonObject jsonObj();

signals:

public slots:
private:
    QString m_command;
    bool m_hasConfiguration;
    VideoSenderConfiguration m_configuration;
};

#endif // VIDEOSENDERMESSAGE_H
