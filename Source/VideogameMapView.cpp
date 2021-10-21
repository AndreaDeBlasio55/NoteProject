//
// Created by Andrea on 21/10/21.
//

#include <iostream>
#include "../Headers/VideogameMapView.h"
using namespace std;

VideogameMapView::VideogameMapView(GameCharacter *gc):subject(gc) {
    this->x = 0;
    this->y = 0;
    attach();
}

void VideogameMapView::attach() {
    subject->subscribe(this);
}

void VideogameMapView::update() {
    this->x = subject->getPosX();
    this->y = subject->getPosY();
    cout << "Stampo X e Y: " << endl;
}

void VideogameMapView::checkPosition () {
    cout << "Position x: " << x << endl;
    cout << "Position y: " << y << endl;
}

