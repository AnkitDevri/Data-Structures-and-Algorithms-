using namespace std;
#include <bits/stdc++.h>
 bool check(string &answerkey, int k , int n){
     int Tcnt = 0;
     for(int i = 0; i < n; i++){
         if(answerkey[i]=='T') Tcnt++;
     }
     if(n-Tcnt<=k || Tcnt<=k) return true;
     for(int i = n; i<answerkey.length(); i++){

         if(answerkey[i-n]=='T') Tcnt--;

         if(answerkey[i]=='T') Tcnt++;

         if(n-Tcnt<=k || Tcnt<=k) return true;
     }
     return false;
 }
 int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 1;
        int left = 1;
        int right = answerKey.length();
        while(left<=right){
            int mid = (left + right)/2;
            bool val = check(answerKey,k,mid);
            if(val && mid==answerKey.size()) return mid;
            if(val && !check(answerKey,k,mid+1)){ans=mid; break;}
            if(!val) right = mid-1;
            else left = mid+1;
        }
        return ans;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    string anskey;
    cin>>anskey;
    int k;
    cin>>k;
    cout<<maxConsecutiveAnswers(anskey,k);
    return 0;
}