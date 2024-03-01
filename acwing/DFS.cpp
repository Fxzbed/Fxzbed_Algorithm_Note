#include <cstdio>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
//dfs template 
int dfs(TreeNode* root) {
    if (!root) return 0;
    
    int left = dfs(root->left);
    int right = dfs(root->right);

    return left > right ? left + 1 : right + 1;
}   

int main(void) {
    //code
    return 0;
}