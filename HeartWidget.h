#ifndef HEAERWIDGET_H
#define HEAERWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QTimer>
#include <QMediaPlayer>
#include <QApplication>
#include <QDesktopWidget>
#include <cmath>
#include <QDebug>
#include <QLabel>

class HeartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HeartWidget(QWidget *parent = 0);
    ~HeartWidget();
    void initWindow();
    void initTimer();
    void initMusic();

protected:
    void paintEvent(QPaintEvent *event);

private:
    const double PI = 3.1415926;
    QTimer *timer;
    QPainter *painter;
    QMediaPlayer *player;
    int w, h;
    // 定义分辨率标识,适配多种分别率
    // 0 -> 1920 * 1080
    // 1 -> 1366 * 768
    int resolution;
};

#endif // HEAERWIDGET_H
