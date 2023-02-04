#include <iostream>

int findFactorialRecursive(int num) {
  int ans;
  if (num == 2) {
    return num;
  }
  else {
    ans = num * findFactorialRecursive(num - 1);
  }

  return ans;
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