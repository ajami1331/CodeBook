const int sz = 1e5 + 10;
int ar[sz];
struct node {
    int left;
    int right;
    int val;
} nodes[sz * 32];
int root[sz];

void build( int nd, int l, int r ) {
    if( l == r ) {
        nodes[nd].val = 0;
        return;
    }
    int mid = ( l + r ) >> 1;
    nodes[nd].left = ++nxt;
    nodes[nd].right = ++nxt;
    build( nodes[nd].left, l, mid );
    build( nodes[nd].right, mid + 1, r );
    nodes[nd].val = nodes[ nodes[nd].left ].val + nodes[ nodes[nd].right ].val;
}

int update( int nd, int l, int r, int idx, int x ) {
    if( r < idx || idx < l ) {
        return nd;
    }
    if( l == r ) {
        int n_nd = ++nxt;
        nodes[ n_nd ].val = nodes[ nd ].val + x;
        nodes[ n_nd ].left = nodes[ nd ].left;
        nodes[ n_nd ].right = nodes[ nd ].right;
        return n_nd;
    }
    int mid = ( l + r ) >> 1;
    int n_nd = ++nxt;
    nodes[ n_nd ].val = nodes[ nd ].val;
    nodes[ n_nd ].left = update( nodes[ nd ].left, l, mid, idx, x );
    nodes[ n_nd ].right = update( nodes[ nd ].right, mid + 1, r, idx, x );
    nodes[ n_nd ].val = nodes[ nodes[ n_nd ].left ].val + nodes[ nodes[ n_nd ].right ].val;
    return n_nd;
}

int query( int nd, int l, int r, int i, int j ) {
    if( r < i || l > j ) {
        return 0;
    }
    if( i <= l && r <= j ) {
        return nodes[ nd ].val;
    }
    int mid = ( l + r ) >> 1;
    return query( nodes[ nd ].left, l, mid, i, j ) + query( nodes[ nd ].right, mid + 1, r, i, j );
}

int main() {
    ar[] = { 1, 2, 3 };
    nxt = -1;
    root[0] = ++nxt;
    build( root[0], 0, 2 );
    root[1] = update( root[0], 0, 2, 1, 1 );
    root[1] = update( root[1], 0, 2, 1, 1 );
    printf( "%d\n", query( root[0], 0, 2, 0, 2 ) );
    printf( "%d\n", query( root[1], 0, 2, 0, 2 ) );
}
