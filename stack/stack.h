//
// Created by Mauro Nicolì on 2019-03-08.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

using namespace std;

template<class T>
class Stack;

template<class T>
class NodeS {
    friend class Stack<T>;

private:
    T value;
    NodeS<T> *_next;
};

template<class T>
class Stack {

public:

    Stack();

    Stack(const Stack<T> &);

    ~Stack();

    // methods

    bool empty() const;

    T top() const;

    void pop();

    void push(const T &);

    void push_no_duplicati(const T &);

    bool operator==(const Stack<T> &);

    void revert();

private:

    int _length;

    NodeS<T> *_head;

};

template<class T>
Stack<T>::Stack() {
    _head = new NodeS<T>;
    _head->_next = _head;
    _length = 0;
}

template<class T>
Stack<T>::Stack(const Stack<T> &other) {
    _head = new NodeS<T>;
    _head->_next = _head;
    _length = 0;
    NodeS<T> *temp = other._head;
    for (int i = 0; i < other._length; i++) {
        push(temp->_next->value);
        temp = temp->_next;
    }
    this->revert();
}

template<class T>
Stack<T>::~Stack() {
    while (!empty()) {
        pop();
    }
    _length = 0;
    delete _head;
}

template<class T>
bool Stack<T>::empty() const {
    return (_length == 0);
}

template<class T>
T Stack<T>::top() const {
    if (!empty()) {
        return _head->_next->value;
    }
    return 0;
}

template<class T>
void Stack<T>::pop() {
    if (!empty()) {
        NodeS<T> *temp = _head;
        _head = _head->_next;
        delete temp;
        _length--;
    }
}

template<class T>
void Stack<T>::push(const T &x) {
    NodeS<T> *n = new NodeS<T>;
    n->_next = _head->_next;
    _head->_next = n;
    n->value = x;
    _length++;
}

template<class T>
void Stack<T>::push_no_duplicati(const T &x) {
    Stack<T> copy = *this;
    for (int i = 0; i < _length; i++) {
        if(x == copy.top()){
            return;
        }
        copy.pop();
    }
    push(x);

}

template<class T>
ostream &operator<<(ostream &os, const Stack<T> &s) {
    Stack<T> copy = s;
    while (!copy.empty()) {
        cout << "| ";
        cout << copy.top();
        cout << " |" << endl;
        copy.pop();
    }
    cout << ". ";
    cout << "-";
    cout << " ." << endl;
    cout << endl;
    return os;
}

template<class T>
bool Stack<T>::operator==(const Stack<T> &s) {
    if (_length != s._length) {
        return false;
    } else {
        NodeS<T> *thisNodeS = _head;
        NodeS<T> *sNodeS = s._head;
        for (int i = 0; i <= s._length; i++) {
            if (thisNodeS->value == sNodeS->value) {
                thisNodeS = thisNodeS->_next;
                sNodeS = sNodeS->_next;
            } else {
                return false;
            }
        }
        return true;
    }
}

template<class T>
void Stack<T>::revert() {
    Stack<T> temp, copy;
    while (!(this->empty())) {
        temp.push(this->top());
        this->pop();
    }
    while (!temp.empty()) {
        copy.push(temp.top());
        temp.pop();
    }
    while (!copy.empty()) {
        push(copy.top());
        copy.pop();
    }
}


#endif //STACK_STACK_H
