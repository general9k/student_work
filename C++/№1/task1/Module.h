//
// Created by general9k on 15.09.2023.
//
#include <vector>

using namespace std;

#ifndef ___MODULE_H
#define ___MODULE_H


class Module {
public:
    static vector<int> sort_choice(vector<int> array, int &counter_assignment, int &counter_if);

    static vector<int> sort_bubble(vector<int> array, int &counter_assignment, int &counter_if);

    static vector<int> sort_insert(vector<int> array, int &counter_assignment, int &counter_if);
};


#endif //___MODULE_H
