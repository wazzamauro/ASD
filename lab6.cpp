//
// Created by Mauro Nicolì on 2019-03-12.
//
#include <iostream>
#include <string>
#include "strutture_dati.h"


using namespace std;

//esercizio 1
Queue<int> &positiveQueue(Queue<int> &q) {
    Queue<int> *out = new Queue<int>;
    int len = q.size();
    for (int i = 0; i < len; i++) {
        if ((q.top()) >= 0) {
            out->push(q.top());
            q.pop();
        } else {
            q.pop();
        }
    }
    return *out;
}

//esercizio 2

//
// TODO multistack
//


// esercizio 3

Queue<int> &_positiveQueue(const Queue<int> &q) {
    Queue<int> *out = new Queue<int>;
    Queue<int> copy = q;
    int len = q.size();
    for (int i = 0; i < len; i++) {
        if ((copy.top()) >= 0) {
            out->push(copy.top());
            copy.pop();
        } else {
            copy.pop();
        }
    }
    return *out;
}

// esercizio 4

//
// Dequeue FATTO
//

// esercizio 5
//
// push stack no duplicati FATTO
//


// esercizio 6
//
// interprete espressione TODO
//

// esercizio 7
//
// notazione postfissa FATTO
//
Queue<string> &postfissa(const string &s) {
    Queue<string> *postfissa = new Queue<string>;
    Stack<string> operand;

    string op = "+*/(-^";
    string escape = ")";
    string num = "1234567890";
    string space = " ";
    string thisnum = "";
    string thisop = "";
    string stack_to_queue = "";

    int s_len = s.length();

    for (int i = 0; i <= s_len; i++) {
        if ((num.find(s[i])) != string::npos) {
            thisnum.append(1, s[i]);

        } else if ((escape.find(s[i])) != string::npos) {
            if (!thisnum.empty()) {
                postfissa->push(thisnum);
                thisnum = "";

                if (!thisop.empty()) {
                    postfissa->push(thisop);
                    thisop = "";
                }
            }
            while (!operand.empty()) {
                if (operand.top() == "(") {
                    operand.pop();
                }
                postfissa->push(operand.top());
                operand.pop();
            }

        } else if (op.find(s[i]) != string::npos) {
            thisop = s[i];
            if (thisop == "^") {

            } else {
                operand.push(thisop);
                thisop = "";
            }

            if (!thisnum.empty()) {
                postfissa->push(thisnum);
                thisnum = "";
            }
        } else if ((space.find(s[i]) != string::npos + 1) || (space.find(s[i]) != string::npos)) {
            if (!thisnum.empty()) {
                postfissa->push(thisnum);
                thisnum = "";
                if (!thisop.empty()) {
                    postfissa->push(thisop);
                    thisop = "";
                }
            }
        }
    }
    while (!operand.empty()) {
        postfissa->push(operand.top());
        operand.pop();
    }

    return *postfissa;
}

int main() {
/*
    Queue<int> q_int, _q_pos, q_pos;
    q_int.push(-1);
    q_int.push(2);
    q_int.push(5);
    q_int.push(-7);
    q_int.push(0);
    q_int.push(3);
    q_int.push(-9);

    cout << "stampa di q_int: " << endl;
    cout << q_int << endl;

    cout << "chiamata funzione _positiveQueue(q_int)    *** senza modifica del parametro ***" << endl;
    _q_pos = _positiveQueue(q_int);

    cout << "stampa di q_pos: " << endl;
    cout << _q_pos << endl;
    cout << "stampa di q_int: " << endl;
    cout << q_int << endl;

    cout << "chiamata funzione positiveQueue(q_int)    *** modifica del parametro ***" << endl;
    q_pos = positiveQueue(q_int);

    cout << "stampa di q_int: " << endl;
    cout << q_pos << endl;
    cout << "stampa di q_int: " << endl;
    cout << q_int << endl;


    Dequeue<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_front(3);
    d.push_back(4);
    d.push_back(5);
    d.push_front(6);

    cout << d;

    d.pop_back();
    d.pop_front();

    Dequeue<int> d1 = d;
    cout << d1;
*/
    //string giuseppe = "35 + 17 * (40 - 9) - 7";
    string giuseppe = "35 ^ 17 - 40 * 7";

    Queue<string> q_post = postfissa(giuseppe);
    cout << q_post << endl;
    return 0;
}

