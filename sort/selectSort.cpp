/*****************************************************
    > File Name: selectSort.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年03月23日 星期三 16时28分08秒
    > 选择排序 不稳定
    > 每次都从无序序列中选取最小的值放入有序序列的最后，
    > 最差和平均时间复杂度都是O(n^2)
***************************************************/

#include <iostream>
#include <cstring>
using namespace std;

void selectSort(int length, int a[]);
void change(int &a, int &b);

int main()
{
    int length = 10;
    int a[] = {34, 12, 66, 12, 10, 34, 29, 9, 98, 45};
    selectSort(length, a);
    for(int i=0;i<length;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}

void selectSort(int length, int a[])
{
    for(int j=0;j<length;j++){
	int min_el = j;
	for(int i=j+1;i<length;i++){
	    if(a[i] < a[min_el]){
		min_el = i;
	    }
	}
	if(a[min_el] != a[j]){
	    change(a[min_el], a[j]);
	}
    }
}

void change(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
