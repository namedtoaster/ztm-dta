#include <iostream>
#include <vector>

void selectionSort(std::vector<int> &out) {
  for (int i = 0; i < out.size(); i++) {
    int min = i;
    int tmp = out[i];

    for (int j = i + 1; j < out.size(); j++) {
      if (out[j] < out[min]) {
        min = j;
      }
    }

    out[i] = out[min];
    out[min] = tmp;
  }
}

int main() {
  std::vector<int> in = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
  selectionSort(in);
  for (int val : in) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
  return 0;
}
