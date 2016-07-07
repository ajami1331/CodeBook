/**
    Implementation of Kruskal's minimum spanning tree algorithm
    Running time:
        O(|E|log|V|)
    Usage:
        - initialize by calling init()
        - add edges by add_edge()
        - call kruskal() to generate minimum spanning tree
    Input:
        - n, number of nodes, provided when init() is called
        - graph, constructed using add_edge()
    Output:
        - weight of minimum spanning tree
        - prints the mst
    Tested Problems:
        UVA:
            1208 - Oreon
*/

#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, cost;
	bool operator < (const edge& other) const{
		if( other.cost == this->cost ) {
			if( other.u == this->u ) {
			    return other.v > this->v;
			} else {
			    return other.u > this->u;
			}
		} else {
			return other.cost > this->cost;
		}
	}
};

vector< edge > edges;
vector < int > par, cnt, rank;
int N;

void init( int n ) {
    N = n;
    par.resize( n );
    cnt.resize( n );
    rank.resize( n );
}

void add_edge( int u, int v, int c ) {
    edges.push_back( { u, v, c } );
}

void make_set() {
	for(int i=0; i<N; i++) {
		par[i] = i;
		cnt[i] = 1;
		rank[i] = 0;
	}
}

int find_rep( int x ) {
	if(x != par[ x ]) {
		par[ x ] = find_rep( par[ x ] );
	}
	return par[ x ];
}

int kruskal() {
	int ret = 0;
	make_set();
	sort( edges.begin(), edges.end() );
	cout << "Case " << ++cs << ":\n";
	for( edge e : edges ) {
		int u = e.u;
		int v = e.v;
		if( ( u = find_rep( u ) ) != ( v = find_rep( v ) ) ) {
            if( rank[ u ] < rank[ v ] ) {
                cnt[ v ] += cnt[ u ];
                par[ u ] = par[ v ];
            } else {
                rank[ u ] = max( rank[ u ], rank[ v ] + 1 );
                cnt[ u ] += cnt[ v ];
                par[ v ] = par[ u ];
            }
            cout << city[ e.u ] << "-" << city[ e.v ] << " " << e.cost << "\n";
            ret += e.cost;
        }
	}
	return ret;
}


