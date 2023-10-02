#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "MyWidgetDraw.h"
#include "Game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    MyWidgetDraw * m_MyWidgetDraw;
    Game game;
public:
    MainWindow(QWidget * parent = nullptr);

    ~MainWindow();

private slots:
    void on_NewGame_clicked();
};
#endif // MAINWINDOW_H
