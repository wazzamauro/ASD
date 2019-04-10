//
// Created by Mauro Nicolì on 2019-03-12.
//
#include "strutture_dati.h"
#include <string>


void test_graph() {

    GraphList<string, int> g(20);

    NodeG n1, n2, n3, n4, n5, n6, n7;

    g.insNode(n1);
    g.writeItem(n1, "San Francesco");
    //cout << g.readItem(n1);

    g.insNode(n2);
    g.writeItem(n2, "Santa Teresa");
    //cout << g.readItem(n2);

    g.insNode(n3);
    g.writeItem(n3, "San Pietro");

    g.insNode(n4);
    g.writeItem(n4, "San Giovanni");

    g.insNode(n5);
    g.writeItem(n5, "Santa Maria");

    g.insNode(n6);
    g.writeItem(n6, "San Giorgio");

    g.insArch(n1, n2, 10);
    g.insArch(n1, n3, 3);
    g.insArch(n2, n1, 8);
    g.insArch(n2, n3, 2);
    g.insArch(n2, n6, 7);
    g.insArch(n3, n5, 7);
    g.insArch(n3, n6, 1);
    g.insArch(n4, n3, 3);
    g.insArch(n4, n5, 5);
    g.insArch(n4, n6, 7);
    g.insArch(n5, n1, 4);
    g.insArch(n5, n2, 6);
    g.insArch(n5, n4, 1);
    g.insArch(n5, n6, 9);
    g.insArch(n6, n2, 8);
    g.insArch(n6, n5, 4);



    //cout << g.list_nodes().read(g.list_nodes().begin())->getId();
    cout << endl;

    //cout << g.existNodo(n6);
    cout << endl;


    cout << "stampo grafo g ___________________________________________________________________ stampo grafo g" << endl;
    g.print();
    cout << endl;

    cout << "copy constr gg = g ___________________________________________________________ copy constr gg = g" << endl;
    GraphList<string, int> gg = g;
    cout << endl;

    cout << "stampo grafo gg _________________________________________________________________ stampo grafo gg" << endl;
    gg.print();
    cout << endl;

    cout << "gg.insNode(n7) ___________________________________________________________________ gg.insNode(n7)" << endl;
    gg.insNode(n7);
    cout << endl;

    cout << "gg.writeItem(n7, \"Luca\") ___________________________________________ gg.writeItem(n7, \"Luca\")" << endl;
    gg.writeItem(n7, "Luca");
    cout << endl;


    cout << "stampo grafo gg _________________________________________________________________ stampo grafo gg" << endl;
    gg.print();
    cout << endl;

    cout << "stampo grafo g ___________________________________________________________________ stampo grafo g" << endl;
    g.print();
    cout << endl;


    cout << "operator= gg = g ______________________________________________________________ operator= gg = g " << endl;
    gg = g;

    cout << "stampo grafo gg _________________________________________________________________ stampo grafo gg" << endl;
    gg.print();
    cout << endl;

    cout << "stampo grafo g ___________________________________________________________________ stampo grafo g" << endl;
    g.print();
    cout << endl;

    cout << g.readWeigth(n1, n2);
    cout << endl;
    cout << (g == gg);

    cout << "gg.insNode(n7) ___________________________________________________________________ gg.insNode(n7)" << endl;
    gg.insNode(n7);
    cout << endl;

    cout << "gg.writeItem(n7, \"Luca\") ___________________________________________ gg.writeItem(n7, \"Luca\")" << endl;
    gg.writeItem(n7, "San Luca");
    cout << endl;
/*
*/
    cout << endl;
    cout << endl;
    cout << (g == gg);
    cout << endl;

    cout << "stampo grafo gg _________________________________________________________________ stampo grafo gg" << endl;
    gg.print();
    cout << endl;

    cout << gg.inDegree(n5);
    cout << endl;

    cout << gg.outDegree(n5);
    cout << endl;

    cout << gg.meanOutDegree();
    cout << endl;

    gg.insArch(n7, n5, 4);
    //gg.insArch(n4, n7, 4);

    cout << "stampo grafo gg _________________________________________________________________ stampo grafo gg" << endl;
    gg.print();
    cout << endl;

    gg.DFS(n1);

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    gg.BFS(n1);

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;


    gg.findPath(n1, n4);



}

