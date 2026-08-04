class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> pq;

        // First window
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        // Remaining windows
        for (int i = k; i < nums.size(); i++) {

            // Remove elements outside the current window
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }

            // Add current element
            pq.push({nums[i], i});

            // Maximum of current window
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};