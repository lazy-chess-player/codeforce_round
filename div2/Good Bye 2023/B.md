# B. Two Divisors

time limit per test
1 second
memory limit per test
256 megabytes
input
standard input
output
standard output

A certain number $1 \leq x \leq 10^9$ is chosen. You are given two integers $a$ and $b$, which are the two largest divisors of the number $x$. At the same time, the condition $1 \leq a < b < x$ is satisfied.

For the given numbers $a$, $b$, you need to find the value of $x$.

† The number $y$ is a divisor of the number $x$ if there is an integer $k$ such that $x = y \cdot k$.

选择某个数字 $1 \leq x \leq 10^9$ 。给你两个整数 $a$ 和 $b$ ，它们是数 $x$ 的两个最大除数。同时满足条件 $1 \leq a < b < x$ 。

对于给定的数 $a$ , $b$ , 你需要求出 $x$ 的值。

† 如果有整数 $k$ 使得 $x = y \cdot k$ 是整数 $x$ 的整除，那么数 $y$ 是整数 $x$ 的整除。

## Input

Each test consists of several test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Then follows the description of the test cases.

Each test case's only line contains two integers $a$, $b$ ($1 \leq a < b \leq 10^9$).

It is guaranteed that $a$, $b$ are the two largest divisors for some number $1 \leq x \leq 10^9$.

输入

每个测试由多个测试用例组成。第一行包含一个整数 $t$ ( $1 \leq t \leq 10^4$ ) - 测试用例的数量。然后是测试用例的描述。

每个测试用例的唯一一行包含两个整数 $a$ 、 $b$ ( $1 \leq a < b \leq 10^9$ )。

保证 $a$ , $b$ 是某个数字 $1 \leq x \leq 10^9$ 的两个最大除数。

## Output

For each test case, output the number $x$, such that $a$ and $b$ are the two largest divisors of the number $x$.

If there are several answers, print any of them.

输出

对于每个测试用例，输出数字 $x$ ，使得 $a$ 和 $b$ 是数字 $x$ 的两个最大除数。

如果有多个答案，则打印其中任意一个。

## Example

### input

```
8
2 3
1 2
3 11
1 5
5 10
4 6
3 9
250000000 500000000
```

### output

```
6
4
33
25
20
12
27
1000000000
```

## Note

For the first test case, all divisors less than 6 are equal to [1,2,3], among them the two largest will be 2 and 3.

For the third test case, all divisors less than 33 are equal to [1,3,11], among them the two largest will be 3 and 11.

For the fifth test case, all divisors less than 20 are equal to [1,2,4,5,10], among them the two largest will be 5 and 10.

For the sixth test case, all divisors less than 12 are equal to [1,2,3,4,6], among them the two largest will be 4 and 6.

备注

在第一个测试案例中，所有小于 $6$ 的除数都等于 $[1, 2, 3]$ ，其中最大的两个除数是 $2$ 和 $3$ 。

在第三个测试情形中，所有小于 $33$ 的除数都等于 $[1, 3, 11]$ ，其中最大的两个除数是 $3$ 和 $11$ 。

在第五种测试情形中，所有小于 $20$ 的除数都等于 $[1,2,4,5,10]$，其中最大的两个将是 $5$ 和 $10$ 。

对于第六种测试情况，所有小于 $12$ 的除数都等于 $[1, 2, 3, 4, 6]$ ，其中最大的两个除数是 $4$ 和 $6$ 。