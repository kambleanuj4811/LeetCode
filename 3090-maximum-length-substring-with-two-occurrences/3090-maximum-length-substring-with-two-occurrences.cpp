class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int>freq;
        int left =0;
        int maxlen =0;

        for(int i=0;i<s.size();i++){
            freq[s[i]]++;

            while(freq[s[i]]>2){
                freq[s[left]]--;
                left++;
            }

            maxlen = max(maxlen, i-left+1);
        }
        return maxlen;
    }
};