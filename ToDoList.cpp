/* TASK 4 : TO-DO LIST

Build a simple console-based to-do list manager that allows users to add, view, and delete tasks

Task Input: Allow users to input tasks they want to add to the list.
Add Task: Implement a function to add tasks to the list.
View Tasks: Display the list of tasks with their status (completed or
pending).
Mark Task as Completed: Allow users to mark tasks as completed.
Remove Task: Provide an option to remove tasks from the list. */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task class representing each task
class Task 
{
private:
    string description;
    bool completed;

public:
    // Constructor to initialize task with description and default completed status (false)
    Task(const string& desc) : description(desc), completed(false) {}

    // Method to mark the task as completed
    void markAsCompleted() 
	{
        completed = true;
    }

    // Method to get task description
    string getDescription() const 
	{
        return description;
    }

    // Method to check if the task is completed
    bool isCompleted() const 
	{
        return completed;
    }
};

// ToDoList class to manage tasks
class ToDoList 
{
private:
    vector<Task> tasks;

public:
    // Method to add a new task
    void addTask(const string& description) 
	{
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    // Method to view all tasks
    void viewTasks() const 
	{
        if (tasks.empty()) 
		{
            cout << "No tasks in the list." << endl;
        } 
		else 
		{
            cout << "Tasks:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].getDescription() << " - ";
                if (tasks[i].isCompleted()) {
                    cout << "Completed";
                } else {
                    cout << "Pending";
                }
                cout << endl;
            }
        }
    }

    // Method to mark a task as completed
    void markTaskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].markAsCompleted();
            cout << "Marked task as completed: " << tasks[index - 1].getDescription() << endl;
        } else {
            cout << "Invalid task number. No task marked." << endl;
        }
    }

    // Method to remove a task
    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            cout << "Removed task: " << tasks[index - 1].getDescription() << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task number. No task removed." << endl;
        }
    }
};

// Main function for Execution 
int main() 
{
    ToDoList tdl;
    int choice;
    string taskDescription;
    size_t taskIndex;

    while (true) 
	{
        // Display menu
        cout << "\n===== To-Do List in C++ =====" << endl;
        cout << "1. Add Task to the List " << endl;
        cout << "2. View Tasks of the List " << endl;
        cout << "3. Mark Task as Completed the Task " << endl;
        cout << "4. Remove Task from the List " << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                cout << "Enter task description: ";
                cin.ignore(); // ignore newline character in buffer
                getline(cin, taskDescription);
                tdl.addTask(taskDescription);
                break;
            case 2:
                tdl.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                tdl.markTaskCompleted(taskIndex);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskIndex;
                tdl.removeTask(taskIndex);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }

    return 0;
}

