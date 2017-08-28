const int sz = 1e5 + 10;
int ar[sz];

struct node {
    node *left;
    node *right;
    int val;

    node( int val = 0, node *left = nullptr, node *right = nullptr ) {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    void build( int l, int r ) {
        if( l == r ) {
            this->val = ar[l];
            return;
        }
        int mid = ( l + r ) >> 1;
        this->left = new node();
        this->right = new node();
        this->left->build( l, mid );
        this->right->build( mid + 1, r );
        this->val = this->left->val + this->right->val;
    }

    node *update( int l, int r, int idx, int x ) {
        if( r < idx || idx < l ) {
            return this;
        }
        if( l == r ) {
            node *ret = new node( this->val, this->left, this->right );
            ret->val += x;
            return ret;
        }
        int mid = ( l + r ) >> 1;
        node *ret = new node( this->val );
        ret->left = this->left->update( l, mid, idx, x );
        ret->right = this->right->update( mid + 1, r, idx, x );
        ret->val = ret->left->val + ret->right->val;
        return ret;
    }

    int query( int l, int r, int i, int j ) {
        if( r < i || l > j ) {
            return 0;
        }
        if( i <= l && r <= j ) {
            return this->val;
        }
        int mid = ( l + r ) >> 1;
        return this->left->query( l, mid, i, j ) + this->right->query( mid + 1, r, i, j );
    }
} *root[sz];

int main() {
    ar[] = { 1, 2, 3 };
    root[0] = new node();
    root[0]->build( 0, 2 );
    root[1] = root[0]->update( 0, 2, 1, 1 );
    root[1] = root[1]->update( 0, 2, 1, 1 );
    printf( "%d\n", root[0].query( 0, 2, 0, 2 ) );
    printf( "%d\n", root[1].query( 0, 2, 0, 2 ) );
}
