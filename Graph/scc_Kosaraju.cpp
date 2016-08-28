#include <bits/stdc++.h>
using namespace std;
int p, t;
bool vis[1001];
vector<int> G[1001], gT[1001];
map<string,int> mp;
stack < int > top_sorted;

void dfs_top_sort(int u) {
	vis[u] = true;
	for(int v: G[u]) {
		if(!vis[v]) {
			dfs_top_sort( v );
		}
	}
	top_sorted.push( u );
}

void top_sort() {
	for(int i=1; i<=p; i++) {
		if(!vis[i]) {
			dfs_top_sort(i);
		}
	}
}

void dfs_kosaraju(int u) {
	vis[u] = true;
	for(int v: gT[u]) {
		if(!vis[v]) {
			dfs_kosaraju( v );
		}
	}
}

int kosaraju() {
	memset( vis, false, sizeof(vis) );
	top_sort();
	int u, ret = 0;
	memset( vis, false, sizeof(vis) );
	while(!top_sorted.empty()) {
		u = top_sorted.top();
		top_sorted.pop();
		if(!vis[u])
			dfs_kosaraju( u ), ret++;
	}
	return ret;
}

