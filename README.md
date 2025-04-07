# Simple_RPG
A turn-based game against two CPU's; Player 1 and Player 2.

The number of rounds is selected by user input.
For each round, the two CPU's are assigned either a mage, fighter, or tank "champion"; each champion has a 1/3rd percent chance of being selected.
Depending on the champion, a random number of points is assigned to each CPU.
Each CPU either receives or loses their current round’s points depending on their matchup (described below).
The CPU with the higher number of points at the end of the all the rounds wins!

<MATCHUPS>
  
**MAGE vs MAGE** 
  Player with higher POINTS wins.
  The winning player gains their current points.
  The losing player loses their current points.
  If tie, nothing happens.	

**MAGE vs FIGHTER**
  Player with higher POINTS wins. 
  If MAGE wins, they gain their current points, but FIGHTER gets no penalty.
  If FIGHTER wins, they gain no reward, but MAGE loses their current points. 
  If tie, nothing happens.	

**MAGE vs TANK**
  MAGE gains their current points.
  TANK loses their current points.

**FIGHTER vs FIGHTER**		
  Both players win and gain all their current points.	

**FIGHTER vs TANK**
  TANK loses but with no penalty. 
  FIGHTER wins and gains current points.

**TANK vs TANK**
  Nothing happens – no penalty or reward.


