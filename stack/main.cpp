#include <iostream>
#include "stack.h"

using namespace std;

int main() {

    Stack<char> s1;
    s1.push('c');
    s1.push('a');
    s1.push('z');
    s1.push('z');
    s1.push('o');

    //cout << s1.top();

    cout << s1 << endl;

    Stack<char> s3 = s1;

    s1.revert();
    cout  << s1 << endl;

    //cout << s1._length;


    cout << s3 << endl;
    cout << "operator == : "<< (s1==s3) <<endl;

    cout << endl << endl;


    Stack<int> s2;

    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    s2.push(5);

    cout << s2 << endl;

    return 0;
}