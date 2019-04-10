//
// Created by Mauro Nicolì on 2019-03-13.
//

#ifndef STRUTTURE_DATI_HASH_TABLE_H
#define STRUTTURE_DATI_HASH_TABLE_H

#include <iostream>
#include "dictionary.h"
#include "hash.h"
#include "../list/linked_list.h"
#include "../stack/stack.h"

using namespace std;

template<class K, class V>
class HashTable : public Dictionary<K, V> {

public:

    HashTable(int);

    HashTable(const HashTable<K, V> &);

    bool empty() const {
        return (_size == 0);
    };

    int size() const {
        return _size;
    };

    void erase(const K &);

    void modify(const K &, const V &);

    void create() const;

    int search(const K &) const;

    Entry<K, V> *find(const K &k) const;

    void insert(Entry<K, V> &);

    void print() const;

    HashTable<K, V> &operator=(const HashTable<K, V> &);

    bool operator==(const HashTable<K, V> &);

    bool containsValue(const V &);

    Linked_list<V> values();

    Linked_list<K> keys();

    void resize();


private:

    Entry<K, V> **table;

    int divisor;

    Hash<K> hashm;

    int _size;

};


template<class K, class V>
HashTable<K, V>::HashTable(int div) {
    divisor = div;
    _size = 0;

    table = new Entry<K, V> *[divisor];
    for (int i = 0; i < divisor; i++) {
        table[i] = NULL;
    }
}

template<class K, class V>
HashTable<K, V>::HashTable(const HashTable<K, V> &h) {
    this->divisor = h.divisor;
    this->_size = h._size;
    this->table = new Entry<K, V> *[this->divisor];

    for (int i = 0; i < h.divisor; i++) {
        Entry<K, V> *hentry = h.table[i];
        if (h.table[i] != NULL) {
            this->table[i] = new Entry<K, V>;
            this->table[i]->key = hentry->key;
            this->table[i]->value = hentry->value;
            Entry<K, V> *tentry = this->table[i];
            while (hentry->_next != NULL) {
                tentry->_next = new Entry<K, V>;
                tentry->_next->key = hentry->_next->key;
                tentry->_next->value = hentry->_next->value;
                hentry = hentry->_next;
                tentry = tentry->_next;
            }
        }
    }
}


template<class K, class V>
void HashTable<K, V>::erase(const K &k) {
    int b = search(k);
    if (table[b] != NULL) {
        table[b] = NULL;
        _size--;
    }
}

template<class K, class V>
void HashTable<K, V>::modify(const K &k, const V &v) {
    int b = search(k);
    if (table[b] != NULL) {
        erase(k);
        Entry<K, V> ent;
        ent.value = v;
        ent.key = k;
        insert(ent);
    }
}

template<class K, class V>
int HashTable<K, V>::search(const K &k) const {
    int i = (int) hashm(k) % divisor;
    int j = i;
    do {
        if (table[j] == NULL || table[j]->key == k) {
            return j;
        }
        j = (j + 1) % divisor;
    } while (j != i);

    return j;
}

template<class K, class V>
Entry<K, V> *HashTable<K, V>::find(const K &k) const {
    int b = search(k);
    if (table[b] == NULL || table[b]->key != k) {
        return NULL;
    }
    return table[b];
}


template<class K, class V>
void HashTable<K, V>::insert(Entry<K, V> &e) {
    int b = search(e.key);
    if (table[b] == NULL) {
        table[b] = new Entry<K, V>(e);
        _size++;

    } else if (table[b]->key == e.key) {
        if (table[b]->value != e.value) {
            Entry<K, V> *temp = table[b];
            while (temp->_next != NULL) {
                if (temp->_next->value != e.value) {
                    temp = temp->_next;
                } else {
                    //throw "Duplicate value";
                    cout << "Try to insert duplicate value" << endl << endl;
                    return;
                }
            }
            temp->_next = new Entry<K, V>(e);

        } else {
            //throw "Duplicate value";
            cout << "Try to insert duplicate value" << endl << endl;
            return;
        }

    } else {
        //throw "Hash table is full";
        cout << "Hash table is full" << endl << endl;
        return;
    }
}

/*
template<class K, class V>
void HashTable<K, V>::insert(Entry<K, V> &e) {
    int b = search(e.key);
    if (table[b] == NULL) {
        table[b] = new Entry<K, V>(e);
        _size++;

    } else if (table[b]->key == e.key) {
        Entry<K, V> *temp = table[b];
        while (temp != NULL) {

            if (temp->value != e.value) {
                temp = temp->_next;
            } else {
                cout << "Try to insert duplicate value" << endl << endl;
                return;
            }
        }
        temp = new Entry<K, V>(e);
    } else {
        cout << "Hash table is full" << endl << endl;
        return;
    }
}
*/
template<class K, class V>
void HashTable<K, V>::create() const {

}

