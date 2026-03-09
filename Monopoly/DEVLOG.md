# Developer Log
## Monopoly Board Simulator

### Entry 1 ###
**Date:** 2025-03-08
**Entry Type:** Bug Fix
**Task worked on:** addMany() function
**Issue or decision:** When using the addMany() function, the value of nodeCount of the board was greater than the expected value. 
**What I tried:** I printed the value of nodeCount when each function was called to identify where the possible issue could be 
**Fix:** The addMany() function used the addSpace() function, both of which incremented the value of nodeCount

---

### Entry 2
**Date:** 2025-03-08
**Entry Type:** Bug Fix 
**Task worked on:** movePlayer() Function
**Issue or decision:** The function was incrementing the passGoCount more than the expected value
**What I tried:** I added the debugging portion of code that showed there was an issue with the board, so I built the printBoardOnce() function to see the full board. After building the function, I realized there was an issue with the construction of the linked list. 
**Fix:** The tail was not being updated in the addSpace function, so I corrected the code to ensure the linked list was constructed correctly

---


