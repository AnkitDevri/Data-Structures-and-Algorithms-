using namespace std;
#include<bits/stdc++.h>
bool verify(vector<int>& pages,int n,int& students){
    int total=pages[0];
    if(total>n) return false;

    int allocated=1;
    for(int i=1;i<pages.size();i++){
      if(total+pages[i]>n){
          allocated++;
          total=pages[i];
      }
      else total+=pages[i];
    }
 return allocated<=students;
}

int allocateBooks(vector<int>& pages,int& students, int start,int end){
    if(students>pages.size()) return -1;

    int mid=(start+end)/2;
    if(verify(pages,mid,students)){
        if(mid==*max_element(pages.begin(),pages.end()) || !verify(pages,mid-1,students)) return mid;
        else return allocateBooks(pages,students,start,mid-1);
    }
    else return allocateBooks(pages,students,mid+1,end);
}
int main(){
    int n,ele;
    cin>>n;
    vector<int> pages(n,0);
    for(int i=0;i<n;i++){
        cin>>ele;
        pages[i]=ele;
    }
    int students;
    cin>>students;
    int start,end;

    start=*max_element(pages.begin(),pages.end());
    end=accumulate(pages.begin(),pages.end(),0);

    cout<<allocateBooks(pages,students,start,end);
    getchar();
    return 0;
}