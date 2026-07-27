/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int Height(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int leftht = Height(root->left);
        int rightht = Height(root->right);

        int currHt = max(leftht, rightht)+1;

        return currHt;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        int leftht = Height(root->left);
        int rightht = Height(root->right);

        if(abs(leftht-rightht) > 1){
            return false;
        }
        
        return isBalanced(root->left) &&
                isBalanced(root->right);
        
    }
};