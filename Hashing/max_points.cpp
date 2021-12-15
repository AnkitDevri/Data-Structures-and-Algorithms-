using namespace std;
#include <bits/stdc++.h>
int max_points ( vector <pair <int,int>>& points ){
    int maxPoints = 0;
    map <pair <int,int>,int> hmap;
    for ( int i = 0; i < points.size(); i++) {
        hmap.clear();
        for ( int j = i+1; j < points.size(); j++ ) {
            int num = points[i].first - points[j].first;
            int denom = points[i].second - points[j].second;
            int gcd = __gcd(num,denom);
            num = num/gcd;
            denom = denom/gcd;

            if ( denom < 0 && num >= 0 ) {
                denom = abs(denom);
                num = num*(-1);
            }
            else if ( denom < 0 && num < 0 ) {
                num = abs(num);
                denom = abs(denom);
            }
            pair <int,int> temp = make_pair(num,denom);
            auto it = hmap.find(temp);
            if ( it != hmap.end() ) {
                it->second++;
                maxPoints = max (maxPoints, it->second);
            }
            else{ 
                hmap.insert({temp,1});
                maxPoints = max (maxPoints, 1);
            }
            
        }
    }
    return maxPoints + 1;
}
int main () {
    int size;
    scanf("%d", &size);
    vector <pair <int,int>> points;

    int x, y;
    for ( int i = 0; i < size; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        points.push_back(make_pair(x,y));
    }
    printf("%d", max_points(points));
    getchar();
    return 0;
}