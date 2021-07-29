#include <vector>
#include <iostream>

template<typename T> void debugVec(std::vector <T> v) {
    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << (*it) << ",";
    }
    std::cout << std::endl;
}

template<typename T> void debugVec2(std::vector < std::vector<T>> v) {
    for (auto it1 = v.begin(); it1 != v.end(); it1++) {
        for (auto it2 = (*it1).begin(); it2 != (*it1).end(); it2++) {
            std::cout << (*it2) << ",";
        }
        std::cout << std::endl;
    }
}
