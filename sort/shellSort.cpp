/*****************************************************
    > File Name: shellSort.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年03月23日 星期三 17时08分38秒
    > 希尔排序 不稳定
    > 采用一个步长将数组分为几个序列，每个序列使用插入排序
    > 按照一定的规律把步长减小，重复上步操作，直至步长为1
    > 希尔排序的时间复杂度和步长有关，涉及一些数学上未解决的难题，
    > 一般为O(n^1.3)
***************************************************/

#include <iostream>
#include <cstring>
using namespace std;

void shellSort(int length, int a[]);
void change(int &a, int &b);
void shellInsert(int a[], int length, int d);

int main()
{
    int length = 10;
    int a[] = {34, 12, 66, 12, 10, 34, 29, 9, 98, 45};
    shellSort(10, a);
    for(int i=0;i<length;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}

void shellSort(int length, int a[])
{
    int d = length/2;
    while(d>=1){
	shellInsert(a, length, d);
	d = d/2;
    }
}

void shellInsert(int a[], int length, int d)
{
    for(int i=d;i<length;i+=1){
	int j = i;
	while(j >= 0 && a[j] < a[j-d]){
	    change(a[j], a[j - d]);
	}
    }
}

void change(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
