# CS210 Programming Assignment
## Monopoly Board Simulator (Spring 2026)

## Overview
This program simulates a simplified Monopoly-style board using a circular linked list in C++. The board consists of spaces representing Monopoly properties, and a player moves around the board by rolling dice. This project uses pointer-based traversal to move the player around the board. The program demonstrates board construction, player movement, board traversal, and tracking how many times the player passes the GO space.

---

# Build Instructions

Compile the program using the C++17 standard.


The program will:
1. Build the Monopoly board.
2. Simulate several turns of gameplay.
3. Roll dice each turn.
4. Move the player through the circular list.
5. Display the player's position and nearby spaces.
6. Track how many times the player passes GO.
7. Reverse the Monopoly Board
8. Print the Monopoly Board

---

# Data Structures Used

## MonopolySpace Class
This class represents a single Monopoly board space.

Each space contains:
- `propertyName` – Name of the property
- `propertyColor` – Property color group
- `value` – Purchase value
- `rent` – Rent amount

Functions included:
- Constructor for initializing spaces
- `isEqual()` for comparing property names
- `print()` for displaying space information

---

## Node Template Class

The `Node` class represents one element in the circular linked list.

Each node contains:
- `data` – The Monopoly space stored in the node
- `nextNode` – Pointer to the next node

The class is templated so the linked list can store any data type.

---

## CircularLinkedList Template Class

This class implements the Monopoly board using a circular linked list.

Important variables include:

- `headNode` – Pointer to the first space
- `tailNode` – Pointer to the last space
- `playerNode` – Pointer representing the player's position
- `nodeCount` – Number of spaces currently in the board
- `passGoCount` – Number of times the player passes GO

The circular structure is maintained by making the tail node point back to the head node.

---

# Functions

## addSpace(T value)
Adds a new space to the board.

Responsibilities:
- Inserts a node at the end of the list
- Maintains the circular structure
- Enforces the maximum 40-space limit
- Returns `false` if the board is already full

---

## addMany(vector<T> values)
Adds multiple spaces sequentially.

Responsibilities:
- Calls `addSpace()` for each element
- Stops exactly when the board reaches capacity
- Returns the number of spaces successfully added

---

## movePlayer(int steps)
Moves the player forward through the board.

Responsibilities:
- Moves node-by-node through the circular list
- Wraps automatically due to the circular structure
- Detects when the player passes the GO space
- Increments `passGoCount`

---

## printFromPlayer(int count)
Displays spaces starting from the player's position.

Responsibilities:
- Traverses forward from the player's node
- Prints property information
- Stops after a fixed number of steps to avoid infinite loops

---

## printBoardOnce()
Traverses and prints the entire board exactly one time.

This function uses a do-while loop so traversal continues until the program returns to the starting node.

---

## mirrorBoard()
Reverses the direction of the circular linked list.

Responsibilities:
- Reverses the `nextNode` pointer for every node
- Preserves the circular structure
- Keeps the player pointer on the same logical space

---

## countSpaces()
Traverses the board once and counts how many spaces exist.

Used to verify that the board does not exceed the maximum allowed size.

---

## clear()
Deletes all nodes and frees allocated memory.

Steps:
1. Break the circular link
2. Traverse the list
3. Delete each node
4. Reset pointers and counters

---

# Traversal and Player Movement Logic

Player movement is implemented using pointer traversal rather than array indexing.

Movement process:
1. A dice roll generates a number between 2 and 12.
2. The program advances `playerNode` through the `nextNode` pointer.
3. Because the list is circular, the player automatically wraps around the board.
4. If the player lands on `"GO"`, the program increments the pass counter.

This approach models the board as a continuous ring of spaces.

---
