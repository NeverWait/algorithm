/*****************************************************
    > File Name: decToBinary.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年03月27日 星期日 21时57分56秒
    > 十进制转化为二进制
    > 原理：把需要转化的数字A除以2，将余数保存到一个数组， 将A等于除以2后的商；
    >	    重复上述操作，直至商为1，将1保存到数组中；
    >	    将数组倒序输出即为转换后的二进制
***************************************************/

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int x;
    int data[20];
    cout << "请输入需要转换的数：" << endl;
    cin >> x;
    int i = 0;
    if(x == 0 || x == 1){
	data[i] = x;
    }
    else{
	while(x > 1){
	    data[i] = x%2;
	    x = x/2;
	    i++;
	}
	data[i] = 1;
    }
    for(int j=i;j>=0;j--){
	cout << data[j];
    }
    cout << endl;
    return 0;
}
