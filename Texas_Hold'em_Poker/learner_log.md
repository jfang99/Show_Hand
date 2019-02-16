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

I learned from a website that the largest number in texas poker is 1(Ace) instead of 13(K)! Therefore I modified the  class Card's field by adding "string rank" which shows the actual symbol on the card. (e.g. J,Q,A) Here's the link to the website:
https://www.pokernews.com/poker-rules/texas-holdem.htm

I will leave the rest of the change in class interface to tomorrow.

2019/2/16
I added suit and rank to class Card.
Suit represents the type while rank represents the symbol(e.g. K,J)

Note: I realized that the reason why cpp file needs a header file is that we don't need to care about the order of functions. For example, if we write function x before y and try to use y in x, then there would be an error. However this error won't appear if header file is included.

