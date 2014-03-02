#ifndef LFMCOMMANDFACTORY_HPP
#define LFMCOMMANDFACTORY_HPP

#include <QObject>
#include <iris/CommandPluginFactory.hpp>

namespace iris
{
    class LFMCommand;
    class LFMCommandFactory : public QObject, public CommandPluginFactory
    {
        Q_OBJECT
    public:
        explicit LFMCommandFactory();
    public slots:
        ASyncCommand* newCommand();
        QString syntax();

        // CommandPluginFactory interface
    public:
        bool isListener();
    };
}


#endif // LFMCOMMANDFACTORY_HPP

