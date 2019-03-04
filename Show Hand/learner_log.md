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

Note to myself: always call "check_sequence" before "get_sequence".

2019/2/18
I was competing in "Hack on Hill" yesterday so I didn't have any progress yesterday.
# Today I've changed my mind to switch the topic of my project from "Texas Hold'em Poker" to "Show Hand".
The reason is that Texas Hold'em Poker's algorithm is too complex and takes most of the time to work on the algorithm part. However, since I want to learn some new techniques, I don't want to spend too much time on algorithm. Therefore, I've switched to a similar Chinese poker game "Show Hand". Their rules are basically the same, but "Show Hand"'s maximum card size is 5 while "Texas Hold'em Poker" is 7. This little difference makes a lot of differences in the work load. For example, I don't need the function "get_largest_sequence" because there could only be one sequence in "Show Hand"! 
So briefly speaking, I will keep working on my previous project, but quite a bit of changes need to be made.

2019/2/25
I wrote the algorithm and corresponding helper functions for checking "royal flush" "straight flush" "four of a kind" "full house" "flush" "straight" "three of a kind".
The remaining ones are "two pair" "one pair" "high card".

2019/2/26
I searched for the algorithm to find a "pair" in five cards:
https://gamedev.stackexchange.com/questions/49302/determining-poker-hands
It turns out to be not so efficient, so I modified it a little bit.



