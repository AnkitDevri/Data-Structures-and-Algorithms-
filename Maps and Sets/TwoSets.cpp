#include<iostream>
#include<vector>
using namespace std;

 int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}
 int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}


int highCommonFactor(vector<int> a)
{
    while(a.size()>1){
        a[1]=gcd(a[0],a[1]);
        a.erase(a.begin());
    }
    return a[0];
}
int low(vector<int> a)
{
    while(a.size()>1){
        a[1]=lcm(a[0],a[1]);
        a.erase(a.begin());
    }
    return a[0];
}
int getTotalX(vector<int> a, vector<int> b) {
  int hcf=highCommonFactor(b);
  int lcm=low(a);
  int count=0;
  cout<<"LCM: "<<lcm<<endl<<"HCF: "<<hcf<<endl;
  for(int i = lcm, j =2; i<=hcf; i=lcm*j,j++){
            if(hcf%i==0){ count++;}
}
   return count;
}

int main()
{
    vector<int> a;
    vector<int>b;
    int sizea=0,sizeb=0;
    cin>>sizea;
    cin>>sizeb;
    int temp=0;

    for(int i=0;i<sizea;i++){
      cin>>temp;
      a.push_back(temp);
    }


    for(int i=0;i<sizeb;i++){
      cin>>temp;
      b.push_back(temp);
    }


    cout<<getTotalX(a,b);
    
    return 0;
}
