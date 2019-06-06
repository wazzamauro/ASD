//
// Created by Mauro Nicolì on 26/02/2019.
//

#ifndef LIST_LINKED_LIST_H
#define LIST_LINKED_LIST_H

#include "linear_list.h"

template<class T>
class Linked_list;

template<class T>
class Node {
    friend class Linked_list<T>;

private:
    T value;
    Node<T> *_prev;
    Node<T> *_next;
};

template<class T>
class Linked_list : public Linear_list<T, Node<T> *> {

public:
    typedef typename Linear_list<T, Node<T> *>::type type;
    typedef typename Linear_list<T, Node<T> *>::position position;

    // defining constructors
    Linked_list();

    Linked_list(const Linked_list<T> &);

    ~Linked_list();

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

    void swap(Linked_list<T> &, Linked_list<T>::position *, Linked_list<T>::position *);

    void ordering_desc(Linked_list<T> &);

    void ordering_asc(Linked_list<T> &);

    // operators overloading

    Linked_list<T> &operator=(const Linked_list<T> &);

    bool operator==(const Linked_list<T> &) const;

private:
    Node<T> *_head;
    int length;
};

template<class T>
Linked_list<T>::Linked_list() {
    length = 0;
    create();
}

template<class T>
Linked_list<T>::Linked_list(const Linked_list<T> &l) {
    create();
    if (!l.empty()) {
        position p = l.last();
        for (int i = 0; i < l.size(); i++) {
            insert(l.read(p), begin());
            p = l.previous(p);
        }
    }
}

template<class T>
Linked_list<T>::~Linked_list() {
    while (!empty()) {
        erase(begin());
    }
    delete _head;
}

template<class T>
int Linked_list<T>::size() const {
    return length;
}

template<class T>
void Linked_list<T>::create() {
    _head = new Node<T>;
    _head->_next = _head;
    _head->_prev = _head;
}

template<class T>
bool Linked_list<T>::empty() const {
    return (length == 0) || _head == _head->_next;
}

template<class T>
typename Linked_list<T>::type Linked_list<T>::read(position p) const {
    if (!end(p)) {
        return p->value;
    }
    return 0;
}

template<class T>
typename Linked_list<T>::position Linked_list<T>::begin() const {
    return _head->_next;
}

template<class T>
typename Linked_list<T>::position Linked_list<T>::last() const {
    return _head->_prev;
}

template<class T>
void Linked_list<T>::write(const type &x, position p) {
    if (!end(p)) {
        p->value = x;
    }
}

template<class T>
bool Linked_list<T>::end(position p) const {
    return (p == _head);
}

template<class T>
typename Linked_list<T>::position Linked_list<T>::next(position p) const {
    return (p->_next);
}

template<class T>
typename Linked_list<T>::position Linked_list<T>::previous(position p) const {
    if (!end(p)) {
        return (p->_prev);
    }
    return 0;
}

template<class T>
void Linked_list<T>::insert(const type &x, position p) {
    position n = new Node<T>;

    n->value = x;

    n->_next = p;
    n->_prev = p->_prev;
    p->_prev->_next = n;
    p->_prev = n;

    length++;
}

template<class T>
void Linked_list<T>::erase(position p) {
    if ((!end(p)) && (!empty())) {
        p->_prev->_next = p->_next;
        p->_next->_prev = p->_prev;
        delete p;
        length--;
    }
}

template<class T>
void Linked_list<T>::pop_back() {
    erase(last());
}


// operators overloading

template<class T>
Linked_list<T> &Linked_list<T>::operator=(const Linked_list<T> &l) {
    if (this != &l) {
        this->clear();
        if (!l.empty()) {
            position p = l.last();
            for (int i = 0; i < l.size(); i++) {
                insert(l.read(p), begin());
                p = l.previous(p);
            }
        }
    }
    return *this;
}

template<class T>
bool Linked_list<T>::operator==(const Linked_list<T> &l) const {
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

template<class T>
void Linked_list<T>::swap(Linked_list<T> &l, position *p, position *q) {
    T temp = l.read(*p);
    l.write(l.read(*q), *p);
    l.write(temp, *q);

}

template<class T>
void Linked_list<T>::ordering_desc(Linked_list<T> &l) {
    position p;
    position q;
    for (p = l.begin(); p != l.next(l.last()); p = l.next(p)) {
        for (q = l.begin(); q != p; q = l.next(q)) {
            if (l.read(p) > l.read(q)) {
                swap(l, &p, &q);
            }
        }
    }
}

template<class T>
void Linked_list<T>::ordering_asc(Linked_list<T> &l) {
    position p;
    position q;
    for (p = l.begin(); p != l.next(l.last()); p = l.next(p)) {
        for (q = p; q != l.next(l.last()); q = l.next(q)) {
            if (l.read(p) > l.read(q)) {
                swap(l, &p, &q);
            }
        }
    }
}

#endif //LIST_LINKED_LIST_H
