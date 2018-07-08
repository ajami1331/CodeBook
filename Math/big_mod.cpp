ll big_mod( ll b, ll p ) {
        ll ret = 1;
        for( ; p>0; p >>= 1 ) {
                if( p&1 ) ret = ( ret * b ) % mod;
                b = ( b * b ) % mod;
        }
        return ret % mod;
}

ll mod_inv( ll b ) {
        return big_mod( b, mod - 2 );
}
