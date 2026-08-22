class Solution {
public:
    bool checkDivisibility(int n) {
       string num = to_string(n);
       int sum =0;
       int multi =1;

       for(int i=0;i<num.size();i++){
        sum = sum+(num[i]-'0');
        multi = multi*(num[i]-'0');
       }
       int total = sum+multi;
       if(n%total==0){
        return true;
       }

       return false;

    }
};