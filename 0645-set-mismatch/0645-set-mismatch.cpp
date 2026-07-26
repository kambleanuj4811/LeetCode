class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        int duplicate = -1;
        int missing = -1;
        sort(nums.begin(), nums.end());
        for(int i =0, j=i+1 ; j<nums.size(); i++, j++){
            if(nums[i]==nums[j]){
                duplicate = nums[i];
            }
        }

        for(int num = 1 ; num <= nums.size(); num++){
            bool isfound =  false;

            for(int i = 0 ; i<nums.size(); i++){
                if(nums[i]==num){
                    isfound = true;
                    break;
                }
            }
            if(!isfound) {
                missing = num;
                break;
            }

        }
        ans.push_back(duplicate);
        ans.push_back(missing);

        return ans;
        

    }
};