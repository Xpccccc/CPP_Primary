
// 215. 数组中的第K个最大元素

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        // 建立k个元素的小堆 
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin() + k);

        // 再将后面n-k个元素插入到这个小堆中（大于这个堆里面最小的元素就插入），使得这个堆最后只剩下最大的k个元素
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};