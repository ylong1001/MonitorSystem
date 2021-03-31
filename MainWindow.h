#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SysConfig.h"
#include "sqliteutil.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showCurrentTime();
    void createXmlConfigFile();
    quint64 getDosFsDiskFreeSpace(void);
    QStringList cfgStrList;
private:
    Ui::MainWindow *ui;
    int showDateTimeId;
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H
