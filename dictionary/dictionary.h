//
// Created by Mauro Nicolì on 2019-03-13.
//

#ifndef STRUTTURE_DATI_DICTIONARY_H
#define STRUTTURE_DATI_DICTIONARY_H

template<class K, class V>
struct Entry {
    K key;
    V value;
    Entry *_next;

    Entry() {
        _next = NULL;
    };

    Entry(Entry<K, V> &e) {
        key = e.key;
        value = e.value;
        _next = e._next;
    }

};

template<class K, class V>
class Dictionary {

public:

    virtual ~Dictionary() {};

    virtual void create() const = 0;

    virtual bool empty() const = 0;

    virtual int size() const = 0;

    virtual Entry<K, V> *find(const K &) const = 0;

    virtual void insert(Entry<K, V> &) = 0;

    virtual void erase(const K&) = 0;

    virtual void modify(const K&, const V&) = 0;

};

#endif //STRUTTURE_DATI_DICTIONARY_H
