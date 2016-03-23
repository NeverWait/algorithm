/*****************************************************
    > File Name: mergeSort.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年03月22日 星期二 16时29分26秒
    > 归并排序 稳定 最坏情况和平均情况的时间复杂度为O(nlogn)
    > 将一个序列拆分为两个子序列，再将两个子序列继续拆分为两个序列
    > 以此类推直至剩余一个元素。认为该元素有序
    > 再依次两两合并
***************************************************/

#include <iostream>
#include <cstring>
using namespace std;

void mergeSort(int length, int a[]);
void splitArray(int a[], int temp[], int first, int last);
void mergeArray(int a[], int first, int mid, int last, int temp[]);

int main()
{
    int length = 10;
    int a[] = {34, 12, 66, 12, 10, 34, 29, 9, 98, 45};
    mergeSort(10, a);
    for(int i=0;i<length;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}

void mergeSort(int length, int a[])
{
    int *p = new int[length];
    if(p == NULL){
	return;
    }
    splitArray(a, p,  0, length-1);
    delete[] p;
    return;
}

void splitArray(int a[], int temp[], int first, int last)
{
    if(first >= last){
	return;
    }
    int mid = (first + last)/2;
    splitArray(a, temp, first, mid);
    splitArray(a, temp, mid+1, last);
    mergeArray(a, first, mid, last, temp);
}

void mergeArray(int a[], int first, int mid, int last, int temp[])
{
    int f = first, m = mid, n = mid + 1, l = last, t = 0;
    while(f <= m && n <= l){
	if(a[f] < a[n]){
	    temp[t++] = a[f++];
	}
	else{
	    temp[t++] = a[n++];
	}
    }
    while(f <= m){
	temp[t++] = a[f++];
    }
    while(n <= l){
	temp[t++] = a[n++];
    }
    for(int i=0;i<t;i++){
	a[first+i] = temp[i];
    }
}
