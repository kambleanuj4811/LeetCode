class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(2*nums.size(), 0);
        for(int i=0;i<nums.size();i++){
            ans[i]=nums[i];
        }
        int i = 0;
        while(i<n){
            ans[i+n]=(nums[i]);
            i++;
        }

        return ans;
    }
};