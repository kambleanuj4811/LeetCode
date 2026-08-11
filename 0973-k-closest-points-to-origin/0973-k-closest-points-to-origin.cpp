class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,int>>dispoint;

        for (int i = 0; i < points.size(); i++) {
            int distsq = points[i][0] * points[i][0] 
                       + points[i][1] * points[i][1];

            dispoint.push_back({distsq, i});
        }


        vector<vector<int>>ans;
        priority_queue<pair<int, int>, vector<pair<int,int>> , greater<pair<int,int>>>pq;
        for (auto x : dispoint){
         pq.push(x);

        }

        for(int i=0 ; i<k ; i++){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};