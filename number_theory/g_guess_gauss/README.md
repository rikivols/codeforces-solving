# Guess Gauss

Attached Python script solves it.

# Description of the problem:
Tony and Ben are two classmates who typically get very bored throughout their summer vacation. To cure their boredom, they always try out the silliest games they can come up with. The latest one they played involved choosing a positive integer and calculating the sum of all the terms from 1
up to that integer.

Tony calculated the sum of integers from 1
to 𝑛
(1+2+⋯+𝑛
), while Ben computed the sum of integers from 1
to 𝑚
(1+2+⋯+𝑚
).

A few days later, the two boys recalled their game, but they could no longer remember the values of 𝑛
and 𝑚
, only the difference 𝑑
between the two sums they had initially obtained. They also recall that 𝑚
was larger than 𝑛
.

For a given value of 𝑑
, find all pairs (𝑛,𝑚)
.

## Input
The only line of input contains the integer 𝑑 (2 ≤ 𝑑 ≤ 10^12).

## Output
In the first line print integer 𝑠
— the number of pairs. In the next 𝑠
lines print all pairs (𝑛,𝑚)
. You may print the pairs in any order. Each pair must be printed exactly once, and 𝑚>𝑛
must hold for all pairs.

Under given constraints, it can be proven that 1 ≤ 𝑠 ≤ 10^4.

## Examples
### Input
```
5
```
### Output
```
2
4 5
1 3
```

### Input
```
9
```
### Output
```
3
8 9
3 5
1 4
```