#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
    private:
        string name;
        string description;
        string dueDate;
        bool completed;
    public:
        Task(string name, string description, string dueDate) {
            this->name = name;
            this->description = description;
            this->dueDate = dueDate;
            this->completed = false;
        }
        string getName() {
            return name;
        }
        string getDescription() {
            return description;
        }
        string getDueDate() {
            return dueDate;
        }
        bool isCompleted() {
            return completed;
        }
        void setCompleted(bool completed) {
            this->completed = completed;
        }
};

class TaskList {
    private:
        vector<Task> tasks;
    public:
        void addTask(Task task) {
            tasks.push_back(task);
        }
        void removeTask(int index) {
            tasks.erase(tasks.begin() + index);
        }
        void displayTasks() {
            if (tasks.empty()) {
                cout << "No tasks to display" << endl;
            } else {
                for (int i = 0; i < tasks.size(); i++) {
                    cout << i+1 << ". " << tasks[i].getName() << " - " << tasks[i].getDescription() << " - Due: " << tasks[i].getDueDate() << endl;
                }
            }
        }
};

int main() {
    TaskList taskList;
    int choice;
    do {
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. Display Tasks" << endl;
        cout << "4. Mark Task Complete" << endl;
        cout << "5. Mark Task Incomplete" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string name, description, dueDate;
                cout << "Enter task name: ";
                cin >> name;
                cout << "Enter task description: ";
                cin >> description;
                cout << "Enter task due date: ";
                cin >> dueDate;
                Task task(name, description, dueDate);
                taskList.addTask(task);
                break;
            }
            case 2: {
                int index;
                cout << "Enter index of task to remove: ";
                cin >> index;
                taskList.removeTask(index-1);
                break;
            }
            case 3: {
                taskList.displayTasks();
                break;
            }
            case 4: {
                int index;
                cout << "Enter index of task to mark complete: ";
                cin >> index;
                Task task = taskList.getTask(index-1);
                task.setCompleted(true);
                break;
            }
            case 5: {
                int index;
                cout << "Enter index of task to mark incomplete: ";
                cin >> index;
                Task task = taskList
