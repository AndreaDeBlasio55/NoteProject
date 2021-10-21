//
// Created by Andrea on 21/10/21.
//

#ifndef NOTEPROJECT_SUBJECT_H
#define NOTEPROJECT_SUBJECT_H

#include "Observer.h"

class Subject {

    virtual void subscribe(Observer* o) = 0;
    virtual void  unsubscribe(Observer* o) = 0;
    virtual void notify() = 0;

    virtual ~Subject() = default;
};

#endif //NOTEPROJECT_SUBJECT_H
