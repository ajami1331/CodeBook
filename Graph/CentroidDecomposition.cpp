/**
    Centroid Decomposition
    Running time:
        O( n * log ( n ) )
    Usage:
        - call rec() to decompose
    Input:
        - Graph
    Output:
        - Centroid Tree
    Tested Problems:
      CodeForces:
        321C/322E - Ciel the Commander
**/
const int sz = 1e5 + 10;
vector < int > G[sz];
char ans[sz];
int tr[sz], fl[sz];

void dfs( int u, int p ) {
    tr[u] = 1;
    for( int v: G[u] ) {
        if( v != p && !fl[v] ) {
            dfs( v, u );
            tr[u] += tr[v];
        }
    }
}

int centroid( int u ) {
    dfs( u, -1 );
    int ret = u;
    int found = 0, par = -1;
    while( 1 ) {
        found = 0;
        for( int v: G[ret] ) {
            if( !fl[v] && v != par && tr[v] >= ( tr[u] + 1 ) / 2 ) {
                found = 1;
                par = ret;
                ret = v;
                break;
            }
        }
        if( !found ) break;
    }
    return ret;
}

void rec( int u, char a ) {
    u = centroid( u );
    fl[u] = 1;
    ans[u] = a;
    for( int v: G[u] ) {
        if( !fl[v] ) rec( v, a + 1 );
    }
    return;
}
