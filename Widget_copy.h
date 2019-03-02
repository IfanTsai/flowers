#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QTimer>
#include <QMediaPlayer>
#include <cmath>
#include <QDebug>

//#define MAX_SIZE 173

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void initWindow();
    void initTimer();
    void initMusic();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Widget *ui;
    QTimer *timer;
    QPainter *painter;
    QMediaPlayer *player;
};

#endif // WIDGET_H
