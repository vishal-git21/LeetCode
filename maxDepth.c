/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int min(int a,int b){
    if(a>b)return a;
    else{
        return b;
    }
}
int f(struct TreeNode *root){
    if(root == NULL)return 0;
    else{
        return 1 + min(f(root->left),f(root->right));
    }
}


int maxDepth(struct TreeNode* root) {
    return f(root);
}