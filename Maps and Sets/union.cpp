
 #include<algorithm>
 #include<conio.h>
 #include<iostream>
 #include<map>

 using namespace std;
 int doUnion(int a[], int n, int b[], int m)  {
    map<int, int> mp;
   
    // Inserting array elements in mp
    for (int i = 0; i < n; i++)
        mp.insert({ a[i], i });
   
    for (int i = 0; i < m; i++)
        mp.insert({ b[i], i });

     return mp.size();
    }
 
    int main(){
        int n,m;
         cin>>n>>m;
         int a[n],b[m];

        for(int i=0;i<n;i++)
         cin>>a[i];
         
        for(int i=0;i<m;i++)
         cin>>b[i];

        cout<<doUnion(a,n,b,m);
        getch();
        return 0;
    }
    