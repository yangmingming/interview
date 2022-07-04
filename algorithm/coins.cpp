#include <iostream>
#include <string>
#include <vector>

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
