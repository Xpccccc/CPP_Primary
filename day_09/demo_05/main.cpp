

//26. 删除有序数组中的重复项
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }

        int i = 0; // 慢指针，指向当前不重复的元素位置
        for (int j = 1; j < n; ++j) {
            if (nums[j] != nums[i]) {
                ++i;
                nums[i] = nums[j]; // 将不重复的元素放到慢指针的位置
            }
        }

        return i + 1; // 返回不重复元素的个数
    }
};