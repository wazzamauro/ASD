//
// Created by Mauro Nicolì on 2019-03-05.
//

#ifndef LIST_LINKED_LIST_SINGLE_H
#define LIST_LINKED_LIST_SINGLE_H

#include "linear_list.h"

template<class T>
class Linked_list_single;

template<class T>
class Node_single {
    friend class Linked_list_single<T>;

private:
    T value;
    Node_single<T> *_next;
};

template<class T>
class Linked_list_single : public Linear_list<T, Node_single<T> *> {

public:
    typedef typename Linear_list<T, Node_single<T> *>::type type;
    typedef typename Linear_list<T, Node_single<T> *>::position position;

    // defining constructors
    Linked_list_single();

    Linked_list_single(const Linked_list_single<T> &);

    ~Linked_list_single();

    // defining operators

    int size() const;

    void create();

    bool empty() const;

    type read(position) const;

    void write(const type &, position);

    position begin() const;

    position last() const;

    bool end(position) const;

    position next(position) const;

    position previous(position) const;

    void insert(const type &, position);

    void erase(position);

    void pop_back();

    // operators overloading

    Linked_list_single<T> &operator=(const Linked_list_single<T> &);

    bool operator==(const Linked_list_single<T> &) const;

private:
    Node_single<T> *_head;
    int length;
};

template<class T>
Linked_list_single<T>::Linked_list_single() {
    length = 0;
    this->create();
}

template<class T>
Linked_list_single<T>::Linked_list_single(const Linked_list_single<T> &l) {
    create();
    //this->length = l.size();
    if (!l.empty()) {
        position p = l.last();
        for (int i = 0; i < l.size(); i++) {
            insert(l.read(p), begin());
            p = l.previous(p);
            //length--;
        }
    }
}

template<class T>
Linked_list_single<T>::~Linked_list_single() {
    while (!empty()) {
        erase(begin());
    }
    delete _head;
}

template<class T>
int Linked_list_single<T>::size() const {
    return length;
}

template<class T>
void Linked_list_single<T>::create() {
    _head = new Node_single<T>;
    _head->_next = _head;
}

template<class T>
bool Linked_list_single<T>::empty() const {
    return (length == 0);
}

template<class T>
typename Linked_list_single<T>::type Linked_list_single<T>::read(position p) const {
    if (!end(p)) {
        return p->value;
    }
    return 0;
}

template<class T>
typename Linked_list_single<T>::position Linked_list_single<T>::begin() const {
    return _head->_next;
}

template<class T>
typename Linked_list_single<T>::position Linked_list_single<T>::last() const {
    position p = begin();
    for (int i = 0; i < length - 1; i++) {
        p = next(p);
    }
    return p;
}

template<class T>
void Linked_list_single<T>::write(const type &x, position p) {
    if (!end(p)) {
        p->value = x;
    }
}

template<class T>
bool Linked_list_single<T>::end(position p) const {
    return (p == _head);
}

template<class T>
typename Linked_list_single<T>::position Linked_list_single<T>::next(position p) const {
    return (p->_next);
}

template<class T>
typename Linked_list_single<T>::position Linked_list_single<T>::previous(position p) const {
    position prev = begin();
    while (!end(prev) && (next(prev) != p)) {
        prev = next(prev);
    }
    return prev;
}

template<class T>
void Linked_list_single<T>::insert(const type &x, position p) {
    position n = new Node_single<T>;

    n->value = x;

    position prev = previous(p);
    n->_next = p;
    prev->_next = n;

    length++;
}

template<class T>
void Linked_list_single<T>::erase(position p) {
    if ((!end(p)) && (!empty())) {
        position prev = previous(p);
        prev->_next = p->_next;

        delete p;
        length--;
    }
}

template<class T>
void Linked_list_single<T>::pop_back() {
    erase(last());
}


// operators overloading

template<class T>
Linked_list_single<T> &Linked_list_single<T>::operator=(const Linked_list_single<T> &l) {
    if (this != &l) {
        this->clear();
        //this->length = l.size();
        if (!l.empty()) {
            position p = l.last();
            for (int i = 0; i < l.size(); i++) {
                insert(l.read(p), begin());
                p = l.previous(p);
                //length--;
            }
        }
    }
    return *this;
}

template<class T>
bool Linked_list_single<T>::operator==(const Linked_list_single<T> &l) const {
    if (this->length != l.length) {
        return false;
    } else {
        position p = l.begin();
        position s = this->begin();
        for (int i = 0; i < l.size(); i++) {
            if (l.read(p) != this->read(s)) {
                return false;
            }
            p = l.begin()->_next;
            s = this->begin()->_next;
        }
        return true;
    }
}

#endif //LIST_LINKED_LIST_SINGLE_H
