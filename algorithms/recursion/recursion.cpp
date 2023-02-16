#include <iostream>
#include <vector>

// 5 * (4 * (3 * 2))
int findFactorialRecursive(int num) {
  if (num == 2) {
    return num;
  }
  return (num * findFactorialRecursive(num - 1));
}

int findFactorialIterative(int num) {
  int ans = num;
  for (int i = num; i > 1; i--) {
    ans *= i - 1;
  }

  return ans;
}

int fibonacciIterative(int n) { // O(n)
  std::vector<int> arr = {0, 1};

  for (int i = 2; i <= n; i++) {
    arr.push_back(arr[i - 1] + arr[i - 2]);
  }

  return arr[n];
}

int fibonacciRecursive(int n) { // O(2^n)
  if (n < 0) {
    std::cout << "Invalid number" << std::endl;
    return -1;
  }
  if (n < 2) return n;
  return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
  //std::cout << findFactorialRecursive(5) << std::endl;
  //std::cout << findFactorialIterative(5) << std::endl;

  std::cout << fibonacciRecursive(40) << std::endl;

  std::cout << fibonacciIterative(40) << std::endl;
}
