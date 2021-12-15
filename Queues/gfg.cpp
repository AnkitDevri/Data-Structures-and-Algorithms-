// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends




vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                        vector <long long> answer;
                        queue <int> usefulValues;
                    for ( int i = 0; i < N; i++){
                        if( A[i] < 0) usefulValues.push(i);
                    }    
                    
                    for ( int i = 0; i < N - K + 1; i++){
                        if(!usefulValues.empty() && i - usefulValues.front() < K - 1) answer.push_back(A[usefulValues.front()]);
                        else {
                            answer.push_back(0);
                            if(!usefulValues.empty())usefulValues.pop();
                        }
                    }
                    
                    return answer;
 }