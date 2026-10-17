class Solution {
public:
bool canDistribute(int n, const std::vector<int>& quantities, int k) {
        int storesNeeded = 0;
        for (int q : quantities) {
            storesNeeded += (q + k - 1) / k;
            if (storesNeeded > n) {
                return false;
            }
        }
        return storesNeeded <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *std::max_element(quantities.begin(), quantities.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canDistribute(n, quantities, mid)) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }

        return ans;
    }
};