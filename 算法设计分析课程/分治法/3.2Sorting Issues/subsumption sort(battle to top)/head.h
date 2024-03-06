#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
void merge(int a[], int low, int mid, int high);//合并
void mergesort(int a[], int n);//长度
void print(int a[], int n); 
void mergepass(int a[], int length, int n);//二路归并
