//
//  OderSeek.hpp
//  data_structure
//
//  Created by 植亚汉 on 2019/3/10.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#ifndef OderSeek_hpp
#define OderSeek_hpp

#include <stdio.h>

class Order {
    
    
public:
    
    /**
     
     顺序查找

     @param A 数组
     @param n 数组大小
     @param key 查找的关键字
     @return 返回查找的关键字下标
     */
    int Seek(int A[],int n,int key);
};

#endif /* OderSeek_hpp */
