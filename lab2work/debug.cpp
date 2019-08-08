//Rakshith Raghu,rr5de, 9/11/2018, debug.cpp
#include <iostream>
using namespace std;

const int MAX = 5;

double GetAverage(int nIn[], int nMax);
int GetMax(int nIn[], int nMax);

int main(){
  int nValues[MAX];
  int nCount;

  cout <<"Enter five numbers: "<<endl;

  for( nCount = 0; nCount<MAX; nCount++){
    cout << "Enter the next number : ";
    cin >> nValues[nCount];
  }

  for ( nCount = 0; nCount < MAX; nCount++){
    cout <<"Value [" << nCount+1 << "] is : " << nValues[nCount] << endl;
  }

  cout << "The average is " << GetAverage(nValues,MAX)<<endl;

  cout << "The max is " <<GetMax(nValues, MAX) << endl;

  return 0;
}

double GetAverage(int nIn[], int nMax){
  double temp = 0.0;
  for(int i = 0; i <  nMax; i++){
    temp += nIn[i];
  }
  temp /= nMax;

  return temp;
}

int GetMax(int nIn[], int nMax){
  int nBiggest = nIn[0];
  for(int i = 1; i < nMax; i++){
    if(nBiggest < nIn[i]){
      nBiggest = nIn[i];
    }
  }

  return nBiggest;
}
