
int* robHelper(struct TreeNode* node) {
    if (node == NULL) {
        int* res = (int*)malloc(2 * sizeof(int));
        res[0] = 0; 
        res[1] = 0;  
        return res;
    }

    int* left = robHelper(node->left);
    int* right = robHelper(node->right);

    int* res = (int*)malloc(2 * sizeof(int));
    
    res[0] = node->val + left[1] + right[1];

    res[1] = fmax(left[0], left[1]) + fmax(right[0], right[1]);

    free(left);
    free(right);

    return res;
}

int rob(struct TreeNode* root) {
    int* result = robHelper(root);
    int final_result = fmax(result[0], result[1]); 
    free(result);
    return final_result;
}
