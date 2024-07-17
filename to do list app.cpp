#include <iostream>  // Include standard input-output library
#include <cstdlib>   // Include standard library for functions like rand()
#include <cmath>     // Include cmath library for mathematical functions
#include <ctime>     // Include ctime library for date and time functions
#include <vector>    // Include vector library
#include <stack>     // Include stack library

using namespace std;

class Task {
public:
    string description;
    string category;
    bool completed;
    string dueDate;
    string priority;

    // Constructor to initialize a Task object
    Task(string description, string category, string priority, string dueDate) {
        this->description = description;
        this->category = category;
        this->dueDate = dueDate;
        this->priority = priority;
        this->completed = false; // Initially task is not completed
    }
};

stack<Task> undoStack;      // Stack to store deleted tasks for undo operation
vector<Task> NotesAdded;    // Vector to store all added tasks
vector<string> categories = {"Work", "Personal", "Study", "Shopping", "Other"};  // List of predefined categories

// Function to display all tasks
void displayTasks() {
    if (NotesAdded.empty()) {
        cout << "Please add some tasks first to view." << endl;
    } else {
        cout << "\nTasks:\n";
        cout << "   " << "Task" << " " << "Category" << " " << "Priority" << " " << "DueDate" << " " << "Status" << "\n";
        for (int i = 0; i < NotesAdded.size(); i++) {
            cout << i + 1 << ". "
                 << NotesAdded[i].description << " "
                 << NotesAdded[i].category << " "
                 << NotesAdded[i].priority << " "
                 << NotesAdded[i].dueDate << " "
                 << (NotesAdded[i].completed ? "Completed" : "Pending") << "\n";
        }
    }
}

// Function to mark a task as completed
void markTaskAsCompleted() {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= NotesAdded.size()) {
        NotesAdded[taskNumber - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid Task Number" << endl;
    }
}

// Function to delete a task
void deleteTask() {
    int taskNumber;
    cout << "Enter the task number to delete: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= NotesAdded.size()) {
        Task task = NotesAdded[taskNumber - 1];
        undoStack.push(task);  // Push deleted task onto the undo stack
        NotesAdded.erase(NotesAdded.begin() + taskNumber - 1);  // Remove task from NotesAdded vector
        cout << "Task deleted." << endl;
    } else {
        cout << "Invalid Task Number" << endl;
    }
}

// Function to undo the last deleted task
void undoDeleteTask() {
    if (!undoStack.empty()) {
        Task lastTask = undoStack.top();  // Get the last deleted task from the stack
        undoStack.pop();  // Remove the task from the stack
        NotesAdded.push_back(lastTask);  // Restore the task to NotesAdded vector
        cout << "Undo successful. Last deleted task restored." << endl;
    } else {
        cout << "Nothing to Undo." << endl;
    }
}

// Function to filter tasks by category
void filterTaskByCategory() {
    string filterCategory;
    cout << "Enter the category to filter by: ";
    cin >> filterCategory;

    cout << "\nFiltered Tasks (" << filterCategory << "):\n";
    cout << "   " << "Task" << " " << "Category" << " " << "Priority" << " " << "DueDate" << " " << "Status" << "\n";
    for (const auto& task : NotesAdded) {
        if (task.category == filterCategory) {
            cout << task.description << " "
                 << task.category << " "
                 << task.priority << " "
                 << task.dueDate << " "
                 << (task.completed ? "Completed" : "Pending") << "\n";
        }
    }
}

// Function to add a new task
void addTask() {
    string description, category, priority;

    cout << "Enter the Description: ";
    cin.ignore();
    getline(cin, description);

    auto now = time(nullptr);
    tm* current = localtime(&now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", current);
    string dueDate(buffer);  // Get current date as due date

    cout << "Choose a category: " << endl;
    for (size_t i = 0; i < categories.size(); ++i) {
        cout << i + 1 << ". " << categories[i] << endl;
    }

    int categoryChoice;
    cin >> categoryChoice;
    if (categoryChoice > 0 && categoryChoice <= categories.size()) {
        category = categories[categoryChoice - 1];
    } else {
        cout << "Invalid choice, defaulting to 'Other'" << endl;
        category = "Other";
    }

    cout << "Enter priority (HIGH/LOW/MEDIUM): ";
    cin >> priority;

    Task task(description, category, priority, dueDate);  // Create new Task object
    NotesAdded.push_back(task);  // Add task to NotesAdded vector
}

// Function to display the main menu and handle user inputs
void displayMenu() {
    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Add Task\n"
             << "2. View Tasks\n"
             << "3. Mark Task as Completed\n"
             << "4. Delete Task\n"
             << "5. Undo Last Delete\n"
             << "6. Filter Task By Category\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                undoDeleteTask();
                break;
            case 6:
                filterTaskByCategory();
                break;
            case 7:
                cout << "Goodbye! Please do the tasks on time." << endl;
                break;
            default:
                cout << "Please enter a valid choice." << endl;
        }
    } while (choice != 7);
}

int main() {
    displayMenu();  // Start the program by displaying the menu
    return 0;
}
