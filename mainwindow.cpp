#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) /*m_GameOverLbl(game)*/ /*, game()*/
{
    ui->setupUi(this);    
    QPropertyAnimation * m_AnimationEngine;
    QGraphicsColorizeEffect * effect1 = new QGraphicsColorizeEffect();
    ui->NewGame->setGraphicsEffect(effect1);
    m_AnimationEngine = new QPropertyAnimation(effect1, "color");
    m_AnimationEngine->setStartValue(QColor(Qt::gray));
    m_AnimationEngine->setKeyValueAt(0.25f, QColor(Qt::green));
    m_AnimationEngine->setKeyValueAt(0.5f, QColor(Qt::blue));
    m_AnimationEngine->setKeyValueAt(0.75f, QColor(Qt::red));
    m_AnimationEngine->setEndValue(QColor(Qt::black));
    m_AnimationEngine->setDuration(1000);
    m_AnimationEngine->setLoopCount(-1);
    m_AnimationEngine->start();
    ui->NewGame->show();

    //ui->centralwidget->setFixedSize(1100,900);
    auto s = ui->centralwidget->size();

    m_MyWidgetDraw = new MyWidgetDraw(game, s);

    ui->centralwidget->layout()->addWidget(m_MyWidgetDraw);
    //if(!game.GetIsNewGame())
    m_MyWidgetDraw->setFocus();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_NewGame_clicked()
{
    game.SetNewGame(true);
    //game.SetGameOver();
    //ui->centralwidget->setFocus();
}

