//
//  main.cpp
//  binarytree
//
//  Created by 植亚汉 on 2019/3/5.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include <iostream>
#include "ErchashuShunxu.cpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    ErchashuNode* Node ;
    
    ErchashuClass*  ec = new ErchashuClass();
    
    ec->InitTree(Node);
    
    ElemType b ='A(B(C),D(E(F,G),H(0,I)))';
    
    ec->CreateTree(Node, b);
    
    bool n = ec->EmptyTree(Node);
    
    std::cout<< n;
    std::cout<< '\n';
    
    int h = ec->DepthTree(Node);
    
    
    std::cout<< h;
    std::cout<< '\n';
    
    
    ec->PreOrder(Node);
    return 0;
}
