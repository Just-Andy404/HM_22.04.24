#include "Node.h"

Node::Node() :Node(0) {}

Node::Node(int num)
{
    _data = num;
    _next = nullptr;
    _last = nullptr;
}

void Node::operator=(int num)
{
    _data = num;
}

void Node::print()
{
    cout << _data << endl;
}

int Node::getNode()
{
    return _data;
}

void Node::setNode()
{
    cout << "Enter node! " << endl;
    cin >> _data;

}