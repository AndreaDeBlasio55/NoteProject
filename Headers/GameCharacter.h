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
    GameCharacter();
    virtual ~GameCharacter() = default;

    void move(int x, int y){
        posX += x;
        posY += y;
        notify();
    }
    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;

    int getPosX() const {
        return posX;
    }
    int getPosY() const {
        return posY;
    }
    void setPosX (int posX){
        this->posX = posX;
        notify();
    }
    void setPosY (int posY){
        this->posY = posY;
        notify();
    }

private:
    int posX, posY;
    list <Observer*> observer;
};


#endif //NOTEPROJECT_GAMECHARACTER_H
