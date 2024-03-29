# Elimination bracket

Attached Python script solves it.

# Description of the problem:
Let 𝑡
be a string of '(' and ')'. The beauty of such a string is the length of its longest subsequence (not necessarily contiguous) that is correctly parenthesised. A string 𝑎
is a subsequence of the string 𝑡
if 𝑎
can be obtained from 𝑡
by the deletion of several (possibly, zero or all) characters. A string is considered to be correctly parenthesised if it satisfies the following conditions:

The string consists solely of the characters '(' and ')'.
The number of opening parentheses '(' is equal to the number of closing parentheses ')'.
For every prefix of the string, the number of opening parentheses is greater than or equal to the number of closing parentheses.
You are given a string 𝑠
consisting of characters '(', ')' and '?'. Replace each '?' by either '(' or ')' such that the beauty of the resulting string 𝑡
is minimized.

## Input
The first line of the input contains a single integer 𝑛
(1≤𝑛≤4⋅10^6) — the length of the input string.

The second line contains the string 𝑠
of length 𝑛 . 𝑠 consists of only characters '(', ')' and '?'.

## Output
Output the minimum possible beauty.

## Examples
### Input
```
10
(((??)))))
```
### Output
```
6
```

### Input
```
22
()??)((?)?)()()?)??)?)
```
### Output
```
10
```

## Note
In the first example, there are four ways of substituting the '?':

* ((((()))))
* (((())))))
* ((()()))))
* ((()))))))

The beauty of these strings is 10
, 8
, 8
, and 6
, respectively.