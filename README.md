# Texas-Hold-em-Poker
This is Texas Hold'em Poker game with C++ language.

# Below is the rule for Texas Hold'em Poker:
First randomly choose the dealer button (use rand() )

Process:
1. (Preflop) The left to the button is the small blind, the left to left is the big blind. (const int buttom_pouring = ?) ( the small blind pours rand(), the big blind pours rand()*2)
2. 2 cards to each player (all covered )
3. Move to right until everyone acts & the same amount of money for everyone in play. (Acts: call, raise ,fold) 
4. (The flop) Place 3 public cards on the table. 
5. Start from the first active player to the left of the button. (Act: check, call, raise, fold) Until everyone acts & the same amount of money for everyone in play.
6. (The turn) Place 1 more public card on the table.
7. Start from the first active player to the left of the button. (Act: check, call, raise, fold) Until everyone acts & the same amount of money for everyone in play.
8. (The river) Place 1 more public card on the table
9. Start from the first active player to the left of the button. (Act: check, call, raise, fold) Until everyone acts & the same amount of money for everyone in play.
10. (Showdown) every active player show their cards and decide the winner! (Using "Compare" function)

Remember that the small blind and big blind move to right at each turn. 




# I plan to first write the algorithm with command line at the beginning. 
[Link to my Command line folder](./Texas Hold'em Poker/)
