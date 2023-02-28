#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &out) {
  int last = out.size();
  while (last != 0) {
    for (int i = 0; i < last - 1; i++) {
      if (out[i] > out[i + 1]) {
        int tmp = out[i];
        out[i] = out[i + 1];
        out[i + 1] = tmp;
      }
    }
    last--;
  }
}

int main() {
  std::vector<int> in = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
  bubbleSort(in);

  for (int val : in) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  return 0;
}
