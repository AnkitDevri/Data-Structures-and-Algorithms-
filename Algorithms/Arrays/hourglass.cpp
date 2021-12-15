using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>

int hourglassSum(vector<vector<int>> arr) {
 vector<int>sum(16,0);
 int addj=0,addk=0;
 for(int i=0; i<16;i++){
  for(int j=0; j<3;j++)
  {
    for(int k=0;k<3;k++)  
    {  

        if((j==1&&k==0) ||  (j==1&&k==2)){}
          //ignore
        else{
            sum[i]=sum[i]+arr[j+addj][k+addk];
        }
    }
  }
       addk++;
       
        if(i!=0 && addk%4==0)
        {
            addk=0;
            addj++;
        }
        
    
  }
  
 
  return *max_element(sum.begin(),sum.end());
}

int main(){
  vector<vector<int>> arr(6);
  int data;
    for (int i = 0; i < 6; i++) {
     for (int j = 0; j < 6; j++) {
            cin >> data;
            arr[i].push_back(data);
        }
    }
     int result = hourglassSum(arr);

    cout<< result << "\n";

    return 0;
}