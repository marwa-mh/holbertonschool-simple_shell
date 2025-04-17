🐚 Simple Shell -- Project Overview
==================================

This project is a basic implementation of a Unix shell in C. It reads user commands, executes them in a child process, and supports basic interaction like custom prompts and command parsing.

* * * * *

📁 File Breakdown
-----------------

### `main.c`

This is the **entry point** of the shell program.

c

CopyEdit

`int main(void)`

-   **`while (1)`**: Keeps the shell running in a loop until the user exits (e.g., with `Ctrl+D`).

-   **`display_prompt()`**: Shows the shell prompt (`#cisfun$`) if in an interactive terminal.

-   **`read_input()`**: Reads and cleans the input line from the user.

-   **`execute_command(line)`**: Parses and runs the command.

-   **`free(line)`**: Frees the dynamically allocated memory after each loop iteration.

It also handles:

-   **Ctrl+D** (EOF): Exits the shell gracefully.

-   **Empty lines**: Skips executing when the user just presses Enter.

* * * * *

### `prompt.c`

c

CopyEdit

`void display_prompt(void)`

-   Displays the prompt only when the shell is running in **interactive mode** (e.g., a user typing directly into a terminal).

-   Uses `isatty(STDIN_FILENO)` to check if input is from a terminal.

Output:

arduino

CopyEdit

`#cisfun$`

* * * * *

### `input.c`

Handles **user input** and **cleanup**.

#### `read_input()`

-   Uses `getline()` to read an entire line from standard input.

-   Trims leading and trailing whitespace using custom logic.

-   Removes the newline at the end (`\n`) if present.

-   Returns a **clean, dynamically allocated string** to be executed.

#### `is_whitespace(char ch)`

A helper function to check if a character is a space, tab, or newline.

* * * * *

### `execute.c`

The core logic that runs the user's command.

#### `execute_command(char *line)`

1.  **Parses** the command line into an array of strings (`argv[]`) using `strtok()`.

2.  **Creates a child process** using `fork()`.

3.  Inside the **child**:

    -   Calls `execve()` to run the command with arguments.

    -   On failure, prints an error with `perror()`.

4.  Inside the **parent**:

    -   Waits for the child to finish using `wait()`.

Supports commands like:

bash

CopyEdit

`./hbtn_ls /var
ls -l
/bin/ls /etc`

* * * * *

💡 Features
-----------

-   Custom shell prompt (`#cisfun$`)

-   Reads and cleans user input

-   Handles whitespace, newlines, and empty lines

-   Uses `fork()` and `execve()` to run commands

-   Parses arguments properly using `strtok`

-   Graceful exit with `Ctrl+D` (EOF)

* * * * *

🔧 Limitations (Basic Shell)
----------------------------

-   No `PATH` resolution (e.g., typing `ls` without full path won't work)

-   No built-in commands (like `exit`, `cd`)

-   Doesn't support chaining (`&&`, `||`), pipes, or redirection

-   Max arguments: 63 (hardcoded array size)

* * * * *

🧪 Example Session
------------------

bash

CopyEdit

`#cisfun$ /bin/ls
execute.c  input.c  main.c  prompt.c  shell.h
#cisfun$ ./hbtn_ls /var
backups  cache  lib  local  log  mail  ...
#cisfun$`
