//
//  main.cpp
//  seek
//
//  Created by 植亚汉 on 2019/3/5.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include <iostream>
#include "OderSearch.cpp"
#include "BinarySearch.cpp"
#include "IndexSearch.cpp"


int main(int argc, const char * argv[]) {
    
    
    // insert code here..

    int a[] =  {1,9,10,7,8,17,56};
    //二分查找，必须是有序表
    int A[] =  {12,23,26,37,54,60,75,82,96};


    //顺序查找
    Order order ;
    int r = order.Seek(a,7,10);

    std::cout << "顺序查找 查找的位置== ";
    std::cout <<  r;
    std::cout << "\n";

    //二分查找
    Binary binary;
    int r1 = binary.BinarySearch(A, 0, 7, 23);
    std::cout << "二分查找1 查找的位置== ";
    std::cout <<  r1;
    std::cout << "\n";

    //二分查找改版
    int r2 = binary.BinarySearch2(A,8, 82);
    std::cout << "二分查找2 查找的位置== ";
    std::cout <<  r2;
    std::cout << "\n";

    //索引表的建立
    Index index;

    //主表，用来存储子表的索引
    int MainIndex[15];

    //索引表，用来存储子表的最大关键字，起始位置、长度
    IndexItem IndexList[3];

    int A1[] = {15,16,18,34};
    int A2[] = {36,72,40,57,43};
    int A3[] = {86,93,98};

    for (int i = 0; i < sizeof(A1); i++) {
        MainIndex[i] = A1[i];
    }

    for (int i = 0; i < sizeof(A2) ; i++) {
        MainIndex[i+5] = A2[i];
    }

    for (int i = 0; i < sizeof(A3) ; i++) {
        MainIndex[i+10] = A3[i];
    }



    //块1
    IndexItem  indexItem1;

    indexItem1.index = 34;
    indexItem1.lenght = 4;
    indexItem1.start = 0;

    //块2
    IndexItem  indexItem2;
    indexItem2.index = 72;
    indexItem2.lenght = 5;
    indexItem2.start = 5;
    
    //块3
    IndexItem  indexItem3;
    indexItem3.index = 98;
    indexItem3.lenght = 3;
    indexItem3.start = 10;


    IndexList[0] = indexItem1;
    IndexList[1] = indexItem2;
    IndexList[2] = indexItem3;


    //查找
    int r5 = index.Blocksch2(MainIndex,IndexList,3,40);
    std::cout << "索引查找 查找的位置== ";
    std::cout <<  r5;
    std::cout << "\n";

    return 0;
}



