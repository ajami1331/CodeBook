struct info {
    int prop, sum;
} tree[ mx * 3 ];

void update( int node, int b, int e, int i, int j, int x ) {
//    cerr << b << " " << e << " " << i << " " << j << " " << x << "\n";
    if( i > e || j < b ) {
        return;
    }
    if( b >= i && e <= j ) {
        tree[node].sum = ( e - b + 1 ) * x;
        tree[node].prop = x;
        return;
    }

    int left = node << 1;
    int right = left | 1;
    int mid = (b + e) >> 1;

    if( tree[node].prop != -1 ) {
        tree[left].sum = ( mid - b + 1 ) * tree[node].prop;
        tree[right].sum = ( e - mid ) * tree[node].prop;
        tree[node].sum = tree[left].sum + tree[right].sum;
        tree[left].prop = tree[node].prop;
        tree[right].prop = tree[node].prop;
        tree[node].prop = -1;
    }

    update(left, b, mid, i, j, x);
    update(right, mid + 1, e, i, j, x);

    tree[node].sum = tree[left].sum + tree[right].sum;}

int query( int node, int b, int e, int i, int j ) {
    if( i > e || j < b ) {
        return 0;
    }
    if( b >= i and e <= j ) {
        return tree[node].sum;
    }

    int left = node << 1;
    int right = left | 1;
    int mid = (b + e) >> 1;

    if( tree[node].prop != -1 ) {
        tree[left].sum = ( mid - b + 1 ) * tree[node].prop;
        tree[right].sum = ( e - mid ) * tree[node].prop;
        tree[node].sum = tree[left].sum + tree[right].sum;
        tree[left].prop = tree[node].prop;
        tree[right].prop = tree[node].prop;
        tree[node].prop = -1;
    }

    int p1 = query( left, b, mid, i, j );
    int p2 = query( right, mid + 1, e, i, j );


    return p1 + p2;
}
