#include "MyWidgets.h"

gameover::MyLabel::MyLabel(QWidget * p)
    :  QLabel(p){}

void gameover::MyLabel::SetAnimation(float Width, float Height, float kH, float kW)
{
    float HeightInPixel = Width / kW;
    float WidthInPixel = Height / kH;

    this->setTextFormat(Qt::RichText);
    QString text("Game Over");
    this->setStyleSheet(QString("font-size: %1px").arg(32));
    this->setAlignment(Qt::AlignCenter);
    this->setText(text);


    m_AnimPtr1 = new QPropertyAnimation(this, "pos");
    m_AnimPtr2 = new QPropertyAnimation(this, "size");
    QGraphicsColorizeEffect * m_ColorEffectPtr = new QGraphicsColorizeEffect();
    this->setGraphicsEffect(m_ColorEffectPtr);
    m_AnimPtr3 = new QPropertyAnimation(m_ColorEffectPtr, "color");

    m_AnimPtr1->setDuration(3000);
//    m_AnimPtr1->setStartValue(QPoint(800, 450));
//    m_AnimPtr1->setEndValue(QPoint(800, 350));
    m_AnimPtr1->setStartValue(QPoint(WidthInPixel, HeightInPixel));
    m_AnimPtr1->setEndValue(QPoint(WidthInPixel, HeightInPixel));
    m_AnimPtr1->setEasingCurve(QEasingCurve::InElastic);

    m_AnimPtr2->setDuration(5000);
    m_AnimPtr2->setStartValue(QSize(0, 60));
    m_AnimPtr2->setEndValue(QSize(200, 100));
    m_AnimPtr2->setEasingCurve(QEasingCurve::OutElastic);

    m_AnimPtr3->setStartValue(QColor(Qt::gray));
    m_AnimPtr3->setKeyValueAt(0.25f, QColor(Qt::green));
    m_AnimPtr3->setKeyValueAt(0.5f, QColor(Qt::blue));
    m_AnimPtr3->setKeyValueAt(0.75, QColor(Qt::red));
    m_AnimPtr3->setEndValue(QColor(Qt::black));
    m_AnimPtr3->setDuration(3000);
    m_AnimPtr3->setLoopCount(-1);
}


void gameover::MyLabel::StartAnimation()
{
    m_AnimPtr1->start();
    m_AnimPtr2->start();
    m_AnimPtr3->start();
}

void gameover::MyLabel::DestroyLabel()
{
    this->destroy(true);
}

gameover::MyLabel::~MyLabel()
{
    DestroyLabel();
}

