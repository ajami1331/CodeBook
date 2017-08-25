const int sz = 2e5 + 10;
char inp[sz], str[sz];
int LPS[sz];

int call(){
    int len = 0;
    str[ len++ ]='*';
    for( int i=0; inp[i]; i++ ) {
        str[ len++ ] = inp[i];
        str[ len++ ] = '*';
    }
    str[ len ] = '\0';
    int c = 0, r = 0, ans = 0;
    for( int i=1; i<len-1; i++ ) {
        int _i = c - ( i - c );
        if( r > i ) LPS[i] = min( LPS[_i] , r - i );
        else LPS[i] = 0;
        while( i - 1 - LPS[i] >= 0 && str[ i - 1 - LPS[i] ] == str[ i + 1 + LPS[i] ] ) {
            LPS[i]++;
        }
        if( i + LPS[i] > r ) {
            r = i + LPS[i];
            c = i;
        }
        ans = max( ans, LPS[i] );
    }
    return ans;
}
