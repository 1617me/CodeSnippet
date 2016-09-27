//
//  main.c
//  memchr
//
//  Created by LiuQiang on 16/9/27.
//  Copyright © 2016年 LiuQiang. All rights reserved.
//

#include <stdio.h>
#include <string.h>
/*
 * extern void *memchr(const void *buf, int ch, size_t l);
 * 从buf 指定的区域, 搜索前 l 长度, 查找ch, 如果找到则返回对应的指针, 没找到返回 NULL;
 */

int main(int argc, const char * argv[]) {
    char str[] = "abcdefg";
    char *ps = memchr(str, 'd', strlen(str));
    if (ps != NULL){
        printf("search character found: %s\n", ps);
    }
    else {
        printf("search character not found\n");
    }
    return 0;
}
