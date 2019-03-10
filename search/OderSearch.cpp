//
//  OderSeek.cpp
//  data_structure
//
//  Created by 植亚汉 on 2019/3/10.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include "OderSearch.hpp"


/**
 
 顺序查找
 
 @param A 数组
 @param n 数组大小
 @param key 查找的关键字
 @return 返回查找的关键字下标
 */
int Order::Seek(int A[],int n,int key){
    A[n] = key; //设置岗哨，可以忽略大小的限制，提高效率
    for (int i = 0;  ; i++) {
        if (A[i] == key) {
            if (i<n) {
                return i;
            }else{
                return -1;
            }
            break;
        }
    }
}
