#pragma once

class Node{
private:
    Node *next;
public:
    Node();
    Node(std::string data);
    Node(std::string,Node* next);
    std::string data;

    void setData(std::string data);
    void setNext(Node *next);
    std::string getData();
    Node *getNext();
};
