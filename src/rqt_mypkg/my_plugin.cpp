#include "rqt_mypkg/my_plugin.h"

#include <pluginlib/class_list_macros.h>
#include <ros/master.h>

namespace rqt_mypkg {

/**
 * @brief MyPlugin::MyPlugin
 */
MyPlugin::MyPlugin()
    : rqt_gui_cpp::Plugin()
    , widget_(0) {
    
    setObjectName("MyPlugin");
}

/**
 * @brief MyPlugin::initPlugin
 * @param context
 */
void MyPlugin::initPlugin(qt_gui_cpp::PluginContext& context) {
    widget_ = new QWidget();
    ui_.setupUi(widget_);
    if (context.serialNumber() > 1) {
        widget_->setWindowTitle(widget_->windowTitle() + " (" + QString::number(context.serialNumber()) + ")");
    }
    context.addWidget(widget_);
}

/**
 * @brief MyPlugin::shutdownPlugin
 */
void MyPlugin::shutdownPlugin() {
}

/**
 * @brief MyPlugin::saveSettings
 * @param plugin_settings
 * @param instance_settings
 */
void MyPlugin::saveSettings(qt_gui_cpp::Settings& plugin_settings,
                               qt_gui_cpp::Settings& instance_settings) const {
}

/**
 * @brief MyPlugin::restoreSettings
 * @param plugin_settings
 * @param instance_settings
 */
void MyPlugin::restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
                                  const qt_gui_cpp::Settings& instance_settings) {
}

} // namespace

PLUGINLIB_EXPORT_CLASS(rqt_mypkg::MyPlugin, rqt_gui_cpp::Plugin)
