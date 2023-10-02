#ifndef MYWIDGETDRAW_H
#define MYWIDGETDRAW_H
#include <QWidget>
#include <QTimer>

#include "Game.h"


class MyWidgetDraw : public QWidget
{
Q_OBJECT

protected:
    Game & game;
    QTimer timer;
    QSize m_CentralWidgetSize;
public:

    explicit MyWidgetDraw(Game &_game, QSize CentralWidgetSize, QWidget *parent = nullptr);
    ~MyWidgetDraw();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void SlotReceiveTimerTimeout();
};

#endif // MYWIDGETDRAW_H
