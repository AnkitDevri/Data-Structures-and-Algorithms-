using namespace std;
#include<bits/stdc++.h>

int getAns(vector<int> &sample,int& sum){
    int i=0,j=sample.size()-1;
    int count=0;
    while(i<j){
        if(sample[i]+sample[j]<sum) i++;

        else if (sample[i]+sample[j]>sum) j--;
        
        else{
            if(sample[i]==sample[j]){
            int counti=1;
            while(i!=j){ counti++; i++;}
            count+=(counti*(counti-1))/2;
            }
            else{
                int counti=0,countj=0;
                int val1=sample[i];
                int val2=sample[j];
                while(sample[i]==val1){
                    counti++; 
                    i++;
                 }
                while(sample[j]==val2){
                    countj++; 
                    j--;
                 }
                count+=counti*countj;
            }
        }
    }
    return count;
}
int main(){
    int n,num;
    cin>>n;
     int sum;
     cin>>sum;
    vector<int> sample(n);
    for(int idx=0;idx<n;idx++){
        cin>>num;
        sample[idx]=num;
     }
    sort(sample.begin(),sample.end());
     cout<<getAns(sample,sum);
    getchar();
    return 0;
}