void test_list() {
    Vector_list<char> v_char, v_char2;

    cout << "liste (v_char==v_char2) :";
    if (v_char == v_char2) {
        cout << "TRUE";
    } else {
        cout << "FALSE";
    }
    cout << endl;


    v_char.insert('m', 1);
    v_char.insert('a', 2);
    v_char.insert('u', 3);
    v_char.insert('r', 4);
    v_char.insert('o', 5);
    v_char.insert('a', 6);
    v_char.insert('a', 7);
    v_char.insert('a', 8);
    v_char.insert('a', 9);
    v_char.insert('a', 10);
    v_char.insert('a', 11);
    v_char.insert('u', 12);

    v_char2 = v_char;

    cout << v_char2;
    Vector_list<char> v_char_3 = v_char2;
    cout << v_char_3;


    v_char.push_front('a');
    v_char.pop_front();
    v_char.pop_back();

    v_char2 = v_char;


    Vector_list<int> v_int;
    v_int.insert(2, 1);
    v_int.insert(1, 2);
    v_int.insert(1, 3);
    v_int.insert(1, 4);
    v_int.insert(1, 5);
    v_int.insert(1, 6);
    v_int.insert(1, 7);
    v_int.insert(1, 8);
    v_int.insert(1, 9);
    v_int.insert(1, 10);
    v_int.insert(1, 11);
    v_int.insert(2, 12);


    v_int.erase(5);
    v_int.push_back(3);
    v_int.clear();

    cout << v_char;
    cout << v_char.size();

    cout << endl;

    cout << v_int;
    cout << v_int.size();

    cout << endl;

    cout << v_char2;
    cout << v_char2.size() << endl;


    v_char.pop_back();

    cout << (v_char == v_char2) << endl;

    cout << endl;
    cout << endl;
    cout << endl;

    Linked_list<int> l_list_int, l_list_int1;

    l_list_int.insert(1, l_list_int.begin());
    l_list_int.insert(2, l_list_int.begin());
    l_list_int.insert(3, l_list_int.begin());
    l_list_int.insert(4, l_list_int.begin());
    l_list_int.insert(5, l_list_int.begin());

    cout << "l_list_int : " << l_list_int << endl;
    cout << "l_list_int.size() : " << l_list_int.size() << endl;

    cout << "liste (l_list_int1==l_list_int) :";

    if (l_list_int1 == l_list_int) {
        cout << "TRUE";
    } else {
        cout << "FALSE";
    }
    cout << endl;

    l_list_int1 = l_list_int;

    if (l_list_int1 == l_list_int) {
        cout << "TRUE";
    } else {
        cout << "FALSE";
    }

    cout << endl;

    cout << endl << endl;

    Linked_list<char> l_list_char;

    l_list_char.insert('a', l_list_char.begin());
    l_list_char.insert('b', l_list_char.begin());
    l_list_char.insert('c', l_list_char.begin());
    l_list_char.insert('d', l_list_char.begin());
    l_list_char.insert('e', l_list_char.begin());

    cout << "l_list_char : " << l_list_char << endl;
    cout << "l_list_char.size() : " << l_list_char.size() << endl;

    Linked_list<char> l_list_char_1 = l_list_char;
    cout << "l_list_char_1 : " << l_list_char_1 << endl;

    cout << endl << endl;


    Linked_list_single<int> lls1, lls3;


    lls1.insert(1, lls1.begin());
    lls1.insert(2, lls1.begin());
    lls1.insert(3, lls1.begin());
    lls1.insert(4, lls1.begin());
    lls1.insert(5, lls1.begin());
    lls1.insert(4, lls1.begin());
    lls1.insert(3, lls1.begin());
    lls1.insert(2, lls1.begin());
    lls1.insert(1, lls1.begin());

    cout << endl << lls1 << endl;
    // bool giuseppe = lls1.palindroma():
    //cout << "palindroma? :" << lls1.palindroma() << endl;

    //cout << lls1.read(lls1.last());

    lls1.pop_back();

    cout << endl << lls1;
    Linked_list_single<int> lls2 = lls1;
    cout << lls2.size() << endl;

    lls3 = lls2;
    cout << lls3 << endl;
    lls3.inverti();
    cout << lls3 << endl;


    Linked_list_ordered<int> llo1;
    llo1.insert(1);
    llo1.insert(2);

    llo1.insert(3);
    llo1.insert(4);
    llo1.insert(5);
    llo1.insert(6);
    cout << "llo1 : " << llo1;
    llo1.exchange(llo1.begin(), llo1.last());
    cout << "llo1 exchange: " << llo1;

    cout << llo1 << endl;
    cout << llo1.num_elem(llo1.begin(), llo1.last());

    cout << endl << endl;
    cout << "_______________________________________________________________________________________________________"
         << endl;

    Vector_list<int> vecList;
    vecList.insert(1, vecList.begin());

    cout << vecList << endl;


    Vector_list<int> vecListC = vecList;
    cout << vecList << endl;
    cout << vecListC << endl;

    vecListC.insert(2, vecListC.begin());

    cout << vecList << endl;
    cout << vecListC << endl;

}

