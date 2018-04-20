/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Queue.h
 *   Purpose:   Class definition for UI class UImanager
 *   Author:    vargha Tebyaniyan, Abdulkadir Abdulkadir
 *   
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef QUEUE_H
#define QUEUE_H

#include "Pirate.h"

class Queue
{
  public:
    Queue();
    ~Queue();
    Queue(const Queue&);
    Queue* operator= (const Queue&);
    void operator+= (Pirate*);
    Queue* operator-= (Pirate*);
    Pirate* operator[] (int);
    bool operator! ();
    void push(Pirate*);
    Pirate* find(int);
    Pirate* front() const;

    
  private:
    void pop();
    bool empty() const;
    void remove(int);
    class Node
    {
      public:
	Node() : next(0), prev(0) {}
        Pirate* data;
	Node*   next;
	Node*   prev;
    };
    Node* head;
    Node* tail;

  protected:
    Node* findPirate(int);
};

#endif
