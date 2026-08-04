class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>missing;
        int maxi =INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxi =  max(nums[i], maxi);
            mini= min(nums[i], mini);
        }

        for(int num = mini ; num<=maxi ; num++){
            bool found =false;
            for(int i = 0 ; i<nums.size();i++){
                if(nums[i]==num){
                    found = true;
                    break;
                }
            }

            if(!found){
                missing.push_back(num);
            }
        }

       return missing;
    }
};