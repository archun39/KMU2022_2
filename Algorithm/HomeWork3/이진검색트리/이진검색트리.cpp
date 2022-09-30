#include <stdio.h>
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node *newNode(int data)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void insert(struct node** root, int data);
void preOrder(struct node* root);
void inOrder(struct node* root);
void postOrder(struct node* root);
int size(struct node* root);
int height(struct node* root);
int sumOfWeight(struct node* root);
int maxPathWeight(struct node* root);
void mirror(struct node** root);
void destruct(struct node** root);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--)
    {
        int num, i;
        struct node* root = NULL;
        scanf("%d", &num);
        for (i = 0; i < num; i++)
        {
            int data;
            scanf("%d", &data);
            insert(&root, data);
            
            
        }
        printf("%d\n", size(root)); 
        printf("%d\n", height(root));
        printf("%d\n", sumOfWeight(root)); 
        printf("%d\n", maxPathWeight(root)); 
        mirror(&root);
        preOrder(root); 
        printf("\n");
        inOrder(root); 
        printf("\n");
        postOrder(root); 
        printf("\n");
        destruct(&root); // BST의 모든 노드의 동적 메모리 해제 
        if (root == NULL) printf("0\n");
        else printf("1\n");
    }
return 0; 
}
// 데이터 삽입(recursion)
void insert(struct node** root, int data) {
    if(*root == NULL) {
        *root = newNode(data);
    }
    else{
        if((*root)->data > data) insert(&((*root)->left),data);
        else insert(&((*root)->right),data);
    }
}
// 전위(preorder)탐색(recursion) 
void preOrder(struct node* root) {
   if(root == NULL) return;
    else{
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
        
    }
}
// 중위(inorder)탐색(recursion)
 void inOrder(struct node* root) {
    if(root == NULL) return;
    else{
        inOrder(root -> left);
        printf("%d ", root->data);
        inOrder(root -> right);
        
    }
    
}
// 후위(postorder)탐색(recursion) 
void postOrder(struct node* root) {
    if(root == NULL) return;
    else{
        postOrder(root -> left);
        postOrder(root -> right);
        printf("%d ", root->data);
        
    }
}
// 노드의 개수(recursion) 
int size(struct node* root) {
    if(root == NULL) return 0;
    else return 1+size(root->left) + size(root->right);
}
// 높이(recursion)
int height(struct node* root) {
    if(root == NULL) return -1;
    int left = height(root->left)+1;
    int right = height(root->right)+1;
    if(left > right) return left;
    else return right;
}
// 미러 이미지로 변환하기(recursion) 
void mirror(struct node** root)
{
    if(*root == NULL) return;
    struct node* tmp = (struct node *)malloc(sizeof(struct node));
    tmp = ((*root)->left);
    ((*root)->left) = ((*root)->right);
    ((*root)->right) = tmp;
    mirror(&(*root)->left);
    mirror(&(*root)->right);
    
    
}
// 노드에 저장된 데이터의 값의 합 구하기(recursion) 
int sumOfWeight(struct node* root)
{
    if(root == NULL) return 0;
    else{
        return (root->data) +  sumOfWeight(root->left) + sumOfWeight(root->right);
    }   
}
// 루트노드부터 단말노드까지의 경로 상의 데이터의 최대합(recusrion) 
int maxPathWeight(struct node* root)
{
    if(root == NULL) return 0;
    else{
        int right = maxPathWeight(root->right);
        int left = maxPathWeight(root->left);
        if(right > left) return right + root->data;
        else return left+ root->data;
    }
    
}
// 트리노드의 동적 메모리 해제하기(recursion) 
void destruct(struct node** root)
{
    if(*root == NULL) return;
    else{
        destruct(&(*root)->left);
        destruct(&(*root)->right);
        *root = NULL;
    }
}