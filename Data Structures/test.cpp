#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int j = n - 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == val) {
                while (nums[j] == val) {
                    nums[j] = 0;
                    j--;
                    if(j < 0) {
                        break;
                    }
                }
                if(j < 0) {
                    break;
                }
                nums[i] = nums[j];
                nums[j] = 0;
                j--;
            }
        }
        return j + 1;
    }
};

int main(){
    vector<int> nums = {4, 5};
    int val = 5;
    Solution s;
    cout << s.removeElement(nums, val) << endl;
    return 0;
}
