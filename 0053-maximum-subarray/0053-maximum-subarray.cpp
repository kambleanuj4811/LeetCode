class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int MaxSum=INT_MIN;
        int currsum=0;
        for (int num : nums){
            
            currsum+=num;
            MaxSum=max(MaxSum,currsum);

            if(currsum<0){
                currsum=0;
            }
        }
        return MaxSum;
    }
};