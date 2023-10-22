

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

    bool isCyclicDFS(int node, vector<int> adj[], vector<bool> &recStack, vector<bool> &visited)
    {

        for (auto k : adj[node])
        {

            if (!visited[k])
            {

                visited[k] = true;
                recStack[k] = true;

                if (isCyclicDFS(k, adj, recStack, visited))
                    return true;

                recStack[k] = false;
            }

            else if (recStack[k])
                return true;
        }

        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here

        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < visited.size(); i++)
        {

            if (!visited[i])
            {
                if (isCyclicDFS(i, adj, recStack, visited))
                    return true;
            }
        }

        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
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