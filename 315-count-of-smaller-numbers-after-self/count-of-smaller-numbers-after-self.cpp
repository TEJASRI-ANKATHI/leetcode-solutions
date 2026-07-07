class Solution {
public:
    vector<int> ans;

    void mergeSort(vector<pair<int,int>> &nums, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        int j = mid + 1;

        for (int i = left; i <= mid; i++) {
            while (j <= right && nums[j].first < nums[i].first)
                j++;
            ans[nums[i].second] += (j - (mid + 1));
        }

        vector<pair<int,int>> temp;
        int i = left;
        j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i].first <= nums[j].first)
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while (i <= mid)
            temp.push_back(nums[i++]);

        while (j <= right)
            temp.push_back(nums[j++]);

        for (int k = left; k <= right; k++)
            nums[k] = temp[k - left];
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        ans.assign(n, 0);

        vector<pair<int,int>> arr;

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        mergeSort(arr, 0, n - 1);

        return ans;
    }
};