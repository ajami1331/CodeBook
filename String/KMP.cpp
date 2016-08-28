/// complexity : o( n + m )
///solution reference loj 1255 Substring Frequency
#include <bits/stdc++.h>
using namespace std;

int t;
const int mx = 1e6 + 10;
char a[mx], b[mx];
int table[mx], lenA, lenB;

void hash_table( char *s ) {
	table[ 0 ] = 0;
	int i = 1, j = 0;
	while( i < lenB ) {
		if( s[i] == s[j] ) {
			j++;
			table[ i ] = j;
			i++;
		} else {
			if( j ) {
				j = table[ j - 1 ];
			} else {
				table[ i ] = 0;
				i++;
			}
		}
	}
}

int kmp( char *s, char *m ) {
	hash_table( m );
	int i = 0, j = 0;
	int ans = 0;
	while( i < lenA ) {
		while( i < lenA && j < lenB && s[i] == m[j] ) {
			i++;
			j++;
		}
		if( j == lenB ) {
			j = table[ j - 1 ];
			ans++;
		} else if( i < lenA && s[i] != m[j] ) {
			if( j ) {
				j = table[ j - 1 ];
			} else {
				i++;
			}
		}
	}
	return ans;
}

int main() {
#ifdef LU_SERIOUS
	freopen("in.txt", "r", stdin);
#endif // LU_SERIOUS
	scanf( "%d", &t );
	for(int cs=1; cs<=t; cs++) {
		lenA = 0; lenB = 0;
		scanf("%s", &a);
		scanf("%s", &b);
		lenA = strlen( a );
		lenB = strlen( b );
		printf( "Case %d: %d\n", cs, kmp( a, b ) );
	}
 	return 0;
}