template<class K, class V>
void HashTable<K, V>::print() const {

    for (int i = 0; i < divisor; i++) {
        cout << "BuckIndex[" << i << "] -> ";
        if (table[i] == NULL) {
            cout << "Key : [-] |  Value : [ - ]";
        } else {
            cout << "Key : [" << this->table[i]->key << "] | ";
            cout << " Value : ";
            Entry<K, V> *temp = table[i];
            while (temp != NULL) {
                cout << "[ " << temp->value << " ]";
                temp = temp->_next;
            }
        }
        cout << endl;
    }
    cout << endl;
}

template<class K, class V>
bool HashTable<K, V>::containsValue(const V &v) {
    for (int i = 0; i < divisor; i++) {
        Entry<K, V> *temp = table[i];
        while (temp != NULL) {
            if (temp->value == v) {
                return true;
            } else {
                temp = temp->_next;
            }
        }
    }
    return false;
}

template<class K, class V>
Linked_list<V> HashTable<K, V>::values() {
    Linked_list<V> list_values;
    Stack<V> stack_values;
    for (int i = 0; i < divisor; i++) {
        Entry<K, V> *temp = table[i];
        while (temp != NULL) {
            stack_values.push_no_duplicati(temp->value);
            temp = temp->_next;
        }
    }
    while (!stack_values.empty()) {
        list_values.push_back(stack_values.top());
        stack_values.pop();
    }
    return list_values;
}

template<class K, class V>
Linked_list<K> HashTable<K, V>::keys() {
    Linked_list<K> list_keys;
    for (int i = 0; i < divisor; i++) {
        if (this->table[i] != NULL) {
            list_keys.push_back(table[i]->key);
        }
    }
    return list_keys;
}

template<class K, class V>
void HashTable<K, V>::resize() {
    HashTable<K, V> *new_table = new HashTable(this->divisor * 2);
    for (int i = 0; i < this->divisor; i++) {
        if (this->table[i] != NULL) {
            new_table->table[i] = this->table[i];
        }
    }
    *this = *new_table;
}

template<class K, class V>
HashTable<K, V> &HashTable<K, V>::operator=(const HashTable<K, V> &h) {
    this->divisor = h.divisor;
    this->_size = h._size;
    this->table = new Entry<K, V> *[this->divisor];

    for (int i = 0; i < h.divisor; i++) {
        Entry<K, V> *hentry = h.table[i];
        if (h.table[i] != NULL) {
            this->table[i] = new Entry<K, V>;
            this->table[i]->key = hentry->key;
            this->table[i]->value = hentry->value;
            Entry<K, V> *tentry = this->table[i];
            while (hentry->_next != NULL) {
                tentry->_next = new Entry<K, V>;
                tentry->_next->key = hentry->_next->key;
                tentry->_next->value = hentry->_next->value;
                hentry = hentry->_next;
                tentry = tentry->_next;
            }
        }
    }
    return *this;
}

template<class K, class V>
bool HashTable<K, V>::operator==(const HashTable<K, V> &e) {
    bool check = false;
    if (this->_size != e._size) {
        check = false;
    } else {
        for (int i = 0; i < divisor; i++) {
            Entry<K, V> *etemp = e.table[i];
            Entry<K, V> *ttemp = table[i];
            while ((etemp != NULL) && (ttemp != NULL)) {
                if ((ttemp->key == etemp->key) && (ttemp->value == etemp->value)) {
                    etemp = etemp->_next;
                    ttemp = ttemp->_next;
                } else {
                    return false;
                }
            }
        }
        check = true;
    }
    return check;
}

/*
template<class K, class V>
ostream &HashTable<K, V>::operator<<(ostream &os, const HashTable<K, V> &h) {
    cout << "BuckIndex[i]: [ key, value ]" << endl;
    for (int i = 0; i <= h.size(); i++) {
        if (h.table[i] == NULL){
            cout << "BuckIndex[]: [ - , - ]" << endl;
        } else {
            cout << "BuckIndex[" << i << "]: [ " << h.table[i]->key;
            cout << ", ";
            cout << h.table[i]->value << " ]" << endl;
        }

    }
    return os;
}
 */

#endif //STRUTTURE_DATI_HASH_TABLE_H
