#include <iostream>
#include <string.h>
using namespace std;
void turn(char s[], int begin, int end)
{
    char temp;
    while(begin < end){
        temp = s[begin];
        s[begin] = s[end];
        s[end] = temp;
        begin++;
        end--;
    }
}
void overturn(char s[], int n)
{
    // 首先实现字符串的全部翻转
    int index = 0, begin = 0, end = n - 1;
    turn(s, begin, end);
    end = 0;
    while(end <= n){
        if(s[end]==' ' || s[end]=='\0'){
            index = end;
            turn(s, begin, end-1);  // 将每个翻转
            begin = index + 1;
            end = index + 1;
        } else {
            end += 1;
        }
    }
}
int main(void)
{
    char s[100];
    int s_len = 0;
    cout << "enter string\n";
    cin.get(s,100);
    s_len = strlen(s);
    overturn(s, s_len);
    cout << s;
}
