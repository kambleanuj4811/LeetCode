class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        ans.reserve(nums.size());
        int sz = nums.size();
        int i = 0;
        int j = n;
        while(j<sz){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            i++;
            j++;
        }
        return ans;
        
    }
};