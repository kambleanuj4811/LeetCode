class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>present(n+1, 0);
        vector<int>missing;

        for(int i = 0 ; i<n;i++){
            present[nums[i]]=1;
        }
        for(int num =1 ;num<=n; num++){
            if(present[num]==0){
                missing.push_back(num);
            }
        }

        return missing;
       
    }
};