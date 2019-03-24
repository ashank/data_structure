//
//  main.cpp
//  sort
//
//  Created by 植亚汉 on 2019/3/5.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include <iostream>
#include "Sort.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    Sort sort;
    
    
    
    int Data3[] = {304,2,100,56,809,405,4,21};
    sort.BubbleSort(Data3, 8);
    
    int Data[] = {34,22,1,56,89,45,33,21};
    sort.InsertSort(Data,8);
    
    
    int Data1[] = {34,22,1,56,89,45,33,21};
    sort.ShellSort(Data1, 8);
    
    int Data2[] = {34,22,1,56,89,45,4,21};
    sort.SelectSort(Data2, 8);
    
    
    return 0;
}
