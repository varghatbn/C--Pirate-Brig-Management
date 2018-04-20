/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Queue.cc
 *   Purpose:   Class definition for UI class UImanager
 *   Author:    vargha Tebyaniyan, Abdulkadir Abdulkadir
 *   
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Queue.h"

Queue::Queue()
{
  head = 0;
  tail = 0;
}


Queue::~Queue()
{
  while (!empty())
  {
    pop();
  }
}

//copy constructor
Queue::Queue(const Queue& obj)
{
  Node* objNode = obj.head;
  head = tail = 0;
  while (objNode != 0)
  {	
    push(objNode->data);
    objNode = objNode->next;
  }
}

//adds a pirate to the end of the list
void Queue::push(Pirate* p)
{
  Node* node = new Node();
  node->data = new Pirate(*p);
  if (head == 0){
    head = node;
    tail = head;
  }
  else{
    tail->next = node;
    node->prev = tail;
    tail = node;
  }
}


void Queue::pop()
{
  Node* nextNode;
  if (head != 0){
    nextNode = head->next; 
    delete head->data;
    
    head->next = 0;
    head->prev =0;
    delete head;

    if (nextNode == 0){		
      head = nextNode;
      tail = head;
    }
    else{
      head = nextNode;
      nextNode->prev = 0;
    }
  }
}


bool Queue::empty() const
{
  return head == 0;
}


Pirate* Queue::front() const
{
  if(head == 0){
    return 0;
  }
  return head->data;
}


Pirate* Queue::find(int pID)
{
  Node* node = findPirate(pID);
  if (node == 0){
    return 0;
  }
  return node->data;
}


void Queue::remove(int pID)
{
  Node* node = findPirate(pID);
  if (node != 0){		
    Node* prev = node->prev;
    Node* next = node->next;
    if (prev == 0){
      pop();
    }
    else{
      prev->next = next;
      if (next != 0){
        next->prev = prev;
      }
      delete node->data;
      delete node;
    }		
  }
}


Queue::Node* Queue::findPirate(int pID)
{
  Node* tmp = head;
  while (tmp != 0){
    if (tmp->data->getId() == pID){
      break;
    }
    tmp = tmp->next;
  }
  return tmp;
}


Queue* Queue::operator= (const Queue& obj)
{
  if (this != &obj){
    while (!empty()){
      pop();
      Node* objNode = obj.head;

      while (objNode != 0){
        push(objNode->data);
	objNode = objNode->next;
      }
    }
  }
  return this;
}

void Queue::operator+=(Pirate *p){
  push(p);
}

Queue* Queue::operator-= (Pirate* p){
  remove(p->getId());
}

Pirate* Queue::operator[] (int n){
  return find(n);
}

bool Queue::operator! (){
  Node *currNode = head;
  if(currNode == 0){
    return false;
  }else{
    return true;
  }
}
