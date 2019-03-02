#include "FireWidget.h"

FireWidget::FireWidget(QWidget *parent) : QWidget(parent)
{
    // 初始化音乐
    initMusic();

    // 设置程序不在任务栏显示且窗体无边框 ^_^
    this->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);

    // 全屏显示
    QRect screenRect = QApplication::desktop()->screenGeometry();
    //QRect screenRect = QGuiApplication::screens()[0]->geometry();
    w = screenRect.width();
    h = screenRect.height();
    // 设置分别率
    if (w == 1920)
        resolution = 0;
    else if (w <= 1400 && w >= 1280)
        resolution = 1;
    else
        resolution = 1;
    resize(w, h);

    // 设置背景全黑
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(5, 4, 3));
    setAutoFillBackground(true);
    setPalette(palette);

    QPixmap pixmap;
    switch (resolution)
    {
    case 0:
        pixmap.load(":/new/prefix1/images/fire.gif");
        break;
    case 1:
        pixmap.load(":/new/prefix1/images/fire1.gif");
        break;
    }

    int mw = pixmap.size().width();
    int mh = pixmap.size().height();

    QLabel *label1 = new QLabel(this);
    label1->move(w / 2 - mw / 2, h / 2 - mh / 2);
    playMovie(label1);

    QLabel *label2 = new QLabel(this);
    label2->move(w / 2 - mw * 1.5, h / 2 - mh);
    playMovie(label2);

    QLabel *label3 = new QLabel(this);
    label3->move(w / 2 + mw / 2, h / 2 - mh);
    playMovie(label3);

    QLabel *label4 = new QLabel(this);
    label4->move(w / 2 - mw * 1.5, h / 2);
    playMovie(label4);

    QLabel *label5 = new QLabel(this);
    label5->move(w / 2 + mw / 2, h / 2);
    playMovie(label5);


    QTimer *timer = new QTimer(this);
    timer->start(7000);
    connect(timer, &QTimer::timeout, [=]{
        timer->stop();
        player->stop();
        this->close();
        HeartWidget *w = new HeartWidget();
        w->show();
    });

    // 文字
    QLabel *textLabel = new QLabel(this);
    textLabel->move(80, 100);
    QFont ft;
    switch (resolution)
    {
    case 0:
        ft.setPointSize(28);
        break;
    case 1:
        ft.setPointSize(22);
        break;
    default:
        ft.setPointSize(22);
    }

    textLabel->setFont(ft);
    QPalette pa;
    pa.setColor(QPalette::WindowText, Qt::white);
    textLabel->setPalette(pa);
    textLabel->setWordWrap(true);
    textLabel->setAlignment(Qt::AlignTop);
    textLabel->setText(QString::fromUtf8(text));

//    QTimer *timer1 = new QTimer(this);
//    timer1->start(500);
//    connect(timer1, &QTimer::timeout, [=]{

//    });
}

void FireWidget::initMusic()
{
    player = new QMediaPlayer(this);
    player->setMedia(QMediaContent(QUrl("qrc:/new/prefix2/mp3/fire.mp3")));
    player->play();
}

void FireWidget::playMovie(QLabel *label)
{
    QMovie *movie = new QMovie(this);
    switch (resolution)
    {
    case 0:
        movie->setFileName(":/new/prefix1/images/fire.gif");
        break;
    case 1:
        movie->setFileName(":/new/prefix1/images/fire1.gif");
        break;
    default:
        movie->setFileName(":/new/prefix1/images/fire1.gif");
    }
    // 动画
    label->setMovie(movie);
    movie->start();
}

