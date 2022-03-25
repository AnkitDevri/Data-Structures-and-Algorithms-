using namespace std;
#include <bits/stdc++.h>
    void help(vector<int>& ans, int& num,int& low, int& high,int idx){
        if(idx==10) return;  
        int temp = num;
        for(int i = idx; i<=9; i++){
            num*=10;
            num+=i;
            if(num>high) break;
            if(num>=low && num<=high) 
                ans.push_back(num);
        }
        num = temp;
        help(ans,num,low,high,idx+1);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int num = 0;
        help(ans,num,low,high,1);
        return ans;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int low,high;
    cin>>low>>high;
    vector <int> ans = sequentialDigits(low,high);
    for(auto i : ans) cout<<i<<endl;
    return 0;
}