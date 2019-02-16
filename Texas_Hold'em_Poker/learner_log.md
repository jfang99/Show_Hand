This is the readme for command line files.

2019/2/8
In order to have a very basic idea of how to start, I first looked at a list of files of a completed Texas Hold’em Poker project. Here’s the link:
https://github.com/anttiahonen/texashold/tree/master/src

I also checked the special character for four types of pokers on:
http://www.cplusplus.com/forum/general/187685/

2019/2/13
I found that I mistook Texas Hold’em Poker with a Chinese poker game called “show hand”, so I just learned how to play Texas Hold’em Poker. The rules are different in some way, but they are also similar. 

2019/2/14
I reviewed the selection sort learned in pic10b and used it in one of my helper function. 
https://www.toptal.com/developers/sorting-algorithms/selection-sort

2019/2/15
I learned that variable names can contain numbers, but it can’t be the first character of the name. Because I tried to use "1st_large_sequence" as a variable name but failed.

I wrote three "find_sequence" functions:
1) check the smallest sequence.
2) check the second largest sequence.
3) check the largest sequence.
They are needed because when there are 7 cards (maximum), there can be at most three sequences, and I need to use "get_largest_sequence" to find the largest one. The other two are needed because if the 7 cards contain a "royal flush" and several (<=3) sequences, I need to know which sequence contains the royal flush.
- I wrote all these algorithms from scratch without referencing others' codes.
(It took me about 3 hours to write them)

