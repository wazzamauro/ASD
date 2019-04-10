//
// Created by Mauro Nicolì on 26/02/2019.
//

#ifndef LIST_VECTOR_LIST_H
#define LIST_VECTOR_LIST_H

#include <iostream>
#include "linear_list.h"

using namespace std;

template<class T>
class Vector_list : public Linear_list<T, int> {
public:
    typedef typename Linear_list<T, int>::type type;
    typedef typename Linear_list<T, int>::position position;

    // defining constructors
    Vector_list();

    Vector_list(int);

    Vector_list(const Vector_list<T> &);

    ~Vector_list();

    // defining operators

    int size() const;

    void create();

    bool empty() const;

    type read(position) const;

    void write(const type &, position);

    position begin() const;

    bool end(position) const;

    position next(position) const;

    position previous(position) const;

    void insert(const type &, position);

    void erase(position);

    bool operator==(const Vector_list<T> &);

    Vector_list &operator=(const Vector_list<T> &);

private:

    void change_dimendion(T *&, int, int);

    type *elements;
    int length;
    int array_dimension;

};

template<class T>
int Vector_list<T>::size() const {
    return length;
}

template<class T>
Vector_list<T>::Vector_list() {
    array_dimension = 10;
    this->create();
}

template<class T>
Vector_list<T>::Vector_list(int dimension) {
    array_dimension = dimension;
    this->create();
}

template<class T>
Vector_list<T>::Vector_list(const Vector_list<T> &l) {
    this->array_dimension = l.array_dimension;
    this->length = l.length;
    this->elements = new T[array_dimension];
    for (int i = 0; i < l.array_dimension; i++) {
        this->elements[i] = l.elements[i];
    }
}

template<class T>
Vector_list<T>::~Vector_list() {
    delete[] elements;
}

template<class T>
void Vector_list<T>::create() {
    this->elements = new T[array_dimension];
    this->length = 0;
}

template<class T>
bool Vector_list<T>::empty() const {
    return (length == 0);
}

template<class T>
typename Vector_list<T>::type Vector_list<T>::read(position p) const {
    if ((1 <= p) && (p <= length)) {
        return elements[p - 1];
    }
}

template<class T>
void Vector_list<T>::write(const type &x, position p) {
    if ((1 <= p) && (p <= length)) {
        elements[p - 1] = x;
    }
}

template<class T>
typename Vector_list<T>::position Vector_list<T>::begin() const {
    return 1;
}

template<class T>
bool Vector_list<T>::end(position p) const {
    if ((1 <= p) && (p <= length + 1)) {
        return (p == length + 1);

    } else {
        return false;
    }
}

template<class T>
typename Vector_list<T>::position Vector_list<T>::next(position p) const {
    if ((1 <= p) && (p <= length)) {
        return p + 1;
    } else {
        return p;
    }
}

template<class T>
typename Vector_list<T>::position Vector_list<T>::previous(position p) const {
    if ((1 <= p) && (p <= length)) {
        return p - 1;
    } else {
        return p;
    }
}

template<class T>
void Vector_list<T>::insert(const type &x, position p) {
    if (length == array_dimension) {
        change_dimendion(elements, array_dimension, array_dimension * 2);
        array_dimension = array_dimension * 2;
    }
    if ((1 <= p) && (p <= length + 1)) {
        for (int i = length; i >= p; i--) {
            elements[i] = elements[i - 1];
        }
        elements[p - 1] = x;
        length++;
    }
}

template<class T>
void Vector_list<T>::erase(position p) {
    if ((1 <= p) && (p <= length)) {
        if (!empty()) {
            for (int i = p - 1; i < length - 1; i++) {
                elements[i] = elements[i + 1];
            }
            length--;
        }
    }
}

template<class T>
void Vector_list<T>::change_dimendion(T *&array, int vecchia_dim, int nuova_dim) {
    T *temp = new T[nuova_dim];
    int num;
    if (vecchia_dim < nuova_dim) {
        num = vecchia_dim;
    } else {
        num = nuova_dim;
    }
    for (int i = 0; i < num; i++) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;

}

// overload operators

template<class T>
bool Vector_list<T>::operator==(const Vector_list<T> &l) {
    typename Vector_list<T>::position p, s;
    typename Vector_list<T>::type t, u;

    if (this->size() != l.size()) {
        return false;
    } else {
        for (p = l.begin(), s = this->begin(); !end(p); p = l.next(p), s = this->next(s)) {
            t = read(p);
            u = read(s);
            if (u != t) {
                return false;
            }
        }
    }
    return true;
}

template<class T>
Vector_list<T> &Vector_list<T>::operator=(const Vector_list<T> &l) {
    if (this != &l) {
        this->array_dimension = l.array_dimension;
        this->length = l.length;
        delete this->elements;
        this->elements = new T[array_dimension];
        for (int i = 0; i < l.array_dimension; i++) {
            this->elements[i] = l.elements[i];
        }
    }
    return *this;
}

#endif //LIST_VECTOR_LIST_H
