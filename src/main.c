#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct {
    char name[51];
    int day;
    bool completo;
    int taskId;
} task;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

task tarefas[21];
int totalTarefas = 0;

void createTask() 
{
    system("clear");

    if (totalTarefas >= 21) {
        printf("[!] task limit reached\n");
        return;
    }

    printf("taskname: ");
    fgets(tarefas[totalTarefas].name, sizeof(tarefas[totalTarefas].name), stdin);
    tarefas[totalTarefas].name[strcspn(tarefas[totalTarefas].name, "\n")] = '\0';

    int dl;
    printf("\nDeadline (day): ");
    scanf("%i", &dl);
    clearBuffer();

    tarefas[totalTarefas].day = dl;
    tarefas[totalTarefas].taskId = totalTarefas;
    tarefas[totalTarefas].completo = false;

    printf("[*] task created successfully.\n");
    totalTarefas++;
    sleep(2);
    system("clear");
}

void showTasks()
{
    system("clear");

    if (totalTarefas == 0) {
        printf("[!] no tasks to show.\n");
        sleep(2);
        system("clear");
        return;
    }

    for (int j = 0; j < totalTarefas; j++) {
        printf("-------------------[ %i ]---------------------\n", tarefas[j].taskId);
        printf("Name: %s\n", tarefas[j].name);
        printf("Days: %i\n", tarefas[j].day);      
    }

    sleep(2);
    system("clear");
}

int main() 
{
    int chc;
    while (true) {
        printf("\n1) create task\n");
        printf("2) view tasks\n");

        printf(">> ");
        scanf("%i", &chc);
        clearBuffer();
    
        if (chc == 1) {
            createTask(); 
        } else if (chc == 2) {
            showTasks();
        } else {
            printf("[ - ] invalid option\n");
        }
    }
}
