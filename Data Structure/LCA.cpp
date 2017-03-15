/**
    Implementation of LCA ( Lowest Common Ancestor ) with sparse table
    Running time:
        O( n * log ( n ) )
    Usage:
        - call dfs( 0, 0, 0 )
        - call init()
        - call query() to get output
    Input:
        - Graph
        - n, nodes
    Output:
        - Lowest Common Ancestor
    Tested Problems:
      SPOJ:
        LCA - Lowest Common Ancestor
        QTREE2 - Query on a tree II
**/
#include <bits/stdc++.h>
using namespace std;

const int sz = 1005;
int lg[sz];
int lvl[sz];
int table[sz][12];
int par[sz];

vector < int > G[sz];

void dfs( int fr, int u, int dep ) {
    lvl[u] = dep;
    par[u] = fr;
    for( int v: G[u] ) {
        if( fr == v ) continue;
        dfs( u, v, dep+1 );
    }
}

int init( int n ) {
    memset( table, -1, sizeof table );
    for( int i=0; i<n; i++ ) {
        table[i][0] = par[i];
    }
    for( int j=1; ( 1 << j ) < n; j++ ) {
        for( int i=0; i<n; i++ ) {
            if( table[i][j-1] == -1 ) continue;
            table[i][j] = table[ table[i][j-1] ][j-1];
        }
    }
    for( int i=0; i<10; i++ ) lg[1 << i] = i;
    for( int i=1; i<sz; i++ ) if( !lg[i] ) lg[i] = lg[i-1];
}

int query( int n, int p, int q ) {
    int log;
    if( lvl[p] < lvl[q] ) swap( p, q );
    log = lg[ lvl[ p ] ];
    for( int i=log; i>=0; i-- ) {
        if( lvl[p] - ( 1 << i ) >= lvl[q] ) {
            p = table[ p ][ i ];
        }
    }
    if( p == q ) return p;
    for( int i=log; i>=0; i-- ) {
        if( table[ p ][ i ] != -1 && table[ p ][ i ] != table[ q ][ i ] ) {
            p = table[ p ][ i ];
            q = table[ q ][ i ];
        }
    }
    return par[p];
}

int dist( int n, int p, int q ) {
    int lca = query( n, p, q );
    return lvl[p] + lvl[q] - 2 * lvl[lca];
}
