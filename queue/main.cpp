#include <iostream>
#include "queue.h"
#include "dequeue.h"

int main() {

    Queue<char> q;

    q.push('c');
    q.push('a');
    q.push('z');
    q.push('z');
    q.push('o');

    Queue<char> q1 = q;
    cout << q;

    q.pop();
    cout << q.top() << endl;
    cout << "operator == : " << (q == q1) << endl;

    cout << q1;


    Dequeue<char> d;
    d.push_back('a');

    return 0;
}