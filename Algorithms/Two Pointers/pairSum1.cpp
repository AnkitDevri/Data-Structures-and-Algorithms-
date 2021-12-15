using namespace std;
#include<bits/stdc++.h>

pair<int,int> getAns(vector<int> &sample,int& sum,int i,int j){
    if(i==j) return make_pair(INT_MIN,INT_MIN);
    if(sample[i]+sample[j]==sum) return make_pair(sample[i],sample[j]);
    else if(sample[i]+sample[j]>sum) return getAns(sample,sum,i,j-1);
    else return getAns(sample,sum,i+1,j);
}
int main(){
    int n,num;
    cin>>n;
    vector<int> sample(n);
    for(int idx=0;idx<n;idx++){
        cin>>num;
        sample[idx]=num;
     }
     int sum=0;
     cin>>sum;
     sort(sample.begin(),sample.end());
     pair<int,int> answer=getAns(sample,sum,0,sample.size()-1);
     if(answer.first==INT_MIN && answer.second==INT_MIN) cout<<"NO PAIR";
     else cout<<answer.first<<" + "<<answer.second;
    getchar();
    return 0;
}