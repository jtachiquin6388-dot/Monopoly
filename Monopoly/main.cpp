#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

static const int MAX_SPACES = 40;


// -------------------------------
// Data class (NOT a struct)
// -------------------------------
class MonopolySpace {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolySpace() {
        // TODO: define default constructor (recommended)
        this->propertyName = "";
        this->propertyColor = "";
        this->value = 0;
        this->rent = 0;
    }
    MonopolySpace(string propertyName, string propertyColor, int value, int rent) {
        this->propertyName = propertyName;
        this->propertyColor = propertyColor;
        this->value = value;
        this->rent = rent;
    }
    bool isEqual(MonopolySpace other) {
        if (this->propertyName == other.propertyName) {
            return true;
        }
        return false;
    }
    void print() {

        cout << "Property name  : " << this->propertyName << endl;
        cout << "Property color : " << this->propertyColor << endl;
        cout << "Property value : " << this->value << endl;
        cout << "Rent           : " << this->rent << endl;

        return;
    }
};
// -------------------------------
// Template Node class (NOT a struct)
// -------------------------------
template <typename T>
class Node {
public:
    T data;
    Node<T>* nextNode;
    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};


// -------------------------------
// Template Circular Linked List class
// Spring 2026 version: traversable board
// -------------------------------
template <typename T>
class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;

    // player cursor for traversal-based gameplay
    Node<T>* playerNode;
    int nodeCount;
    int passGoCount;
