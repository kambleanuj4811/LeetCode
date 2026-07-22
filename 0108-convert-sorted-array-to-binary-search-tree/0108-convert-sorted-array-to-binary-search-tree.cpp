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
    TreeNode*sortedArry(vector<int>&nums,int st , int end){
        int mid = (st+end)/2;

        if(st>end){
            return NULL;
        }
        TreeNode* currRoot = new TreeNode(nums[mid]);

        currRoot->left = sortedArry(nums, st, mid-1);
        currRoot->right = sortedArry(nums, mid+1 , end);

        return currRoot;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArry(nums, 0, nums.size()-1);
    }
};