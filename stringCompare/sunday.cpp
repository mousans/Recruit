#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 返回值：如果匹配则返回true，不匹配则返回false
 * s：原串
 * target:被匹配的串
 * index:原串的开始下标
 * */
bool match(string s, string target, int index)
{
    for (int i = 0; i < target.length(); i++)
    {
        if (s[index + i] != target[i])
        {
            return false;
        }
    }
    return true;
}



/**
 * 算法思想：每次尽量将原串的当先下表往后移动，如果s[index+m]在原串中找不到则直接移动m+1，将index移动到index+m+1，如果原串能找到，则移动index将s和p对齐继续比较
 * 返回值：如果找到匹配串，则返回匹配串在s中的第一个字符的下标，否则返回-1
 * s:原串
 * target:希望匹配的到的串
 * */
int sunday(string s, string target)
{
    int n = s.length();
    int m = target.length();
    unordered_map<char, int> shift;
    for (int i = 0; i < n; i++)
    {
        shift[s[i]] = m + 1;
    }
    for (int i = 0; i < m; i++)
    {
        shift[target[i]] = m - i;
    }
    int index = 0;
    while (index < n - m + 1)
    {
        if (match(s, target, index))
        {
            return index;
        }
        index += shift[s[index + m]];
    }
    return -1;
}

int main()
{
    int res = sunday("gergregeagbb", "bb");
    cout << res << endl;
    getchar();
    return 1;
}