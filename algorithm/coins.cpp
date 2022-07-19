#include <iostream>
#include <string>
#include <vector>

// 为啥 dp 数组中的值都初始化为 amount + 1 呢，因为凑成 amount 金额的硬币数最多只可能等于 amount（全用 1 元面值的硬币），所以初始化为 amount + 1 就相当于初始化为正无穷，便于后续取最小值。为啥不直接初始化为 int 型的最大值 Integer.MAX_VALUE 呢？因为后面有 dp[i - coin] + 1，这就会导致整型溢出。
// https://labuladong.github.io/algo/3/24/67/
int coinChange(std::vector<int>& coins, int amount) {
    if(amount <= 0){
        return 0;
    }

    // amount + 1 个值为amount + 1的元素
    std::vector<int> dp(amount + 1, amount + 1);
    //for(auto i = 0; i < dp.size(); i++){
    //    std::cout << "dp " << i << " = " << dp[i] << std::endl;
    //}

    dp[0] = 0;
    for(auto i = 1; i < amount + 1; i++){
        for(auto coin : coins){
            if(i < coin){
                continue;
            }
            dp[i] = std::min(dp[i], dp[i - coin] + 1);
        }
    }

    return dp[amount] != amount + 1 ? dp[amount] : -1;
}

int main(){
    std::vector<int> coins{1,2,5};

    for(auto i = 0; i < 30; i++){
        std::cout << i << " -> " << coinChange(coins, i) << std::endl;
    }

    return 0;
}
