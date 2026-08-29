class Solution {
public:
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size() - 1, k);
    }

    int solve(string& s, int left, int right, int k) {
        if (right - left + 1 < k)
            return 0;

        unordered_map<char, int> mp;

        for (int i = left; i <= right; i++) {
            mp[s[i]]++;
        }

        for (int i = left; i <= right; i++) {
            if (mp[s[i]] < k) {
                int leftPart = solve(s, left, i - 1, k);
                int rightPart = solve(s, i + 1, right, k);

                return max(leftPart, rightPart);
            }
        }

        return right - left + 1;
    }
};