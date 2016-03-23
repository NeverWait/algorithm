/*****************************************************
    > File Name: radixSort.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年03月22日 星期二 19时08分08秒
    > 基数排序 稳定
    > 按照元素每位的值装入相应的桶
    > 收集元素
    > 重复上两步直至走完所有的位
    > 
***************************************************/

#include <iostream>
#include <cstring>
using namespace std;

void radixSort(int length, int a[]); 
int maxBit(int length, int a[]);
int temp[10];
int count[10];

int main()
{
    int length = 10;
    int a[] = {34, 12, 66, 12, 10, 34, 29, 9, 98, 45};
    radixSort(10, a);
    for(int i=0;i<length;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}

void radixSort(int length, int a[])
{
    int d = maxBit(length, a);
    int r = 1;
    for(int j=0;j<d;j++){
	for(int i=0;i<10;i++){
	    count[i] = 0;
	}
	for(int i=0;i<length;i++){
	    int k = a[i]/r;
	    int q = k%10;
	    count[q]++;
	}
	for(int i=1;i<10;i++){
	    count[i] += count[i-1];
	}
	for(int i=length-1;i>=0;i--){
	    int p = a[i]/r;
	    int s = p%10;
	    temp[count[s]-1] = a[i];
	    count[s]--;
	}
	for(int i=0;i<length;i++){
	    a[i] = temp[i];
	}
	r = r*10;
    }
}

int maxBit(int length, int a[])
{
    int d = 1;
    for(int i=0;i<length;i++){
	int temp = 1;
	int p = 10;
	while(a[i]/p){
	    temp++;
	    p = p * 10;
	}
	if(temp > d){
	    d = temp;
	}
    }
    return d;
}
