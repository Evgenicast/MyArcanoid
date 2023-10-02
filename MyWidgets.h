#ifndef MYWIDGETS_H
#define MYWIDGETS_H

#include <QObject>
#include <QWidget>
#include <QtWidgets>

namespace gameover
{
    class MyLabel : public QLabel
    {
    private:
        QPropertyAnimation * m_AnimPtr1, * m_AnimPtr2, * m_AnimPtr3;
    public:
        MyLabel(QWidget * p = nullptr);
        void SetAnimation(float Width, float Height, float kH, float kW);
        void StartAnimation();

        void DestroyLabel();

        ~MyLabel();
    };

}//mywidgets


#endif // MYWIDGETS_H
