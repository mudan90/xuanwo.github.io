title: POJ 2192 Zipper
date: 2014-08-16 14:35:52
tags: [ACM, POJ, C/C++, 字符串, DP]
categories: Exercise
toc: true
---
# 题目
源地址：http://poj.org/problem?id=2192

# 理解
动态规划的核心方程：b.dp[i][j-1]==1&&str2[j-1]==str3[i+j-1]

<!-- more -->

# 代码
```
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;

char st1[205];
char st2[205];
char st3[410];
int dp[205][205];

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int k = 0;
    while (n--)
    {
        k++;
        scanf("%s %s %s", st1, st2, st3);
        getchar();
        int k1 = strlen(st1);
        int k2 = strlen(st2);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i <= k1; i++)
        {
            for (int j = 0; j <= k2; j++)
            {
                if (i >= 1 && dp[i - 1][j] == 1 && st1[i - 1] == st3[i + j - 1])
                    dp[i][j] = 1;
                if (j >= 1 && dp[i][j - 1] == 1 && st2[j - 1] == st3[i + j - 1])
                    dp[i][j] = 1;
            }
        }
        if (dp[k1][k2] == 1)
            printf("Data set %d: yes\n", k);
        else
            printf("Data set %d: no\n", k);
    }
    return 0;
}
```

# 更新日志
- 2014年08月16日 已AC。