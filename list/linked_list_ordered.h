//
// Created by Mauro Nicolì on 2019-03-05.
//

#ifndef LIST_LINKED_LIST_ORDERED_H
#define LIST_LINKED_LIST_ORDERED_H

#include "linked_list.h"

template<class T>
class Linked_list;

template<class T>
class Node_ord {
    friend class Linked_list<T>;

private:
    T value;
    Node_ord<T> *_prev;
    Node_ord<T> *_next;
};

template<class T>
class Linked_list_ordered : public Linked_list<T> {

public:
    typedef typename Linked_list<T>::type type;
    typedef typename Linked_list<T>::position position;

    void insert(const type &);

private:
    Node_ord<T> *_head;
    int length;

};

template<class T>
void Linked_list_ordered<T>::insert(const type &x) {
    position n = new Node<T>;
    position p = Linked_list<T>::begin();
    while ((Linked_list<T>::read(p) < x) && !(Linked_list<T>::end(p))) {
        p = Linked_list<T>::next(p);
    }
    Linked_list<T>::insert(x, p);
}


#endif //LIST_LINKED_LIST_ORDERED_H
