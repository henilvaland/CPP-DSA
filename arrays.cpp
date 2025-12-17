#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

int largestElement(std::vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int largest = nums[nums.size() - 1];
    return largest;
}

void moveZeroes(vector<int>& nums) {
    int j = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    vector<int> nums = {1, 0, 2, 7, 0, 4, 5};
    int target = 4;
    moveZeroes(nums);
    for(int i=  0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}