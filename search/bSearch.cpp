/*****************************************************
    > File Name: bSearch.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年03月26日 星期六 20时10分26秒
    > 二分查找 时间复杂度O(logn)
    > 初始数列必须有序
***************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int binarySearch(int temp,int left, int right, int a[]);

int main()
{
    int length = 10;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    cout << "enter your number:" << endl;
    int temp;
    cin >> temp;
    int re = binarySearch(temp, 0, length, a);
    cout << re << endl;
    return 0;
}

int binarySearch(int temp, int left, int right ,int a[])
{
    int l = left;
    int r = right;
    int mid = (l + r)/2;
    while(a[mid] != temp && l < r){
	if(a[mid] > temp){
	    r = mid - 1;
	    mid = (r + l)/2;
	}
	else{
	    l = mid + 1;
	    mid = (l + r)/2;
	}
    }
    if(a[mid] == temp){
	return mid;
    }
    else{
	return -1;
    }
}
