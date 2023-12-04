
//118. 杨辉三角
class Solution {
public:
    vector <vector<int>> generate(int numRows) {
        vector <vector<int>> vv;
        vv.resize(numRows);
        for (size_t i = 0; i < vv.size(); ++i) {
            vv[i].resize(i + 1, 0);
            vv[i].front() = vv[i].back() = 1;
        }
        for (size_t i = 0; i < vv.size(); ++i) {
            for (size_t j = 0; j < vv[i].size(); ++j) {
                if (vv[i][j] == 0) {
                    vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
                }
            }
        }
        return vv;
    }
};