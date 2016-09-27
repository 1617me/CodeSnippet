//
//  main.cpp
//  search_01adjacent_find
//
//  Created by LiuQiang on 16/9/27.
//  Copyright © 2016年 LiuQiang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, const char * argv[]) {
    std::vector<int> v1{0, 1, 2, 3, 40, 40, 41, 41, 8};
    
    /* 检查临近的两个元素, 返回第一个两个相等元素的首个 iterator */
    auto i1 = std::adjacent_find(v1.begin(), v1.end());
    
    if (i1 == v1.end()) {
        std::cout << "no matching adjacent elements\n";
    } else {
        std::cout << "the first adjacent pair of equal elements at: "
        << std::distance(v1.begin(), i1) << '\n';
        std::cout << *i1 << " | " << *(i1 + 1) << std::endl;
    }
    
    /* 
     * 检查临近的两个元素, 判断两个元素是否是第一个 < 第二个元素,如果是返回第一个的 iterator 
     * 使用 binary predicate p less<class> greater<class> 来作为条件.
     */
//    auto i2 = std::adjacent_find(v1.begin(), v1.end(), std::greater<int>());
    auto i2 = std::adjacent_find(v1.begin(), v1.end(), std::less<int>());
    if (i2 == v1.end()) {
        std::cout << "The entire vector is sorted in ascending order\n";
    } else {
        std::cout << "The last element in the non-decreasing subsequence is at: "
        << *i2 << " " <<  *(i2+1)<< std::endl;;
    }
    return 0;
}
