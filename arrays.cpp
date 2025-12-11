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

int main() {
    vector<int> nums = {1, 2, 7, 4, 5};
    int target = 4;
    int result = largestElement(nums);
    cout << result << endl;
    return 0;
}