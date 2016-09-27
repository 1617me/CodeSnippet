//
//  main.cpp
//  search_03find&&find_if
//
//  Created by LiuQiang on 16/9/27.
//  Copyright © 2016年 LiuQiang. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

/* 
 * 利用等于操作符，把标志范围内的元素与输入值比较，返回相等元素个数。
 */

using namespace std;
int main(int argc, const char * argv[]) {
    
    int data[] = {1, 2, 3, 4, 4, 3, 6, 7, 8, 9, 12};
    vector<int> v(data, data+11);
    
    cout << " ******** find *********" << endl;
    int target1 = 3;
    int target2 = 5;
    long num_items1 = count(v.begin(), v.end(), target1);
    long num_items2 = count(v.begin(), v.end(), target2);
    cout << "number: " << target1 << " count: " << num_items1 << endl;
    cout << "number: " << target2 << " count: " << num_items2 << endl;
    putchar(10) ;
    cout << " ******** find_if *********" << endl;
    
    long num_if = count_if(v.begin(), v.end(), [](int i){
        return i % 3 == 0;
    });
    
    long num_if2 = count_if(v.begin(), v.end(), [](int i){
        return i % 2 == 0;
    });
    cout << "pre: i % 3 -> " << num_if << endl;
    cout << "pre: i % 2 -> " << num_if2 << endl;
    return 0;
}
