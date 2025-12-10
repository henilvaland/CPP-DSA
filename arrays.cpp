#include<iostream>
using namespace std;

int linearSearch(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 4;
    int result = linearSearch(nums, target);
    cout << result << endl;
    return 0;
}