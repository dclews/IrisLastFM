#include "LFMCommandFactory.hpp"
#include "LFMCommand.hpp"

namespace iris
{
    LFMCommandFactory::LFMCommandFactory()
    {
    }
    ASyncCommand* LFMCommandFactory::newCommand()
    {
        return new LFMCommand;
    }

    QString LFMCommandFactory::syntax()
    {
        return QString("LFM FOLLOW <user>");
    }

    bool LFMCommandFactory::isListener()
    {
        return false;
    }
}

