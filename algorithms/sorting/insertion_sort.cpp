#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &out) {
  int key;
  for (int i = 1; i < out.size(); i++) {
    key = out[i];
    int j = i - 1;

    while (j >= 0 && out[j] > key) {
      out[j + 1] = out[j];
      j = j - 1;
    }
    out[j + 1] = key;
  }
}

int main() {
  std::vector<int> in = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
  insertionSort(in);

  for (int val : in) {
    std::cout << val << ' ';
  }
  std::cout << std::endl;
}
