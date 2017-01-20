/**
    Implementation of Disjoint-Set Union Data Structure
    Running time:
        O(nlog(n))
    Usage:
        - call make_set() to reset the set
        - call find_rep() to get the set of the vertex
        - call union_() to merge to sets
    Input:
        - n, number of sets
    Tested Problems:
      UVA:
        10608 - Friends
        11503 - Virtual Friends
        10583 - Ubiquitous Religions
**/

struct Disjoint_Set {
    int n;
    vector < int > par, cnt, rnk;

    Disjoint_Set( int n ) : n(n), rnk(n), par(n), cnt(n) {}

    void make_set() {
        for(int i=0; i<n; i++) {
            par[i] = i;
            cnt[i] = 1;
            rnk[i] = 0;
        }
    }

    int find_rep( int x ) {
        if(x != par[ x ]) {
            par[ x ] = find_rep( par[ x ] );
        }
        return par[ x ];
    }

    int union_( int u, int v ) {
        if( ( u = find_rep( u ) ) != ( v = find_rep( v ) ) ) {
            if( rnk[ u ] < rnk[ v ] ) {
                cnt[ v ] += cnt[ u ];
                par[ u ] = par[ v ];
                return cnt[v];
            } else {
                rnk[ u ] = max( rnk[ u ], rnk[ v ] + 1 );
                cnt[ u ] += cnt[ v ];
                par[ v ] = par[ u ];
            }
        }
        return cnt[u];
    }
} DS( sz );
