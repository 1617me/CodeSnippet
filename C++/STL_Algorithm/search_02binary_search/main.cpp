//
//  main.cpp
//  search_02binary_search
//
//  Created by LiuQiang on 16/9/27.
//  Copyright © 2016年 LiuQiang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, const char * argv[]) {
    std::vector<int> haystack{1, 3, 4, 5, 7, 9};
    std::vector<int> needles{1, 2, 5};
    for(auto needle: needles){
        std::cout << "searching for " << needle << '\n';
        /**
         *
         * 二分查找:查找 begin~end 之间是否有和 value 相等的, 如果有则返回 true, 否则范湖 false, 查找的 begin ~ end 需要是有序的,
         * 重载函数, 可使用自定义判断条件来进行判断是否相等
         * 在有序序列中查找value，找到返回true。重载的版本实用指定的比较函数对象或函数指针来判断相等。
         */
        if (std::binary_search(haystack.begin(), haystack.end(), needle)){
            std::cout << "Found!" << needle << '\n';
        }
        else {
            std::cout << "no dice!\n";
        }
    }
    return 0;
}

/* possible implementation */
#if 0
template <class ForwardIt, class T>
bool binary_search(ForwardIt first, ForwardIt last, const T& value){
    first = std::lower_bound(first, last, value);
    return (!(first == last) && !(value < &first));
}

template <class ForwardIt, class T, class>
bool binary_search(ForwarIt first, ForwardIt last, const T& value, Compare comp){
    first = std::lower_bound(first, last, value, comp);
    return (!(first == last) && !(comp(value, *first)));
}

#endif