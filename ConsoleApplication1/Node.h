#pragma once
#include <iostream>
using namespace std;
class Node
{
    int _data;
public:
    Node* _next;
    Node* _last;

    Node();
    Node(int);
    void operator=(int);
    void print();
    int	getNode();
    void setNode();
};