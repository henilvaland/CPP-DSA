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

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum1 = (n * (n + 1)) / 2;
    int sum2 = 0;
    for(int num : nums){
        sum2+=num;
    }
    return sum1 - sum2;
}

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for(int j = i + 1; j < nums.size(); j++){
        if(nums[j] != nums[i]){
            nums[i + 1] = nums[j];
            i++;
        }
    }
    return i+1;
}

int main() {
    vector<int> nums = {1, 0, 2, 7, 0, 4, 5};
    int target = 4;
    int missingNum = missingNumber(nums);
    //for(int i=  0; i < nums.size(); i++){
        cout << missingNum << " ";
    //}
    cout << endl;
    return 0;
}