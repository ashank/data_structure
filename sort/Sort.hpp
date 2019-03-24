//
//  Sort.hpp
//  data_structure
//
//  Created by 植亚汉 on 2019/3/11.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#ifndef Sort_hpp
#define Sort_hpp

#include <stdio.h>

class Sort {
    
    
public:
    
    void InsertSort(int Data[],int length);
    void ShellSort(int Data[],int length);
    
    void SelectSort(int Data[],int length);
    
    void HeapSort(int Data[],int length);
    
    void BubbleSort(int Data[],int length);
    void QuickSort(int Data[],int length);
    
    void print(int Data[],int length,int i);
    
    
};


#endif /* Sort_hpp */
