#include <iostream>
#include <string>
#include <vector>

/*
 *                                                                    
 *                                                                    ~                                                                                                                                在一个平行宇宙中，麦当劳的麦乐鸡块分为7块装、13块装和29块装。有一天，你的老板让你出去购买正好为n块(0 < n <= 10000)的麦乐鸡块回来，请提供一个算法判断是否可行。

 */

bool IsValid(std::vector<int> &chicken, int target){
    std::vector<int> dp;
    for(int i = 0; i < target + 1; i++){
        dp.push_back(target+1);
    }

    dp[0] = 0;

    for(int i= 1; i <= target; i++){
        for(auto v : chicken){
            if(i - v < 0){
                continue;
            }

            dp[i] = std::min(dp[i - v] + 1, dp[i]);
        }
    }

    return (dp[target] == (target + 1)) ? false : true;
}
int main(){
    std::vector<int> chicken{7, 13, 29};
    for(int i = 0; i < 30; i++){
        std::cout << i << ", " << IsValid(chicken, i) << std::endl;
    }
    return 0;
}
