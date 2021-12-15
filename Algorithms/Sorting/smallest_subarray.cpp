using namespace std;
#include<bits/stdc++.h>
 int search ( vector <int>& presum, int left, int right, int k ) {
    int answer;
    int low = left;
    int high = right ;
    int mid = ( low + high ) / 2;

    while ( low <= high ) {
         mid = ( low + high ) / 2 ;
        if ( presum[mid] < k) low = mid;
        else { 
            if ( presum[mid-1] > k ) high = mid ;
            else return mid;
        }

    }
 }
 int get_length ( vector <int>& num_array , int k ) {
    vector <int> presum( num_array.size(), 0 );
    presum[0] = ( num_array[0] );
    for ( int i = 1; i < num_array.size(); i++ ){
        presum[i] = num_array[i] + presum[i-1];
    }
    int answer = INT_MAX;
    for ( int i = 0 ; i < num_array.size(); i++ ) {
        answer = min ( answer , search ( presum, i, num_array.size()-1, k) - i );
    }
    return answer;
 }
int main() {
    int size, k, element;
    scanf ( "%d" , &size );
    scanf ( "%d" , &k );
    vector <int> num_array;
     
    for ( int i = 0; i < size ; i++ ) {
        scanf( "%d" , &element );
        num_array.push_back( element );
    }

    printf ( "%d", get_length( num_array, k ) );

    
    getchar();
    return 0;
}