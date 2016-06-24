/**
    Implementation of Edmonds-Karp max flow algorithm
    Running time:
        O(|V|*|E|^2)
    Usage:
        - add edges by add_edge()
        - call max_flow() to get maximum flow in the graph
    Input:
        - n, number of nodes
        - directed, true if the graph is directed
        - graph, constructed using add_dge()
        - source, sink
    Output:
        - Maximum flow
    Tested Problems:
      CF:
      	653D - Delivery Bears
      UVA:
    	820 - Internet Bandwidth
		10330 - Power Transmission
**/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct edmonds_karp {
	int n;
	vector< int > par;
	vector< bool > vis;
	vector< vector< int > > graph;
	
	edmonds_karp () {}
	edmonds_karp( int _n ) : n( _n ), par( _n ), vis( _n ), graph( _n, vector< int > ( _n, 0 ) ) {}
	~edmonds_karp() {}

	void add_edge( int from, int to, int cap, bool directed ) {
		this->graph[ from ][ to ] += cap;
		this->graph[ to ][ from ] = directed ? graph[ to ][ from ] + cap : graph[ to ][ from ] ;
	}

	bool bfs( int src, int sink ) {
		int u;
		fill( vis.begin(), vis.end(), false );
		fill( par.begin(), par.end(), -1 );
		vis[ src ] = true;
		queue < int > q;
		q.push( src );
		while( !q.empty() ) {
			u = q.front();
			q.pop();
			if( u == sink ) return true;
			for(int i=0; i<n; i++) {
				if( graph[u][i] > 0 and not vis[i] ) {
					q.push( i );
					vis[ i ] = true;
					par[ i ] = u;
				}
			}
		}
		return par[ sink ] != -1;
	}

	int min_val( int i ) {
		int ret = INF;
		for( ; par[ i ] != -1; i = par[ i ] ) {
			ret = min( ret, graph[ par[i] ][ i ] );
		}
		return ret;
	}

	void augment_path( int val, int i ) {
		for( ; par[ i ] != -1; i = par[ i ] ) {
			graph[ par[i] ][ i ] -= val;
			graph[ i ][ par[i] ] += val;
		}
	}

	int max_flow( int src, int sink ) {
		int min_cap, ret = 0;
		while( bfs( src, sink ) ) {
			augment_path( min_cap = min_val( sink ), sink );
			ret += min_cap;
		}
		return ret;
	}
};