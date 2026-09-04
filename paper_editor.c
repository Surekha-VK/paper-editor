/*
    ============================================================
    PAPER EDITOR (Array-based Line Editor)
    ------------------------------------------------------------
    A simple menu-driven program that stores lines of text in a
    2D character array ("array of strings") and lets the user
    Insert, Delete, and Display lines — just like a basic paper
    document being edited line by line.

    Data structure used: 2D array   char paper[MAX_LINES][MAX_LEN]
    - Think of it as a stack of paper strips.
    - paper[0] is the 1st line, paper[1] is the 2nd line, etc.
    - Each "strip" (row) can hold up to MAX_LEN-1 characters of text.
    ============================================================
*/

#include <stdio.h>
#include <string.h>

#define MAX_LINES 100   // maximum number of lines the paper can hold
#define MAX_LEN   200   // maximum characters allowed in one line

// The array that stores all lines of text.
// paper[i] = the text of line number (i+1)
char paper[MAX_LINES][MAX_LEN];

// Keeps track of how many lines currently have text in them.
int lineCount = 0;

// ---------- FUNCTION DECLARATIONS ----------
void insertLine();
void deleteLine();
void displayPaper();
void showMenu();

// ============================================================
// MAIN FUNCTION - runs the menu loop
// ============================================================
int main() {
    int choice;

    printf("===== WELCOME TO PAPER EDITOR (Array Based) =====\n");

    while (1) {   // infinite loop until user chooses Exit
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // clear the leftover newline character from the input buffer
        // (needed because we mix scanf with fgets later)
        getchar();

        switch (choice) {
            case 1:
                insertLine();
                break;
            case 2:
                deleteLine();
                break;
            case 3:
                displayPaper();
                break;
            case 4:
                printf("Exiting Paper Editor. Goodbye!\n");
                return 0;   // ends the program
            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}

// ============================================================
// SHOW MENU - just prints the 4 options
// ============================================================
void showMenu() {
    printf("\n----------------------------\n");
    printf(" 1. Insert\n");
    printf(" 2. Delete\n");
    printf(" 3. Display\n");
    printf(" 4. Exit\n");
    printf("----------------------------\n");
}

// ============================================================
// INSERT LINE
// Lets the user insert a new line of text at a chosen position.
// All lines from that position onward are shifted DOWN by one
// to make room (just like pushing paper strips down to insert
// a new strip in between).
// ============================================================
void insertLine() {
    int pos;

    // Stop if the paper is already full
    if (lineCount >= MAX_LINES) {
        printf("Paper is full! Cannot insert more lines.\n");
        return;
    }

    printf("Enter position to insert (1 to %d): ", lineCount + 1);
    scanf("%d", &pos);
    getchar(); // clear newline left in buffer by scanf

    // Validate the position: must be between 1 and (lineCount + 1)
    // (lineCount + 1 means "insert right after the last line")
    if (pos < 1 || pos > lineCount + 1) {
        printf("Invalid position!\n");
        return;
    }

    // ---- SHIFTING STEP ----
    // Move every line from the last one down to the insert
    // position ONE STEP DOWN, starting from the back so we
    // don't overwrite data we still need to move.
    // Example: inserting at position 2 in [A, B, C]
    //   before: paper[0]=A paper[1]=B paper[2]=C
    //   after shifting: paper[0]=A paper[1]=_ paper[2]=B paper[3]=C
    for (int i = lineCount; i >= pos; i--) {
        strcpy(paper[i], paper[i - 1]);
    }

    // Now the gap at index (pos - 1) is empty; read the new text into it.
    printf("Enter text: ");
    fgets(paper[pos - 1], MAX_LEN, stdin);

    // fgets keeps the trailing newline character ('\n') from Enter key.
    // We remove it so the stored line doesn't have an extra blank line.
    paper[pos - 1][strcspn(paper[pos - 1], "\n")] = '\0';

    lineCount++;   // one more line now exists
    printf("Line inserted successfully!\n");
}

// ============================================================
// DELETE LINE
// Removes the line at a chosen position.
// All lines AFTER that position are shifted UP by one to close
// the gap (like pulling one strip of paper out and sliding the
// rest up to fill the space).
// ============================================================
void deleteLine() {
    int pos;

    if (lineCount == 0) {
        printf("Paper is empty! Nothing to delete.\n");
        return;
    }

    printf("Enter position to delete (1 to %d): ", lineCount);
    scanf("%d", &pos);
    getchar();

    if (pos < 1 || pos > lineCount) {
        printf("Invalid position!\n");
        return;
    }

    // ---- SHIFTING STEP ----
    // Move every line AFTER the deleted one back by ONE STEP,
    // starting from the deleted position and going forward.
    // Example: deleting position 2 in [A, B, C]
    //   before: paper[0]=A paper[1]=B paper[2]=C
    //   after shifting: paper[0]=A paper[1]=C  (C moved into B's old spot)
    for (int i = pos - 1; i < lineCount - 1; i++) {
        strcpy(paper[i], paper[i + 1]);
    }

    lineCount--;   // one less line now exists
    printf("Line deleted successfully!\n");
}

// ============================================================
// DISPLAY PAPER
// Prints every current line along with its line number, so the
// user can see the full document state.
// ============================================================
void displayPaper() {
    if (lineCount == 0) {
        printf("Paper is empty. No lines to display.\n");
        return;
    }

    printf("\n----- PAPER CONTENTS -----\n");
    for (int i = 0; i < lineCount; i++) {
        printf("%d. %s\n", i + 1, paper[i]);
    }
    printf("---------------------------\n");
}