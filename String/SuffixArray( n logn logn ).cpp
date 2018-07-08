/**
    Implementation of Suffix Array
    Running time:
        O( n log( n ) log( n ) )
    Input:
        - s, string for that suffix array to be completed
    Output:
        - Suffix Array
    Tested Problems:
      SPOJ:
        SARRAY - Suffix Array
**/
#include <bits/stdc++.h>
using namespace std;

struct suffix {
        int index;
        int rank[2];
        bool operator < ( const suffix &other ) const {
                if( this->rank[0] == other.rank[0] ) {
                        return this->rank[1] < other.rank[1];
                }
                return this->rank[0] < other.rank[0];
        }
};

vector < int > buildSuffixArray( const string &s ) {
        int n = int( s.size() );
        vector < int > sufArray;
        vector < suffix > suffixes( n );
        for( int i=0; i<n; i++ ) {
                suffixes[i].index = i;
                suffixes[i].rank[0] = s[i];
                suffixes[i].rank[1] = i + 1 < n ? s[i+1] : -1;
        }
        vector < int > ind( n );
        int nextIndex, rank, prev_rank, n_2 = n << 1;
        sort( suffixes.begin(), suffixes.end() );
        for( int k=4; k<n_2; k<<=1 ) {
                rank = 0;
                prev_rank = suffixes[0].rank[0];
                suffixes[0].rank[0] = rank;
                ind[ suffixes[0].index ] = 0;
                for( int i=1; i<n; i++ ) {
                        if( suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1] ) {
                                prev_rank = suffixes[i].rank[0];
                                suffixes[i].rank[0] = rank;
                        } else {
                                prev_rank = suffixes[i].rank[0];
                                suffixes[i].rank[0] = ++rank;
                        }
                        ind[ suffixes[i].index ] = i;
                }
                for( int i=0; i<n; i++ ) {
                        nextIndex = suffixes[i].index + k / 2;
                        suffixes[i].rank[1] = nextIndex < n ? suffixes[ ind[ nextIndex ] ].rank[0] : -1;
                }
                sort( suffixes.begin(), suffixes.end() );
        }
        for( const suffix suf: suffixes ) {
                sufArray.push_back( suf.index );
        }
        return sufArray;
}

vector<int> kasai( const string& s, const vector<int> &sa ) {
        int n=s.size(),k=0;
        vector<int> lcp(n,0);
        vector<int> rank(n,0);

        for(int i=0; i<n; i++) rank[sa[i]]=i;

        for(int i=0; i<n; i++, k?k--:0) {
                if(rank[i]==n-1) {
                        k=0;
                        continue;
                }
                int j=sa[rank[i]+1];
                while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
                lcp[rank[i]]=k;
        }
        return lcp;
}


int main() {
    #ifdef CLown1331
        freopen( "in.txt", "r", stdin );
    #endif /// CLown1331
    string s;
    while( cin >> s ) {
        vector < int > sufArray = buildSuffixArray( s );
        for( const int ind: sufArray ) {
            cout << ind << "\n";
        }
        cerr << "----\n";
    }
    return 0;
}
