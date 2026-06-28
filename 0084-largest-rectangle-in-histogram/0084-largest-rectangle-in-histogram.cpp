class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    vector<int>nsl(heights.size());
    vector<int>nsr(heights.size());
    stack<int>st;

    // for nsl
    nsl[0]= -1;
    st.push(0);
    for(int i = 1 ; i<heights.size();i++){
        int curr=heights[i];

        while (!st.empty()&& curr<=heights[st.top()])
        {
            st.pop();
        }

        if(st.empty()){
            nsl[i]= -1;
        }
        else{
            nsl[i]=st.top();
        }

        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    // for nsr
    int idx =  nsr.size()-1;
    nsr[idx]= heights.size();
    
    for(idx-1; idx>=0;idx--){
        int curr = heights[idx];
        while (!st.empty() && curr <= heights[st.top()])
        {
            st.pop();
        }
        if(st.empty()){
            nsr[idx]= heights.size();
        }
        else{
            nsr[idx]=st.top();
        }

        st.push(idx);
        
    }
    // calculating maxArea
    int maxArea = INT_MIN;
    int area=1;
    for(int i = 0 ; i<heights.size();i++){

        area=(heights[i]*(nsr[i]-nsl[i]-1));
        
        maxArea = max(area,maxArea);
    }

    return maxArea;
    
    
}

};