/*
 * Huffman_Code.c
 *
 *  Created on: 2019. 6. 19.
 *      Author: ±èº¸À±
 */


#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct treeNode{
	char alphabet;
	int freq;
	struct treeNode* left;
	struct treeNode* right;
}TreeNode;

typedef struct{
	TreeNode* heap[MAX_ELEMENT];
	int heap_size;
}heapType;

heapType* createHeap(){
	heapType* h= (heapType*)malloc(sizeof(heapType));
	h->heap_size=0;
	return h;
}

void insertHeap(heapType*h, TreeNode* item){
	int i;
	h->heap_size=h->heap_size+1;
	i=h->heap_size;
	while((i!=1)&&(item->freq<h->heap[i/2]->freq)){
		h->heap[i]=h->heap[i/2];
		i/=2;
	}
	h->heap[i]=item;
}
TreeNode* deleteHeap(heapType* h){
	int parent,child;
	TreeNode* item,*temp;
	item=h->heap[1];
	temp=h->heap[h->heap_size];
	h->heap_size=h->heap_size-1;
	parent=1;
	child=2;
	while(child<=h->heap_size){
		if((child<h->heap_size)&&(h->heap[child]->freq > h->heap[child+1]->freq))
			child++;
		if(temp->freq<=h->heap[child]->freq)
			break;
		else{
			h->heap[parent]=h->heap[child];
			parent=child;
			child=child*2;
		}
	}
	h->heap[parent]=temp;
	return item;
}

TreeNode* makeRootNode(int data, TreeNode* leftNode, TreeNode* rightNode){
	TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
	root->freq=data;
	root->left=leftNode;
	root->right=rightNode;
	return root;
}

TreeNode* buildHuffmanTree(heapType* h){
	TreeNode *a,*b,*c;
	while(h->heap_size!=1){
		a=deleteHeap(h);
		b=deleteHeap(h);
		c=makeRootNode(a->freq+b->freq,a,b);
		insertHeap(h,c);
	}
	if(h->heap_size==1)
		a=deleteHeap(h);
	return a;
}

void printHuffmanTree(TreeNode* root){
	if(root!=NULL){
		printHuffmanTree(root->left);
		printHuffmanTree(root->right);
		printf("%d ",root->freq);
	}
}

void printHuffmanCode(TreeNode* root, int codes[], int h){
	if(root->left==NULL&& root->right==NULL){
		printf("%c: ",root->alphabet);
		for(int i=0; i<h; i++)
			printf("%d",codes[i]);
		printf("\n");
	}
	if(root->left){
		codes[h]=1;
		printHuffmanCode(root->left,codes,h+1);
	}
	if(root->right){
		codes[h]=0;
		printHuffmanCode(root->right,codes,h+1);
	}
}

int main() {
	TreeNode* temp;
	heapType* heap = createHeap();
	temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->alphabet = 's';
	temp->freq = 4;
	temp->left = NULL;
	temp->right = NULL;
	insertHeap(heap, temp);
	temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->alphabet = 'i';
	temp->freq = 6;
	temp->left = NULL;
	temp->right = NULL;
	insertHeap(heap, temp);
	temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->alphabet = 'n';
	temp->freq = 8;
	temp->left = NULL;
	temp->right = NULL;
	insertHeap(heap, temp);
	temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->alphabet = 't';
	temp->freq = 12;
	temp->left = NULL;
	temp->right = NULL;
	insertHeap(heap, temp);
	temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->alphabet = 'e';
	temp->freq = 15;
	temp->left = NULL;
	temp->right = NULL;
	insertHeap(heap, temp);
	TreeNode* HuffmanRoot = buildHuffmanTree(heap);
	printf("Huffman Tree: ");
	printHuffmanTree(HuffmanRoot);
	printf("\n");
	int HuffmanCodes[100];
	printHuffmanCode(HuffmanRoot, HuffmanCodes, 0);
}
