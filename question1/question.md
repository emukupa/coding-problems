Given a linked list, rearrange the node values such that they appear in alternating low -> high -> low -> high ... form.
For example, given 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7, you should return 1 -> 3 -> 2 -> 5 -> 4 -> 7 -> 6.

- Can you make it alternate starting with high -> low .....

Strategy
flag : 1 | 0 - true or false
compare adjacent elements

if flag is true expect cur > prev
else flag is false expect cur < prev
else swap elements
