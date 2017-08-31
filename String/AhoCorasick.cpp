const int sz = 1e6 + 10;
const int MAX = 150 * 70 + 100;
char inp[sz], s[105][75];

struct AhoCorasick {
    vector < int > mark[MAX + 7];
    int state, failure[MAX + 7];

    struct node {
        int nxt[26];
        node() {
            set();
        }
        void set() {
            memset( nxt, -1, sizeof nxt );
        }
    }  trie[MAX + 7];

    AhoCorasick() {
        init();
    }

    void init() {
        mark[0].clear();
        trie[0].set();
        state = 0;
    }

    int value( char c ) {
        return c - 'a';
    }

    void add( char *s, int t ) {
        int root = 0, id;
        for( int i=0; s[i]; i++ ) {
            id = value( s[i] );
            if( trie[ root ].nxt[ id ] == -1 ) {
                trie[ root ].nxt[ id ] = ++state;
                mark[ state ].clear();
                trie[ state ].set();
            }
            root = trie[ root ].nxt[ id ];
        }
        mark[ root ].push_back( t );
    }

    void computeFailure() {
        queue < int > Q;
        failure[0] = 0;
        for( int i=0; i<26; i++ ) {
            if( trie[ 0 ].nxt[ i ] != -1 ) {
                failure[ trie[ 0 ].nxt[ i ] ] = 0;
                Q.push( trie[ 0 ].nxt[ i ] );
            }
            else trie[ 0 ].nxt[ i ] = 0;
        }
        while( !Q.empty() ) {
            int u = Q.front();
            Q.pop();
            for( int v: mark[ failure[ u ] ] ) mark[ u ].push_back( v );
            for( int i=0; i<26; i++ ) {
                if( trie[ u ].nxt[ i ] != -1 ) {
                    failure[ trie[ u ].nxt[ i ] ] = trie[ failure[ u ] ].nxt[ i ];
                    Q.push( trie[ u ].nxt[ i ] );
                }
                else trie[ u ].nxt[ i ] = trie[ failure[ u ] ].nxt[ i ];
            }
        }
    }
} automata;

int cnt[155];

void countFreq() {
    for( int i=0,root=0,id; inp[i]; i++ ) {
        id = automata.value( inp[i] );
        root = automata.trie[ root ].nxt[ id ];
        if( root == 0 ) continue;
        for( int v: automata.mark[ root ] ) cnt[v]++;
    }
}
