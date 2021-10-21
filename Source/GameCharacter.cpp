//
// Created by Andrea on 21/10/21.
//

#include <iostream>
#include <list>
#include "../Headers/GameCharacter.h"

using namespace std;

GameCharacter::GameCharacter(int posX, int posY) {
    this->posX = posX;
    this->posY = posY;
}

void GameCharacter::subscribe(Observer *o) {
    observer.push_back(o);
}
void GameCharacter::unsubscribe(Observer *o) {
    observer.remove(o);
}
void GameCharacter::notify() {
    for (auto itr= begin(observer); itr!= end(observer); itr++){
        (*itr)->update();
    }
}
int GameCharacter::getPosX() const {
    return posX;
}
int GameCharacter::getPosY() const {
    return posY;
}
void GameCharacter::setPosX (int posX){
    this->posX = posX;
    notify();
}
void GameCharacter::setPosY (int posY){
    this->posY = posY;
    notify();
}