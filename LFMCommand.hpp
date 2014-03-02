#ifndef LFMCOMMAND_HPP
#define LFMCOMMAND_HPP

#include <QObject>
#include <iris/ASyncCommand.hpp>
#include <QPointer>
#include <QNetworkReply>
#include <IrcCommand>
#include <lastfm/User.h>

class IrcCommand;
class QTimer;

namespace iris
{
    class LFMCommand : public ASyncCommand
    {
    private:
        Q_OBJECT
        QString lfmCommand;
        QNetworkReply* reply;
        QNetworkReply* mRecentTrackReply;
        lastfm::User user;
        QTimer* timer;

    public:
        explicit LFMCommand();
        ~LFMCommand();

    signals:
        void printLine(QString nick, QString line);
        void commandDone(int exitCode);

    public slots:
        // ASyncCommand interface
        QString syntax();
        void exec();
        //@Override
        void setCommand(IrcCommand* cmd);
    private slots:
        void gotRecentTracks();
        void getRecentTracks();
    };
}

#endif // LFMCOMMAND_HPP

