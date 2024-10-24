# Minishell Project - My Project at 42

Made in colaboration with [rpisoner](https://github.com/rpisoner)

## Summary
The **Minishell** project involves creating a simple shell that replicates some core features of a Unix shell. The goal is to manage user input, execute commands, handle environment variables, and implement some built-in functions, providing an interactive prompt for users.

## Implementation
The shell needs to handle various features of a typical command-line interface, including:
- **Prompt**: Displaying a prompt where the user can input commands.
- **Command Execution**: Supporting simple commands and executing them via `execve`.
- **Pipes and Redirections**: Managing multiple processes connected via pipes, as well as input/output redirections (`<`, `<<`, `>`, `>>`).
- **Environment Variables**: Handling and updating environment variables, allowing for commands like `export` and `unset`.
- **Built-ins**: Implementing built-in commands such as:
  - `cd`: Change directory.
  - `echo`: Print text to the terminal.
  - `pwd`: Print the current working directory.
  - `env`: Display environment variables.
  - `export`: Set environment variables.
  - `unset`: Remove environment variables.
  - `exit`: Exit the shell.
  
### Core Features:
1. **Lexing and Parsing**: Breaks down the input into tokens and parses it into executable commands.
2. **Signal Handling**: Catching signals like `Ctrl+C`, `Ctrl+D`, and `Ctrl+\`, ensuring the shell behaves appropriately.
3. **Pipes and Redirection**: Supporting command chains connected by pipes (e.g., `ls | grep`) and input/output redirection.
4. **Environment Variables**: Commands can access and modify environment variables in real time.
5. **Error Management**: Handling errors like command not found, invalid syntax, or permission issues gracefully.

### Example:
```sh
$ ./minishell
minishell> echo "Hello, world!"
Hello, world!
minishell> cd ..
minishell> pwd
/home/user
minishell> exit
