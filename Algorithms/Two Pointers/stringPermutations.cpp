using namespace std;
#include<bits/stdc++.h>
   bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        vector<int> frqS1(26,0);
        vector<int> frqS2(26,0);

        for(int i = 0 ; i < s1.length(); i++) {
            frqS1[s1[i]-'a']++;
            frqS2[s2[i]-'a']++;
        }
        int p1 = 0, p2 = s1.length()-1;
        if(frqS1==frqS2) return true;

        while(p2<s2.length()-1){
            frqS2[s2[p1]-'a']--;
            p1++;

            p2++;
            frqS2[s2[p2]-'a']++;
            if(frqS2==frqS1) return true;
        }
        return false;
    }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout<<checkInclusion(s1,s2);
    getchar();
    return 0;
}