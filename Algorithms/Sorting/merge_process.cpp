using namespace std;
#include <bits/stdc++.h>
vector <int> mergeProcess( vector <int>& arr1, vector <int>& arr2 ){
    vector <int> ans (arr1.size() + arr2.size(), 0);
    int pointer1 = 0, pointer2 = 0, pointer3 = 0;

    while ( pointer3 < arr1.size() + arr2.size()) {
        if ( pointer1 < arr1.size()) {
            if ( pointer2 < arr2.size()){
                if( arr1[pointer1] < arr2[pointer2] ) {
                    ans[pointer3] = arr1[pointer1];
                    pointer1++;
                }
                else {
                    ans[pointer3] = arr2[pointer2];
                    pointer2++;
                }
            }
            else {
                ans[pointer3] = arr1[pointer1];
                pointer1++; 
            }
        }
      
        else {
            ans[pointer3] = arr2[pointer2];
            pointer2++;
            }
            
        pointer3++;       
    }

    return ans; 
}
int main () {
    int size1, size2, element;
    scanf( "%d", &size1 );
    scanf( "%d", &size2 );

    vector <int> arr1;
    vector <int> arr2;

    for ( int i = 0; i < size1; i++) {
        scanf("%d", &element);
        arr1.push_back(element);
    }

    for ( int j = 0; j < size2; j++) { 
        scanf( "%d", &element);
        arr2.push_back(element);
    }

    vector <int> merged = mergeProcess(arr1,arr2);

    for ( int i = 0; i < size1 + size2; i++) {
        printf ( "%d ", merged[i]);
    }
    getchar();
    return 0;
}  