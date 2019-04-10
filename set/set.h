//
// Created by Mauro Nicolì on 2019-03-17.
//

#ifndef STRUTTURE_DATI_SET_H
#define STRUTTURE_DATI_SET_H

#include <iostream>

using namespace std;

template<class T>
class Set {

public:

    Set();

    Set(const Set<T> &);

    ~Set();

    bool empty() const;

    bool is_member(const T &) const;

    void insert(const T &);

    void remove(const T &);

    Set<T> union_set(const Set<T> &, const Set<T> &);

    Set<T> intersection_set(const Set<T> &, const Set<T> &);

    Set<T> difference_set(const Set<T> &, const Set<T> &);

    //friend ostream &operator<<(ostream &os, const Set<T> &);

    //Set<T> &operator=(const Set<T> &);

    void print();

private:

    int length;

    int array_dimension;

    T *elements;

    void change_dimendion(T *&, int, int);

};

template<class T>
Set<T>::Set() {
    array_dimension = 10;
    length = 0;
    this->elements = new T[array_dimension];
}

template<class T>
Set<T>::Set(const Set<T> &s) {
    this->length = s.length;
    this->elements = new T[s.array_dimension];
    for (int i = 0; i <= s.length; i++) {
        this->elements[i] = s.elements[i];
    }
}

template<class T>
Set<T>::~Set() {
    delete[] elements;
    length = 0;
}

template<class T>
bool Set<T>::empty() const {
    return (length == 0);
}

template<class T>
bool Set<T>::is_member(const T &t) const {
    bool check = false;
    for (int i = 0; i <= length; i++) {
        if (t == elements[i]) {
            check = true;
        }
    }
    return check;
}

template<class T>
void Set<T>::insert(const T &t) {
    if (length == array_dimension) {
        change_dimendion(elements, array_dimension, array_dimension * 2);
        array_dimension = array_dimension * 2;
    }
    if (!is_member(t)) {
        this->length++;
        this->elements[length - 1] = t;
    }
}


template<class T>
void Set<T>::remove(const T &t) {
    if (is_member(t)) {
        for (int i = 0; i <= length; i++) {
            if (t == elements[i]) {
                for (int j = i; j < length; j++) {
                    elements[j] = elements[j + 1];
                }
            }

        }
        length--;
    }
}

template<class T>
Set<T> Set<T>::union_set(const Set<T> &s1, const Set<T> &s2) {
    if (s1.empty()) {
        return s2;
    } else if (s2.empty()) {
        return s1;
    } else {
        for (int i = 0; i < s1.length; i++) {
            insert(s1.elements[i]);
        }
        for (int j = 0; j < s2.length; j++) {
            if (!is_member(s2.elements[j])){
                insert(s2.elements[j]);
            }
        }
    }
    return *this;
}

template<class T>
Set<T> Set<T>::intersection_set(const Set<T> &s1, const Set<T> &s2) {
    if (s2.length > s1.length) {
        for (int i = 0; i < s1.length; i++) {
            if (s2.is_member(s1.elements[i])) {
                insert(s1.elements[i]);
            }
        }
    } else {
        for (int i = 0; i < s2.length; i++) {
            if (s1.is_member(s2.elements[i])) {
                insert(s2.elements[i]);
            }
        }
    }
    return *this;
}

template<class T>
Set<T> Set<T>::difference_set(const Set<T> &s1, const Set<T> &s2) {
    for (int i = 0; i < s1.length; i++) {
        if(!s2.is_member(s1.elements[i])){
            insert(s1.elements[i]);
        }
    }
    return *this;
}

template<class T>
void Set<T>::change_dimendion(T *&array, int vecchia_dim, int nuova_dim) {
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

template<class T>
void Set<T>::print() {
    cout << "(";
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            cout << elements[i];
        } else {
            cout << ", " << elements[i];
        }
    }
    cout << ")" << endl;
}
/*
template<class T>
Set<T> &Set<T>::operator=(const Set<T> &s){
    this->length = s.length;
    this->elements = new T[s.array_dimension];
    for (int i = 0; i <= s.length; ++i) {
        this->elements[i] = s.elements[i];
    }
    return this;
}
*/

/*
template<class T>
ostream &operator<<(ostream &os, const Set<T> &s) {
    cout << "(";
    for (int i = 0; i < s.length ; i++) {
        if (i==0){
        cout << s.elements[i];

        }else{
            cout << ", " << s.elements[i];

        }
    }
    cout << ")" << endl;

    return os;
}
*/
#endif //STRUTTURE_DATI_SET_H
