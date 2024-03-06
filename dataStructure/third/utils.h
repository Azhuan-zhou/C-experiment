#include <iostream>
#include <chrono>
using namespace std;
template<typename E>
void printHelp(E A[],int n){
    for(int k=0;k<10;k++)
    {
        cout<<A[k]<<' ';
    }
    cout<<"............"<<endl;
}
template<typename E>
void swap(E A[], int i, int j){
    E temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

template<typename E>
bool prior(E a, E b,int &times){
    times++;
    if(a<b) return true;
    else return false;
}