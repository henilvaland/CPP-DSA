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

vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;

    while(i < n1 && j < n2){
        if(nums1[i] <= nums2[j]){
            if(unionArr.size() == 0 || unionArr.back() != nums1[i]){
                unionArr.push_back(nums1[i]);
            }
            i++;
        }
        else {
            if(unionArr.size() == 0 || unionArr.back() != nums2[j]){
                unionArr.push_back(nums2[j]);
            }
            j++;
        }
    }

    while(i < n1){
        if(unionArr.size() == 0 || unionArr.back() != nums1[i]){
            unionArr.push_back(nums1[i]);
        }
        i++;
    }

    while(j < n2){
        if(unionArr.size() == 0 || unionArr.back() != nums2[j]){
            unionArr.push_back(nums2[j]);
        }
        j++;
    }

    return unionArr;
}

int main() {
    vector<int> nums = {1, 0, 2, 7, 0, 4, 5};
    vector<int> nums2 = {1, 2, 7};
    int target = 4;
    var unionArr = unionArray(nums, nums2); 
    //int missingNum = missingNumber(nums);
    //for(int i=  0; i < nums.size(); i++){
        //cout << missingNum << " ";
    //}
    cout << endl;
    return 0;
}