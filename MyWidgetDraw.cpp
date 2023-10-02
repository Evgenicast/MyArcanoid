#include "MyWidgetDraw.h"

#include <QPainter>
#include <QKeyEvent>

MyWidgetDraw::MyWidgetDraw(Game &_game, QSize CentralWidgetSize, QWidget * parent)
    : QWidget(parent), game(_game), m_CentralWidgetSize(CentralWidgetSize)
{
    //this->setFocusPolicy(Qt::StrongFocus);// не работает

    connect(&timer, SIGNAL(timeout()), this, SLOT(SlotReceiveTimerTimeout()));// каждые 17 милисикунд посылается таймоут
    timer.start(10); // 17 ms
}

MyWidgetDraw::~MyWidgetDraw()
{
    timer.stop();
}

void MyWidgetDraw::paintEvent([[maybe_unused]] QPaintEvent * event) // ~ 60 раз / сек
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGreen, 4));
    painter.drawRect(0,0,  game.GetWorldSize().width() / game.GetKSizeAdvance().kw,
                     (game.GetWorldSize().height() / game.GetKSizeAdvance().kh));
    //if(game.GetIsNewGame())
    game.DrawAll(&painter);
}

void MyWidgetDraw::keyPressEvent(QKeyEvent * event)
{
    //this->setFocusPolicy(Qt::StrongFocus);
    if (event->isAutoRepeat())
        return;

    game.OnKeyPress(event);

//    this->repaint();
}

void MyWidgetDraw::keyReleaseEvent(QKeyEvent * event)
{
    if (event->isAutoRepeat()) // ?
        return;

    game.OnKeyRelease(event);

//    this->repaint();
}

void MyWidgetDraw::resizeEvent([[maybe_unused]]QResizeEvent *event)
{
//    auto h = this->height();
//    auto w = this->width();
//    auto h1 = event->oldSize().height();
//    auto h2 = event->size().height();
//    auto wh = QWidget::height();

    double kh = game.GetWorldSize().height() / this->height();
    double kw = game.GetWorldSize().width() / this->width();
//    double kh = game.GetWorldSize().height() / m_CentralWidgetSize.height();
//    double kw = game.GetWorldSize().width() / m_CentralWidgetSize.width();
    double k = std::min(kw, kh);
    game.Set_kSize(k);
    game.SetKSizeAdvance(k, kh, kw); // так лучше. Все пропорции работают.
}

void MyWidgetDraw::SlotReceiveTimerTimeout()   // ~ 60 раз / сек
{
    game.NextStep(timer.interval() / 1000.0f); // game.NextStep(17) при делении на 1000; при 10 плавнее идет
    //if(game.GetIsGameOver() || !game.GetIsNewGame())// нельзя, нужно исправить
    //{
    //    timer.stop();
    //}
    this->repaint();
}





