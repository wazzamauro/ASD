//
// Created by Mauro Nicolì on 2019-03-11.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

using namespace std;

template<class T>
class Queue;

template<class T>
class NodeQ {
    friend class Queue<T>;

private:
    T value;
    NodeQ<T> *_next;
};

template<class T>
class Queue {


public:

    Queue();

    Queue(const Queue<T> &);

    ~Queue();

    // methods

    bool empty() const;

    T top() const;

    void pop();

    void push(const T &);

    bool operator==(const Queue<T> &);

    int size() const;


private:

    int _length;

    NodeQ<T> *_head;

    NodeQ<T> *_queue;

};


template<class T>
Queue<T>::Queue() {
    _head = new NodeQ<T>;
    _queue = new NodeQ<T>;

    _queue->_next = _head;
    _head->_next = _queue;
    _length = 0;
}

template<class T>
Queue<T>::Queue(const Queue<T> &other) {
    _head = new NodeQ<T>;
    _queue = new NodeQ<T>;

    _head->_next = _queue;
    _queue->_next = _head;
    _length = 0;

    NodeQ<T> *temp = other._head;

    for (int i = 0; i < other._length; i++) {
        push(temp->_next->value);
        temp = temp->_next;
    }
}

template<class T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
    _length = 0;
    delete _head;
    delete _queue;
}

template<class T>
int Queue<T>::size() const {
    return _length;
}

template<class T>
bool Queue<T>::empty() const {
    return (_length == 0);
}

template<class T>
T Queue<T>::top() const {
    if (!empty()) {
        return _head->_next->value;
    }
    return 0;
}

template<class T>
void Queue<T>::pop() {
    if (!empty()) {
        NodeQ<T> *temp = _head;
        _head = _head->_next;
        delete temp;
        _length--;
    }
}

template<class T>
void Queue<T>::push(const T &x) {
    NodeQ<T> *n = new NodeQ<T>;
    NodeQ<T> *temp = _head;

    for (int i = 0; i < _length; i++) {
        temp = temp->_next;
    }
    temp->_next = n;
    n->_next = _queue;
    n->value = x;
    _length++;
}

template<class T>
ostream &operator<<(ostream &os, const Queue<T> &s) {
    Queue<T> copy = s;
    int toprint = copy.size();
    cout << ". ";
    cout << "-";
    cout << " .";
    cout << endl;
    for (int i = 0; i < toprint; i++) {
        cout << "| ";
        cout << copy.top();
        cout << " |" << endl;
        copy.pop();
    }

    cout << endl << endl;
    return os;
}

template<class T>
bool Queue<T>::operator==(const Queue<T> &s) {
    if (_length != s._length) {
        return false;
    } else {
        NodeQ<T> *thisNodeQ = _head;
        NodeQ<T> *sNodeQ = s._head;
        for (int i = 0; i <= s._length; i++) {
            if (thisNodeQ->value == sNodeQ->value) {
                thisNodeQ = thisNodeQ->_next;
                sNodeQ = sNodeQ->_next;
            } else {
                return false;
            }
        }
        return true;
    }
}



#endif //QUEUE_QUEUE_H
