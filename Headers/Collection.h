//
// Created by Andrea on 21/10/21.
//

#ifndef NOTEPROJECT_COLLECTION_H
#define NOTEPROJECT_COLLECTION_H

#include "Subject.h"
#include <iostream>
#include <list>
using namespace std;

class Collection : public Subject {
public:
    Collection(string name);
    virtual ~Collection() = default;

    virtual void subscribe(Observer* o) override;
    virtual void unsubscribe(Observer* o) override;
    virtual void notify() override;

    int getCountNotes() const;

private:
    string name;
    list <Observer*> observerNote;
};

#endif //NOTEPROJECT_COLLECTION_H
