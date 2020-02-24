#include <iostream>

#include "Node.h"

Node::Node() : next(nullptr)
{
}

Node::Node(std::string data){
  this->data = data;
  this->prev = nullptr;
  this->next = nullptr;
}

Node::Node(std::string data, Node *prev){
  this->data = data;
  this->prev = prev;
  this->next = nullptr;
}

Node::Node(std::string data, Node *next){
  this->data = data;
  this->prev = nullptr;
  this->next = next;
}

Node::Node(std::string data, Node *prev, Node *next){
  this->data = data;
  this->prev = prev;
  this->next = next;
}

void Node::setData(std::string data){
  this->data = data;
}

void Node::setPrev(Node *prev){
  this->prev = prev;
}

void Node::setNext(Node *next){
  this->next = next;
}

std::string Node::getData(){
  return data;
}

Node* Node::getPrev(){
  return prev;
}

Node* Node::getNext(){
  return next;
}
