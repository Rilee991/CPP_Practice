//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool bfsCycle(vector<int> adj[], vector<bool> &vis, vector<int> &parent, int node) {
        queue<int> q;
        
        q.push(node);
        vis[node] = true;
        
        while(!q.empty()) {
            int u = q.front();
            
            q.pop();
            
            for(int v: adj[u]) {
                if(vis[v] == false) {
                    vis[v] = true;
                    parent[v] = u;
                    q.push(v);
                } else if(v != parent[u])   return true;
            }
        }
        
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        vector<int> parent(V, -1);
        vector<int> ind(V, 0);
        vector<int> nodes;
        
        for(int i=0;i<V;i++) {
            for(int v: adj[i])
                ind[v]++;
        }
        
        for(int i=0;i<V;i++)
            if(ind[i] == 0)
                nodes.push_back(i);
        
        if(nodes.size() == 0)   return true;
        
        for(int i: nodes) {
            if(vis[i] == false) {
                cout<<"Calling: "<<i<<" ";
                if(bfsCycle(adj, vis, parent, i))   return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends