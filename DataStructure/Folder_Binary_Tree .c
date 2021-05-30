/*
 * Folder_BInary_tree.c
 *
 *  Created on: 2019. 6. 2.
 *      Author: 김보윤
 */


#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode{
	int size;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

int FolderSize=0;

treeNode* makeRootNode(int size, treeNode *leftNode, treeNode *rightNode){
	treeNode* root=(treeNode*)malloc(sizeof(treeNode));
	root->size=size;
	root->left=leftNode;
	root->right=rightNode;
	return root;
}
void postorder_FolderSize(treeNode*root){
	if(root){
		postorder_FolderSize(root->left);
		postorder_FolderSize(root->right);
		FolderSize+=root->size;
	}
}

int main(){
	treeNode* F11=makeRootNode(120,NULL,NULL);
	treeNode* F10=makeRootNode(55,NULL,NULL);
	treeNode* F9=makeRootNode(100,NULL,NULL);
	treeNode* F8=makeRootNode(200,NULL,NULL);
	treeNode* F7=makeRootNode(68,F10,F11);
	treeNode* F6=makeRootNode(40,NULL,NULL);
	treeNode* F5=makeRootNode(15,NULL,NULL);
	treeNode* F4=makeRootNode(2,F8,F9);
	treeNode* F3=makeRootNode(10,F6,F7);
	treeNode* F2=makeRootNode(0,F4,F5);
	treeNode* F1=makeRootNode(0,F2,F3);
	postorder_FolderSize(F2);
	printf("\n\nC:\\의 용량:%d M\n",FolderSize);
	FolderSize=0;postorder_FolderSize(F3);
	printf("\nD:\\의 용량:%d M\n",FolderSize);
	FolderSize=0;postorder_FolderSize(F1);
	printf("\n내 컴퓨터의 전체 용량:%d M\n",FolderSize);
}
