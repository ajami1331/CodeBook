using vi = vector < int >;
using vii = vector < vi >;

struct BIT_2D {
    int n;
    vii tree;

    BIT_2D () {}
    BIT_2D ( int _n ) : n( _n ), tree( _n, vi( _n, 0 ) ) {}
    ~BIT_2D () {}
    void update_y( int x, int y, int v ) {
        for( ; y<n; y+=(y&-y) ) {
            tree[x][y] += v;
        }
    }

    void update( int x, int y, int v ) {
        for( ; x<n; x+=(x&-x) ) {
            update_y( x, y, v );
        }
    }

    int query_y( int x, int y ) {
        int ret = 0;
        for( ; y; y-=(y&-y) ) {
            ret += tree[x][y];
        }
        return ret;
    }

    int query( int x, int y ) {
        int ret = 0;
        for( ; x; x-=(x&-x) ) {
            ret += query_y( x, y );
        }
        return ret;
    }

    int query( int x1, int y1, int x2, int y2 ) {
        return ( query( x2, y2 ) - query( x2, y1-1 ) - query( x1-1, y2 ) + query( x1-1, y1-1 ) );
    }
}

struct BIT {
    int n;
    vi tree;

    BIT () {}
    BIT ( int _n ) : n( _n ), tree( _n, 0 ) {}
    ~BIT () {}
    void update( int x, int v ) {
        for( ; x<n; y+=(x&-x) ) {
            tree[x] += v;
        }
    }

    int query( int x ) {
        int ret = 0;
        for( ; x; x-=(x&-x) ) {
            ret += tree[x];
        }
        return ret;
    }

    int query( int x, int y, int x2, int y2 ) {
        return ( query( y ) - query( x-1 ) );
    }
}


template <class T>
class FenwickTree {
private:
    T tr[sz];
    int LOGN = floor(log2(sz));
public:
    FenwickTree() {
        memset(tr, 0, sizeof tr);
    }
    void Update(int x, T v) {
        for (; x < sz; x += (x & -x)) {
            tr[x] += v;
        }
    }
    T Query(int x) {
        T ret = 0;
        for (; x > 0; x -= (x & -x)) {
            ret += tr[x];
        }
        return ret;
    }
    T QueryRange(int l, int r) {
        return Query(r) - Query(l - 1);
    }
    int BinarySearch(int v) {
        int sum = 0;
        int pos = 0;
        
        for (int i = LOGN; i >= 0; i--) {
            if (pos + (1 << i) < sz && sum + tr[pos + (1 << i)] < v) {
                sum += tr[pos + (1 << i)];
                pos += (1 << i);
            }
        }
        return pos + 1;
    }
};
