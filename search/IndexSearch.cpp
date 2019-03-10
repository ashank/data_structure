//
//  IndexSeek.cpp
//  data_structure
//
//  Created by 植亚汉 on 2019/3/10.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include "IndexSearch.hpp"


/**
 分块索引算法，索引表采用顺序查找法

 @param MainIndex 主表，保存了所有的子表的数值
 @param IndexList 索引表，保存所有子表的关键字、在主表中的起始位置、长度、最大关键字
 @param m 索引表的大小
 @param key 索引的数值
 @return 返回主表中的位置
 */
int Index::Blocksch(int MainIndex[], IndexItem IndexList[],int m, int key){
    int j;
    int startPosition = -1 ; //查找的关键字在哪个块中
    int endPosition = -1;
    
    //在索引表中顺序查找关键字为key的对应的索引项
    for (int i = 0; i < m; i++){
        //如果 查找的 值，小于 索引表的对应的最大关键字，说明这个值在这个块中
        if (key <=IndexList[i].index){
            startPosition = IndexList[i].start;
            endPosition = startPosition + IndexList[i].lenght;
            break;
        }
    }
    
    //如果是key大于所有的最大关键字中的任何一个，说明它不属于这个表中
    if (startPosition == endPosition == -1) {
        return -1;
    }
    
    //获取得到开始的位置
    j = startPosition;
    //开始顺序查询主表
    while (j < endPosition ) {
        if (key == MainIndex[j]) {
            return j;
        } else {
            j++;
        }
    }
    return -1;
    
}


/**
 分块索引算法，索引表采用二分查找法
 
 @param MainIndex 主表，保存了所有的子表的数值
 @param IndexList 索引表，保存所有子表的关键字、在主表中的起始位置、长度、最大关键字
 @param m 索引表的大小
 @param key 索引的数值
 @return 返回主表中的位置
 */
int Index::Blocksch2(int MainIndex[], IndexItem IndexList[],int m, int key){
    int j;
    int startPosition = -1 ; //查找的关键字在哪个块中
    int endPosition = -1;
    
    
    //采用二分查找法
    int low = 0;
    int high = m-1;
    
    while (low <= high) {
        int mid = (low +high)/2;
        if (key == IndexList[mid].index) {
            startPosition = IndexList[mid].start;
            endPosition = IndexList[mid].start + IndexList[mid].lenght;
            break;
        }else if (key < IndexList[mid].index){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    

    if (low > high) {
        startPosition = IndexList[low].start;
        endPosition = IndexList[low].start + IndexList[low].lenght;
    }
    
    
    //如果是key大于所有的最大关键字中的任何一个，说明它不属于这个表中
    if (startPosition == endPosition == -1) {
        return -1;
    }
    
    //获取得到开始的位置
    j = startPosition;
    //开始顺序查询主表
    while (j < endPosition ) {
        if (key == MainIndex[j]) {
            return j;
        } else {
            j++;
        }
    }
    return -1;
    
}

