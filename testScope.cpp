using namespace std;
#include<bits/stdc++.h>
void recDigitSum(string& number){
    if(number.size()==1){
        return;
    }
    int num = 0;
    for(auto i : number){
        num += i -'0';
    }
    number = to_string(num);
    recDigitSum(number);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    
    string num;
    int k;
    cin>>num;
    cin>>k;
    int number = 0;
    for(int i = 0; i < num.size(); i++){
        number+= num[i]-'0';
    }
    number*=k;
    num = to_string(number);
    recDigitSum(num);
    cout<<num;
    return 0;
}