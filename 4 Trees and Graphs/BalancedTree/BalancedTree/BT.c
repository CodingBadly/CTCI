#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

unsigned int getHeight(struct TreeNode *pNode)
{
    if (pNode == NULL) {
        return 0; // Base node, depth is 0
    }
    return max(getHeight(pNode->left), getHeight(pNode->right)) + 1;
}

bool isBalanced(struct TreeNode *pNode)
{
    int diff;

    if (pNode == NULL) return true;

    diff = getHeight(pNode->left) - getHeight(pNode->right);
    if (diff > 1 || diff < -1) {
        return false;
    } else {
        return isBalanced(pNode->left) && isBalanced(pNode->right);
    }
}

int main()
{
    return 1;
}