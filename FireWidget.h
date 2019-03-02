#ifndef FIREWIDGET_H
#define FIREWIDGET_H

#include <QWidget>
#include <QPalette>
#include <QLabel>
#include <QMovie>
#include <QColor>
#include <QDebug>
#include <QTimer>
#include <QMediaPlayer>
#include <QPixmap>
#include <QPainter>
#include <QFont>
#include <QString>
#include <cstring>
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>
#include <QScreen>
#include <QGuiApplication>
#include <HeartWidget.h>

class FireWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FireWidget(QWidget *parent = nullptr);
    void initMusic();
    void playMovie(QLabel *label);

private:
    QMediaPlayer *player;
    char *text = "送\n给\n我\n大\n学\n唯\n一\n的\n一\n个\n喜\n欢\n的\n女\n生";
    int i = 1;
    int w, h;
    // 定义分辨率标识,适配多种分别率
    // 0 -> 1920 * 1080
    // 1 -> 1366 * 768
    int resolution;

protected:

signals:

public slots:
};

#endif // FIREWIDGET_H
