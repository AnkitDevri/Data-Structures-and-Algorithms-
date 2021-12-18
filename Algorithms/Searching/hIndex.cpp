using namespace std;
#include<bits/stdc++.h>
int hIndex(vector<int>& citations) {
        int answer = 0;
        for(int i = 0; i < citations.size(); i++)
            if(citations[i]>=citations.size()-i){
                answer = citations.size()-i;
                break;
            }
        return answer;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> citations(size);
    for(int i = 0; i < citations.size(); i++) cin>>citations[i];
    cout<<hIndex(citations);
    return 0;
}