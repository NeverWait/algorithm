/*****************************************************
    > File Name: quickSort.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年03月22日 星期二 20时01分50秒
    > 快速排序 不稳定
    > 采用分治法，首先取一个基准数，将大于它的元素放到右边，小于它的元素放到左边
    > 重复上一步直至剩余一个元素。最差和平均时间复杂度为O(n^2)和O(nlgn),空间复杂度O(n*lgn)
***************************************************/

#include <iostream>
#include <cstring>
using namespace std;

void quickSort(int left, int right, int a[]);

int main()
{
    int length = 10;
    int a[] = {34, 12, 66, 12, 10, 34, 29, 9, 98, 45};
    quickSort(0, 9, a);
    for(int i=0;i<length;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}

void quickSort(int left, int right, int a[])
{
    if(left < right){
	int l = left, r = right, x = a[l];
	while(l < r){
	    while(l < r && a[r] > x){
		r--;
	    }
	    if(l < r){
		a[l++] = a[r];
	    }
	    while(l < r && a[l] < x){
		 l++;
	    }
	    if(l < r){
		a[r--] = a[l];
	    }
	}
	a[l] = x;
	quickSort(left, l-1, a);
	quickSort(l+1, right, a);
    }
}
