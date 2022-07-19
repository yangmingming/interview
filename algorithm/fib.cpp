#include <iostream>
#include <string>

using namespace std;

// 递归方法
int fib1(int n){
    if(n == 0 || n == 1){
        return n;
    }

    return fib1(n - 1) + fib1(n - 2);
}

int fib_memo(int* memo,int n){
    if(n == 0 || n == 1){
        return n;
    }

    if(memo[n] != 0){
        return memo[n];
    }

    memo[n] = fib_memo(memo, n-1) + fib_memo(memo, n-2);

    return memo[n];
}

// 备忘录方法
int fib2(int n){
    if(n == 0 || n == 1){
        return n;
    }

    int* memo = new int[n+1];

    return fib_memo(memo, n);
}

// 递推的方式[注意参数为0的情况]
int fib3(int n){
    if(n == 0 || n == 1){
        return n;
    }

    int* dp= new int[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i-2];
    }


    return dp[n];
}

int main() {
    std::cout << "----------" << std::endl;
    std::cout << fib2(40) << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << fib3(40) << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << fib1(40) << std::endl;
    return 0;
}
