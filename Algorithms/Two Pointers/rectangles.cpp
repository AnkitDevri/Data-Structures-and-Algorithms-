using namespace std;
#include<bits/stdc++.h>
int getRectangles(vector<int>& arr,int area){
    int start=0;
    int end=arr.size()-1;
    int count=0;
    while(start<end){
        if(arr[start]*arr[start]<=area) count++;
        if(arr[start]*arr[end]<area){
            count+=(2*(end-start));
            start++;
        }
        else end--;
    }
    return count;
}
int main(){
    int area;
    cin>>area;
    int total_elements;
    cin>>total_elements;

    int element;
    vector<int> arr(total_elements,0);
    for(int item=0;item<total_elements;item++){
        cin>>element;
         arr[item]=element;
    }
    sort(arr.begin(),arr.end());
    cout<<getRectangles(arr,area);

    getchar();
    return 0;
}