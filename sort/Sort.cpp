//
//  Sort.cpp
//  data_structure
//
//  Created by 植亚汉 on 2019/3/11.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include "Sort.hpp"
#include <iostream>


/**
 直接插入排序
 
 1、思想：
 把n个待排序的元素看成一个有序表和一个无序表，开始时有序表中只有一个元素，无序表中有n-1个元素；排序过程即每次从无序表中取出第一个元素，将它插入到有序表中，使之成为新的有序表，重复 n-1 次完成整个排序过程。
 
 2、时间复杂度
 O（n的平方）
 
 @param Data 数据
 */
void Sort:: InsertSort(int Data[],int length){
    
    std::cout << "------------------直接插入排序-----------------\n";
    //临时数据
    int temp;
    int i,j;
    //标记元素插入的位置
    int insertPosition = 0;
    
    //从第二个元素起，循环n-1次取值比较、
    for (i=1; i < length; i++) {
        
        //temp为本次循环待插入有序列表中的数，即待插入数值
        temp = Data[i];
        //此循环是 有序表中的数值循环，寻找temp插入有序列表的正确位置
        //---------------第一种方式-------------------------
//        for (j= i-1 ; j >= 0; j--) {
//            //将临时数据和有序表中的所有数据比较
//            if (temp< Data[j]) {
//                //元素后移
//                Data[j+1] = Data[j];
//                insertPosition=j;
//            }else{
//                insertPosition = j+1;
//                break;
//            }
//        }
//        //插入temp
//        Data[insertPosition] = temp;
        
        //-------------第二种方式-------------------
        for (j= i-1 ; j >= 0 && temp< Data[j]; j--) {
            //元素后移
             Data[j+1] = Data[j];
        }
        //插入temp
        Data[j+1] = temp;
        
        //打印数组
        print(Data, length, i);
    }
}




/**
 希尔排序
 
 1、思想：
 希尔排序是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；随着增量逐渐减少，每组包含的关键词越来越多，当增量减至1时，整个文件恰被分成一组，算法便终止。
 
希尔排序中对于增量序列的选择十分重要，直接影响到希尔排序的性能
 
 
假设length = 8
 
1、确定分组，若d=length/2=4, 则分成4组，每一组独立进行排序
2、缩小增量，在原来的分组d=4上再次除以2 缩小增量，即d=2，分成两组再次进行 独自排序
3、继续缩小增量，直到d==1，以整体的分组来进行排序。
 
 2、时间复杂度
 O(n2)
 
 @param Data 数据
 @param length 数组长度
 */
void Sort::ShellSort(int Data[], int length){
     std::cout << "------------------希尔排序-----------------\n";
    //临时数据
    int temp;
    
    int i = 0;
    int j = 0;
    //分组，若d=length/2, 则分成4组，每一组独立进行排序
    int d = 0;
    
    for (d= length/2; d >= 1; d/=2) {
        std::cout <<"分组数==";
        std::cout << d;
        std::cout <<"\n";
        for (i=d; i<length; i++) {
            
            temp = Data[i];
            for (j=i-d; j>=0 && temp<Data[j]; j-=d) {
                Data[j+d] = Data[j];
            }
            Data[j+d] = temp;
            //打印数组
            print(Data, length, i);
        }
    }
}

/**
 直接选择排序
 
 1、思想：
 
每一趟从待排序的数据元素中选出最小（最大）的元素，顺序放在待排序的数列最前，直到全部待排序的数据元素全部排完。
 
 
实现思路：
双重循环，外层i控制当前序列最小（最大）值存放的数组元素位置，内层循环j控制从i+1到n序列中选择最小的元素所在位置k。
 
 2、时间复杂度
 O(n2)
 
 @param Data 数据
 @param length 数组长度
 */
void Sort::SelectSort(int Data[],int length){
     std::cout << "------------------直接选择排序-----------------\n";
    
    //临时数据
    int temp;
    
    //标记最小的的值的位置
    int minPosition;
    
    for (int i=0; i<length; i++) {
        //每次循环，默认取第i个元素暂时为最小元素下标
        minPosition = i;
        //将循环i+1之后的数值（i之前的数值都已经排序好了，不需要循环了），并将元素逐个和Data[minPosition]比较，较小的数值下标暂时标记为minPosition，知道所有比较完，确定最终未排序的最小值的下标
        for (int j= i+1; j < length; j++) {
            if (Data[j] < Data[minPosition]) {
                //查找到最小值，每次都会更新比较后的最小值的下标，比较到最后就是未排序部分数列中最小的值的下标
                minPosition = j;
            }
        }
        if (minPosition!=i) {
            //先保存i位置的值
            temp = Data[i];
            //把最小的元素放置在i的位置
            Data[i] = Data[minPosition];
            //i元素的的值放在原来最小值的下标位置；完成数值交换
            Data[minPosition] = temp;
        }
        
        print(Data, length, i);
    }
    
    
}

void Sort::BubbleSort(int Data[],int length){
    
    
}


//打印数据
void Sort::print(int Data[],int length,int i){
    //打印数据
    std::cout << "第";
    std::cout << i;
    std::cout << "次排序：";
    for (int k = 0;  k < length ; k++) {
        std::cout << Data[k];
        if(k < length - 1){
            std::cout << ",";
        }
    }
    std::cout << "\n";
}
