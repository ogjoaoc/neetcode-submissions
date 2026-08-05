class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int N = numbers.size();
        int l = 0, r = N - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum > target) {
                r--;
            } else if (sum < target) {
                l++;
            } else {
                return vector<int>({l + 1, r + 1});
            }
        }   
    }
};
