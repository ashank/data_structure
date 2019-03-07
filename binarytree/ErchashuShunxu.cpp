//
//  ErchashuShunxu.cpp
//  erchashu
//
//  Created by 植亚汉 on 2019/2/12.
//  Copyright © 2019 植亚汉. All rights reserved.
//

#include "ErchashuShunxu.hpp"
#include <iostream>
#include<string.h>

void ErchashuClass::InitTree(ErchashuNode *&Node){
    
    Node = NULL;
    
}


void ErchashuClass::CreateTree(ErchashuNode *&Node, ElemType* a){
    
    const int MaxSize = 10; //栈数组长度大于等于二叉树的深度减1
    ErchashuNode* s[MaxSize] ; //s数组作为存储更结点指针的栈使用
    int  top = -1; //栈顶指针
    Node = NULL; //z置空树
    ErchashuNode* p; //定义p为指向二叉树结点的指针
    int k; //定义k作为处理结点的左子树和右子树的标记
    int i = 0; //i 扫描宿主a中存储的二叉树广义表字符串
    
    
    
    while (a[i]) {
        
        switch (a[i]) {
            case ' ':
                //空格不做处理
                break;
            case '(' :
                //左括号
                
                if(top == MaxSize - 1){
                    std::cout << "栈空间太小，需要增加空间";
                    exit(1);
                }
                top++;
                s[top] = p;
                k = 1;
            
        
                break;
            case ',' :
                
                k = 2;
            
                break;
            default:
                
                p = new ErchashuNode;
                p->data = a[i];
                p->left = p->right = NULL;
                
                if (Node == NULL) {
                    Node = p;
                }else {
                    if (k == 1) {
                        //作为左孩子
                        s[top]->left = p;
                    }else {
                        //作为右孩子
                        s[top]->right = p;
                    }
                }
                
                break;
        }
        
        
        i++;
    }

}


bool ErchashuClass::EmptyTree(ErchashuNode *&Node){
    
    return Node == NULL;
    
}


int ErchashuClass:: DepthTree(ErchashuNode *&Node){
    
    if(Node == NULL){
        
        return 0;
    }else {
        
        int dep1= DepthTree(Node->left);
        int dep2 = DepthTree(Node->right);
        
        if (dep1>dep2) {
            return dep1+1;
        }else{
            return  dep2+1;
        }
        
    }
    
}


//bool ErchashuClass::FindTree(ErchashuNode *&Node, ElemType* a){
//
//    if (Node == NULL) {
//        return false;
//    } else {
//
//        if (strcmp("s", "S") == 0) {
//
//            a = Node -> data;
//
//            return true;
//        }else {
//
//            if (FindTree(Node->left, a)) {
//                return true;
//            }
//
//            if (FindTree(Node->right, a)) {
//                return true;
//            }
//
//
//            return false;
//        }
//
//    }
//
//
//}



void ErchashuClass::ClearTree(ErchashuNode *&Node){
    if(Node != NULL ){
        
        ClearTree(Node->left);
        ClearTree(Node->right);
        delete Node;//释放
        Node = NULL;
    }
}


void ErchashuClass::PreOrder(ErchashuNode *&Node){
    
    if (Node != NULL){

        std::cout<< Node->data ;
        PreOrder(Node->left);
        PreOrder(Node->right);

    }
    
    
}


void ErchashuClass::InOrder(ErchashuNode *&Node){
    
    InOrder(Node->left);
    std::cout<< Node->data ;
    InOrder(Node->right);
    
}


void ErchashuClass::PostOrder(ErchashuNode *&Node){
    
    PostOrder(Node->left);
    PostOrder(Node->right);
    std::cout<< Node->data ;
}

