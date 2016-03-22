/*****************************************************
    > File Name: insertSort.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年03月22日 星期二 10时44分21秒
    > 插入排序 稳定
    > 向有序的序列中插入新的元素，直至找到合适的位置
    > 最差和平均的时间复杂度均为O(n^2)
***************************************************/

#include <iostream>
#include <cstring>
using namespace std;

void insertSort(int length, int a[]);
void change(int &a, int &b);

int main()
{
    int length = 10;
    int a[] = {34, 12, 66, 12, 10, 34, 29, 9, 98, 45};
    insertSort(10, a);
    for(int i=0;i<length;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}

void change(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void insertSort(int length, int a[])
{
    for(int i=1;i<length-1;i++){
	int j = i;
	while(j>0 && a[j]<a[j-1]){
	    change(a[j],a[j-1]);
	    j--;
	}
    }
}

