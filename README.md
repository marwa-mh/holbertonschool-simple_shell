
# 🐚 Simple Shell

This project is a basic Unix shell built in C, created as part of the Holberton School curriculum. It reads user input, parses it, and executes commands—just like `/bin/sh`.

---

## 📌 Features

- Displays a prompt: `#cisfun$`
- Executes command-line programs (`ls`, `pwd`, `echo`, etc.)
- Handles command-line arguments
- Built-in support for:
  - `exit` — to exit the shell
  - `env` — to print environment variables
- Searches executable commands using the `PATH`
- Handles command not found errors
- Trims leading and trailing whitespace from user input
- Works in both interactive and non-interactive mode

---

## 🧠 How It Works

1. **Main Loop**:  
   The shell runs in a loop, displaying a prompt and waiting for user input.

2. **Reading Input**:  
   The `read_input()` function uses `getline()` to read input from `stdin`, removes extra whitespace, and returns a cleaned string.

3. **Parsing and Executing**:  
   - The `execute_command()` function splits the input into arguments.
   - If it's a built-in like `exit` or `env`, it's handled directly.
   - Otherwise, it checks if the command exists in the system's `PATH`.
   - If found, it forks a new process and uses `execve()` to run it.

4. **Built-ins**:
   - `exit`: Closes the shell.
   - `env`: Displays environment variables.

---

## 🚀 Example Usage

```
#cisfun$ ls -l
#cisfun$ pwd
#cisfun$ env
#cisfun$ echo Hello, world!
#cisfun$ exit
```

---

## 📁 Files and Functions

| File | Description |
|------|-------------|
| `main.c` | Entry point, handles prompt and main loop |
| `read_input.c` | Reads and trims user input |
| `execute_command.c` | Parses and runs commands |
| `find_in_path.c` | Searches the `PATH` for executables |
| `prompt.c` | Displays the shell prompt |
| `shell.h` | Header file with includes and function declarations |

---

## 🔧 Compilation

Compile using:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

---

## 📦 Usage

Run the shell:

```bash
./hsh
```

Use interactively or pipe a script to it:

```bash
echo "ls -l" | ./hsh
```

---

## 🧪 Testing

Try typing common shell commands like:

- `ls`
- `pwd`
- `echo Hello`
- `env`

Then exit with:

```bash
exit
```

---

## 👨‍💻 Author

**Kaj Kennedy**

**Ian Gibson**

**Marwa Al Mahmoud**  

Holberton School | Simple Shell Project

---
