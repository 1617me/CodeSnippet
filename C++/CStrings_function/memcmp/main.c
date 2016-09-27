//
//  main.c
//  memcmp
//
//  Created by LiuQiang on 16/9/27.
//  Copyright © 2016年 LiuQiang. All rights reserved.
//

#include <stdio.h>
#include <string.h>

/* 
 * int memcmp(const void *buf1, const void *buf2, unsigned int count);
 * 比较内存 buf1, buf2 的前 count 区域
 * buf1 < buf2 , 返回 -1
 * buf1 > buf2 , 返回 1
 * buf1 == buf2, 返回 0
 * 函数是以字节进行比较的
 */
int main(int argc, const char * argv[]) {
    char str1[15];
    char str2[15];
    memcpy(str1, "abcdef", 6);
    memcpy(str1, "ABCDEF", 6);
    
    
    int ret = memcmp(str1, str2, 5);
    if (ret > 0) {
        printf("str1 > str2\n");
    }
    else if (ret < 0){
        printf("str1 < str2\n");
    }
    else {
        printf("str1 == str2\n");
    }
    return 0;
}
