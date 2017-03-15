/**
    Implementation of Lexicographically smallest string rotation
    Running time:
        O( 2 * s.size() )
    Input:
        - s, string
    Tested Problems:
        UVA:
            719 - Glass Beads
        DevSkill:
            DCP-207: Mina and Raju Part 2
**/
const int sz = 1e5 + 10;
int f[sz];

int calc( const string& s ) {
    int n = s.size();
    string t = s + s;
    memset( f, -1, sizeof f );
    int k = 0;
    for( int j = 1; j < 2 * n; ++j ) {
        int i = f[j - k - 1];
        while( i != -1 && t[j] != t[k + i + 1] ) {
            if( t[j] < t[k + i + 1] ) {
                k = j - i - 1;
            }
            i = f[i];
        }
        if( i == -1 && t[j] != t[k + i + 1] ) {
            if( t[j] < t[k + i + 1] ) {
                k = j;
            }
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }
    return k;
}
