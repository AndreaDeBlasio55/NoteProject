//
// Created by Andrea on 21/10/21.
//

#ifndef NOTEPROJECT_OBSERVER_H
#define NOTEPROJECT_OBSERVER_H

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update() = 0;
    virtual void attach() = 0;
    //virtual void detach() = 0;

};

#endif //NOTEPROJECT_OBSERVER_H
