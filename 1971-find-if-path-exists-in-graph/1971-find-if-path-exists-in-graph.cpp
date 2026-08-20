class Graph {
    int V;
    list<int>* l;

public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        // undirected edge: u -- v
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool helperHasPath(int src, int dest, vector<bool>& vis) {

        // destination reached
        if (src == dest) {
            return true;
        }

        vis[src] = true;

        for (int v : l[src]) {

            if (!vis[v]) {

                if (helperHasPath(v, dest, vis)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool hasPath(int src, int dest) {
        vector<bool> vis(V, false);

        return helperHasPath(src, dest, vis);
    }
};


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        // Create graph
        Graph graph(n);

        // Add all edges
        for (int i = 0; i < edges.size(); i++) {
            graph.addEdge(edges[i][0], edges[i][1]);
        }

        // Check path
        return graph.hasPath(source, destination);
    }
};