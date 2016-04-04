/*****************************************************
    > File Name: theLastStrLen.cpp
    > Author: Yonqi
    > Mail: haidaiheshi@gmail.com 
    > Created Time: 2016年04月03日 星期日 21时30分20秒
    > 计算字符串最后一个单词的长度，单词以空格隔开
    > hello world
    > 样例输出 hello world, 输出 5
    > 知识点：求字符串的长度：size()和length一样返回字符串的字节数，每个字符占一个字节;
    >	      sizeof是一个运算符，返回对象或者类型实际占有的空间
    >	      strlen()是一个函数，从某个下标开始扫描直至遇到第一个'\0'为止返回计数器长度.
***************************************************/
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    int str_len = str.size() - 1;
    int i = 0;
    while(str_len>=0 && str[str_len]!=' '){
	str_len--;
	i++;
    }
    cout << i << endl;
    return 0;
}
