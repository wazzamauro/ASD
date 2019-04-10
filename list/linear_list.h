//
// Created by Mauro Nicolì on 26/02/2019.
//

#ifndef LIST_LINEAR_LIST_H
#define LIST_LINEAR_LIST_H

#include <iostream>

using namespace std;

template<class T, class P>
class Linear_list {
public:

    // defining pharams
    typedef T type;
    typedef P position;

    // defining operators
    virtual void create() = 0;

    virtual bool empty() const = 0;

    virtual type read(position) const = 0;

    virtual void write(const type &, position) = 0;

    virtual position begin() const = 0;

    virtual bool end(position) const = 0;

    virtual position next(position) const = 0;

    virtual position previous(position) const = 0;

    virtual void insert(const type &, position) = 0;

    virtual void erase(position) = 0;

    // support operator

    virtual int size() const = 0;

    virtual void inverti();

    //virtual bool palindroma();

    virtual void push_front(const type &);

    virtual void push_back(const type &);

    virtual void pop_front();

    virtual void pop_back();

    virtual void clear();

    virtual int num_elem(const position, const position);

    virtual void exchange(const position, const position);
/*
    virtual void move_min_max();

private:

    int * minmax(const position, const position, int);
*/
};

template<class T, class P>
ostream &operator<<(ostream &os, const Linear_list<T, P> &l) {
    typename Linear_list<T, P>::position p;
    p = l.begin();
    cout << "[";
    while (!l.end(p)) {
        if (p != l.begin()) {
            cout << ", " << l.read(p);
        } else {
            cout << l.read(p);
        }
        p = l.next(p);
    }
    cout << "]" << endl;
    return os;
}


template<class T, class P>
void Linear_list<T, P>::push_front(const type &x) {
    typename Linear_list<T, P>::position p;
    p = begin();
    insert(x, p);
}

template<class T, class P>
void Linear_list<T, P>::push_back(const type &x) {
    Linear_list<T, P>::position p;
    p = begin();
    while (!end(p)) {
        p = next(p);
    }
    insert(x, p);
}

template<class T, class P>
void Linear_list<T, P>::pop_front() {
    Linear_list<T, P>::position p;
    p = begin();
    erase(p);
}

template<class T, class P>
void Linear_list<T, P>::pop_back() {
    Linear_list<T, P>::position p;
    p = begin();
    while (!end(p)) {
        p = next(p);
    }
    erase(p);
}

template<class T, class P>
void Linear_list<T, P>::clear() {
    Linear_list<T, P>::position p;
    p = begin();
    while (!end(p)) {
        erase(p);
    }
}

template<class T, class P>
void Linear_list<T, P>::inverti() {
    //position first = begin();
    position last = begin();
    position first = begin();
    while (!end(next(last))) {
        last = next(last);
    }
    type temp;
    for (int i = 0; i < size() / 2; i++) {
        temp = read(first);
        write(read(last), first);
        write(temp, last);
        first = next(first);
        last = previous(last);
    }
}
/*
template<class T, class P>
bool Linear_list<T, P>::palindroma() {
    bool check = false;
    position last = begin();
    position first = begin();
    while (!end(next(last))) {
        last = next(last);
    }
    for (int i = 0; i < size() / 2; i++) {
        if (read(first) != read(last)) {
            return false;
        } else {
            check = true;
        }
        first = next(first);
        last = previous(last);
    }
    return check;
}
*/
template<class T, class P>
int Linear_list<T, P>::num_elem(const position p1, const position p2) {
    position temp_p = p1;
    int count = 0;
    while ((temp_p != p2) && ((!end(temp_p)))) {
        temp_p = next(temp_p);
        count++;
    }
    if ((end(temp_p))) {
        return -1;
    }
    return count;
}

template<class T, class P>
void Linear_list<T, P>::exchange(const position p1, const position p2) {
    type temp;
    temp = read(p1);
    write(read(p2), p1);
    write(temp, p2);
}
/*
template<class T, class P>
int * Linear_list<T, P>::minmax(const position p1, const position p2, int len) {
    int arr[2];
    len = size()/2;
    if (num_elem(p1, p2) <= 1) {
        if (read(p1) >= read(p2)) {
            arr[1] = read(p1);
            arr[0] = read(p2);
        }
    } else {
        while ()
        *arr = minmax(p1, p2/2);
        *arr = minmax(p1+, p2);
    }
    return arr;
}


template<class T, class P>
void Linear_list<T, P>::move_min_max() {
    position first = begin();
    position last = begin();
    while (!end(next(last))) {
        last = next(last);
    }
    minmax(first, last, );

}
*/
#endif //LIST_LINEAR_LIST_H
