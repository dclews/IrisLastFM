#include "LFMCommand.hpp"
#include <lastfm/Track.h>
#include <lastfm/XmlQuery.h>
#include <QTimer>

namespace iris
{
    LFMCommand::LFMCommand()
    {

    }
    LFMCommand::~LFMCommand()
    {

    }
    void LFMCommand::exec()
    {
        //Based on: https://github.com/lastfm/liblastfm/blob/master/demos/demo1.cpp
        // deleting a reply cancels the request and disconnects all signals

        lastfm::ws::ApiKey = "0dba4d466298a3b4f4d1a6ed81d0aac1";

        qDebug() << "[LastFM] exec()";
        if(lfmCommand == "FOLLOW")
        {
            user = lastfm::User(parameters.at(2));
            qDebug() << "[LastFM] Following user: " << user.name();

            timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), this, SLOT(getRecentTracks()));
            timer->start(20000);
        }
    }
    void LFMCommand::getRecentTracks()
    {
        reply = user.getRecentTracks(1, 1);
        connect(reply, SIGNAL(finished()), this, SLOT(gotRecentTracks()));
    }

    void LFMCommand::setCommand(IrcCommand* cmd)
    {
        ASyncCommand::setCommand(cmd);
        lfmCommand = parameters.at(1);
    }
    QString LFMCommand::syntax()
    {
        return QString("LFM FOLLOW <user>");
    }
    void LFMCommand::gotRecentTracks()
    {
        qDebug() << "[LastFM] Got recent track list.";
        int status = 1;
        lastfm::XmlQuery lfm;

        mRecentTrackReply = static_cast<QNetworkReply*>(sender());

        if(!mRecentTrackReply)
        {
            qDebug() << "[LastFM] [Error] Reply was null!";
        }
        else if (lfm.parse(mRecentTrackReply))
        {
            qDebug() << "[LastFM] Got valid reply";
            foreach ( const lastfm::XmlQuery& trackXml, lfm["recenttracks"].children("track") )
            {
//                if ( trackXml.attribute( "nowplaying" ) == "true" )
//                {
                    QString msg = user.name() + " is now listening to " + trackXml["name"].text() + " by " + trackXml["artist"]["name"].text();
                    printLine(target, msg);
                    status = 0;
//                }
            }
        }

        if(mRecentTrackReply) mRecentTrackReply->deleteLater();
        if(reply) reply->deleteLater();
    }
}
