using namespace std;
#include<bits/stdc++.h>

vector<int> isPossibleSum(vector<int>& arr,int& sum){
    vector<int> answer;
    int p1=0,p2=0,current_Sum=arr[0];
    while(p2<arr.size()){
        if(current_Sum==sum){
            answer.push_back(p1);
            answer.push_back(p2);
            return answer;
        }
          else if(current_Sum<sum){
            p2++;
            if(p2>=arr.size()) return answer;
            else current_Sum+=arr[p2];
        }
        else {
            current_Sum-=arr[p1];
            p1++;
            if(p1>p2){
                p2=p1;
               if(p2<arr.size()) current_Sum=arr[p1];
            } 
         
        }
    }
    return answer;
}
int main(){
    int total_elements,element,sum;
    cin>>total_elements;
    vector<int> arr(total_elements);
    cin>>sum;
    for(int i=0;i<total_elements;i++){
        cin>>element;
        arr[i]=element;
    }
    vector<int> soulution=isPossibleSum(arr,sum);
    cout<<soulution[0]<<" "<<soulution[1];
    getchar();
    return 0;
}