void test_stack() {

    Stack<char> s1;
    s1.push('m');
    s1.push('a');
    s1.push('u');
    s1.push('r');
    s1.push('o');

    //cout << s1.top();

    cout << s1 << endl;

    Stack<char> s3 = s1;

    s1.revert();
    cout << s1 << endl;

    //cout << s1._length;


    cout << s3 << endl;
    cout << "operator == : " << (s1 == s3) << endl;

    cout << endl << endl;


    Stack<int> s2;

    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    s2.push_no_duplicati(7);
    s2.push_no_duplicati(5);
    s2.push_no_duplicati(6);
    s2.push_no_duplicati(7);
    s2.push_no_duplicati(3);
    s2.push_no_duplicati(8);
    s2.push_no_duplicati(7);
    s2.push(7);
    s2.push_no_duplicati(7);


    cout << s2 << endl;

}

void test_queue() {

    Queue<char> q;

    q.push('m');
    q.push('a');
    q.push('u');
    q.push('r');
    q.push('o');

    Queue<char> q1 = q;
    cout << q;

    q.pop();
    cout << q.top() << endl;
    cout << "operator == : " << (q == q1) << endl;

    cout << q1;


    Dequeue<char> d;
    d.push_back('s');
    d.push_front('a');
    d.push_back('d');
    d.pop_front();
    d.pop_back();
    cout << d;

}

void test_hash() {

    Entry<string, char> e1;
    Entry<string, char> e2;
    Entry<string, char> e3;
    Entry<string, char> e4;
    Entry<string, char> e5;
    Entry<string, char> e6;

    e1.key = "a";
    e1.value = 'A';
    e2.key = "a";
    e2.value = 'B';
    e3.key = "a";
    e3.value = 'C';
    e4.key = "a";
    e4.value = 'D';
    e5.key = "e";
    e5.value = 'D';
    e6.key = "a";
    e6.value = 'Z';

    HashTable<string, char> h(10);

    h.insert(e1);
    h.insert(e2);
    h.insert(e3);
    h.insert(e4);
    h.insert(e5);
    cout << "print h --------------------------------------------------------------------------------- print h" << endl;
    h.print();

    cout << "insert in h (duplicate) ------------------------------------------------- insert in h (duplicate)" << endl;
    h.insert(e1);
    cout << "print h --------------------------------------------------------------------------------- print h" << endl;
    h.print();

    HashTable<string, char> h1 = h;
    cout << "HashTable h1 (copy constructor h1 = h): ---------------- HashTable h1 (copy constructor h1 = h): " << endl;

    cout << "print h1 ------------------------------------------------------------------------------- print h1" << endl;
    h1.print();

    cout << "insert in h1 ----------------------------------------------------------------------- insert in h1" << endl;
    h1.insert(e6);

    cout << "print h1 ------------------------------------------------------------------------------- print h1" << endl;
    h1.print();

    cout << "print h --------------------------------------------------------------------------------- print h" << endl;
    h.print();

    cout << "erase h (a) ------------------------------------------------------------------------ erase h (a) " << endl;
    h.erase("a");

    cout << "print h --------------------------------------------------------------------------------- print h" << endl;
    h.print();


    cout << "bool containsValue (hash h, val E): ------------------------ bool containsValue (hash h, val E): " << endl;
    cout << h.containsValue('E') << endl << endl;
    cout << "bool containsValue (hash h, val D): ------------------------ bool containsValue (hash h, val D): " << endl;
    cout << h.containsValue('D') << endl << endl;


    Linked_list<char> values = h.values();
    cout << "Lista di valori nel dizionario: " << values << endl;

    Linked_list<string> keys = h.keys();
    cout << "Lista di chiavi nel dizionario: " << keys << endl;


    HashTable<string, char> h2(5);
    cout << "creating h2(5) ------------------------------------------------------------------- creating h2(5)" << endl;

    cout << "insert in h2 ----------------------------------------------------------------------- insert in h2" << endl;
    h2.insert(e6);

    cout << "print h2 ------------------------------------------------------------------------------- print h2" << endl;
    h2.print();

    cout << "resize h2 ----------------------------------------------------------------------------- resize h2" << endl;
    h2.resize();

    cout << "print h2 ------------------------------------------------------------------------------- print h2" << endl;
    h2.print();


    cout << "HashTable h2 (operator =): ------------------------------------------- HashTable h2 (operator =):" << endl;
    h2 = h;

    cout << "print h2 ------------------------------------------------------------------------------- print h2" << endl;
    h2.print();


    cout << endl << endl;
    cout << "test operator== ----------------------------------------------------------------- test operator==" << endl;
    cout << endl << endl;

    cout << "operator= (h=h1) --------------------------------------------------------------- operator= (h=h1)" << endl;
    h = h1;

    cout << "print h --------------------------------------------------------------------------------- print h" << endl;
    h.print();

    cout << "print h1 ------------------------------------------------------------------------------- print h1" << endl;
    h1.print();

    cout << "bool h1==h :  " << (h1 == h) << endl;

    cout << "remove in h1 ----------------------------------------------------------------------- remove in h1" << endl;
    h1.erase("e");

    cout << "print h1 ------------------------------------------------------------------------------- print h1" << endl;
    h1.print();

    cout << "print h --------------------------------------------------------------------------------- print h" << endl;
    h.print();

    cout << "bool h1==h :  " << (h1 == h) << endl;


}

