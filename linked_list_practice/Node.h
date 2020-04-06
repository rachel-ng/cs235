#pragma once

class Node{
private:
    Node *next;
public:
    Node();
    Node(int data);
    Node(int,Node* next);
    int data;

    void setData(int data);
    void setNext(Node *next);
    int getData();
    Node *getNext();
};
