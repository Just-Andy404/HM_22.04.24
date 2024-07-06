/*
Создайте шаблонный класс односвязного списка для
работы с целыми значениями. Нужно создать реализации для
типичных операций над элементами:
■ AddToHead - добавление элемента в голову списка;
■ AddToTail - добавление элемента в хвост списка;
■ DeleteFromHead - удаление элемента из головы списка;
■ DeleteFromTail - удаление элемента из хвоста списка;
■ DeleteAll - удаление всех элементов;
Show - вывод всех элементов списка на экран.

*/
#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template<class L >
class List
{
    L* _head;
    L* _tail;
    int _nodeIn = 0;

public:
    List();
    List(L*);
    void addToHead(L*);
    void addToTail(L*);
    void deleteFromHead();
    void deleteFromTail();
    void deleteAll();
    void show();
    void addToPosition(L*, int);
    void deleteFromPosition(int);
    int findElement(int);
    void changeElement(int);
    void reverse();

};

template<class L>
inline List<L>::List() : _head(nullptr), _tail(nullptr) {}

template<class L>
inline List<L>::List(L* node) : _head(node), _tail(node)
{
    _nodeIn++;
}

template<class L>
inline void List<L>::addToHead(L* node)
{
    if (_head != nullptr)
    {
        _head->_next = node;
        node->_last = _head;
        _head = node;
        _nodeIn++;
    }
    else
    {
        _head = node;
        _tail = node;
        _nodeIn++;
    }
}

template<class L>
inline void List<L>::addToTail(L* node)
{
    if (_head != nullptr)
    {
        node->_next = _tail;
        _tail->_last = node;
        _tail = node;
        _nodeIn++;
    }
    else
    {
        _head = node;
        _tail = node;
        _nodeIn++;
    }
}

template<class L>
inline void List<L>::deleteFromHead()
{
    if (_head != nullptr)
    {
        L* node = _head;
        _head = _head->_last;
        _head->_next = nullptr;
        node->_last = nullptr;
        node->_next = nullptr;
        _nodeIn--;
    }
}

template<class L>
inline void List<L>::deleteFromTail()
{
    if (_tail != nullptr)
    {
        L* node = _tail;
        _tail = _tail->_next;
        _tail->_last = nullptr;
        node->_next = nullptr;
        node->_last = nullptr;
        _nodeIn--;
    }
}

template<class L>
inline void List<L>::deleteAll()
{
    _tail = nullptr;
    _head = nullptr;
    _nodeIn = 0;
}

template<class L>
inline void List<L>::show()
{
    if (_tail != nullptr)
    {
        L* node = _tail;
        int count = 1;
        do
        {
            cout << "Pos: " << count << endl;
            node->print();
            node = node->_next;
            count++;
        } while (node != nullptr);
    }
    else
        cout << "List is empty!" << endl;
}

template<class L>
inline void List<L>::addToPosition(L* node, int pos)
{
    if (pos == 1)
    {
        addToTail(node);
    }
    else if (pos == _nodeIn)
    {
        addToHead(node);
    }
    else if (pos > 1 && pos < _nodeIn)
    {
        int count = 1;
        L* newNode = _tail;
        while (newNode != nullptr && pos != count)
        {
            newNode = newNode->_next;
            count++;
        }
        node->_next = newNode;
        node->_last = newNode->_last;
        newNode->_last = node;
        newNode = node->_last;
        newNode->_next = node;
        _nodeIn++;
    }
}

template<class L>
inline void List<L>::deleteFromPosition(int pos)
{
    if (pos == 1)
    {
        deleteFromTail();
    }
    else if (pos == _nodeIn)
    {
        deleteFromHead();
    }
    else if (pos > 1 && pos < _nodeIn)
    {
        int count = 1;
        L* newNode1 = _tail;
        while (newNode1 != nullptr && pos != count)
        {
            newNode1 = newNode1->_next;
            count++;
        }
        L* newNode2 = newNode1->_next;
        newNode2->_last = newNode1->_last;
        newNode1->_next = nullptr;
        newNode1->_last = nullptr;
        newNode1 = newNode2->_last;
        newNode1->_next = newNode2;
        _nodeIn--;
    }
}

template<class L>
inline int List<L>::findElement(int el)
{
    int count = 1;
    L* newNode = _tail;
    while (el != newNode->getNode())
    {
        newNode = newNode->_next;
        if (newNode == nullptr)
        {
            return 0;
        }
        count++;
    }
    return count;
}

template<class L>
inline void List<L>::changeElement(int pos)
{
    if (pos > 0 && pos <= _nodeIn)
    {
        int count = 1;
        L* newNode = _tail;
        while (newNode != nullptr && pos != count)
        {
            newNode = newNode->_next;
            count++;
        }
        newNode->setNode();
    }


}

template<class L>
inline void List<L>::reverse()
{
    L* newNode = _tail;
    _tail = _head;
    _head = newNode;
    while (newNode != nullptr)
    {
        L* temp = newNode->_next;
        newNode->_next = newNode->_last;
        newNode->_last = temp;
        newNode = temp;
    }
}