class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]={0};
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        freq[ch-'a']++;
    }
    for(int i=0;i<s.size();i++){
        char ch =s[i];
        if(freq[ch-'a']==1){
            return i;
        }
    }
    return -1;
    }
};