#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int& len){
    int* n = new int[len+1];
    if(idx>len){
        for(int i=0; i<len; i++)n[i]=arr[i];
        n[idx]=num;
    }
    else{
        for(int i=0; i<idx; i++)n[i]=arr[i];
    n[idx]=num;
    for(int i=idx+1; i<len+1; i++)n[i]=arr[i-1];
}
len++;
for(int i=0; i<len; i++)arr[i]=n[i];
delete[] n;
}

void erase(int idx, int arr[], int& len){
    len--;
    int* n = new int[len];
    for(int i=0; i<idx; i++)n[i]=arr[i];
    for(int i=idx; i<len+1; i++)n[i]=arr[i+1];
    for(int i=0; i<len; i++)arr[i]=n[i];
    delete[] n;
}

void printArr(int arr[], int& len){
  for(int i = 0; i < len; i++) cout << arr[i] << ' ';
  cout << "\n\n";
}

void insert_test(){
  cout << "***** insert_test *****\n";
  int arr[10] = {10, 20, 30};
  int len = 3;
  insert(3, 40, arr, len); // 10 20 30 40
  printArr(arr, len);
  insert(1, 50, arr, len); // 10 50 20 30 40
  printArr(arr, len);
  insert(0, 15, arr, len); // 15 10 50 20 30 40
  printArr(arr, len);
}

void erase_test(){
  cout << "***** erase_test *****\n";
  int arr[10] = {10, 50, 40, 30, 70, 20};
  int len = 6;
  erase(4, arr, len); // 10 50 40 30 20
  printArr(arr, len);
  erase(1, arr, len); // 10 40 30 20
  printArr(arr, len);
  erase(3, arr, len); // 10 40 30
  printArr(arr, len);
}

int main(void) {
  insert_test();
  erase_test();
}
