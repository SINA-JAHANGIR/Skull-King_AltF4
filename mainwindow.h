#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "start.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_play_clicked();

    void on_btn_exit_clicked();

    void on_btn_setting_clicked();

    void on_btn_history_clicked();

private:
    Ui::MainWindow *ui;
    start* start_page;
};
#endif // MAINWINDOW_H
