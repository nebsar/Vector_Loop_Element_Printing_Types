/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 13, 2018, 10:58 PM
 */

#include <iostream>
#include <vector>
#include <algorithm>

int printElement(int element) {
    std::cout << element << " ";
}

struct PrintFunctor {

    int operator()(int elem) {
        std::cout << elem << " ";
    }
};

int main(int argc, char** argv) {

    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "from normal loop :  ";
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";

    std::cout << '\n';
    std::cout << "from elem : v loop :  ";

    for (auto elem : v)
        std::cout << elem << " ";

    std::cout << '\n';
    std::cout << "from for_each lambda loop :  ";

    for_each(v.begin(), v.end(), [&](int elem) {
        std::cout << elem << " ";
    });

    std::cout << '\n';
    std::cout << "from for_each function loop :  ";

    for_each(v.begin(), v.end(), printElement);

    std::cout << '\n';
    std::cout << "from Functor loop :  ";

    for_each(v.begin(), v.end(), PrintFunctor());


    return 0;
}

