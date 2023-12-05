
//JZ39 数组中出现次数超过一半的数字
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        // write code here
        //摩尔投票法
        int candidate = numbers[0];
        int count = 1;

        for(int i = 1; i<numbers.size(); ++i){
            if(numbers[i] == candidate)
                ++count;
            else
                --count;

            if(count == 0){
                //重新确定候选
                candidate = numbers[i];
                count = 1;
            }
        }

        return candidate;
    }
};