#ifndef list_h
#define list_h

template <typename T>
struct Node
{
    static int amount;
    Node<T> *next;
    T data;
    Node(T);
    void _delete();
};

template <typename T>
class List
{
private:
    Node<T> *first, *last;

public:
    List();
    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    void reverse();
    void reverse_it();
    void insert(int position, T data);
    void remove(T data);
    void print();
    bool isEmpty();
    int size();
};

#include "list.cpp"
#endif