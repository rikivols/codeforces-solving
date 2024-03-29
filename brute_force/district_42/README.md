# District 42

This problem's solution in Python was too slow, so I had to make a new code in C++ to solve it.

Attached c++ script solves it.
inp.txt file contains test inputs, you can run the script with 
`./a.out < inp.txt` to test it.

# Description of the problem:
In the mystical land of District 42, where life, the universe, and everything is just a little bit odd, residents ponder a curious question. They observe the sequence of numbers 1,2,3,…,𝑛
without leading zeros or commas. Their quest is to determine how many times the mystical number 42
appears within this sequence.

## Input
The only line of the input contains a single integer 𝑛
(1 ≤ 𝑛 ≤ 2⋅10^5), the length of the sequence.

## Output
Print one integer — number of times 42
appears.

## Examples
```
>24
0

>25
1

>250
9
```

## Note
In the second example, the sequence is 1234567891011…2425
, at which point 42 appears for the first time.