void test_set() {

    Set<int> s1, s2;

    s1.insert(0);
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(5);
    s1.insert(6);

    s2.insert(5);
    s2.insert(6);
    s2.insert(7);
    s2.insert(8);
    s2.insert(9);
    s2.insert(10);

    cout << "Set s1 : ";
    s1.print();

    cout << "Set s2 : ";
    s2.print();
/*

    Set<int> s2 = s1;
    cout << "Set s2 (copy constructor): ";
    s2.print();

    s2.insert(5);
    s2.insert(6);
    s2.insert(7);
    s2.insert(8);
    s2.insert(9);
    s2.insert(10);

    s2.remove(1);
    s2.remove(2);
    s2.remove(3);
    s2.remove(4);

*/

    Set<int> su, si, sd;

    cout << "unione s1 s2 : ";
    su.union_set(s1, s2).print();

    cout << "intersezione s1 s2 : ";
    si.intersection_set(s1, s2).print();

    cout << "differenza s1 s2 : ";
    sd.difference_set(s1, s2).print();

    cout << endl << endl;

    Set<int> dio;
    dio.insert(0);
    dio.insert(1);
    cout << "Set dio : ";

    dio.print();
}

void test_link_tree() {

    cout << "creo albero a _____________________________________________________________________ creo albero a" << endl;
    TreeLink<char> a;
    cout << endl;

    cout << "a.insRoot('r') ___________________________________________________________________ a.insRoot('r')" << endl;
    a.insRoot('r');
    cout << endl;

    cout << "a.insFirst(a.root(), 'c') _____________________________________________ a.insFirst(a.root(), 'c')" << endl;
    a.insFirst(a.root(), 'c');
    cout << endl;

    cout << "a.insNext(a.firstChild(a.root()), 'a') ___________________ a.insNext(a.firstChild(a.root()), 'a')" << endl;
    a.insNext(a.firstChild(a.root()), 'a');
    cout << endl;

    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;

    cout << "a.insFirst(a.root(), 'b') _____________________________________________ a.insFirst(a.root(), 'b')" << endl;
    a.insFirst(a.root(), 'b');
    cout << endl;

    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;

    cout << "creo albero t _____________________________________________________________________ creo albero t" << endl;
    TreeLink<char> t;
    cout << endl;

    cout << "t.insRoot('R') ___________________________________________________________________ t.insRoot('R')" << endl;
    t.insRoot('R');
    cout << endl;

    cout << "t.insFirst(t.root(), 'C') _____________________________________________ t.insFirst(t.root(), 'C')" << endl;
    //t.insFirst(t.root(), 'C');
    cout << endl;

    cout << "stampo albero t _________________________________________________________________ stampo albero t" << endl;
    t.print(t.root());
    cout << endl;

    cout << "a.insFirstSubTree(a.firstChild(a.root()), t) _______ a.insFirstSubTree(a.firstChild(a.root()), t)" << endl;
    a.insFirstSubTree(a.firstChild(a.root()), t);
    cout << endl;

    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;

    cout << "a.insSubTree(a.firstChild(a.root()), t) _______________ a.insSubTree(a.firstChild(a.root()), t)" << endl;
    a.insSubTree(a.firstChild(a.root()), t);
    cout << endl;

    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;

    cout << "stampo albero t _________________________________________________________________ stampo albero t" << endl;
    t.print(t.root());
    cout << endl;


    cout << endl;
    cout << endl;
    cout << endl;


    cout << "copy constructor tt = t _________________________________________________ copt constructor tt = t" << endl;
    TreeLink<char> tt = t;
    cout << endl;

    cout << "stampo albero tt _______________________________________________________________ stampo albero tt" << endl;
    tt.print(tt.root());
    cout << endl;

    cout << "stampo albero t _________________________________________________________________ stampo albero t" << endl;
    t.print(t.root());
    cout << endl;

    cout << "stampo (tt==t) __________________________________________________________________ stampo (tt==t)" << endl;
    cout << (tt == t);
    cout << endl;

    cout << "tt.insFirst(tt.root(), 'a') _________________________________________ tt.insFirst(tt.root(), 'a')" << endl;
    tt.insFirst(tt.root(), 'a');
    cout << endl;

    cout << "stampo albero tt _______________________________________________________________ stampo albero tt" << endl;
    tt.print(tt.root());
    cout << endl;

    cout << "stampo albero t _________________________________________________________________ stampo albero t" << endl;
    t.print(t.root());
    cout << endl;

    cout << "stampo (tt==t) __________________________________________________________________ stampo (tt==t)" << endl;
    cout << (tt == t);
    cout << endl;

    cout << "t.~TreeList<char>() _________________________________________________________ t.~TreeList<char>()" << endl;
    //t.~TreeLink<char>();
    cout << endl;

    a.insNext(a.firstChild(a.firstChild(a.root())), 'd');


    cout << "stampo albero a _________________________________________________________________ stampo albero t" << endl;
    a.print(a.root());
    cout << endl;


    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

/*
    cout << "print albero a " << endl;
    a.print(a.root());
    cout << endl;

    cout << "pre_print albero a " << endl;
    a.pre_print(a.root());
    cout << endl;
    cout << endl;

    cout << "in_print albero a " << endl;
    a.in_print(a.root());
    cout << endl;
    cout << endl;

    cout << "post_print albero a " << endl;
    a.post_print(a.root());
    cout << endl;
    cout << endl;
*/
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    TreeLink<int> toprint;
    toprint.insRoot(5);

    toprint.insFirst(toprint.root(), 6);
    toprint.insFirst(toprint.firstChild(toprint.root()), 20);
    toprint.insFirst(toprint.firstChild(toprint.root()), 21);

    toprint.insFirst(toprint.root(), 15);
    toprint.insFirst(toprint.root(), 4);

    toprint.insFirst(toprint.firstChild(toprint.root()), 9);
    toprint.insFirst(toprint.firstChild(toprint.root()), 8);

    toprint.insFirst(toprint.nextSibling(toprint.firstChild(toprint.firstChild(toprint.root()))), 3);
    toprint.insFirst(toprint.nextSibling(toprint.firstChild(toprint.firstChild(toprint.root()))), 11);
    toprint.insFirst(toprint.nextSibling(toprint.firstChild(toprint.firstChild(toprint.root()))), 12);


    cout << endl;
    cout << endl;
    cout << endl;


    cout << "print albero toprint " << endl;
    toprint.print(toprint.root());

    cout << endl;
    cout << endl;
    cout << endl;

    cout << "pre_print albero toprint " << endl;
    toprint.pre_print(toprint.root());
    cout << endl;
    cout << endl;

    cout << "in_print albero toprint " << endl;
    toprint.in_print(toprint.root());
    cout << endl;
    cout << endl;

    cout << "post_print albero toprint " << endl;
    toprint.post_print(toprint.root());
    cout << endl;
    cout << endl;

}

