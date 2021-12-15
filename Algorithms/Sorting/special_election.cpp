using namespace std;
#include<bits/stdc++.h>
vector <int> compute_votes ( vector <int>& minions ) {
     vector <int> test(minions.size(),0);
     for ( int i = 0 ; i < minions.size(); i++ ) {

         int left = i , right = i;
         if( i > 0 ) left = i - 1;
         if (i < minions.size()-1 ) right = i + 1;
         int leftSum = 0, rightSum = 0;

         while(left >= 0 || right <= minions.size()-1) {
             bool decider = false;
             if ( left >= 0) {
                if ( left == i - 1 ) {
                    test[left]++;
                    leftSum += minions[left];
                    left--;
                    decider = true ;
                }
                 else if ( minions[i] > leftSum ) {
                    test[left]++;
                    leftSum += minions[left];
                    left--;
                    decider = true;
                }
             }
             if ( right <= minions.size() ){
                if ( right == i + 1 ) {
                    test[right]++;
                    rightSum += minions[right];
                    right++;
                    decider = true;
                }

                else if ( minions [i] > rightSum ) {
                    test[right]++;
                    rightSum += minions[right];
                    right++;
                    decider = true;
                }
             }
             if (!decider) break;
         }
     }
     return test;
}
int main () {
    int test_cases, total_minions, influence;
    scanf( "%d", &test_cases );

    vector< vector <int> > all_cases;

    for ( int i = 0; i < test_cases ; i++ ) {
        scanf ( "%d", &total_minions );
        vector <int> minions;
        for ( int j = 0; j < total_minions ; j++ ) {
            scanf ( "%d" , &influence );
            minions.push_back( influence );
        }
        all_cases.push_back(minions);
    }

    vector< vector <int> > all_votes;

    for ( int i =0 ; i < test_cases ; i++) {
        all_votes.push_back(compute_votes ( all_cases[i] ));
    }

    for ( int i = 0; i < all_votes.size() ; i++ ) {
        for ( int j = 0; j < all_votes[i].size() ; j++ ) {
            printf ( "%d " , all_votes[i][j] );
        }
        printf ( "\n" );
    }
    getchar ();
    return 0;
}