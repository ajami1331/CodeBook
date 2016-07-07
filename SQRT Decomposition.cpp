/**
    Implementation of SQRT-Decomposition Data Structure
    Running time:
        O( ( n + q ) * sqrt( n ) * f() )
    Usage:
        - call int() to initialize the array
        - call update() to update the element in a position
        - call query() to get ans from segment [L...R]
    Input:
        - n, number of elements
        - n elements
        - q queries
    Tested Problems:
      lightOJ:
        1082 - Array Queries
**/
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 1;
const int sz = 1e3 + 1;
const int inf = 1e9;
int BLOCK_SIZE;
int n, q, t, cs, x, y;
int BLOCKS[sz];
int ar[mx];

int getID( int idx ) {
    return idx / BLOCK_SIZE;
}

void init() {
    for( int i=0; i<sz; i++ ) BLOCKS[i] = inf;
}

void update( int idx, int val ) {
    int id = getID( idx );
    BLOCKS[id] = min( val, BLOCKS[id] );
}

int query( int l, int r ) {
    int le = getID( l );
    int ri = getID( r );
    int ret = inf;

    if( le == ri ) {
        for( int i=l; i<=r; i++ ) {
            ret = min( ret, ar[i] );
        }
        return ret;
    }

    for( int i=l; i<(le+1)*BLOCK_SIZE; i++ ) ret = min( ret, ar[i] );
    for( int i=le+1; i<ri; i++ ) ret = min( ret, BLOCKS[i] );
    for( int i=ri*BLOCK_SIZE; i<=r; i++ ) ret = min( ret, ar[i] );

    return ret;
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    scanf( "%d", &t );
    for( cs=1; cs<=t; cs++ ) {
        scanf( "%d %d", &n, &q );
        BLOCK_SIZE = sqrt( n );
        init();
        for( int i=0; i<n; i++ ) {
            scanf( "%d", &ar[i] );
            update( i, ar[i] );
        }
        printf( "Case %d:\n", cs );
        for( int i=0; i<q; i++ ) {
            scanf( "%d %d", &x, &y );
            printf( "%d\n", query( x-1, y-1 ) );
        }
    }
    return 0;
}
