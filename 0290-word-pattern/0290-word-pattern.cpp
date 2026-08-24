class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> st;
        string str = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                st.push_back(str);
                str = "";
            } else {
                str += s[i];
            }
        }
        st.push_back(str);

        if (pattern.size() != st.size())
            return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string word = st[i];

            if (mp.count(c) && mp[c] != word)
                return false;

            if (rev.count(word) && rev[word] != c)
                return false;

            mp[c] = word;
            rev[word] = c;
        }

        return true;
    }
};