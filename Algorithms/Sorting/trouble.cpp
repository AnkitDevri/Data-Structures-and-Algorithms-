#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONILINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int tc;
    cin>>tc;
    int initial = tc;
    while(tc--){
        int size;
        cin>>size;
        vector<int> arr(size+1,0);
        vector<int> odd;
        vector<int> even;
        for(int i = 1 ; i < arr.size(); i++){
            cin>>arr[i];
            if(i%2==0) even.push_back(arr[i]);
            else odd.push_back(arr[i]);
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        int oIdx=0,eIdx=0;
        for(int i = 1; i < arr.size(); i++){
            if(i%2==0){
                arr[i] = even[eIdx];
                eIdx++;
            }
            else{
                arr[i] = odd[oIdx];
                oIdx++;
            }
        }
        bool flag = true;
        int trouble = 0;
        for(int i = 1; i < arr.size()-1;i++){
            if(arr[i]<arr[i+1]) continue;
            else { flag = false; trouble = i;break;}
        }
        if(flag) cout<<"Case #"<<initial-tc<<": OK\n";
        else cout<<"Case #"<<initial-tc<<": "<<trouble-1<<"\n";
    }
    return 0;
}