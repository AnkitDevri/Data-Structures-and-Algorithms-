using namespace std;
#include <bits/stdc++.h>

int partition ( vector <int>& nums, int left, int right) {
    int pivot = nums[left];
    int i = left + 1, j = right;

    for (; i <= j ; ){
        while( i <= right && nums [i] <= pivot ) i++;
        while( j >= left + 1 && nums [j] > pivot ) j--;
        if ( i < j )
        swap ( nums[i], nums[j]);
    }
    swap ( nums[j], nums[left]);

    return j;

}
void quickSort( vector <int>& nums, int left, int right) {
    if ( left >= right ) return;
     int part = partition( nums, left, right);
     quickSort ( nums, left, part - 1);
     quickSort ( nums, part + 1, right);
}
int main () {
    int size, element;
    scanf( "%d", &size);
    vector <int> nums (size,0);

    for(int i = 0; i < nums.size(); i++) {
        scanf ( "%d", &element);
        nums[i] = element;
    }
    quickSort(nums, 0, nums.size()-1);

    for (auto i : nums ) printf("%d ",i);
    getchar();
    return 0;
}