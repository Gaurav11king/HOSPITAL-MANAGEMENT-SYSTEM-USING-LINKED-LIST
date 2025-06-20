#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient
{
    int id;
    char name[30];
    int age;
    char disease[40];
    struct Patient* next;
};

struct Patient* head = NULL;

void addPatient()
{
    struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));
    printf("Enter ID: ");
    scanf("%d", &newPatient->id);
    printf("Enter Name: ");
    scanf(" %s", newPatient->name);
    printf("Enter Age: ");
    scanf("%d", &newPatient->age);
    printf("Enter Disease: ");
    scanf("%s",newPatient->disease);
    newPatient->next = head;
    head = newPatient;
    printf("Patient added.\n");
}

void viewPatients()
{
    struct Patient* temp = head;
    while (temp != NULL)
    {
        printf("Name: %s, ID: %d,  Age: %d, Disease: %s\n",temp->name,temp->id,temp->age,temp->disease);
        temp = temp->next;
    }
}

void searchPatient()
{
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    struct Patient* temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("Found: %s, Age: %d, Disease: %s\n", temp->name, temp->age,temp->disease);
            return;
        }
        temp = temp->next;
    }
    printf("Patient not found.\n");
}

void deletePatient()
{
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    struct Patient *temp = head, *prev = NULL;
    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Patient not found.\n");
        return;
    }
    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
    printf("Patient deleted.\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n--- Hospital Menu ---\n");
        printf("1. Add Patient\n2. View Patients\n3. Search Patient\n4. Delete Patient\n5. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                addPatient();
                break;
            }
            case 2: 
            {
                viewPatients();
                break;
            }
            case 3:
            {
                searchPatient();
                break;
            }
            case 4:
            {
                deletePatient();
                break;
            }
            case 5:
            {
                printf("Exiting...\n");
                break;
            }
            default:
            {
                printf("Invalid choice.\n");
            }
        }
    }
    while (choice != 5);
    return 0;
}
