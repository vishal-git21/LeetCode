/*


Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.



Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 


*/


int min(int a,int b){
    if(a>b)return b;
    else{
        return a;
    }
}
int minDepth(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else if(root->left == NULL){
        return 1 + minDepth(root->right);
    }
    else if(root->right == NULL){
        return 1 + minDepth(root->left);
    }
    else{
        return 1 + min(minDepth(root->left),minDepth(root->right));
    }
}