using namespace std;
#include<bits/stdc++.h>
 int get_manhattan_distance(vector<int>& x,vector<int>& y){
     int answer=0;
     sort(x.begin(),x.end());
     sort(y.begin(),y.end());
     vector<int> Xsuffix;
     vector<int> Ysuffix;
     Xsuffix.push_back(x[x.size()-1]);
     Ysuffix.push_back(y[y.size()-1]);

     for(int i=x.size()-2;i>=0;i--){
        Xsuffix[i]=x[i]+Xsuffix[i+1];
        Ysuffix[i]=y[i]+Ysuffix[i+1];
     }

     for(int i=0;i<x.size()-1;i++){
         answer+=Xsuffix[i+1]-(x[i]*(x.size()-1-i));
         answer+=Ysuffix[i+1]-(y[i]*(y.size()-1-i));
     }
     return answer;
 }
int main(){
    int total_points;
    scanf("%d",&total_points);
    int x_input,y_input;
    vector<int> x;
    vector<int> y;
    for(int i=0;i<total_points;i++){
        scanf("%d",&x_input);
        x.push_back(x_input);
        scanf("%d",&y_input);
        y.push_back(y_input);

    }
    printf("%d",get_manhattan_distance(x,y));
    getchar();
    return 0;
}