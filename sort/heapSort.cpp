/*****************************************************
    > File Name: heapSort.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年03月23日 星期三 20时07分47秒
    > 堆排序，不稳定，大根堆节点的值大于它的任何子节点，小根堆的值小于它的任何子节点
    > 堆一般用数组表示，它的左孩子(如果存在)坐标为2n+1,右孩子(如果有)坐标为2n+2;
    > 每次插入堆都是先放在最后，然后再依次调整；堆每次删除都是删除第0个数据
    > 所以删除时先将最后一个值赋给根节点，再逐步调整
    > 时间复杂度为O(nlogn)
***************************************************/

#include <iostream>
#include <cstring>
using namespace std;

void heapSort(int length, int a[]);
void change(int &a, int &b);

int main()
{
    int length = 10;
    int a[] = {34, 12, 66, 12, 10, 34, 29, 9, 98, 45};
    heapSort(length, a);
    for(int i=0;i<length;i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}

void heapSort(int length, int a[])
{
    for(int i=1;i<length;i++){
	int j=i;
	while(j>0 && a[j]<a[(j-1)/2]){
	    change(a[j], a[(j-1)/2]);
	    j = (j-1)/2;
	}
    }
}

void change(int &a, int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
