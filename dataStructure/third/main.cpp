#include "RadixSort.h"
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;
int main() {
    const int n = 10000;
    int bestCase[n];
    for (int i = 0; i < n; i++) {
        bestCase[i] = i;
    }
    int worstCase[n];
    for (int i = 0; i < n; i++) {
        worstCase[i] = n - i-1;
    }
    int averageCase[n];
    for (int i = 0; i < n; i++) {
        averageCase[i] = i;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(averageCase, averageCase + n, g);
    cout<<"--------------������-------------"<<endl;
    radixSort<int>(bestCase,n);
    cout<<"--------------����-------------"<<endl;
    radixSort<int>(worstCase,n);
    cout<<"--------------ƽ�����-------------"<<endl;
    radixSort<int>(averageCase,n);
}


