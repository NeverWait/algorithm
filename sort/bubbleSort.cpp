/*****************************************************
    > File Name: bubbleSort.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年03月22日 星期二 09时56分01秒
    > 冒泡排序，稳定
    > 每次都会有一个元素找到最终位置，最坏和平均复杂度为O(n^2)
***************************************************/

#include <iostream>
#include <cstring>
using namespace std;
void bubbleSort(int length, int a[]);
void change(int &a, int &b);
int main()
{

    int length = 10;
    int a[] = {34, 12, 66, 12, 10, 34, 29, 9, 98, 45};
    bubbleSort(10, a);
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

void bubbleSort(int num, int a[])
{
    for(int i=1;i<num;i++){
	for(int j=0;j<num-i;j++){
	    if(a[j] > a[j+1]){
		change(a[j], a[j+1]);
	    }
	}
    }
}
