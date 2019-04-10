//
// Created by Mauro Nicolì on 2019-03-12.
//

#ifndef STRUTTURE_DATI_DEQUEUE_H
#define STRUTTURE_DATI_DEQUEUE_H
using namespace std;

template<class T>
class Dequeue;

template<class T>
class NodeD {
    friend class Dequeue<T>;

private:
    T value;
    NodeD<T> *_next;
    NodeD<T> *_prev;

};

template<class T>
class Dequeue {


public:

    Dequeue();

    Dequeue(const Dequeue<T> &);

    ~Dequeue();

    // methods

    bool empty() const;

    T top() const;

    void pop_front();

    void pop_back();

    void push_front(const T &);

    void push_back(const T &);

    bool operator==(const Dequeue<T> &);

    int size() const;


private:

    int _length;

    NodeD<T> *_head;

    NodeD<T> *_queue;

};


template<class T>
Dequeue<T>::Dequeue() {
    _head = new NodeD<T>;
    _queue = new NodeD<T>;

    _head->_next = _queue;
    _head->_prev = _queue;
    _queue->_prev = _head;
    _queue->_next = _head;
    _length = 0;
}

template<class T>
Dequeue<T>::Dequeue(const Dequeue<T> &other) {
    _head = new NodeD<T>;
    _queue = new NodeD<T>;

    _head->_next = _queue;
    _head->_prev = _queue;
    _queue->_prev = _head;
    _queue->_next = _head;
    _length = 0;

    NodeD<T> *temp = other._head;

    for (int i = 0; i < other._length; i++) {
        push_back(temp->_next->value);
        temp = temp->_next;
    }
}

template<class T>
Dequeue<T>::~Dequeue() {
    while (!empty()) {
        pop_front();
    }
    _length = 0;
    delete _head;
    delete _queue;
}

template<class T>
int Dequeue<T>::size() const {
    return _length;
}

template<class T>
bool Dequeue<T>::empty() const {
    return (_length == 0);
}

template<class T>
T Dequeue<T>::top() const {
    if (!empty()) {
        return _head->_next->value;
    }
    return 0;
}

template<class T>
void Dequeue<T>::pop_front() {
    if (!empty()) {
        NodeD<T> *temp = _head;
        _head = _head->_next;
        delete temp;
        _length--;
    }
}

template<class T>
void Dequeue<T>::pop_back() {
    if (!empty()) {
        NodeD<T> *temp = _queue;
        _queue = _queue->_prev;
        delete temp;
        _length--;
    }
}

template<class T>
void Dequeue<T>::push_back(const T &x) {
    NodeD<T> *n = new NodeD<T>;

    _queue->_prev->_next = n;
    n->_next = _queue;
    n->_prev = _queue->_prev;
    _queue->_prev = n;

    n->value = x;
    _length++;
}

template<class T>
void Dequeue<T>::push_front(const T &x) {
    NodeD<T> *n = new NodeD<T>;

    n->_next = _head->_next;
    n->_prev = _head;
    _head->_next = n;
    _head->_next->_prev = n;

    n->value = x;
    _length++;
}

template<class T>
ostream &operator<<(ostream &os, const Dequeue<T> &s) {
    Dequeue<T> copy = s;
    int toprint = copy.size();
    cout << ". ";
    cout << "-";
    cout << " .";
    cout << endl;
    for (int i = 0; i < toprint; i++) {
        cout << "| ";
        cout << copy.top();
        cout << " |" << endl;
        copy.pop_front();
    }

    cout << endl << endl;
    return os;
}

template<class T>
bool Dequeue<T>::operator==(const Dequeue<T> &s) {
    if (_length != s._length) {
        return false;
    } else {
        NodeD<T> *thisNodeD = _head;
        NodeD<T> *sNodeD = s._head;
        for (int i = 0; i <= s._length; i++) {
            if (thisNodeD->value == sNodeD->value) {
                thisNodeD = thisNodeD->_next;
                sNodeD = sNodeD->_next;
            } else {
                return false;
            }
        }
        return true;
    }
}
#endif //STRUTTURE_DATI_DEQUEUE_H
