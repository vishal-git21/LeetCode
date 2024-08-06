/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int nodeCount(struct TreeNode *root){
    if(root == NULL){
        return 0;
    }
    else{
        return 1+nodeCount(root->left)+nodeCount(root->right);
    }
}

void inOrderHelper(struct TreeNode *root,int *result, int *index){
    if(root == NULL)return;
    else{
        inOrderHelper(root->left,result,index);
        result[(*index)++] = root->val;
        inOrderHelper(root->right,result,index);
    }
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int nodecount;
    nodecount = nodeCount(root);

    int *result = (int *)malloc(nodecount * sizeof(int));
    int index = 0;

    inOrderHelper(root,result,&index);

    *returnSize = nodecount;

    return result;

}