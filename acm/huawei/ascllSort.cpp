/*****************************************************
    > File Name: ascllSort.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年04月04日 星期一 14时09分46秒
    > 输入字符串安照ascll码排序，该算法使用的是冒泡排序，时间复杂度为O(n^2)
***************************************************/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int s_len = s.size();
    int i = 0;
    char temp;
    bool flag = true;
    while(flag){
	flag = false;
	for(int i=0;i<s_len-1;i++){
	    if(s[i]>s[i+1]){
		temp = s[i];
		s[i] = s[i+1];
		s[i+1] = temp;
		flag = true;	
	    }
	}
    }
    cout << s << endl;
    return 0;
}
