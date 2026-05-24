#include <stdio.h>
#include <string.h>

struct Task {
    char title[100];
    int isCompleted;
};

struct Task taskList[100];
int taskCount = 0; 

void displayTasks() {
    printf("\n--- Your To-Do List ---\n");
    if (taskCount == 0) {
        printf("No tasks yet!\n");
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        printf("%d. %s - [%s]\n", i + 1, taskList[i].title, taskList[i].isCompleted == 1 ? "Completed" : "Not Completed");
    }
    printf("-----------------------\n");
}

void addTask() {
    if (taskCount >= 100) {
        printf("Sorry, the list is full!\n");
        return;
    }
    printf("Enter task description: ");
    scanf(" %[^\n]s", taskList[taskCount].title); 
    taskList[taskCount].isCompleted = 0; 
    taskCount++; 
    printf("Task added successfully!\n");
}

void deleteTask() {
    int id;
    displayTasks();
    if(taskCount == 0) return;
    
    printf("Enter task number to delete: ");
    scanf("%d", &id);
    
    if (id > 0 && id <= taskCount) {
   
        for (int i = id - 1; i < taskCount - 1; i++) {
            taskList[i] = taskList[i + 1];
        }
        taskCount--; 
        printf("Task deleted!\n");
    } else {
        printf("Invalid task number!\n");
    }
}

void editTask() {
    int id;
    displayTasks();
    if(taskCount == 0) return;

    printf("Enter task number to edit: ");
    scanf("%d", &id);
    
    if (id > 0 && id <= taskCount) {
        printf("Enter new description: ");
        scanf(" %[^\n]s", taskList[id - 1].title);
        printf("Task updated!\n");
    } else {
        printf("Invalid task number!\n");
    }
}

void markTaskStatus() {
    int id, status;
    displayTasks();
    if(taskCount == 0) return;

    printf("Enter task number to change status: ");
    scanf("%d", &id);
    
    if (id > 0 && id <= taskCount) {
        printf("Enter 1 for 'Completed' or 0 for 'Not Completed': ");
        scanf("%d", &status);
        if (status == 1 || status == 0) {
            taskList[id - 1].isCompleted = status;
            printf("Status updated!\n");
        } else {
            printf("Invalid input! Please enter 1 or 0.\n");
        }
    } else {
        printf("Invalid task number!\n");
    }
}

int main() {
    int choice;
    printf("Welcome to Simple To-Do List!\n");
    
    do {
        printf("\n1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Edit Task\n");
        printf("4. Mark Task Status\n");
        printf("5. View All Tasks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addTask(); break;
            case 2: deleteTask(); break;
            case 3: editTask(); break;
            case 4: markTaskStatus(); break;
            case 5: displayTasks(); break;
            case 6: printf("Goodbye!\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
    