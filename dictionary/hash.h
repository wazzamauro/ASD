//
// Created by Mauro Nicolì on 2019-03-13.
//

#ifndef STRUTTURE_DATI_HASH_H
#define STRUTTURE_DATI_HASH_H

#include <string>
#include <math.h>

using namespace std;

template<class T>
class Hash {

public:
    size_t operator()(const T) const;
};

template<>
class Hash<string> {
public:
    size_t operator()(const string key) const {
        unsigned long hash_value = 0;
        int length = (int) key.length();
        for (int i = 0; i < length; i++)
            hash_value = 5 * hash_value + key.at(i);
        return size_t(hash_value);
    }
};

template<>
class Hash<int> {
public:
    size_t operator()(const int key) const {
        return key+1;
    }
};

#endif //STRUTTURE_DATI_HASH_H
