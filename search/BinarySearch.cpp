//
//  BinarySearch.cpp
//  data_structure
//
//  Created by 植亚汉 on 2019/3/10.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include "BinarySearch.hpp"

/**
 二分查找算法
 
 @param A 数组
 @param low 最低的下标
 @param hight 最高的下标
 @param key 你要查找的值
 @return 返回查找值的下标
 */
int Binary::BinarySearch(int A[], int low,int hight,int key){
    
    if (low <= hight) {
        //求出待查区间内，中点元素的下标
        int mid = (low+hight)/2;
        if (key == A[mid]) {
            //如果刚好在中点，则返回
            return mid;
        }else if (key< A[mid]){
            //左子表继续查找
            return BinarySearch(A, low, mid-1, key);
            
        }else if (key > A[mid]){
            //右子表继续查找
            return BinarySearch(A, mid+1,hight, key);
        }else{
            return -1;
        }
    }
    return -1;
    
}

/**
 二分查找算法  改进版
 
 @param A 数组
 @param n 数组的大小
 @param key 你要查找的s值
 @return 返回查找值的下标
 */
int Binary::BinarySearch2(int A[],int n,int key){
    int low = 0;
    int high = n-1;
    
    while (low<=high) {
        int mid = (low+high)/2;
        
        if (key == A[mid]) {
            //如果刚好在中点，则返回
            return mid;
        }else if (key< A[mid]){
            //左子表继续查找
            high = mid -1;
            
        }else if (key > A[mid]){
            //右子表继续查找
            low = mid +1;
        }
    }
    return -1;
    
}
