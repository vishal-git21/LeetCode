/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if(!root)return;
    flatten(root->left);
    flatten(root->right);
    struct TreeNode *left = root->left;
    struct TreeNode *right = root->right;

    root->left = NULL;
    root->right = left;

    struct TreeNode *iter = root;
    while(iter->right != NULL){
        iter = iter->right;
    }
    iter->right = right;


}
