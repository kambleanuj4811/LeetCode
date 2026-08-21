class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        int candidate1 = 0;
        int candidate2 = 1;

        int count1 = 0;
        int count2 = 0;

        // Find possible candidates
        for (int num : nums) {

            if (num == candidate1) {
                count1++;
            }
            else if (num == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Verify candidates
        int countt1 = 0;
        int countt2 = 0;

        for (int num : nums) {
            if (num == candidate1)
                countt1++;

            if (num == candidate2)
                countt2++;
        }

        if (countt1 > n / 3)
            ans.push_back(candidate1);

        if (candidate2 != candidate1 && countt2 > n / 3)
            ans.push_back(candidate2);

        return ans;
    }
};