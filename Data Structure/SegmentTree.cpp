const int sz = 1e5 + 10;
typedef long long ll;
struct info {
    ll prop, sum;
} tree[ sz * 4 ];
 
ll ar[sz];
 
void build( int node, int b, int e ) {
    tree[node].sum = 0;
    tree[node].prop = -1ll;
    if( b == e ) {
        return;
    }
    int left = node << 1;
    int right = left | 1;
    int mid = (b + e) >> 1;
    build( left, b, mid );
    build( right, mid + 1, e );
    tree[node].sum = tree[left].sum + tree[right].sum;
}

void propagate( int node, int b, int e ) {
    if( tree[node].prop != -1ll ) {
        tree[node].sum = ( e - b + 1 ) * tree[node].prop;
        if( b != e ) {
            tree[node*2].prop = tree[node].prop;
            tree[node*2+1].prop = tree[node].prop;
        }
        tree[node].prop = -1ll;
    }
}

void update( int node, int b, int e, int l, int r, ll x ) {
    propagate( node, b, e );
    if( r < b || e < l ) return;
    if( b >= l && e <= r ) {
        tree[node].sum = ( e - b + 1 ) * x;
        // cerr << node << " " << b << " " << e << " " << l << " " << r << " " << tree[node].sum << "up\n";
        if( b != e ) {
            //cerr << b << " " << e << "\n";
            tree[node*2].prop = x;
            tree[node*2+1].prop = x;
        }
        return;
    }
    int left = node << 1;
    int right = left | 1;
    int mid = ( b + e ) >> 1;
    update( left, b, mid, l, r, x );
    update( right, mid + 1, e, l, r, x );
    tree[node].sum = tree[left].sum + tree[right].sum;
}
 
ll query( int node, int b, int e, int l, int r ) {
    // cerr << node << " " << b << " " << e << " " << l << " " << r << " " << tree[node].prop << "\n";
    propagate( node, b, e );
    if( r < b || e < l ) return 0;
    if( b >= l && e <= r ) {
        // cerr << node << " " << b << " " << e << " " << l << " " << r << " " << tree[node].sum << "\n";
        return tree[node].sum;
    }
 
    int left = node << 1;
    int right = left | 1;
    int mid = (b + e) >> 1;
 
    ll p1 = query( left, b, mid, l, r );
    ll p2 = query( right, mid + 1, e, l, r );
 
    return p1 + p2;
}