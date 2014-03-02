#include "LFMPlugin.hpp"
#include "LFMCommandFactory.hpp"

LFMPlugin::LFMPlugin()
{
}

LFMPlugin::~LFMPlugin()
{
}

QList<iris::CommandPluginFactory*> LFMPlugin::commands() const
{
    QList<iris::CommandPluginFactory*> commands;
    commands << new iris::LFMCommandFactory;
    return commands;
}
