#include <bits/stdc++.h>
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("D:\\input.txt","r",stdin);
    freopen("D:\\output.txt","w",stdout);
    #endif
    long long a, b;
    cin >> a >> b;
    long long res = 0;
    do
    {
        res += a/b;
        a %= b;
        swap(a, b);
    } while (b != 0);
    cout << res;
    return 0;
}