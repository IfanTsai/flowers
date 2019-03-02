#include "HeartWidget.h"

HeartWidget::HeartWidget(QWidget *parent) :
    QWidget(parent)
{
    initMusic();
    initWindow();
    initTimer();
}

HeartWidget::~HeartWidget()
{

}

void HeartWidget::initWindow()
{
    // 设置程序不在任务栏显示且窗体无边框 ^_^
    this->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    // 窗口整体透明，但窗口控件不透明
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    // 全屏显示
    this->showFullScreen();

    // 设置分别率
    QRect screenRect = QApplication::desktop()->screenGeometry();
    w = screenRect.width();
    h = screenRect.height();
    if (w == 1920)
        resolution = 0;
    else if (w <= 1400 && w >= 1280)
        resolution = 1;
    else
        resolution = 1;
}

void HeartWidget::initTimer()
{
    timer = new QTimer(this);
    //timer->setInterval(100);
    timer->start(8);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

void HeartWidget::initMusic()
{
    player = new QMediaPlayer(this);
    player->setMedia(QMediaContent(QUrl("qrc:/new/prefix2/mp3/vae.mp3")));
    //player->setMedia(QMediaContent(QUrl("../flowers/images/like.mp3")));
    player->play();
    // 单曲循环
    connect(player, &QMediaPlayer::stateChanged, [=]{player->play();});
}

void HeartWidget::paintEvent(QPaintEvent *)
{
    painter = new QPainter(this);
    QPixmap pix;

#if 1
    // 限定画爱心的取点
    static int count = 0;
    // 参数方程中的角度
    static double angle = 10.0;
    // 用于绘制I❤Y
    // -1 -2 -> 大爱心
    // 0 1 2 -> I
    // 3 4 5 -> Y
    // 6 -> ❤
    // 7 -> 文字
    static int state = -2;
    static int i = 0;
    double a = 1.15, b = 1.15;
    switch(resolution)
    {
    case 0:
        a = 1.4;
        b = 1.4;
        break;
    case 1:
        a = 1.15;
        b = 1.15;
        break;
    }
    if (angle < 30 && state == -2)
    {
        switch (resolution)
        {
        case 0:
            pix.load(":/new/prefix1/images/hh.gif");
            break;
        case 1:
            pix.load(":/new/prefix1/images/hh1.gif");
            break;
        }
        float t = (float) (angle / 3.14159);
        int x = (int) (19.5 * a * (16 * pow(sin(t), 3)));
        int y = (int) (-20.0 * b * (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)));
        // 隔15个点取一次绘制
        if (count % 15 == 0)
        {
            //painter->drawPixmap(550 + x, 400 + y, pix.width(), pix.height(), pix);
            painter->drawPixmap(w / 3.491 + x, h / 2.7 + y, pix.width(), pix.height(), pix);
        }
        count++;
        angle += 0.02;
        if (angle >= 30)
        {
            angle = 10.0;
            state = -1;
        }
    }
    else if (angle < 30 && state == -1)
    {
        float t = (float) (angle / 3.14159);
        int x = (int) (19.5 * a * (16 * pow(sin(t), 3)));
        int y = (int) (-20.0 * b * (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)));
        switch (resolution)
        {
        case 0:
            pix.load(":/new/prefix1/images/ff.png");
            break;
        case 1:
            pix.load(":/new/prefix1/images/ff1.png");
            break;
        }
        // 隔15个点取一次绘制
        if (count % 15 == 0)
        {
            int d = 0;
            if (resolution == 1)
            {
                d = 30;
            }
            //painter->drawPixmap(1250 + x, 400 + y, pix.width(), pix.height(), pix);
            painter->drawPixmap(w / 1.536 + d + x,  h / 2.7 + y, pix.width(), pix.height(), pix);
        }
        count++;
        angle += 0.02;
        if (angle >= 30)
        {
            timer->stop();
            timer->start(100);
            state = 0;
        }
    }
    else
    {
        //timer->stop();
        QPen pen;
        switch(resolution)
        {
        case 0:
            painter->setFont(QFont("Microsoft YaHei", 28, QFont::DemiBold));
            break;
        case 1:
             painter->setFont(QFont("Microsoft YaHei", 20, QFont::DemiBold));
            break;
        }

        pix.load(":/new/prefix1/images/rr1.png");
        if (state == 0)
        {
            int d = 0;
            if (resolution == 1)
            {
                d = -50;
            }
            //painter->drawPixmap(300 + i, 325, pix.width(), pix.height(), pix);
            painter->drawPixmap(w / 6.4 + i, h / 3.323, pix.width(), pix.height(), pix);
            i += 25;
            if (i >= (175 + d))
            {
                state = 1;
                i = 0;
            }
        }
        else if (state == 1)
        {
            int d = 0;
            if (resolution == 1)
            {
                d = -50;
            }
            //painter->drawPixmap(375, 325 + i, pix.width(), pix.height(), pix);
            painter->drawPixmap(w / 5.12 + d / 8, h / 3.323 + i, pix.width(), pix.height(), pix);
            i += 25;
            if (i >= (200 + d))
            {
                state = 2;
                i = 0;
            }
        }
        else if (state == 2)
        {
            int d = 0;
            if (resolution == 1)
            {
                d = -50;
            }
            //painter->drawPixmap(300 + i, 525, pix.width(), pix.height(), pix);
            painter->drawPixmap(w / 6.4 + i, h / 2.057, pix.width(), pix.height(), pix);
            i += 25;
            if (i >= (175 + d))
            {
                state = 3;
                i = 0;
            }
        }
        else if (state == 3)
        {
            int d = 0;
            if (resolution == 1)
            {
                d = -50;
            }
            //pix.load("../flowers/images/love.png");
            //painter->drawPixmap(700 + i, 325 + tan(3.141592 / 3.0) * i, pix.width(), pix.height(), pix);
            painter->drawPixmap(w / 2.743 + i, h / 3.323 + tan(3.141592 / 3.0) * i, pix.width(), pix.height(), pix);
            i += 10;
            if (i >= 50)
            {
                state = 4;
                i = 0;

            }
        }
        else if (state == 4)
        {
            //painter->drawPixmap(755 + i, 411 - tan(3.141592 / 3) * i, pix.width(), pix.height(), pix);
            painter->drawPixmap(w / 2.543 + i, h / 2.628 - tan(3.141592 / 3) * i, pix.width(), pix.height(), pix);
            i += 10;
            if (i >= 60)
            {
                state = 5;
                i = 0;
            }
        }
        else if (state == 5)
        {
            //painter->drawPixmap(755, 411 + i, pix.width(), pix.height(), pix);
            painter->drawPixmap(w / 2.543, h / 2.628 + i, pix.width(), pix.height(), pix);
            i += 25;
            if (i >= 125)
            {
                state = 6;
                i = 0;
            }
        }
        else if (state == 6)
        {
            switch (resolution)
            {
            case 0:
                //pix.load(":/new/prefix1/images/love.png");
                pix.load(":/new/prefix1/images/ll.png");
                break;
            case 1:
                pix.load(":/new/prefix1/images/ll1.png");
                break;
            }
            //painter->drawPixmap(500, 350, pix.width(), pix.height(), pix);
            painter->drawPixmap(w / 3.84, h / 3.086, pix.width(), pix.height(), pix);
            state = 7;
            timer->stop();
            timer->start(1000);
        }
        else if (state == 7)
        {
            int d = 0;
            if (resolution == 1)
                d = 60;
            pen.setBrush(QColor("pink"));
            painter->setPen(pen);
            //painter->drawText(1100, 400, "眼角眉梢都充满着暖意");
            painter->drawText(w / 1.745 + d, h / 2.7, "眼角眉梢都充满着暖意");
            state = 8;
        }
        else if (state == 8)
        {
            int d = 0;
            if (resolution == 1)
                d = 60;
            pen.setBrush(QColor("pink"));
            painter->setPen(pen);
            //painter->drawText(1100, 450, "遇上你，就像浩劫余生");
            painter->drawText(w / 1.745 + d, h / 2.40, "遇上你，就像浩劫余生");
            state = 9;
        }
        else if (state == 9)
        {
            int d = 0;
            if (resolution == 1)
                d = 60;
            pen.setBrush(QColor("pink"));
            painter->setPen(pen);
            //painter->drawText(1100, 500, "漂流过沧海，终见陆地");
            painter->drawText(w / 1.745 + d, h / 2.16, "漂流过沧海，终见陆地");
            state = 10;
        }
        else if (state == 10)
        {
            int d = 0;
            if (resolution == 1)
                d = 60;
            pen.setBrush(QColor("skyblue"));
            painter->setPen(pen);
            //painter->drawText(1100, 600, "  小姜，七夕快乐！");
            painter->drawText(w / 1.745 + d, h / 1.80, "小姜，每天都要快乐！");
            state = 11;
        }
        else if (state == 11)
        {
            int d = 0;
            if (resolution == 1)
                d = 60;
            pen.setBrush(QColor("skyblue"));
            switch (resolution)
            {
            case 0:
                painter->setFont(QFont("Microsoft YaHei", 17, QFont::DemiBold));
                break;
            case 1:
                painter->setFont(QFont("Microsoft YaHei", 13, QFont::DemiBold));
                break;
            default:
                painter->setFont(QFont("Microsoft YaHei", 13, QFont::DemiBold));
                break;
            }
            painter->setPen(pen);
            //painter->drawText(1100, 640, "           —— by 小蔡学长");
            painter->drawText(w / 1.745 + d, h / 1.678, "           —— by 小蔡学长");
            state = 12;
        }
        else if (state == 12)
        {
            pen.setBrush(QColor("purple"));
            switch (resolution)
            {
            case 0:
                painter->setFont(QFont("Microsoft YaHei", 40, QFont::DemiBold));
                break;
            case 1:
                painter->setFont(QFont("Microsoft YaHei", 34, QFont::DemiBold));
                break;
            default:
                painter->setFont(QFont("Microsoft YaHei", 34, QFont::DemiBold));
                break;
            }

            painter->setPen(pen);
            painter->drawText(w / 10.0, h / 5.0 * 4.5, "江南伞贵，长安花贵，洛阳纸贵，然而都不及你贵!");
            state = 13;
        }

    }
#endif
}
