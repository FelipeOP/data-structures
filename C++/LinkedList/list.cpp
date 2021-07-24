#include "list.h"
using std::cout;
using std::swap;

/*
--------------------Node struct methods-------------------
*/

template <typename T>
int Node<T>::amount = 0;

template <typename T>
Node<T>::Node(T data)
{
    this->data = data;
    next = NULL;
    amount++;
}

template <typename T>
void Node<T>::_delete()
{
    delete this;
    amount--;
}

/*
--------------------List class methods-------------------
*/

template <typename T>
List<T>::List()
{
    first = last = NULL;
}

template <typename T>
int List<T>::size()
{
    return first->amount;
}

template <typename T>
bool List<T>::isEmpty()
{
    return first ? false : true;
}

template <typename T>
void List<T>::push_back(T data)
{
    Node<T> *new_node = new Node<T>(data);
    if (first == NULL)
    {
        first = new_node;
    }
    else
    {
        last->next = new_node;
    }
    last = new_node;
    last->next = NULL;
}

template <typename T>
void List<T>::push_front(T data)
{
    Node<T> *new_node = new Node<T>(data);
    if (first == NULL)
    {
        last = new_node;
    }
    new_node->next = first;
    first = new_node;
}

template <typename T>
void List<T>::pop_back()
{
    Node<T> *it = first;
    while (it->next != last)
    {
        it = it->next;
    }
    last->_delete();
    last = it;
    last->next = NULL;
}

template <typename T>
void List<T>::pop_front()
{
    Node<T> *it = first;
    first = first->next;
    it->_delete();
}

template <typename T>
void List<T>::reverse()
{
    last = first;
    Node<T> *current = first, *prev, *next;
    prev = next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    first = prev;
}

template <typename T>
void List<T>::reverse_it()
{
    Node<T> *f, *l;
    int li = 0, fi = 0;
    /*
        int size = this->size() - 2;
        subtract -1 because iterator starts at 0
        subtract -1 again so that the iterator reaches the penultime element
    */
    int size = this->size() - 2;
    swap(first, last);
    //size() is the amount of moves with the pointers (counting last->next = NULL)
    for (f = first; fi < this->size(); f = f->next, fi++)
    {
        for (l = last, li = 0; li < size; l = l->next, li++)
            ;
        size--;
        f->next = l;
        l->next = NULL;
    }
}

template <typename T>
void List<T>::insert(int position, T data)
{
    if (position > this->size() || position < 0)
        return;
    if (position == 0)
    {
        push_front(data);
        return;
    }
    if (position == this->size)
    {
        push_back(data);
        return;
    }
    Node<T> *it = first, *temp;
    int i = 0;
    while (i < (position - 1))
    {
        it = it->next;
        i++;
    }
    temp = it->next;
    it->next = new Node<T>(data);
    it->next->next = temp;
}

template <typename T>
void List<T>::remove(T data)
{
    if (first->data == data)
    {
        pop_front();
        return;
    }
    if (last->data == data)
    {
        pop_back();
        return;
    }
    Node<T> *it = first, *temp;
    bool exist = false;
    while (it != NULL)
    {
        if (it->next->data == data)
        {
            exist = true;
            break;
        }
        it = it->next;
    }
    if (exist)
    {
        temp = it->next->next;
        it->next->_delete();
        it->next = temp;
    }
}

template <typename T>
void List<T>::print()
{
    Node<T> *it = first;
    while (it != NULL)
    {
        cout << it->data << " ";
        it = it->next;
    }
    cout << '\n';
}
