#include<stdio.h>

struct TreeNode {     
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int countNode(struct TreeNode* root){
  if(root == NULL)return 0;
  return countNode(root->left) + countNode(root->right) + 1;
}

void InOrder(struct TreeNode* root,int* arr,int* idx){
  if(root == NULL)return;
  InOrder(root->left,arr,idx);
  arr[(*idx)++] = root->val;
  InOrder(root->right,arr,idx);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int n = countNodes(root);
    *returnSize = n;                      
    int* arr = (int*)malloc(n * sizeof(int));
    int idx = 0;
    inorder(root, arr, &idx);             
    return arr;
}