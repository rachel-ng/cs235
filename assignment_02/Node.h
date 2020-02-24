#pragma once

class Node{
private:
    Node *prev;
    Node *next;
public:
    Node();
    Node(std::string data);
    Node(std::string,Node* prev);
    Node(std::string,Node* next);
    Node(std::string,Node* prev,Node* next);
    
    std::string data;

    void setData(std::string data);
    void setPrev(Node *prev);
    void setNext(Node *next);
    std::string getData();
    Node *getPrev();
    Node *getNext();
};
