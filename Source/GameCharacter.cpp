//
// Created by Andrea on 21/10/21.
//

#include <iostream>
#include <list>
#include "../Headers/GameCharacter.h"

using namespace std;

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