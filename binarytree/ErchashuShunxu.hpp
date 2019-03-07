//
//  ErchashuShunxu.hpp
//  erchashu
//
//  Created by 植亚汉 on 2019/2/12.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#ifndef ErchashuShunxu_hpp
#define ErchashuShunxu_hpp

#include <stdio.h>

typedef char ElemType;

struct ErchashuNode {
    
    ElemType data;
    
    ErchashuNode* left;//左指针
    ErchashuNode* right; // 右指针

};


class ErchashuClass {
    
    
public:
    void InitTree(ErchashuNode*& Node);
    void CreateTree(ErchashuNode*& Node, ElemType *a);
    bool EmptyTree(ErchashuNode*& Node);
    int DepthTree(ErchashuNode*& Node);
    bool FindTree(ErchashuNode*& Node, ElemType *a);
    void PrintTree(ErchashuNode*& Node);
    void ClearTree(ErchashuNode*& Node);
    
    void PreOrder(ErchashuNode*& Node);
    void InOrder(ErchashuNode*& Node);
    void PostOrder(ErchashuNode*& Node);
};



#endif /* ErchashuShunxu_hpp */
