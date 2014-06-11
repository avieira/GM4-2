#include"Observable.hpp"

void Observable::addObserver(Observer *o)
{
    listeObserver.push_back(o);
}

void Observable::notify()
{
    for(int i=0;i<listeObserver.size();i++)
        listeObserver[i]->update();
}
