using namespace std;
#include<bits/stdc++.h>
 vector <bool> nums;
void bin(unsigned n)
{

    if (n > 1)
        bin(n / 2);
 
    
    nums.push_back(n%2);
}
int main(){
    int n,ele;
    cin>>n;
    vector<int> set(n);
    for(int i=0;i<n;i++){
        cin>>ele;
        set[i]=ele;
    }
    nums.resize(n);
    int n2=pow(2,n);

    for(int i=0;i<n2;i++){
      bin(i);
    for(int j=0;j<n;j++)
       if(nums[j])
        cout<<set[j]<<" ";

      nums.clear();
      cout<<endl;
    }

   
    getchar();
    return 0;
}