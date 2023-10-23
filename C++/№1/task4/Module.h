//
// Created by general9k on 15.09.2023.
//
#include <vector>

using namespace std;

#ifndef ___MODULE_H
#define ___MODULE_H


class Module {
public:
    static vector<int> sort_bubble(vector<int> array, int &counter);
    static vector<int> sort_SHELL(vector<int> array, int &counter);
    static vector<int> sort_shaker(vector<int> array, int &counter);
};

#endif //___MODULE_H
