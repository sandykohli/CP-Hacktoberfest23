#include <iostream>
#include <vector>

class Knapsack {
public:
    Knapsack(int capacity, const std::vector<int>& weights, const std::vector<int>& values)
        : capacity_(capacity), weights_(weights), values_(values), num_items_(weights.size()) {}

    int solve() {
        // Create a 2D vector to store the results of subproblems
        std::vector<std::vector<int>> dp(num_items_ + 1, std::vector<int>(capacity_ + 1, 0));

        for (int i = 1; i <= num_items_; ++i) {
            for (int w = 0; w <= capacity_; ++w) {
                if (weights_[i - 1] <= w) {
                    dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights_[i - 1]] + values_[i - 1]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        return dp[num_items_][capacity_];
    }

private:
    int capacity_;
    std::vector<int> weights_;
    std::vector<int> values_;
    int num_items_;
};

int main() {
    std::vector<int> weights = {2, 3, 4, 5};
    std::vector<int> values = {3, 4, 5, 6};
    int capacity = 5;

    Knapsack knapsack(capacity, weights, values);
    int max_value = knapsack.solve();

    std::cout << "Maximum value: " << max_value << std::endl;

    return 0;
}