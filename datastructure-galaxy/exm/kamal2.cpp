#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> edgeWeightPair;
class graph

{
    int V;
    list<edgeWeightPair> *adj;

public:
    graph(int V)
    {
        this->V = V;
        adj = new list<edgeWeightPair>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(make_pair(u, v));
    }
    void check(int k, int n)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[k] = true;
        q.push(k);
        int count = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto element : adj[u])
            {
                int v = element.second;
                if (visited[v] != true)
                {
                    visited[v] = true;
                    q.push(v);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    graph g(n);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    int k;
    cin >> k;
    g.check(k, n);
}