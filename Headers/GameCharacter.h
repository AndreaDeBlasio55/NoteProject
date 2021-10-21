//
// Created by Andrea on 21/10/21.
//

#ifndef NOTEPROJECT_GAMECHARACTER_H
#define NOTEPROJECT_GAMECHARACTER_H


#include "Subject.h"
#include <iostream>
#include <list>
using namespace std;

class GameCharacter : public Subject {
public:
    GameCharacter(int posX, int posY);
    virtual ~GameCharacter() = default;

    void move(int x, int y){
        posX += x;
        posY += y;
        notify();
    }
    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;

    int getPosX() const;
    int getPosY() const;
    void setPosX (int posX);
    void setPosY (int posY);

private:
    int posX, posY;
    list <Observer*> observer;
};


#endif //NOTEPROJECT_GAMECHARACTER_H
