# Pipex Project

The **Pipex** project is part of the **École 42** curriculum. In this project, you will implement a simplified version of a shell pipeline using **forking**, **piping**, and **redirection** in **C**. This project focuses on understanding how processes can be created, communicated, and controlled in a Unix-like operating system.

The main goal of this project is to simulate a basic version of the `pipe` and `|` functionality found in Unix shells, enabling the execution of commands in a pipeline.

## Project Description

The **Pipex** project involves creating a program that simulates the behavior of shell pipes (`|`) in Unix. The objective is to take multiple commands, connect them using pipes, and execute them in parallel processes. The output of one command should be passed as the input to the next command in the pipeline.

### Key Components:
- **Forking**: Create new processes to execute commands.
- **Pipes**: Set up pipes to redirect the output of one process to the input of another.
- **Redirection**: Handle redirection of input/output files (e.g., `<`, `>`, `>>`).
- **Command Execution**: Use `execve()` to execute commands within each process.

## Objectives

- Implement a **pipe** system to redirect the output of one command to the input of the next.
- Use **forking** to create new processes to execute the individual commands.
- Handle **input/output redirection** and **error management**.
- Properly close file descriptors to avoid memory and resource leaks.
- Handle a variable number of commands in the pipeline.

## Technologies Used

- **C**: The project is implemented in the C programming language.
- **Unix System Calls**: Uses `fork()`, `pipe()`, `execvp()`, `dup2()`, and `waitpid()` to handle processes and inter-process communication.
- **Makefile**: For compiling the project and managing dependencies.

