/*****************************************************
    > File Name: createArrayB.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年03月28日 星期一 21时37分20秒
    > 题目：给定一个数组a[N],我们希望构造数组b[N]，其中b[i]=a[0]*a[1]*...*a[N-1]/a[i]
    > 在构造过程：不允许使用除法；
    > 要求：O(1)空间复杂度和O(n)时间复杂度；
    > 除遍历计数器与a[N] b[N]外，不可使用新的变量(包括栈临时变量、对空间和全局静态变量等.
***************************************************/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int length = 10;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int b[10];
    b[0] = 1;
    for(int i=1;i<10;i++){
	b[i] = b[i-1] * a[i-1];
    }
    for(int j=length-1;j>0;j--){
	b[j] = b[0] * b[j];
	b[0] = b[0] * a[j];
    }
    cout << "b的结果为：";
    for(int i=0;i<length;i++){
	cout << b[i] << ' ';
    }
    cout << endl;
    return 0;
}
