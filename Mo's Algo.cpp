/**
    Implementation of Mo's Algo with SQRT-Decomposition Data Structure
    Running time:
        O( ( n + q ) * sqrt( n ) * f() )
    Mo's Algo is a algorithm to process queries offline
    For it to work, this condition must be satisified:
        1) There can be no updates in the array
        2) All queries must be known beforehand
    Tested Problems:
      CF:
        220B - Little Elephant and Array
**/
#include <bits/stdc++.h>
using namespace std;

using piii = pair < pair < int, int >, int >;
const int mx = 1e5 + 1;
int BLOCK_SIZE;
int n, m;
int calc;
int ar[mx];
int ans[mx];
unordered_map < int, int > cnt;
piii query[mx];

struct {
    bool operator()( const piii &a, const piii &b ) {
        int block_a = a.first.first / BLOCK_SIZE;
        int block_b = b.first.first / BLOCK_SIZE;
        if( block_a != block_b ) {
            return block_a < block_b;
        }
        return a.first.second < b.first.second;
    }
} cmp;

void add( int x ) {
    calc -= ( cnt[x] == x ? 1 : 0 );
    cnt[x]++;
    calc += ( cnt[x] == x ? 1 : 0 );
}

void remove( int x ) {
    calc -= ( cnt[x] == x ? 1 : 0 );
    cnt[x]--;
    calc += ( cnt[x] == x ? 1 : 0 );
}

int main() {
    #ifdef LU_SERIOUS
        freopen( "in.txt", "r", stdin );
//        freopen( "out.txt", "w+", stdout );
    #endif // LU_SERIOUS
    while( ~scanf( "%d %d", &n, &m ) ) {

        BLOCK_SIZE = sqrt( n );
        cnt.clear();
        calc = 0;

        for( int i=0; i<n; i++ ) scanf( "%d", ar+i );

        for( int i=0; i<m; i++ ) {
            scanf( "%d %d", &query[i].first.first, &query[i].first.second );
            query[i].second = i;
        }

        sort( query, query+m, cmp );

        int mo_l = 0, mo_r = -1;

        for( int i=0; i<m; i++ ) {
            int left = query[i].first.first - 1;
            int right = query[i].first.second - 1;

            while( mo_r < right ) {
                mo_r++;
                add( ar[mo_r] );
            }

            while( mo_r > right ) {
                remove( ar[mo_r] );
                mo_r--;
            }

            while( mo_l < left ) {
                remove( ar[mo_l] );
                mo_l++;
            }

            while( mo_l > left ) {
                mo_l--;
                add( ar[mo_l] );
            }

            ans[ query[i].second ] = calc;
        }

        for( int i=0; i<m; i++ ) {
            printf( "%d\n", ans[i] );
        }
    }
    return 0;
}
