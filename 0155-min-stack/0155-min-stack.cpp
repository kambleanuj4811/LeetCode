class MinStack {
public:
    stack<long long> st;
    long long minval = -1;

    MinStack() { 

     }
    
    void push(long long val){
        if(st.empty()){
            minval=val;
            st.push(val);
        }
        else{
            if(val>minval){
                st.push(val);
            }
            else{
                st.push(2*val-minval);
                minval=val;
            }

        }
    }
    void pop(){
        if(st.empty()){
            cout<<"Stack is Empty"<<endl;
            return;
        }

        long long x = st.top();
        st.pop();

        if(x<minval){
            minval=2*minval-x;
        }
    }

    int top(){
        if(st.empty()){
            return -1;
        }
        long long x = st.top();
        if(minval<x){
            return x;
        }
        return minval;
    }

    int getMin(){
        return minval;
    }
   
};
