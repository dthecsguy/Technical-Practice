#include <algorithm>
#include <iostream>
#include <map>

int findInnerVol(int *arr, int n) {
  // arr = given arr
  // n = number of elements

  // return value is the calculated volume

  auto it = std::max_element(arr, arr + n);
  int flag = std::distance(arr, it);
  int v = arr[flag];
  int sum = 0;

  if (!(n == 0 || n == 1)) {
    while (v > 0) {

      int p1 = flag - 1, p2 = flag + 1;
      int lpot = 0, rpot = 0;

      if (flag < n) {

        while (p1 >= 0 || p2 < n) {

          if (p1 >= 0) {
            if (arr[p1] >= arr[flag]) {
              sum += lpot;
              lpot = 0;
            } else {
              lpot++;
            }
            p1--;
          }

          if (p2 < n) {
            if (arr[p2] >= arr[flag]) {
              sum += rpot;
              rpot = 0;
            } else {
              rpot++;
            }
            p2++;
          }
        }
      }

      v--;
      it = std::find(arr, arr + n, v);
      flag = std::distance(arr, it);
    }
  }

  return sum;
}

int main() {
  int arr1[11] = {0, 1, 0, 2, 1, 0, 3, 1, 0, 1, 2};
  int arr2[10] = {0, 1, 2, 1, 0};
  int arr3[10] = {0};
  int arr4[11] = {3, 1, 0, 2, 3, 2, 5, 3, 1, 0, 4};

  int ans = findInnerVol(arr1, 11);
  if (ans == 8) {
    std::cout << "Test for arr1 passed!" << std::endl;
  } else {
    std::cout << "Test for arr1 failed" << std::endl;
  }

  std::cout << "Input: {";
  for (char i = 0; i < 11; i++) {
    std::cout << arr1[i] << ", ";
  }

  std::cout << "}\n";
  std::cout << "Calculated Area: " << ans << std::endl;

  ans = findInnerVol(arr2, 5);
  if (ans == 0) {
    std::cout << "Test for arr2 passed!" << std::endl;
  } else {
    std::cout << "Test for arr2 failed" << std::endl;
  }

  std::cout << "Input: {";
  for (char i = 0; i < 5; i++) {
    std::cout << arr1[i] << ", ";
  }

  std::cout << "}\n";
  std::cout << "Calculated Area: " << ans << std::endl;

  ans = findInnerVol(arr3, 1);
  if (ans == 0) {
    std::cout << "Test for arr3 passed!" << std::endl;
  } else {
    std::cout << "Test for arr3 failed" << std::endl;
  }

  std::cout << "Input: {";
  for (char i = 0; i < 1; i++) {
    std::cout << arr1[i] << ", ";
  }

  std::cout << "}\n";
  std::cout << "Calculated Area: " << ans << std::endl;

  ans = findInnerVol(arr4, 11);
  if (ans == 15) {
    std::cout << "Test for arr4 passed!" << std::endl;
  } else {
    std::cout << "Test for arr4 failed" << std::endl;
  }

  std::cout << "Input: {";
  for (char i = 0; i < 11; i++) {
    std::cout << arr1[i] << ", ";
  }

  std::cout << "}\n";
  std::cout << "Calculated Area: " << ans << std::endl;
}
