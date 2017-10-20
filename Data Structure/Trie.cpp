const int sz = 1e5 + 10;
const int szz = 1e6 + 5e5 + 10;
string s[sz];
int n, m, state;
ll ans = 0;
 
struct nd {
    int nxt[27];
    ll cnt;
    nd(){
        cnt = 0;
        memset( nxt, -1, sizeof nxt );
    }
} tree[szz];
 
void insrt( int idx ) {
    int root = 0;
    int id;
    for( int i=0; i<m; i++ ) {
        id = s[idx][i] - 'a';
        if( tree[root].nxt[id] == -1 ) {
            tree[root].nxt[id] = ++state;
            memset( tree[state].nxt, -1, sizeof tree[state].nxt );
            tree[state].cnt = 0;
        }
        root = tree[root].nxt[id];
    }
    tree[root].cnt++;
}
 
void del( int idx ) {
    int root = 0;
    int id;
    for( int i=0; i<m; i++ ) {
        id = s[idx][i] - 'a';
        if( tree[root].nxt[id] == -1 ) {
            return;
        }
        root = tree[root].nxt[id];
    }
    tree[root].cnt--;
}