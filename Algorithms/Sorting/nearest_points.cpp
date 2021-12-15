using namespace std;
#include<bits/stdc++.h>
bool compare(pair<int,int> point_1,pair<int,int> point_2){
    int distance_1= (point_1.first * point_1.first) + (point_1.second * point_1.second);
    int distance_2= (point_2.first * point_2.first) + (point_2.second * point_2.second);
    return distance_1<distance_2;
}


int main(){
    int total_points;
    scanf("%d",&total_points);

    vector<pair<int,int>> points;
    int x,y;
    for(int idx=0;idx<total_points;idx++){
        scanf("%d",&x);
        scanf("%d",&y);
        points.push_back(make_pair(x,y));
    }
    sort(points.begin(),points.end(),compare);
    for(int idx=0;idx<total_points;idx++){
       printf("%d,%d\n",points[idx].first,points[idx].second);
    }

    getchar();
    return 0;
}