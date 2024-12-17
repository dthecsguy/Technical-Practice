#include <iostream>
#include <algorithm>
void findSumPair(int* arr, int* ppair, int sum, int n){      // arr = given arr, ppair = returned pair, sum = desired sum, n = number of elements

  if(!(n == 0 || n == 1)){
    int desNum;
    for(int p1 = 0; p1 < n - 1; p1++){
  
      desNum = sum - arr[p1];
      
      for(int p2 = 1; p2 < n; p2++){
        if(arr[p2] == desNum){
          *ppair = p1;
          *(ppair + 1) = p2;
          return ppair;
        }
      }
    }
  }
  return ppair;
}
int main() {
  int arr1[5] = {1, 2, 3, 4, 5};

  std::cout << sizeof(arr1) / sizeof(arr1[0]) << std::endl;
  int arr2[0] = {};
  int arr3[1] = {2};
  int ppair[2] = {-1, -1};


  findSumPair(arr1, ppair, 8, sizeof(arr1) / sizeof(arr1[0]));
  if(ppair[0] != -1){
    std::cout << "Test for arr1 passed!" << std::endl;

    std::cout << "Input: {";
    for (char i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++){
      std::cout << arr1[i] << ", ";
    }

    std::cout << "}\n";
    std::cout << "Pair is: {" << ppair[0] << ", " << ppair[1] << "}" << std::endl;
    
  }
  else{
    std::cout << "Test for arr1 failed" << std::endl;
  }


  findSumPair(arr2, ppair, 1, sizeof(arr2) / sizeof(arr2[0]));
  if(ppair[0] == -1){
    std::cout << "Test for arr2 passed!" << std::endl; 
  }
  else{
    std::cout << "Test for arr2 failed" << std::endl;
  }


  findSumPair(arr3, ppair, 1, sizeof(arr3) / sizeof(arr3[0]));
  if(ppair[0] == -1){
    std::cout << "Test for arr3 passed!" << std::endl; 
  }
  else{
    std::cout << "Test for arr3 failed" << std::endl;
  }


  findSumPair(arr1, ppair, 1, sizeof(arr1) / sizeof(arr1[0]));
  if(ppair[0] == -1){
    std::cout << "Test for arr1 passed!" << std::endl; 
  }
  else{
    std::cout << "Test for arr1 failed" << std::endl;
  }
}
