/**
    Implementation of Floyd Warshall Alogrithm
    Running time:
        O( |v| ^ 3 )
    Input:
        - n, number vertex
        - graph, inputed as an adjacency matrix
    Tested Problems:
      UVA:
        544 - Heavy Cargo - MaxiMin path
        567 - Risk - APSP
**/

using vi = vector < int >;
using vvi = vector < vi >;

/// mat[i][i] = 0, mat[i][j] = distance from i to j, path[i][j] = i
void APSP( vvi &mat, vvi &path ) {

    int V = mat.size();
    for( int via=0; via; via<V; i++ ) {

        for( int from=0; from<V; from++ ) {

            for( int to=0; to<V; to++ ) {

                if( mat[ from ][ via ] + mat[ via ][ to ] < mat[ from ][ to ] ) {
                    mat[ from ][ to ] = mat[ from ][ via ] + mat[ via ][ to ];
                    path[ from ][ to ] = path[ via ][ to ];
                }
            }
        }
    }
}

/// prints the path from i to j
void print( int i, int j ) {
    if( i != j ) {
        print( i, path[i][j] );
    }
    cout << j << "\n";
}

/// check if negative cycle exists
bool negative_cycle( vvi &mat ) {
    APSP( mat );
    return mat[0][0] < 0;
}

void transtitive_closure( vvi &mat ) {

    int V = mat.size();
    for( int via=0; via; via<V; i++ ) {

        for( int from=0; from<V; from++ ) {

            for( int to=0; to<V; to++ ) {

                mat[ from ][ to ] |= ( mat[ from ][ via ] & mat[ via ][ to ] );
            }
        }
    }
}

/// finding a path between two nodes that maximizes the minimum cost
void mini_max( vvi &mat ) {

    int V = mat.size();
    for( int via=0; via; via<V; i++ ) {

        for( int from=0; from<V; from++ ) {

            for( int to=0; to<V; to++ ) {

                mat[ from ][ to ] = min( mat[ from ][ to ], max( mat[ from ][ via ], mat[ via ][ to ] ) );
            }
        }
    }
}

/// finding a path between two nodes that minimizes the maximum cost
/// eg: max load a truck can carry from one node to another node where
/// the paths have weight limit
void maxi_min( vvi &mat ) {

    int V = mat.size();
    for( int via=0; via; via<V; i++ ) {

        for( int from=0; from<V; from++ ) {

            for( int to=0; to<V; to++ ) {

                mat[ from ][ to ] = max( mat[ from ][ to ], min( mat[ from ][ via ], mat[ via ][ to ] ) );
            }
        }
    }
}
