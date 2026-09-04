# Paper Editor — Help

A simple menu-driven line editor written in C. It stores your document
as lines of text in an array and lets you insert, delete, and display
them.

## Running the program

```
gcc paper_editor.c -o paper_editor
./paper_editor
```

You'll see a menu with 4 options:

```
1. Insert
2. Delete
3. Display
4. Exit
```

Type the number of the option you want and press Enter.

## Commands

### 1. Insert
Adds a new line of text at a position you choose. Any existing lines
at or after that position shift down by one to make room.

**Usage example:**
```
Enter your choice: 1
Enter position to insert (1 to 1): 1
Enter text: Hello world
Line inserted successfully!
```

If you insert again at position 1, "Hello world" becomes line 2 and
your new text becomes line 1.

### 2. Delete
Removes the line at a position you choose. Lines after it shift up by
one to close the gap.

**Usage example:**
```
Enter your choice: 2
Enter position to delete (1 to 2): 1
Line deleted successfully!
```

### 3. Display
Prints every current line along with its line number.

**Usage example:**
```
Enter your choice: 3

----- PAPER CONTENTS -----
1. Hello world
2. This is line two
---------------------------
```

### 4. Exit
Closes the program.

**Usage example:**
```
Enter your choice: 4
Exiting Paper Editor. Goodbye!
```

## Notes

- Maximum 100 lines, each up to 199 characters.
- Invalid positions (e.g. deleting from an empty document, or
  inserting past the end) are rejected with an error message instead
  of crashing.
