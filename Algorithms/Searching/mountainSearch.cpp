using namespace std;
#include<bits/stdc++.h>
 
    int searchLarge(vector<int> &mountainArr,int start,int end){
        int mid = (start + end)/2;
        if(start>end) return -1;
        int element = mountainArr[mid];
        int element1 = mountainArr[mid+1];
        int element2 = mountainArr[mid-1];
        if(element>element1 && element>element2) return mid;
        if(element<element1) return searchLarge(mountainArr,mid+1,end);
        else return searchLarge(mountainArr,start,mid-1);
    }

    int search(vector<int>& mountainArr,int start,int end,int& target){
        int mid = (start + end)/2;
        if(start>end) return -1;
        int element = mountainArr[mid];
        if(element==target) return mid;
        if(target<element) return search(mountainArr,start,mid-1,target);
        else return search(mountainArr,mid+1,end,target);
    }

    int reverseSearch(vector<int>& mountainArr,int start,int end,int& target){
        int mid = (start + end)/2;
        if(start>end) return -1;
        int element = mountainArr[mid];
        if(element==target) return mid;
        if(target<element) return reverseSearch(mountainArr,mid+1,end,target);
        else return reverseSearch(mountainArr,start,mid-1,target);
    }

    int findMountainArray(int target, vector<int> &mountainArr) {
        int largest = searchLarge(mountainArr,0,mountainArr.size()-1);
        int first = search(mountainArr,0,largest-1,target);
        int second = reverseSearch(mountainArr,largest+1,mountainArr.size()-1,target);
        int minimum = min(first,second);
        if(minimum == -1) minimum = max(first,second);
        return minimum;
    }

int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int size;
    cin>>size;
    vector<int> mountain(size);
    for(int i = 0; i < size; i++) cin>>mountain[i];
    int target;
    cin>>target;
    cout<<findMountainArray(target,mountain);
    return 0;
}