# A. 2023

time limit per test
1 second
memory limit per test
256 megabytes
input
standard input
output
standard output

In a sequence $a$, whose product was equal to $2023$, $k$ numbers were removed, leaving a sequence $b$ of length $n$. Given the resulting sequence $b$, find any suitable sequence $a$ and output which $k$ elements were removed from it, or state that such a sequence could not have existed.

Notice that you are not guaranteed that such array exists.

在一个乘积等于 $$$2023$$$ 的序列 $$$a$$$ 中，去掉了 $$$k$$$ 个数字，剩下一个长度为 $$$n$$$ 的序列 $$$b$$$ 。给定所得到的序列 $$$b$$$ ，找出任何合适的序列 $$$a$$$ 并输出从中删除了哪些 $$$k$$$ 元素，或者指出这样的序列不可能存在。

请注意，我们并不保证存在这样的序列。

## Input

Each test consists of several test cases. The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. This is followed by a description of the test cases.

The first line of each test case contains two integers $n$ ($1 \le n, k \le 5$) — the size of sequence $b$ and the number of numbers removed from sequence $a$.

The second line contains $n$ integers $b_1,b_2, \ldots,b_n$ ($1 \leq b_i \leq 2023$) — the remaining sequence. The values of $b_i$ might not be divisors of $2023$.

输入

每个测试由多个测试用例组成。第一行包含一个整数 $t$ ( $1 \le t \le 100$ ) - 测试用例的个数。随后是测试用例的描述。

每个测试用例的第一行包含两个整数 $n$ ( $1 \le n, k \le 5$ ) - 序列 $b$ 的大小和从序列 $ a $ 中删除的数字个数。

第二行包含 $n$ 个整数 $b_1$,$b_2$,…$b_n$ ( $1\leq{b_i}\leq 2023$ )--剩余序列。 $b_i$的值可能不是 $2023$ 的除数。

## Output

For each test case, output "YES" if the sequence $a$ exists, and in the following line output $k$ non-negative integers that were removed from the sequence $a$. If the sequence $$

 does not exist, output "NO" in a single line.

You can output the answer in any case (uppercase or lowercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive answers.

输出

对于每个测试用例，如果序列 $a$ 存在，则输出 "是"，并在下一行输出从序列 $a$ 中删除的非负整数 $k$ 。如果序列 $a$ 不存在，则单行输出 "NO"。

可以用任何大小写(大写或小写)输出答案。例如，字符串 "yEs"、"yes"、"Yes "和 "YES "将被识别为正答案。

## Example

### input

```
7
2 2
5 2
3 1
7 17 7
4 2
1 289 1 1
3 1
7 17 17
1 1
289
1 1
2023
1 3
1
```

### output

```
NO
NO
YES
7 1
YES
1
YES
7
YES
1
YES
7 17 17
```

## Note

In third test case product is equal to $289 \cdot 7 = 2023$.

In fourth test case product is already equal to $2023$.

In seventh test case product is equal to $7 \cdot 17 \cdot 17 = 2023$.

注意

在第三个测试用例中，乘积等于 $289 \cdot 7 = 2023$ 。

在第四个测试用例中，乘积已等于 $2023$ 。

在第七个测试用例中，乘积等于 $7 \cdot 17 \cdot 17 = 2023$。

