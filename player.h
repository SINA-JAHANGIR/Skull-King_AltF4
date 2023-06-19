#ifndef PLAYER_H
#define PLAYER_H

#include "customized_button.h"
#include <QVector>
#include <QString>


class player
{
private:
    QString username;
    QVector<customized_button*> cards;
public:
    player();
    void set_username(QString);
    QString get_username();
    void set_cards(QVector<customized_button*>);
    QVector<customized_button*> get_cards();
};

#endif // PLAYER_H
