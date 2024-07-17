# To Do List Application

## Overview

This project is a console-based task management application implemented in C++. It allows users to efficiently manage their tasks by providing features for adding, viewing, marking completion, deleting, and filtering tasks by category. The application utilizes core C++ programming concepts and incorporates essential Data Structures and Algorithms (DSA).

## Features

- **Add Task:** Users can add tasks with descriptions, categories, priorities, and due dates.
- **View Tasks:** Displays all added tasks with details including category, priority, due date, and completion status.
- **Mark Task as Completed:** Allows users to mark tasks as completed, updating their status.
- **Delete Task:** Enables deletion of tasks with the option to undo the last deletion.
- **Undo Last Delete:** Restores the last deleted task using a stack data structure.
- **Filter Task by Category:** Users can filter tasks based on predefined categories.

## Tech Stack

- **Language:** C++
- **Data Structures:** Vector (for storing tasks), Stack (for undo functionality)
- **Libraries Used:** iostream, cstdlib, cmath, ctime

## Usage

1. **Compile:** Compile the program using a C++ compiler (e.g., g++).
   ```bash
   g++ -o task_manager main.cpp
   Run: Execute the compiled binary.
2. Run: Execute the compiled binary.
bash
Copy code
./task_manager
Menu Navigation: Follow the on-screen menu to interact with different features of the application.

Implementation Details
Classes: Utilizes object-oriented programming with a Task class to encapsulate task attributes.
Error Handling: Provides basic error handling for invalid inputs and boundary conditions.
User Interface: Console-based interface for user interaction, implemented using iostream for input/output operations.
Future Enhancements
Implement file handling for persistent task storage.
Add sorting options for tasks based on different criteria (e.g., due date, priority).
Enhance error handling and input validation for improved user experience.
