#include "game_logo.h"
#include "ui_game_logo.h"
#include <QScreen>
#include <windows.h>
#include "mainwindow.h"
#include "login.h"
#include <iostream>
#include <fstream>
using namespace std;

game_logo::game_logo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game_logo)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    const QRect screenGeometry = QGuiApplication::primaryScreen()->availableGeometry();
    const int x = (screenGeometry.width() - width()) / 2;
    const int y = (screenGeometry.height() - height()) / 2;
    move(x, y - 30);
    lbl_logo = new QLabel(this);
    lbl_logo->setParent(ui->centralwidget);
    QPixmap pixmap(":/photos/game logo.png");
    lbl_logo->setPixmap(pixmap);
    lbl_logo->raise();
    lbl_logo->show();
    animation = new QPropertyAnimation(lbl_logo,"geometry");
    animation->setDuration(1500);
    animation->setStartValue(QRect(width()/2-325,0,650,375));
    animation->setEndValue(QRect(width()/2-325,height()/2-400,1300,750));
    animation->start();
    connect(animation,SIGNAL(finished()),this,SLOT(slo_next_page()));
}

game_logo::~game_logo()
{
    delete ui;
}

void game_logo::slo_next_page()
{
    person p1;
    QFile gamer_file("gamer.txt");
    if(gamer_file.exists())
    {
        if(!gamer_file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this,"ERROR !","The operation was not successful !");
            exit(13);
        }
        else
        {
            QTextStream in(&gamer_file);
            QString username , password , name , phone , email , temp;
            int coin;
            in >> username >>
                password >>
                name >>
                phone >>
                email >>
                coin ;
            p1.set_username(username);
            p1.set_password(password);
            p1.set_name(name);
            p1.set_phone(phone);
            p1.set_email(email);
            p1.set_coin(coin);
        }
        MainWindow* main_page = new MainWindow(p1);
        main_page->setWindowTitle("Skull King");
        this->close();
        main_page->show();
        return;
    }
    else
    {
        gamer_file.close();
        login* login_page = new login;
        login_page->setWindowTitle("Skull King");
        this->close();
        login_page->show();
    }
}
