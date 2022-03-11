 using namespace std;
 #include<bits/stdc++.h>
 vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> sfreq(26,0);
        vector<int> pfreq(26,0);
        unordered_set <char> k;
        int count = 0;
        for(int i = 0; i<p.length(); i++){
            sfreq[s[i]-'a']++;
            pfreq[p[i]-'a']++;
            k.insert(p[i]);
        }
        
        int ecount = k.size();
        
        for(int i = 0; i<26; i++){
            if(sfreq[i]!=0 && sfreq[i]==pfreq[i]) 
                count++;
        }
        
        if(count==ecount) 
            ans.push_back(0);
        
        for(int i = p.length(); i<s.length(); i++){

            if(sfreq[s[i-p.length()]-'a']==pfreq[s[i-p.length()]-'a'])
                count--;
            
            sfreq[s[i-p.length()]-'a']--;

            if(sfreq[s[i-p.length()]-'a']!=0 && sfreq[s[i-p.length()]-'a']==pfreq[s[i-p.length()]-'a'])
                count++;
            

            if(sfreq[s[i]-'a']==pfreq[s[i]-'a'])
                count--;

            sfreq[s[i]-'a']++;
        
            if(sfreq[s[i]-'a']==pfreq[s[i]-'a'])
                count++;
            
            
            if(count==ecount) 
                ans.push_back(i-p.length()+1);
        }
        return ans;
    }

    int main(){
        #ifndef ONLINE_JUDGE
        freopen("D:\\input.txt","r",stdin);
        freopen("D:\\output.txt","w",stdout);
        #endif
        string s,p;
        cin>>s;
        cin>>p;
        vector<int> ans = findAnagrams(s,p);
        for(auto i : ans) cout<<i<<endl;
        return 0;
    }