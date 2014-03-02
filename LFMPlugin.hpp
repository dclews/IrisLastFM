#ifndef LFMPLUGIN_HPP
#define LFMPLUGIN_HPP

#include <QObject>
#include <QtPlugin>

#include <iris/CommandPlugin.hpp>
#include <iris/CommandPluginFactory.hpp>

class LFMPlugin : public QObject, public CommandPlugin
{
private:
    Q_OBJECT
    Q_PLUGIN_METADATA(IID CommandPlugin_iid FILE "plugin.json")
    Q_INTERFACES(CommandPlugin)
public:
    LFMPlugin();
    ~LFMPlugin();
    QList<iris::CommandPluginFactory*> commands() const;
};

#endif // LFMPLUGIN_HPP
