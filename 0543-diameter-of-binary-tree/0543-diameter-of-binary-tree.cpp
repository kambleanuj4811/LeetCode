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
    int HT(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int leftHt = HT(root->left);
        int rightHt =HT(root->right);

        int currHT = max(leftHt, rightHt)+1;
        return currHT;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int currDia = HT(root->left) + HT(root->right);

        int leftDia = diameterOfBinaryTree(root->left);
        int RightDia = diameterOfBinaryTree(root->right);

        return max(currDia , max(leftDia, RightDia));
    }
};