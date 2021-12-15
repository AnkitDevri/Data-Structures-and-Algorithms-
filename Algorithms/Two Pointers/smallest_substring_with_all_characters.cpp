using namespace std;
#include<bits/stdc++.h>
bool verify(vector<int>& f1,vector<int>& f2){
    int i=0;
    for(int i=0;i<256;i++){
        if(f2[i]==0) continue;
        else{
            if(f1[i]<f2[i]) return false;
            else continue;
        }
    }
    return true;
}
string smallestSubstring(string& input,string& test,vector<int>& f1,vector<int>& f2){
    int pointer_1=0;
    int pointer_2=0;
    int ans_1=0;
    int ans_2=0;
    int i=0;
    while(i<input.size()){
        if(!verify(f1,f2)){
            pointer_2++;
            f1[input[i]]++;
            ans_2=pointer_2;
            i++;
        }
        else{
            f1[input[pointer_1]]--;
            if(verify(f1,f2)) pointer_1++;
            else {
                f1[input[pointer_1]]++;
                if(pointer_2<input.size()){
                 pointer_2++;
                 f1[input[pointer_2]]++;
                }
                else{
                    f1[input[pointer_1]]--;
                    if(verify(f1,f2)) pointer_1++;
                    else{
                         if(ans_2-ans_1>pointer_2-pointer_1){
                            ans_2=pointer_2;
                            ans_1=pointer_1;
                            }
                            break;
                    }
                }
            }

        }
     if(ans_2-ans_1>pointer_2-pointer_1){
         ans_2=pointer_2;
         ans_1=pointer_1;
     }
    }
    return input.substr(ans_1,ans_2);

}
int main(){
    string input,test;
    cin>>input;
    cin>>test;
    vector<int> input_frequency(256,0);
    vector<int> test_frequency(256,0);
    for(int i=0;i<test.size();i++) test_frequency[test[i]]++;
    cout<<smallestSubstring(input,test,input_frequency,test_frequency);
    getchar();
    return 0;
}