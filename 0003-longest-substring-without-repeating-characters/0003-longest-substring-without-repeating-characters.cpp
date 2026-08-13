class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>m;
        int left=0;
        int maxlen=0;

        for(int i=0;i<s.size();i++){
            while(m.count(s[i])){
                m.erase(s[left]);
                left++;
            }
            m.insert(s[i]);

            maxlen = max(maxlen , i-left+1);
        }

        return maxlen;
    }
};