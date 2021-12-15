using namespace std;
#include<iostream>
#include<vector>
 vector<int> preProfit(vector<int> prices){
     vector<int>profit(prices.size());
     vector<int>preMin(prices.size());
     profit[0]=0;
     preMin[0]=prices[0];
     for(int i=1;i<prices.size();i++)
       preMin[i]=min(preMin[i-1],prices[i]);
     for(int i=1;i<prices.size();i++)
       profit[i]=max(profit[i-1],prices[i]-preMin[i-1]);
    return profit;
 }

 vector<int> sufProfit(vector<int> prices){
     int size=prices.size();
     vector<int>profit(size),sufMax(size);
     profit[size-1]=0;
     sufMax[size-1]=prices[size-1];
     for(int i=size-2;i>=0;i--)
      sufMax[i]=max(sufMax[i+1],prices[i]);
     for(int i=size-2;i>=0;i--)
      profit[i]=max(profit[i+1],sufMax[i+1]-prices[i]);

    return profit;
 }
  int Profit(vector<int> preProfit,vector<int> sufProfit){
      int profit=sufProfit[0];
      for(int i=0;i<preProfit.size()-1;i++)
        profit=max(profit,preProfit[i]+sufProfit[i+1]);
      return profit;
  }
 
int main(){
    int size,element;
    cin>>size;
    vector<int> prices(size);
    for(int i=0;i<prices.size();i++){
     cin>>element;
     prices[i]=element;
    }
    cout<<Profit(preProfit(prices),sufProfit(prices));
    getchar();
    return 0;
}