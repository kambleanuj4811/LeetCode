class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        for (int x : nums) {
            freq[x]++;
        }


        priority_queue<pair<int, int>>pq; // <element, freq>
         for (auto& [num, count] : freq) {
            pq.push({count, num});
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
        
};