using namespace std;
#include <bits/stdc++.h>

int roman_to_int(string roman){
	map<char,int> rmap;
	rmap['I'] =   1;
	rmap['V'] =   5;
	rmap['X'] =  10;
	rmap['L'] =  50;
	rmap['C'] = 100;
	rmap['D'] = 500;
	rmap['M'] =1000;
	int number=0,i=0;
	
	if(roman.length()<=1){
		return rmap[roman.at(0)];
	}
	else{
		while(i<roman.size()){
			if(rmap[roman[i]]<rmap[roman[i+1]]){
				number+=rmap[roman[i+1]]-rmap[roman[i]];
				i+=2;
			}
			else{
				number+=rmap[roman[i]];
				i++;
			}
		}
		return number;
	}
}
bool cmp(string& a, string& b){
   int pos = a.find(' ');
   string aName = a.substr(0,pos);
   string aRoman = a.substr(pos+1);
   pos = b.find(' ');
   string bName = b.substr(0,pos);
   string bRoman = b.substr(pos+1);

   if(aName==bName){
       return roman_to_int(aRoman)<roman_to_int(bRoman);
   }
   else return aName<bName;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<string> str;
    vector<int> val;
    for(int i = 0; i<n; i++){
        string s;
        cin>>s;
        string k;
        cin>>k;
        string g =s+" "+k;
        str.push_back(g);
    }
    sort(str.begin(),str.end(),cmp);
    for(int i = 0; i<n; i++){
        cout<<str[i]<<endl;
    }
    return 0;
}