void test_list_tree() {

    cout << "creo albero a _____________________________________________________________________ creo albero a" << endl;
    TreeList<char> a;
    cout << endl;

    cout << "creo nodo cursor _______________________________________________________________ creo nodo cursor" << endl;
    TreeList<char>::node cursor;
    cout << endl;

    cout << "a.insRoot('r') ___________________________________________________________________ a.insRoot('r')" << endl;
    a.insRoot('r');
    cout << endl;


    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;

    cout << "a.insFirst(a.root(), 'c') _____________________________________________ a.insFirst(a.root(), 'c')" << endl;
    a.insFirst(a.root(), 'c');
    cout << endl;

    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;

    cursor = a.root();      // cursor = r (root)

    cout << "a.insFirst(a.root(), 'b') _____________________________________________ a.insFirst(a.root(), 'b')" << endl;
    a.insFirst(a.root(), 'b');
    cout << endl;

    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;

    cout << "a.insFirst(a.root(), 'a') _____________________________________________ a.insFirst(a.root(), 'a')" << endl;
    a.insFirst(a.root(), 'a');
    cout << endl;

    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;

    cout << "a.firstChild(cursor) _______________________________________________________ a.firstChild(cursor)" << endl;
    cursor = a.firstChild(cursor); // cursor = a (firstChild di root)
    cout << endl;

    cout << "a.insNext(cursor, 'z') ___________________________________________________ a.insNext(cursor, 'a')" << endl;
    a.insNext(cursor, 'z');
    cout << endl;

    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;

    cout << "a.insFirst(a.root(), 'a') _____________________________________________ a.insFirst(a.root(), 'a')" << endl;
    a.insFirst(cursor, 'm');
    cout << endl;

    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;

    cout << "stampo a.readNode(cursor) _____________________________________________ stampo a.readNode(cursor)" << endl;
    cout << a.readNode(cursor);
    cout << endl;

    cout << "a.removeSubTree(cursor) _________________________________________________ a.removeSubTree(cursor)" << endl;
    a.removeSubTree(cursor);
    cout << endl;

    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;

    cout << "creo albero t _____________________________________________________________________ creo albero t" << endl;
    TreeList<char> t;
    cout << endl;

    cout << "creo nodo cursor _______________________________________________________________ creo nodo cursor" << endl;
    TreeList<char>::node cursor_t;
    cout << endl;

    cout << "t.insRoot('R') ___________________________________________________________________ t.insRoot('R')" << endl;
    t.insRoot('R');
    cout << endl;

    cout << "stampo albero t _________________________________________________________________ stampo albero t" << endl;
    t.print(t.root());
    cout << endl;

    cout << "t.insFirst(t.root(), 'Y') _____________________________________________ t.insFirst(t.root(), 'Y')" << endl;
    t.insFirst(t.root(), 'Y');
    cout << endl;

    cout << "cursor_t = t.firstChild(t.root()) _____________________________ cursor_t = t.firstChild(t.root())" << endl;
    cursor_t = t.firstChild(t.root());     //cursor = Y
    cout << endl;

    cout << "stampo a.readNode(cursor_t) _________________________________________ stampo a.readNode(cursor_t)" << endl;
    cout << a.readNode(cursor_t);
    cout << endl;

    cout << "t.insNext(cursor_t, 'U') _______________________________________________ t.insNext(cursor_t, 'U')" << endl;
    t.insNext(cursor_t, 'U');
    cout << endl;

    cout << "stampo albero t _________________________________________________________________ stampo albero t" << endl;
    t.print(t.root());
    cout << endl;

    cout << "a.firstChild(cursor) _______________________________________________________ a.firstChild(cursor)" << endl;
    cursor = a.firstChild(a.root()); // cursor = z (firstChild di root)
    cout << endl;

    cout << "stampo a.readNode(cursor) _____________________________________________ stampo a.readNode(cursor)" << endl;
    cout << a.readNode(cursor);
    cout << endl;

    cout << "a.insFirstSubTree(cursor, t) _______________________________________ a.insFirstSubTree(cursor, t)" << endl;
    a.insFirstSubTree(cursor, t);
    cout << endl;

    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;

    cout << "a.insSubTree(cursor, t) _________________________________________________ a.insSubTree(cursor, t)" << endl;
    a.insSubTree(cursor, t);
    cout << endl;

    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;


    cout << endl;
    cout << endl;


    cout << "stampo albero t _________________________________________________________________ stampo albero t" << endl;
    t.print(t.root());
    cout << endl;


    cout << "copy constructor tt = t _________________________________________________ copt constructor tt = t" << endl;
    TreeList<char> tt = t;
    cout << endl;

    cout << "stampo albero tt _______________________________________________________________ stampo albero tt" << endl;
    tt.print(tt.root());
    cout << endl;

    cout << "stampo albero t _________________________________________________________________ stampo albero t" << endl;
    t.print(t.root());
    cout << endl;

    cout << "stampo (tt==t) __________________________________________________________________ stampo (tt==t)" << endl;
    cout << (tt == t);
    cout << endl;

    cout << "tt.insFirst(tt.root(), 'a') _________________________________________ tt.insFirst(tt.root(), 'a')" << endl;
    tt.insFirst(tt.root(), 'a');
    cout << endl;

    cout << "stampo albero tt _______________________________________________________________ stampo albero tt" << endl;
    tt.print(tt.root());
    cout << endl;

    cout << "stampo albero t _________________________________________________________________ stampo albero t" << endl;
    t.print(t.root());
    cout << endl;

    cout << "stampo (tt==t) ___________________________________________________________________ stampo (tt==t)" << endl;
    cout << (tt == t);
    cout << endl;

    cout << "t.~TreeList<char>() _________________________________________________________ t.~TreeList<char>()" << endl;
    //t.~TreeList<char>();
    cout << endl;

    cout << "stampo albero t _________________________________________________________________ stampo albero t" << endl;
    t.print(t.root());
    cout << endl;

    cout << "t.profondita() ___________________________________________________________________ t.profondita()" << endl;
    cout << t.profondita();
    cout << endl;

    cout << "a.profondita() ___________________________________________________________________ a.profondita()" << endl;
    cout << a.profondita();
    cout << endl;

    cout << "t.larghezza() _____________________________________________________________________ t.larghezza()" << endl;
    cout << t.larghezza();
    cout << endl;

    cout << "a.larghezza() _____________________________________________________________________ a.larghezza()" << endl;
    cout << a.larghezza();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
/*
    cout << "stampo albero a _________________________________________________________________ stampo albero a" << endl;
    a.print(a.root());
    cout << endl;




    cout << "print albero a " << endl;
    a.print(a.root());
    cout << endl;

    cout << "pre_print albero a " << endl;
    a.pre_print(a.root());
    cout << endl;
    cout << endl;

    cout << "in_print albero a " << endl;
    a.in_print(a.root());
    cout << endl;
    cout << endl;

    cout << "post_print albero a " << endl;
    a.post_print(a.root());
    cout << endl;
    cout << endl;
    */

    TreeList<int> toprint;
    toprint.insRoot(5);

    toprint.insFirst(toprint.root(), 6);
    toprint.insFirst(toprint.firstChild(toprint.root()), 20);
    toprint.insFirst(toprint.firstChild(toprint.root()), 21);

    toprint.insFirst(toprint.root(), 15);
    toprint.insFirst(toprint.root(), 4);

    toprint.insFirst(toprint.firstChild(toprint.root()), 9);
    toprint.insFirst(toprint.firstChild(toprint.root()), 8);

    toprint.insFirst(toprint.nextSibling(toprint.firstChild(toprint.firstChild(toprint.root()))), 3);
    toprint.insFirst(toprint.nextSibling(toprint.firstChild(toprint.firstChild(toprint.root()))), 11);
    toprint.insFirst(toprint.nextSibling(toprint.firstChild(toprint.firstChild(toprint.root()))), 12);

    cout << endl;
    cout << endl;
    cout << endl;


    cout << "print albero toprint " << endl;
    toprint.print(toprint.root());

    cout << endl;
    cout << endl;
    cout << endl;

    cout << "pre_print albero toprint " << endl;
    toprint.pre_print(toprint.root());
    cout << endl;
    cout << endl;

    cout << "in_print albero toprint " << endl;
    toprint.in_print(toprint.root());
    cout << endl;
    cout << endl;

    cout << "post_print albero toprint " << endl;
    toprint.post_print(toprint.root());
    cout << endl;
    cout << endl;
}

