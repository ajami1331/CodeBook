/**
An O(V+E) approach:
-------------------
- perform a DFS on the graph.
- compute d(i) and low(i) for each vertex 1 ... i
        d(i):   dfs number of i, represents the discovery time.
        low(i): the least dfn reachable from i throguh a path consisting of zero or
                more edges follwoing by zero or one back edges.
- vertex u is an AP if and only if:
        - u is the root of the dfs tree and has at least two children.
        - u is not the root and has a child v for which low(v) >= d(u).
 **/
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e4 +  10;
vector < int > G[mx];
int tim, root, n, m, a, b;
int ap[mx], vis[mx], low[mx], d[mx], par[mx];
 
void ap_dfs(int u) {
    tim++;
    int cnt = 0;
    low[u] = tim;
    d[u] = tim;
    vis[u] = 1;
    int v;
    for(int i=0; i<G[u].size(); i++) {
        v = G[u][i];
        if( v == par[u] ) continue;
        if( !vis[v] ) {
            par[u] = v;
            ap_dfs( v );
            low[u] = min( low[u], low[v] );
            /// d[u] < low[v] if bridge is needed
            if( d[u] <= low[v] && u != root ) {
                ap[u] = 1;
            }
            cnt++;
        } else {
            low[u] = min( low[u], d[v] );
        }
        if( u == root && cnt > 1 ) ap[u] = 1;
    }
}

int main() {
	
	return 0;
}

