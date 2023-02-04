#include <iostream>

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

int main() {
  std::cout << findFactorialRecursive(5) << std::endl;
  std::cout << findFactorialIterative(5) << std::endl;
}
