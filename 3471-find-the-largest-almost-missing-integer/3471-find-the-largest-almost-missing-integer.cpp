class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int n = nums.size();

        // Go through every subarray of size k
        for (int i = 0; i <= n - k; i++) {

            unordered_set<int> seen;

            // Current subarray
            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }

            // Count this subarray once for every distinct number
            for (int x : seen) {
                freq[x]++;
            }
        }

        int ans = -1;

        // Find largest number present in exactly one subarray
        for (auto it : freq) {
            if (it.second == 1) {
                ans = max(ans, it.first);
            }
        }

        return ans;
    }
};