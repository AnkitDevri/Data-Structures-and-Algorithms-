/*using namespace std;
#include <bits/stdc++.h>
string compute(long long n){
   if(n==0) 
    return "0";
   if(n==1) 
    return "1";

   string num;
   num = compute(n/2);
   int mod = n%2;

   string v;
   v+=num;
   v+=char(mod);
   v+=num;

    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    long long n;
    cin>>n;
    string v;
    long long l,r;
    v=compute(n);
    string ans;
    ans+=v;
    ans+=char(n%2);
    ans+=v;
    cin>>l>>r;
    l--;r--;
    int count = 0;
    for(int i = l; i<=r; i++){
        if(ans[i]) count++;
    }
    cout<<count;
    return 0;
}*/

#include<bits/stdc++.h>

using namespace std;



long long int n, l, r;



long long int c41(long long int n, long long int left, long long int right)

{

    if (left > r || right < l) return 0;

    if (n < 2)

    {

        if (left >= l && right <= r) return n;

        else return 0;

    }

    long long int mid = (left + right) / 2;

    return c41(n / 2, left, mid - 1) + c41(n % 2, mid, mid) + c41(n / 2, mid + 1, right);

}

int main()

{
    #ifndef ONLINE_JUDGE

    freopen("D:\\input.txt","r",stdin);

    freopen("D:\\output.txt","w",stdout);

    #endif

    cin >> n >> l >> r;

    long long int len = 1;

    int x = log2(n);
    
    for(int i=0;i<x;i++){

        len = len * 2 + 1;

    }

    cout << c41(n, 1, len) << endl;

}