#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task>& taskList, const string& description) {
    Task newTask = {description, false};
    taskList.push_back(newTask);
}

void viewTasks(const vector<Task>& taskList) {
    cout << "Tasks:\n";
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << i+1 << ". " << taskList[i].description << " - ";
        cout << (taskList[i].completed ? "Completed" : "Pending") << endl;
    }
}

void markAsCompleted(vector<Task>& taskList, size_t index) {
    if (index >= 0 && index < taskList.size()) {
        taskList[index].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

void removeTask(vector<Task>& taskList, size_t index) {
    if (index >= 0 && index < taskList.size()) {
        taskList.erase(taskList.begin() + index);
        cout << "Task removed.\n";
    } else {
        cout << "Invalid task index.\n";
    }
}

int main() {
    vector<Task> taskList;

    char choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1': {
                string description;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                addTask(taskList, description);
                break;
            }
            case '2':
                viewTasks(taskList);
                break;
            case '3': {
                size_t index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                markAsCompleted(taskList, index - 1); 
                break;
            }
            case '4': {
                size_t index;
                cout << "Enter task index to remove: ";
                cin >> index;
                removeTask(taskList, index - 1); 
                break;
            }
            case '5':
                cout << "Quitting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}
