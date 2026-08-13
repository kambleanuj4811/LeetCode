class Node{
public:
    unordered_map<char, Node*>children;
    bool endofword;

    Node(){
        endofword = false;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string key){
        Node* temp = root;
        for(int i=0; i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]= new Node(); // insert
            }
            temp= temp->children[key[i]];
        }
        temp->endofword = true;
    }

    bool Search(string key){
        Node * temp = root;
        for(int i=0; i<key.size();i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }
            else{
                return false;
            }
        }

        return temp->endofword;
    }


};
class Solution {
public:

  bool helper(Trie &trie, string key, unordered_map<string,bool>& dp) {
    if(key.size() == 0) {
        return true;
    }

    if(dp.count(key)) {
        return dp[key];
    }

    for(int i = 0; i < key.size(); i++) {
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

        if(trie.Search(first) && helper(trie, second, dp)) {
            return dp[key] = true;
        }
    }

    return dp[key] = false;
}

     bool wordBreaker(vector<string> dict, string key) {

        Trie trie;

        // Build Trie
        for (int i = 0; i < dict.size(); i++) {
            trie.insert(dict[i]);
        }

        // DP map
        unordered_map<string, bool> dp;

        return helper(trie, key, dp);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return wordBreaker(wordDict, s);
    }
};