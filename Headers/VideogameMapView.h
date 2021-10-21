//
// Created by Andrea on 21/10/21.
//

#ifndef NOTEPROJECT_VIDEOGAMEMAPVIEW_H
#define NOTEPROJECT_VIDEOGAMEMAPVIEW_H

#include "Observer.h"
#include "GameCharacter.h"
#include <iostream>

class VideogameMapView : public Observer {
public:
    VideogameMapView(GameCharacter* gc);

    virtual void update() override;
    virtual void attach() override;
    //virtual void detach() override;

    ~VideogameMapView() override =default;

private:
    int x,y;
    GameCharacter* subject;
};

#endif //NOTEPROJECT_VIDEOGAMEMAPVIEW_H
