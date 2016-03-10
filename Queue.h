//Queue.h
//Luis Segarra,Mitchell Chapman, Connor Simpson
//4/5/2015

#ifndef QUEUE_H
#define QUEUE_H

#include <list>
template <class MyType>
class Queue
{
    public:
        Queue();
        ~Queue();
        bool empty();
        void Dequeue();
        void Enqueue(MyType);
        bool crash(int);
        int planeTime(int);
    private:
        MyType *ptr;
        std::list<MyType> planeQueue;

};


/**
        planeTime
**/
template <class MyType>
int Queue<MyType>::planeTime(int currentTime)
{

    ptr = &(planeQueue.front());
    return (ptr->getStartTime() - currentTime);

}


/**
        crash
**/
template <class MyType>
bool Queue<MyType>::crash(int currentTime)
{
    if(!planeQueue.empty())
    {
        ptr = &(planeQueue.front());
        return ptr->didICrash(currentTime);
    }
   else
    return false;
}

/**
        empty
**/
template <class MyType>
bool Queue<MyType>::empty()
{
    return planeQueue.empty();
}


/**
        Dequeue
**/
template <class MyType>
void Queue<MyType>::Dequeue()
{
    if(!planeQueue.empty())
    planeQueue.pop_front();
}

/**
        Enqueue
**/
template <class MyType>
void Queue<MyType>::Enqueue(MyType newPlane)
{

    planeQueue.push_back(newPlane);
}

/**
        Destructor
**/
template <class MyType>
Queue<MyType>::~Queue()
{
     planeQueue.erase(planeQueue.begin(), planeQueue.end());
}

/**
        Constructor
**/
template <class MyType>
Queue<MyType>::Queue()
{

}

#endif // QUEUE_H
