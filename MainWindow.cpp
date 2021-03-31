#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDate>
#include <QStringList>
#include "XmlHelperPrivate.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setAttribute(Qt::WA_TranslucentBackground);
    //setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);//任务栏使程序最小化

    showDateTimeId = startTimer(1000);       //启动定时器，1秒一次

    createXmlConfigFile();

    SqliteUtil* sql = new SqliteUtil("testvxdb","my_conn");
}

MainWindow::~MainWindow()
{
    killTimer(showDateTimeId);
    delete ui;
}

void MainWindow::createXmlConfigFile()
{
    XmlHelperPrivate xml;
    xml.beginIO("config.xml", true, "Root");
#if 1
    xml.updateElem("用户信息", "", true);

    //xml.addChildTextNode("layout", "网卡名称", "xxxx", xml.strmap_t);

    QMap<QString, QString> attrmap;
    attrmap.insert("name", "张三");
    attrmap.insert("age", "30");

    xml.addChildAttrNode("用户信息", "Node", attrmap, xml.strmap_t);
    //attrmap["index"] = "2x";
    //xml.addChildAttrNode("config", "Static", attrmap,xml.strmap_t);

    //QMap<QString, QString> attrmap2 = attrmap;
    //attrmap2["uid"] = "test2";
    //xml.addChildAttrNode("config/Static", "Field", attrmap2, attrmap);
    //xml.addChildTextNode("config/Static", "Field2", "xxx", attrmap);
#else
    QMap<QString, QString> attrmap2;
    attrmap2["uid"] = "test2";
    xml.removeElem("config/Static", attrmap2);
    bool ok = xml.findElement("config/Static", attrmap2);
    qDebug()<<"find result:"<<ok;
    //xml.removeAttr("config/Static", "index", attrmap2);
     QStringList cfgStrList = xml.getElemValue("config/Static");
     for(QStringList::iterator iter = cfgStrList.begin();iter != cfgStrList.end(); iter++)
     {
         qDebug()<<*iter;
     }
//     QStringList attrList = xml.getAttrValue("config/Static", "uid");
//     xml.toComment("config/Static", true);
#endif
    xml.saveIO();
    xml.endIO();
}

quint64 MainWindow::getDosFsDiskFreeSpace(void)
{
    quint64      retStat = 0;
#if 0
    //Copies to <freeCount> the amount of free space, in bytes, on the volume.
    //This function can return value in 64-bit range:

       int 	fd;
       long long freeCount = 0;
       
       fd = open("/ata0a",O_RDONLY, 0);

       if (ERROR == fd)
       {
           printf("open ata0a disk failed \n");
           return (ERROR);
       }

       retStat = ioctl(fd, FIONFREE64, &freeCount);
       close(fd);
#endif
       return (retStat);
}

void MainWindow::timerEvent(QTimerEvent *event)       //定时器事件
{
    if(event->timerId() == showDateTimeId)       //判断是否为相应的定时器
    {
        showCurrentTime();      //显示时间
    }
}

void MainWindow::showCurrentTime()    //在窗体右下角显示时间
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    int n = date.dayOfWeek();
    QString week;
    switch(n)
    {
    case 1:
        week = tr("星期一");
        break;
    case 2:
        week = tr("星期二");
        break;
    case 3:
        week = tr("星期三");
        break;
    case 4:
        week = tr("星期四");
        break;
    case 5:
        week = tr("星期五");
        break;
    case 6:
        week = tr("星期六");
        break;
    case 7:
        week = tr("星期天");
        break;
    }
    QString dateAndTime = date.toString("yyyy-MM-dd") + QString(" ")
            + time.toString("hh:mm:ss") + QString(" ") + week;
    //时间格式为年-月-日 小时：分钟：秒 星期
    ui->Label_showDateTime->setText(dateAndTime);
}
