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

### Entry 3
**Date:** 2026-03-08
**Entry Type:** Bug Fix
**Task worked on:** mirrorBoard() Function
**Issue or decision:** The function changed the linked list, so when trying to print the board, it caused an error. 
**What I tried:** I iterated through the board to see the value of each node. 
**Fix:** The tail pointer did not connect back to the head, causing issues when iterating through it. 

---

### Entry 4
**Date:** 2026-03-08
**Entry Type:** Bug Fix
**Task worked on:** countSpaces() Function
**Issue:** The program was not compiling to the end of the code.
**What I tried:** I added a print statement within the while loop of the countSpace() funcation, showing that it was an infinite loop.
**Fix:** I forgot to iterate through the nodes of the meaning, so the while loop did not come to an end

---

### Entry 5
**Date:** 2025-03-08
**Entry Type: Edge Case
**Task worked on:** Ensuring that there would not be more than 40 spaces
**Issue or decision:** Create more than 40 spaces on the board
**What I tried:** I added print statements in the addSpace() function to ensure that it branched when the board is already at MAX_SPACES
**Resolution:** The code compiled correctly and did not raise an error

---
### Entry 6
**Date:** 2026-03-08
**Entry Type:** Engineering Decision
**Task worked on:** printBoardOnce()
**Decision:** I needed a way to easily see that the board was being constructed correctly, and a way to easily verify the function operated correctly 
**What I tried:** I created the printBoardOnce () function that would be able to easyily display the entire board
**Resolution:** This function allowed me to easily debug and see how the linked list was behaving

