/*****************************************************
    > File Name: sortTree.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年03月22日 星期二 21时08分56秒
    > 二叉排序树 即给定一个序列建立一个二叉排序树，二叉排序树不允许重复值
    > 时间复杂度：O(nlogn)
    > 注意：每次插入的元素一定是叶子节点；
    > 删除时，若是叶子节点直接删除，若不是叶子节点则找左子树的最大值或者右子树的最小值
    > 找到后将其赋予要删除的节点，然后将其删除。
***************************************************/

#include <iostream>
#include <cstring>
#include <stdio.h>  
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

typedef struct Node  
{  
    int data;  
    struct Node *lchild;  
    struct Node *rchild;  
}NODE,*BSTree; 

bool search_BSTree(BSTree pTree,int key,BSTree parent,BSTree &p);

BSTree search(BSTree pTree,int key)  
{  
    if(!pTree || pTree->data == key)   
        return pTree;  
    else if(key < pTree->data)        
        return search(pTree->lchild,key);  
    else  
        return search(pTree->rchild,key);  
}

bool insert(BSTree &pTree,int key)  
{  
    BSTree p;
    if(!search_BSTree(pTree,key,NULL,p))        //如果查找失败，则执行插入操作  
    {  
        BSTree pNew = (BSTree)malloc(sizeof(NODE));  
        pNew->data = key;  
        pNew->lchild = pNew->rchild = NULL;  
        if(!p)                          //如果树空，则直接置pNew为根节点  
            pTree = pNew;  
        else if(key < p->data)            //作为左孩子插入p的左边  
            p->lchild = pNew;            //作为右孩子插入p的右边     
        else  
            p->rchild = pNew;  
    }  
    else  
        return false;  
}

bool search_BSTree(BSTree pTree,int key,BSTree parent,BSTree &p)
{
    if(!pTree)
    {
        p = parent;
        return false;
    }
    else 
    {                        
        if(key == pTree->data)
        {
            p = pTree;
            return true;
        }
        else if(key < pTree->data)  
            return search_BSTree(pTree->lchild,key,pTree,p);
        else
            return search_BSTree(pTree->rchild,key,pTree,p);
    }
}

BSTree create_BSTree(int *arr,int len)  
{  
    BSTree pTree = NULL;  
    int i;  
    for(i=0;i<len;i++)  
        insert(pTree,arr[i]);  
    return pTree;     
}

//递归中序
void mid_traverse(BSTree pTree)  
{  
    if(pTree){  
	if(pTree->lchild)  
	    mid_traverse(pTree->lchild);  
	cout << pTree->data << ' ';  
	if(pTree->rchild)  
	    mid_traverse(pTree->rchild);    
    }  
}
// 不使用递归中序遍历
void mid_trav(BSTree pTree)
{
    if(pTree == NULL){
	return;
    }
    BSTree p = pTree;
    stack<BSTree> s;
    while(!s.empty() || p){
	while(p){
	    s.push(p);
	    p = p->lchild;
	}
	if(!s.empty()){
	    p = s.top();
	    s.pop();
	    cout << p->data << ' ';
	    p = p->rchild;
	}
    }
}

// 先序
void pre_traverse(BSTree pTree)
{
    if(pTree){
	cout << pTree->data << ' ';
	if(pTree->lchild){
	    pre_traverse(pTree->lchild);
	}
	if(pTree->rchild){
	    pre_traverse(pTree->rchild);
	}
    }
}

// 先序非递归
void pre_trav(BSTree pTree)
{
    if(pTree == NULL){
	return;
    }
    BSTree p = pTree;
    stack<BSTree> s;
    while(!s.empty() || p){
	while(p){
	    cout << p->data << ' ';
	    s.push(p);
	    p = p->lchild;
	}
	if(!s.empty()){
	    p = s.top();
	    s.pop();
	    p = p->rchild;
	}
    }
}

void post_traverse(BSTree pTree)
{
    if(pTree){
	if(pTree->lchild){
	    post_traverse(pTree->lchild);
	}
	if(pTree->rchild){
	    post_traverse(pTree->rchild);
	}
	cout << pTree->data << ' ';
    }
}

//后序非递归
void post_trav(BSTree pTree)
{
    if(pTree == NULL){
	return;
    }
    BSTree p = pTree;
    stack<BSTree> s;
    BSTree pre = NULL;
    while(p || !s.empty()){
	while(p!=NULL){
	    s.push(p);
	    p = p->lchild;
	}
	p = s.top();
	if(p->rchild != NULL && p->rchild != pre){
	    p = p->rchild;
	}
	else{
	    cout << p->data << ' ';
	    pre = s.top();
	    s.pop();
	    p = NULL;
	}
    }
}

//层次遍历
void level_trav(BSTree pTree)
{
    if(pTree == NULL){
	return;
    }
    queue<BSTree> q;
    BSTree p = pTree;
    q.push(p);
    while(!q.empty()){
	p = q.front();
	cout << p->data << ' ';
	q.pop();
	if(p->lchild){
	    q.push(p->lchild);
	}
	if(p->rchild){
	    q.push(p->rchild);
	}
    }
}

int main()
{
    int num = 10;
    int arr[10] = {4,9,1,7,10,39,20,2,23,16};
    BSTree pTree = create_BSTree(arr,num);
    cout << "中序遍历：" << endl;
    mid_traverse(pTree);
    cout << endl;
    cout << "中序非递归：" << endl;
    mid_trav(pTree);
    cout << endl;

    cout << "先序遍历：" << endl;
    pre_traverse(pTree);
    cout << endl;
    cout << "先序非递归：" << endl;
    pre_trav(pTree);
    cout << endl;

    cout << "后续遍历：" << endl;
    post_traverse(pTree);
    cout << endl;
    cout << "后序非递归：" << endl;
    post_trav(pTree);
    cout << endl;

    cout << "层次遍历" << endl;
    level_trav(pTree);
    cout << endl;

}
