#include <iostream>
#include <string>
#include <vector>

using namespace std;

// a[i] != b[j] -> max = max(dp[i - 1][j], dp[i][j-1] )
// a[i] == b[j] -> dp[i][j] = dp[i-1][j-1] + 1
int longestCommonSubsequence(string text1, string text2) {
    // 边界初始化为0
    int m = text1.size();
    int n = text2.size();
    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1));
    for(int i = 1; i <= m; i++){
        // 取值下标需要-1
        char c1 = text1[i - 1];
        for(int j = 1; j <= n; j++){
            char c2 = text2[j - 1];

            if(c1 == c2){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
        std::cout << longestCommonSubsequence("abc", "def") << std::endl;
        std::cout << longestCommonSubsequence("abcde", "ace") << std::endl;
        std::cout << longestCommonSubsequence("abc", "abc") << std::endl;

    return 0;
}
