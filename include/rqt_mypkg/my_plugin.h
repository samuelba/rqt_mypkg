#pragma once

#include <rqt_gui_cpp/plugin.h>

#include <ui_my_plugin.h>

#include <ros/ros.h>
#include <ros/master.h>
#include <ros/macros.h>

#include <QList>
#include <QString>
#include <QSize>
#include <QWidget>
#include <QObject>
#include <QEvent>
#include <QTableView>
#include <QResizeEvent>

#include <QApplication>
#include <QLabel>
#include <QPainter>

#include <vector>

namespace rqt_mypkg {

class MyPlugin
  : public rqt_gui_cpp::Plugin {

    Q_OBJECT

private:
    const char* TAG = "mission_monitor";
public:
    MyPlugin();
    
    virtual void initPlugin(qt_gui_cpp::PluginContext& context);
    virtual void shutdownPlugin();
    virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings, 
                              qt_gui_cpp::Settings& instance_settings) const;
    virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings, 
                                 const qt_gui_cpp::Settings& instance_settings);

protected slots:

protected:
    Ui::MyPluginWidget ui_;
    QWidget* widget_;
    ros::NodeHandle nh_;

};

}
