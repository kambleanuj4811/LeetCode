class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> indices;

        while (!pq.empty()) {
            indices.push_back(pq.top().second);
            pq.pop();
        }

        sort(indices.begin(), indices.end());

        vector<int> ans;

        for (int index : indices) {
            ans.push_back(nums[index]);
        }

        return ans;
    }
};