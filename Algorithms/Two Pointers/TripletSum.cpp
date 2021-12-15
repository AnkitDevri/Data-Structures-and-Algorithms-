using namespace std;                                        // Triplet sum should be zero
#include<bits/stdc++.h>

vector<vector<int>> getTriplets(vector<int>& arr){
    vector<vector<int>> answer;
    if(arr[0]>0) return answer;
    else {
            set<int> negatives;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<0) negatives.insert(arr[i]);
            else break;
        }

        for(auto i=negatives.begin();i!=negatives.end();i++){
            int start=distance(negatives.begin(),i)+1;
            int end=arr.size()-1;

            while(start<end){
                if(*i+arr[start]+arr[end]==0){
                    int e1=arr[start];
                    int e2=arr[end];
                    while(arr[start+1]==e1) start++;
                    while(arr[end-1]==e2) end--;

                    answer.push_back({*i,arr[start],arr[end]});
                    start++;
                    end--;
                }
                else if(*i+arr[start]+arr[end]<0) start++;
                else end--;
            }
        }
    }
   return answer;
}
int main(){
    int total_elements,element;
    cin>>total_elements;
    vector<int> arr(total_elements);
    
    for(int i=0;i<total_elements;i++){
        cin>>element;
        arr[i]=element;
    }
    sort(arr.begin(),arr.end());
    vector<vector<int>> Solution=getTriplets(arr);

    for(int i=0;i<Solution.size();i++){
        for(int j=0;j<Solution[i].size();j++){
            cout<<Solution[i][j]<<" ";
        }
        cout<<endl;
    }
    getchar();
    return 0;
}