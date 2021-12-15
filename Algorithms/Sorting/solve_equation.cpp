using namespace std;
#include<bits/stdc++.h>
typedef long long ll;
vector<ll> compute_lhs(vector<ll>& lhs){
    vector<ll> computed;
    for(int i=0;i<lhs.size();i++){
        for(int j=0;j<lhs.size();j++){
            for(int k=0;k<lhs.size();k++){
                computed.push_back((lhs[i]*lhs[j])+lhs[k]);
            }
        }
    }
    return computed;
}
vector<ll> compute_rhs(vector<ll>& rhs){
    vector<ll> computed;
    for(int i=0;i<rhs.size();i++){
        for(int j=0;j<rhs.size();j++){
            for(int k=0;k<rhs.size();k++){
                if(rhs[k]) computed.push_back((rhs[i]+rhs[j])*rhs[k]);
            }
        }
    }
    return computed;
}

int first(vector<ll>& arr, int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x);
        else
            return first(arr, low, (mid - 1), x);
    }
    return -1;
}

int last(vector<ll>& arr, int low, int high, int x)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == arr.size() - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return last(arr, low, (mid - 1), x);
        else
            return last(arr, (mid + 1), high, x);
    }
    return -1;
}

int main(){
    ll total_elements;
    scanf("%ld",&total_elements);
    vector<ll> num_array;
    int element;
    for(int i=0;i<total_elements;i++){
        scanf("%ld",&element);
        num_array.push_back(element);
    }
    vector<ll> LHS=compute_lhs(num_array);
    vector<ll> RHS=compute_rhs(num_array);
    sort(RHS.begin(),RHS.end());
    ll count=0;
    for(int i=0;i<LHS.size();i++){
        int f=first(RHS,0,RHS.size()-1,LHS[i]);
        if(f==-1) continue;
        else {
            int start=f;
            int end=last(RHS,0,RHS.size()-1,LHS[i]);
            count+=(end-start);
        }
    }
    cout<<count;
    getchar();
    return 0;
}