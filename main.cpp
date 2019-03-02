// 2017年8月23日
#include "HeartWidget.h"
#include "FireWidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FireWidget fw;
    fw.show();

    //HeartWidget hw;
    //hw.show();

    return a.exec();
}