public:
    CircularLinkedList() {
        headNode = nullptr;
        tailNode = nullptr;
        playerNode = nullptr;
        nodeCount = 0;
        passGoCount = 0;
    }
    // -------------------------------
    // Board Construction Policy (Reminder)
    // -------------------------------
    // Spaces are added during board construction BEFORE gameplay.
    // You choose how to construct the board:
    // - hardcode spaces, read from file, or generate programmatically
    // The only non-negotiable requirement:
    // - enforce MAX_SPACES
    // - maintain circular integrity
    // -------------------------------

    // -------------------------------
    // Core A: Add a Space with Capacity Enforcement
    // -------------------------------
    bool addSpace(T value) {
        if (nodeCount == MAX_SPACES) {
            cout << "limit reached" << endl;
            return false;
        }

        Node <T>* newNode = new Node<T>(value);

        if (headNode == nullptr) {
            headNode = newNode;
            tailNode = newNode;
            playerNode = newNode;

            cout << "head created"<< endl;
        }
        else {
            tailNode->nextNode = newNode;
            tailNode = newNode;
            tailNode->nextNode = headNode;
        }

        nodeCount++;

        return true;
    }

    // -------------------------------
    // Core B: Add Multiple Spaces at Once
    // -------------------------------
    int addMany(vector<T> values) {
        int count = 0;

        for (T val : values) {
            if (nodeCount == MAX_SPACES) {
                return count;
            }

            addSpace(val);
            count++;
        }

        return count;
    }

    // -------------------------------
    // Core C: Traversal-Based Player Movement
    // -------------------------------
    void movePlayer(int steps) {
        if (headNode == nullptr) {
            return;
        }

        if (playerNode == nullptr) {
            playerNode = headNode;
        }

        for (int i = 0; i < steps; i++) {
            playerNode = playerNode->nextNode;

            if (playerNode->data.propertyName == "GO") {
                passGoCount++;
            }
        }

    }

    int getPassGoCount() {
        return passGoCount;
    }

    // -------------------------------
    // Core D: Controlled Board Display
    // -------------------------------
    void printFromPlayer(int count) {
        if (playerNode == nullptr) {
            return;
        }

        Node <T>* temp = playerNode;

        for (int i = 0; i < count; i++) {
            temp = temp->nextNode;
        }

        temp->data.print();
    }


    void printBoardOnce() {
        if (headNode == nullptr) {
            return;
        }

        Node <T> * temp = headNode;

        do{
            temp->data.print();
            cout << endl;
            temp = temp->nextNode;

        }while (temp != headNode);
    }

    // -------------------------------
    // Advanced Option B (Level 2): Mirror the Board (Circular Reversal)
    // -------------------------------
    void mirrorBoard() {

        if (nodeCount <= 1) {
            return;
        }

        Node <T> * prev = tailNode;
        Node <T> * curr = headNode;
        Node <T> * next = nullptr;

        for (int i = 0; i < nodeCount; i++) {
            next = curr->nextNode;
            curr->nextNode = prev;
            prev = curr;
            curr = next;
        }
        curr = headNode;
        headNode = tailNode;
        tailNode = curr;


    }
    // -------------------------------
    // Edge-case helper: countSpaces O(n)
    // -------------------------------
    int countSpaces() {

        if (headNode == nullptr) {
            return 0;
        }

        int spaces = 1;
        Node <T> * temp = headNode->nextNode;

        while (temp != headNode) {
            spaces++;

            temp = temp->nextNode;
        }

        return spaces;
    }
    // -------------------------------
    // Cleanup
    // -------------------------------
    void clear() {

        tailNode->nextNode = nullptr;

        Node <T> * curr = headNode;
        Node <T> * next = nullptr;

        while (curr != nullptr) {
            next = curr->nextNode;
            delete curr;
            curr = next;
        }

        headNode = tailNode = playerNode = nullptr;
        nodeCount = 0;
    }
};
// -------------------------------
// Main: playable loop demo
// -------------------------------
int rollDice2to12() {
return (rand() % 6 + 1) + (rand() % 6 + 1);
}
int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    CircularLinkedList<MonopolySpace> board;
    // -------------------------------
    // Board Construction Phase
    // -------------------------------
    // You decide how to build the board:
    // - hardcode spaces, load from file, or generate spaces programmatically
    // The only requirement: never exceed MAX_SPACES and keep the list circular.
    //
    // Example (hardcoded) usage:
    // vector<MonopolySpace> spaces;
    // spaces.push_back(MonopolySpace("GO","None",0,0));
    // . .
        // board.addMany(spaces);
    //
    // NOTE: This starter calls addSpace once to show the intended API,
    // but your final submission should build a meaningful board.
    board.addSpace(MonopolySpace("GO", "None", 0, 0));
    board.addSpace(MonopolySpace("Sunset Boulevard", "Orange", 180, 22));
    board.addSpace(MonopolySpace("Harbor View", "Light Blue", 100, 8));

    vector<MonopolySpace> testSpaces;

    testSpaces.push_back(MonopolySpace("Grand Theater District", "Red", 200, 20));
    testSpaces.push_back(MonopolySpace("Maple Grove", "Brown", 60, 4));
    testSpaces.push_back(MonopolySpace("Emerald Gardens", "Green", 280, 26));
    testSpaces.push_back(MonopolySpace("Silver Springs", "Pink", 140, 14));
    testSpaces.push_back(MonopolySpace("Roya Plaza", "Dark Blue", 350, 35));
    testSpaces.push_back(MonopolySpace("Ocean View", "Light Blue", 100, 6));
    testSpaces.push_back(MonopolySpace("Sunset Boulevard", "Orange", 180, 18));
    testSpaces.push_back(MonopolySpace("Crystal Cove", "Yellow", 260, 22));
    testSpaces.push_back(MonopolySpace("Golden Heights", "Yellow", 260, 22));
    testSpaces.push_back(MonopolySpace("Riverwalk", "Light Blue", 120, 8));
    testSpaces.push_back(MonopolySpace("Cedar Point", "Brown", 60, 2));
    testSpaces.push_back(MonopolySpace("Broadway Avenue", "Red", 220, 20));
    testSpaces.push_back(MonopolySpace("Harbor Street", "Pink", 160, 16));
    testSpaces.push_back(MonopolySpace("Union Station", "Railroad", 200, 25));
    testSpaces.push_back(MonopolySpace("Electric Company", "Utility", 150, 12));
    testSpaces.push_back(MonopolySpace("Water Works", "Utility", 150, 12));
    testSpaces.push_back(MonopolySpace("Parkside Lane", "Orange", 180, 18));
    testSpaces.push_back(MonopolySpace("Liberty Square", "Red", 220, 20));
    testSpaces.push_back(MonopolySpace("Highland Avenue", "Light Blue", 100, 6));
    testSpaces.push_back(MonopolySpace("Midtown Crossing", "Pink", 140, 14));
    testSpaces.push_back(MonopolySpace("Summit Ridge", "Green", 300, 28));
    testSpaces.push_back(MonopolySpace("Boardwalk Heights", "Dark Blue", 400, 50));
    testSpaces.push_back(MonopolySpace("Central Park Place", "Green", 280, 26));
    testSpaces.push_back(MonopolySpace("Old Town Road", "Brown", 80, 4));
    testSpaces.push_back(MonopolySpace("Grand Central", "Railroad", 200, 25));
    testSpaces.push_back(MonopolySpace("Market Street", "Orange", 200, 16));
    testSpaces.push_back(MonopolySpace("Sunrise Terrace", "Yellow", 240, 20));
    testSpaces.push_back(MonopolySpace("Victory Lane", "Red", 240, 22));
    testSpaces.push_back(MonopolySpace("Canyon Drive", "Pink", 160, 16));
    testSpaces.push_back(MonopolySpace("Palm Estates", "Green", 320, 30));
    testSpaces.push_back(MonopolySpace("King's Court", "Dark Blue", 350, 35));
    testSpaces.push_back(MonopolySpace("Forest Hills", "Light Blue", 120, 8));
    testSpaces.push_back(MonopolySpace("Lakeview Terrace", "Orange", 180, 18));
    testSpaces.push_back(MonopolySpace("Heritage Square", "Yellow", 260, 22));
    testSpaces.push_back(MonopolySpace("Grand Harbor", "Green", 300, 28));
    testSpaces.push_back(MonopolySpace("Royal Gardens", "Pink", 140, 14));
    testSpaces.push_back(MonopolySpace("Diamond District", "Dark Blue", 400, 50));

    int added = board.addMany(testSpaces);

    board.addSpace(MonopolySpace("Skyline Plaza", "Purple", 150, 12));

    cout << board.countSpaces() << endl;

    cout  << added << endl;

    board.printBoardOnce();



    // -------------------------------
    // Playable Traversal Loop
    // -------------------------------
    for (int turn = 1; turn <= 10; turn++) {
        int roll = rollDice2to12();
        cout << "\nTurn " << turn << " | Rolled: " << roll << endl;
        board.movePlayer(roll);
        cout << "Board view from player (next 5 spaces):" << endl;
        board.printFromPlayer(5);
        cout << "Times passed GO so far: " << board.getPassGoCount() << endl;
    }

    board.mirrorBoard();
    board.printBoardOnce();

    return 0;
}