void test_b_tree() {

    cout << "BTree<int> t _______________________________________________________________________ BTree<int> t" << endl;
    BTree<int> t;
    cout << endl;

    cout << "creo nodo r _________________________________________________________________________ creo nodo r" << endl;
    NodeBTree<int> *r = new NodeBTree<int>;
    cout << endl;

    cout << "t.ins_root(1) _____________________________________________________________________ t.ins_root(1)" << endl;
    t.ins_root(1);
    cout << endl;

    cout << "t.read(r) _____________________________________________________________________________ t.read(r)" << endl;
    cout << t.read(r);
    cout << endl;

    cout << "t.read(t.left(r)) _____________________________________________________________ t.read(t.left(r))" << endl;
    cout << t.read(t.left(r));
    cout << endl;

    cout << "t.left_empty(t.root()) ___________________________________________________ t.left_empty(t.root())" << endl;
    cout << t.left_empty(t.root());
    cout << endl;

    cout << "t.ins_left(t.root()) _______________________________________________________ t.ins_left(t.root())" << endl;
    t.ins_left(t.root());
    cout << endl;

    cout << "t.ins_right(t.root()) _____________________________________________________ t.ins_right(t.root())" << endl;
    t.ins_right(t.root());
    cout << endl;

    cout << "t.write(t.left(t.root()), 2) _______________________________________ t.write(t.left(t.root()), 2)" << endl;
    t.write(t.left(t.root()), 2);
    cout << endl;

    cout << "r = t.left(t.root()) _______________________________________________________ r = t.left(t.root())" << endl;
    r = t.left(t.root());
    cout << endl;

    cout << "stampo t.read(r) _______________________________________________________________ stampo t.read(r)" << endl;
    cout << t.read(r);
    cout << endl;

    cout << "t.write(t.right(t.root()), 3) _____________________________________ t.write(t.right(t.root()), 3)" << endl;
    t.write(t.right(t.root()), 3);
    cout << endl;

    cout << "r = t.right(t.root()) _____________________________________________________ r = t.right(t.root())" << endl;
    r = t.right(t.root());
    cout << endl;

    cout << "stampo t.read(r) _______________________________________________________________ stampo t.read(r)" << endl;
    cout << t.read(r);
    cout << endl;

    cout << "stampo t.print(t.root()) _______________________________________________ stampo t.print(t.root())" << endl;
    t.print(t.root());
    cout << endl;


    cout << "t.ins_left(t.left(t.root())) _______________________________________ t.ins_left(t.left(t.root()))" << endl;
    t.ins_left(t.left(t.root()));
    t.write(t.left(t.left(t.root())), 4);
    cout << endl;

    cout << "t.ins_left(t.right(t.root())) _____________________________________ t.ins_left(t.right(t.root()))" << endl;
    t.ins_right(t.left(t.root()));
    t.write(t.right(t.left(t.root())), 5);
    cout << endl;

    cout << "t.ins_right(t.left(t.root())) _____________________________________ t.ins_right(t.left(t.root()))" << endl;
    t.ins_left(t.right(t.root()));
    t.write(t.left(t.right(t.root())), 6);
    cout << endl;

    cout << "t.ins_right(t.right(t.root())) ___________________________________ t.ins_right(t.right(t.root()))" << endl;
    t.ins_right(t.right(t.root()));
    t.write(t.right(t.right(t.root())), 7);
    cout << endl;

    cout << "stampo t.print(t.root()) _______________________________________________ stampo t.print(t.root())" << endl;
    t.print(t.root());
    cout << endl;

    cout << "BTree<int> tt = t _____________________________________________________________ BTree<int> tt = t" << endl;
    BTree<int> tt = t;
    cout << endl;

    cout << "stampo tt.print(tt.root()) ___________________________________________ stampo tt.print(tt.root())" << endl;
    tt.print(tt.root());
    cout << endl;

    t.erase(t.left(t.root()));

    t.ins_left(t.root());

    cout << "stampo t.print(t.root()) _______________________________________________ stampo t.print(t.root())" << endl;
    t.print(t.root());
    cout << endl;


    t.ins_sub_tree(t.left(t.root()), tt);

    cout << "stampo t.print(t.root()) _______________________________________________ stampo t.print(t.root())" << endl;
    t.print(t.root());
    cout << endl;

    cout << "copy constructor _______________________________________________________________ copy constructor" << endl;
    BTree<int> ttt = t;

    cout << "stampo (ttt==t) _________________________________________________________________ stampo (ttt==t)" << endl;
    cout << (ttt == t);
    cout << endl;
    cout << endl;

    cout << "stampo ttt.print(ttt.root()) _______________________________________ stampo ttt.print(ttt.root())" << endl;
    ttt.print(ttt.root());
    cout << endl;

    cout << "stampo tt.print(tt.root()) ___________________________________________ stampo tt.print(tt.root())" << endl;
    tt.print(tt.root());
    cout << endl;

    //tt.print(tt.root());
    tt.rimuovi_foglie_pari(tt.root());

    cout << "stampo tt.print(tt.root()) ___________________________________________ stampo tt.print(tt.root())" << endl;
    tt.print(tt.root());
    cout << endl;


    BTree<char> A;
    BTree<char> X;
    A.ins_root('a');
    X.ins_root('x');

    A.ins_left(A.root());
    A.write(A.left(A.root()), 'b');

    A.ins_right(A.root());
    A.write(A.right(A.root()), 'c');

    X.ins_left(X.root());
    X.write(X.left(X.root()), 'y');

    X.ins_right(X.root());
    X.write(X.right(X.root()), 'z');

    cout << endl;
    A.print(A.root());
    cout << endl;
    X.print(X.root());

    A.mutation(A, A.root(), X, X.left(X.root()));

    cout << endl;
    A.print(A.root());
    cout << endl;
    X.print(X.root());
    cout << endl;

    cout << X.level(X.left(X.left(X.root())));
    cout << endl;

    cout << "X.level root()" << endl;
    cout << X.level(X.root());
    cout << endl << endl;

    cout << "X.size()" << endl;
    cout << X.size();
    cout << endl << endl;

    cout << "ttt.size()" << endl;
    cout << ttt.size();
    cout << endl << endl;

    cout << "print X" << endl;
    X.print(X.root());
    cout << endl;

    cout << "X.depth()" << endl;
    cout << X.depth();
    cout << endl << endl;

    cout << "print ttt" << endl;
    ttt.print(ttt.root());
    cout << endl << endl;

    cout << "ttt.depth()" << endl;
    cout << ttt.depth();
    cout << endl << endl;

    cout << "print X" << endl;
    X.print(X.root());
    cout << endl;

    cout << "pre_print X" << endl;
    X.pre_print(X.root());
    cout << endl;
    cout << endl;

    cout << "in_print X" << endl;
    X.in_print(X.root());
    cout << endl;
    cout << endl;

    cout << "post_print X" << endl;
    X.post_print(X.root());
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    t.costr(tt, tt);
    t.print(t.root());
    cout << endl;
    cout << endl;

    t.write(t.root(), 10);
    t.print(t.root());
    cout << endl;
    cout << endl;


    X.ins_right(X.right(X.root()));
    X.write(X.right(X.right(X.root())), 'y');

    X.ins_left(X.right(X.root()));
    X.write(X.left(X.right(X.root())), 'w');


    X.ins_left(X.left(X.left(X.root())));
    X.write(X.left(X.left(X.left(X.root()))), 'd');


    cout << "print X" << endl;
    X.print(X.root());
    cout << endl;

    cout << "creo nodo c _________________________________________________________________________ creo nodo c" << endl;
    NodeBTree<char> *c = new NodeBTree<char>;

    c = X.right(X.left(X.root()));
    cout << X.read(c);
    cout << endl;
    cout << endl;


    cout << "creo nodo y _________________________________________________________________________ creo nodo y" << endl;
    NodeBTree<char> *y = new NodeBTree<char>;
    y = X.right(X.right(X.root()));
    cout << X.read(y);
    cout << endl;
    cout << endl;


    cout << "creo nodo z _________________________________________________________________________ creo nodo z" << endl;
    NodeBTree<char> *z = new NodeBTree<char>;
    z = X.right(X.root());
    cout << X.read(z);
    cout << endl;
    cout << endl;


    cout << endl;

    cout << X.diametro(X.root());

}

void test_pri_coda() {
    CodaP<char> c;
    c.insert('c');
    c.print();

    c.insert('d');
    c.print();

    c.insert('a');
    c.print();

    c.insert('b');
    c.print();

/*
    c.deleteMin();
    c.print();

    c.deleteMin();
    c.print();
*/
    c.print_tree_form();

}

int main() {
    //test_list();
    //test_stack();
    //test_queue();
    //test_hash();
    //test_set();
    //test_tree();
    //test_link_tree();
    //test_list_tree();
    //test_b_tree();
    test_graph();
    //test_pri_coda();
}
