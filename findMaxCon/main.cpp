#include <iostream>
#include <algorithm>
#include <map>

#define nBRUTE


void findMaxCon(int* arr, int* ppair, int n){      // arr = given arr, ppair = returned pair, sum =  n = number of elements
  
  if(!(n == 0 || n == 1)){

    int maxArea = 0;

    #ifdef BRUTE
    
      for(int p1 = 0; p1 < n - 1; p1++){
        for(int p2 = p1 + 1; p2 < n; p2++){
          int area = std::min(arr[p1], arr[p2]) * (p2 - p1);

          if(area > maxArea){
            maxArea = area;
            ppair[0] = p1;
            ppair[1] = p2;
          } 
        }
      }

    #else
      int a = 0;
      int b = n - 1;
    
      while(a <= b){

        int area = std::min(arr[a], arr[b]) * (b - a);

        if(area > maxArea){
          maxArea = area;
          ppair[0] = a;
          ppair[1] = b;
        }

        if(arr[a+1] < arr[b-1]){
          a++;
        }
        else{
          b--;
        }
      }
    
    #endif
  }
}

int main() {
  int arr1[10] = {1, 2, 3, 4, 5};
  int arr2[10] = {0};
  int arr3[10] = {2};
  int ppair[2] = {-1, -1};


  findMaxCon(arr1, ppair, 5);
  if(ppair[0] != -1){
    std::cout << "Test for arr1 passed!" << std::endl;
  }
  else{
    std::cout << "Test for arr1 failed" << std::endl;
  }

  std::cout << "Input: {";
  for (char i = 0; i < 5; i++){
    std::cout << arr1[i] << ", ";
  }

  std::cout << "}\n";
  std::cout << "Pair is: {" << ppair[0] << ", " << ppair[1] << "}" << std::endl;

  
}
