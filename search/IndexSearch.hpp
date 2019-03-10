//
//  IndexSeek.hpp
//  data_structure
//
//  Created by 植亚汉 on 2019/3/10.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#ifndef IndexSeek_hpp
#define IndexSeek_hpp

#include <stdio.h>


/**
 索引表的数据结构
 */
struct IndexItem {
    //IndexKeyType 为事先定义的索引值类型，用来记录对应块的最大关键字,类型为int
    int index;
    //子表的第一个元素所在的下标位置
    int start;
    //子表长度域
    int lenght;
};

class Index {
    
public:
    
    
    /**
     分块查询

     @param MainInde 主表
     @param IndexList 索引表
     @param m 子表
     @param key 数值
     @return 数值下标
     */
    int Blocksch(int MainInde[], IndexItem IndexList[],int m, int key);
    
    /**
     分块查询，二分查找s主表
     
     @param MainInde 主表
     @param IndexList 索引表
     @param m 子表
     @param key 数值
     @return 数值下标
     */
    int Blocksch2(int MainInde[], IndexItem IndexList[],int m, int key);
};

#endif /* IndexSeek_hpp */



