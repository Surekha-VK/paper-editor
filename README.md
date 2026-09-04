# Paper Editor (Array-Based Line Editor)

A simple command-line line editor written in C for the "Build a Simple
Line Editor" coding competition (3rd Semester, Portfolio Building —
Studio Course).

## Team

- Surekha V K
- Sinchana N 
- Sinchana M C

## Features implemented

- **Insert** — add a line of text at a chosen position, shifting
  existing lines down.
- **Delete** — remove the line at a chosen position, shifting the
  remaining lines up.
- **Display** — print the full document with line numbers.

Data structure used: a 2D character array (`char paper[MAX_LINES][MAX_LEN]`),
i.e. an array of strings. Chosen for simplicity and because line
count stays small and fixed-size, so the O(n) shifting cost on
insert/delete is not a concern at this scale.

## How to compile and run

```
gcc paper_editor.c -o paper_editor
./paper_editor
```

Then follow the on-screen menu (1. Insert, 2. Delete, 3. Display,
4. Exit). See `HELP.md` for detailed command usage examples.

## Files in this repo

- `paper_editor.c` — the editor source code
- `HELP.md` — command reference with usage examples
- `README.md` — this file
- `paper-design.jpg` (or `.pdf`) — photo/scan of our hand-written
  paper design and core logic
