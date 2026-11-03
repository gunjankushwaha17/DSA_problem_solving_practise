class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 3;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (find(result.begin(), result.end(), nums[i]) != result.end()) {
                continue;
            }

            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }

            if (count > threshold) {
                result.push_back(nums[i]);
            }
            if (result.size() == 2) break;
        }

        return result;
    }
};