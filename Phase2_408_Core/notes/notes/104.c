#include<stdio.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

int maxDepth(struct TreeNode* root) {
    if(root == NULL) return 0;
    int ld = maxDepth(root->left);
    int rd = maxDepth(root->right);

    return (ld > rd ? ld : rd) + 1;
}