//
// Created by danil on 08.11.2021.
//

#ifndef MAIN_CPP_IOBSERVER_H
#define MAIN_CPP_IOBSERVER_H

#include "../Commands.h"

class IObservable;
class IObserver {
public:
    virtual void update(Commands command, IObservable &entity) = 0;
};

class IObservable {
public:
    virtual void addObserver(IObserver* o) = 0;
    virtual void removeObserver(IObserver* o) = 0;
    virtual void notify(Commands dir) = 0;
    virtual ~IObservable()= default;
};


#endif //MAIN_CPP_IOBSERVER_H
