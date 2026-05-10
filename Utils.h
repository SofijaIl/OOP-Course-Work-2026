#ifndef UTILS_H
#define UTILS_H

#include <iostream>

template <typename T>
void printAll(const T& collection) {
    for (const auto& item : collection) {
        item->displayInfo();
    }
}

#endif