using namespace std;
#include<bits/stdc++.h>
void process_range_query ( vector <int>& num_array , vector < pair <int,int> >& query_array ) {
    for ( int i = 0 ; i < query_array.size(); i++ ) {
        num_array[query_array[i].first]++;
        if( query_array[i].second > 0 )
        num_array[query_array[i].second - 1]--;
    }

    for ( int i = num_array.size() - 2; i >= 0; i++ ) {
        num_array[i] = num_array [i] + num_array [i + 1];
    }
}
int main () {
    int size;
    scanf ( "%d", &size );
    vector <int> num_array( size, 0 );
    vector < pair <int,int> > query_array;
    int qsize, start, end;
    scanf ( "%d" , &qsize );
    for ( int i = 0; i < qsize; i++ ) {
        scanf ( "%d", &start );
        scanf ( "%d", &end );
        query_array.push_back( make_pair ( start, end ) );
    }  
    process_range_query( num_array, query_array );

    for ( int i = 0; i < num_array.size(); i++ ) {
        printf ( "%d " , num_array[i] );
    }
    getchar ();
    return 0;
}