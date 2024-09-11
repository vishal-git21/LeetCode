#include <stdio.h>
#include <stdlib.h>

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* copyTree(struct TreeNode* root) {
    if (!root) return NULL;
    struct TreeNode* newRoot = newNode(root->val);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}
struct TreeNode** generateTreesRange(int start, int end, int* returnSize) {
    if (start > end) {
        *returnSize = 1;
        struct TreeNode** trees = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
        trees[0] = NULL;
        return trees;
    }

    struct TreeNode** result = NULL;
    int totalTrees = 0;

    for (int i = start; i <= end; i++) {
        int leftSize = 0;
        struct TreeNode** leftTrees = generateTreesRange(start, i - 1, &leftSize);

        int rightSize = 0;
        struct TreeNode** rightTrees = generateTreesRange(i + 1, end, &rightSize);

        for (int left = 0; left < leftSize; left++) {
            for (int right = 0; right < rightSize; right++) {
                struct TreeNode* root = newNode(i);
                root->left = leftTrees[left];
                root->right = rightTrees[right];

                result = (struct TreeNode**)realloc(result, (totalTrees + 1) * sizeof(struct TreeNode*));
                result[totalTrees] = root;
                totalTrees++;
            }
        }

        free(leftTrees);
        free(rightTrees);
    }

    *returnSize = totalTrees;
    return result;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }
    return generateTreesRange(1, n, returnSize);
}
