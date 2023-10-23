//
// Created by general9k on 15.09.2023.
//
#include <vector>

using namespace std;

#ifndef ___MODULE_H
#define ___MODULE_H


class Module {
public:
    static vector<int> sort_merge(vector<int> array, int &counter);

    static vector<int> sort_fast(vector<int> array, int &counter);

    static vector<int> sort_digit(vector<int> array, int &counter);
};

#endif //___MODULE_H
