# Show_Hand
This is Show Hand Poker game with C++ language.
(All the codes are home-made because no code of this game can be found online. )

# This is a link to a brief introduction of the game:
https://en-betfair.custhelp.com/app/answers/detail/a_id/5954/~/poker%3A-how-to-play-5-card-stud


# Below is the rule for Show_Hand:
（First Street)First everyone is dealt two cards (one coverd & one face up).
Then someone has to bet a certain amount of money (called "bottom_pouring").
The one with the highest hand showing takes the first betting. (betting includes: check,call,raise,fold)
Other players do the betting in order until the money everyone puts in is the same.

(Second Street)Everyone is dealt one more card which is faced up.
The one with the highest hand showing takes the first betting. (betting includes: check,call,raise,fold)
Other players do the betting in order until the money everyone put in is the same.

(Third Street)Similar to second street.

(Fourth Street)Similar. 
The winner is the player who has the best hand showing.

# Here's the rule for playing my Show_Hand game:
There are two players. Each one has 1000 dollars initially.
(First round) Each one is dealt two cards - one face down (N/A) & one face up. 
Both players should "peak at" their face-down card by pressing "VISIBLE1" or "VISIBLE2". (They cannot see each other's face-down card)
One of player is randomly chosen to take initial bid - 10 dollars.
The other player take action first (action includes: FOLD, CHECK, RAISE)

FOLD: Lose the game and all money in jackpot goes to the winner.
CHECK: Two players' bids are set equal, and the round ends - each player is dealt one more card (Notice: if Player1 has more bid than player2, then only player2 can press "CHECK" button)
RAISE: Raise bid by 50 dollars each time. Can press "RAISE" several times in a round. 

The round ends until someone presses "CHECK" or “FOLD". (i.e. Two players' bids are the same)

(Second round) Each one is dealt two cards.
The one who doesn't take initial bid takes action first. (action include: FOLD, CHECK, RAISE)
The round ends until someone presses ”CHECK" or "FOLD".

(Third round) Similar to second round.

(Fourth round) Similar to second round.

(Fifth round) The player with the better hand ranking wins the game and takes all the jackpot.

# The hand ranking is the same as Texas Hold'em Poker. Here's the link to the rule of hand rankings:
https://www.cardplayer.com/rules-of-poker/hand-rankings

# Notice for player of my game:
1. If one player has higher bid than the other, then only the player with lower bid can press "CHECK".
2. If two players' bids are the same and no one wants to add bid, then either player can press "CHECK".
3. Don't press "AGAIN" until the game ends - there's a winner or a tie.
4. Can't add bid in the final round.




# Here's the link to the actual game: (run it in Qt Creator)
[Link to my game: ](./Show_Hand_Qt/)

# This file contains all my learning process records.
[Link to my learning process records](Show_Hand/learner_log.md/)
