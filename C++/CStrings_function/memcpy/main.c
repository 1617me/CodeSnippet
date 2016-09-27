//
//  main.c
//  memcpy
//
//  Created by LiuQiang on 16/9/27.
//  Copyright © 2016年 LiuQiang. All rights reserved.
//

#include <stdio.h>
#include <string.h>

/* 
 * void *memcpy(void *dest, const void *src, size_t n);
 * C/C++ 内存拷贝函数, 从 src 所指的内存地址的起始位置开始拷贝 n 个  \
 * 字节到 dest 所指的内存的起始位置中
 * dest 和 src 都不一定是数组, 可以是任何可读写的空间.
 */


int main(void)
{
    int a[10] = {1,2,3,4,5,0,6,7,8,9}; //整型数组间的拷贝
    int b[10];
    memcpy(b,a,10*sizeof(a[0]));
    for(int i=0; i<10; i++)
    {
        printf("%d\n",b[i]);
    }
    char c[10] = {'a','b','c','d','\0','\n','e','f','g','h'};
    char d[10];
    //字符数组间的拷贝, signal SIGABRT / overflow destination buffer
    memcpy(d,c,10*sizeof(a[0]));
    for(int i=0; i<10; i++)
    {
        printf("%d\n",d[i]);
    }
    puts(d);
    return 0;
}