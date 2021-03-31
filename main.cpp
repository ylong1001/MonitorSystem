#include "MainWindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));   //设置编码
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));//设置编码

    MainWindow w;
    w.show();

    return a.exec();
}
