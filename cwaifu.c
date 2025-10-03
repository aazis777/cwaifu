#include "cwaifu.h"
#include <ctype.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cwaifu_menu(void)
{
    // initialize
    waifu *head = NULL;
    int    id, age, choice = 0;
    char   name[100], gender[50], profession[100];

    // add some waifu
    create_waifu(&head, 1, "Yukinoshita Yukino", 19, "Female", "Student");
    create_waifu(&head, 2, "Mikasa Ackerman", 20, "Female", "Soldier");
    create_waifu(&head, 3, "Rem", 14, "Female", "Maid");

    // program loops
    while (choice != 5)
    {
        printf("\n");
        printf("welcome to CWaifu!\n");
        printf("there is some options you can use:\n");
        printf("1. create_waifu       - create your own waifu (trust me)\n");
        printf("2. print_waifu        - displaying all current waifu\n");
        printf("3. find_waifu_by_id   - search waifu by its id\n");
        printf("4. find_waifu_by_name - search waifu by its name\n");
        printf("5. exit               - exit from the program \n");
        printf("\n");

        choice = get_int_input("enter your choice: ");

        // switch statements
        switch (choice)
        {
            case 1:
                printf("\nyou selected: \'create_waifu\'\n");

                id = get_int_input("enter the id: ");
                get_string_input("enter the name: ", name, sizeof(name));
                age = get_int_input("enter the age: ");
                get_string_input("enter the gender: ", gender, sizeof(gender));
                get_string_input("enter the profession: ", profession,
                                 sizeof(profession));

                create_waifu(&head, id, name, age, gender, profession);

                printf(
                    "\ncreate_waifu success!\nchoose option: \'print_waifu\' "
                    "to "
                    "displaying the waifu.\n");
                break;
            case 2:
                printf("\nyou selected: \'print_waifu\'\n");
                printf("\n");
                printf("list of waifu:\n");
                printf("\n");

                print_waifu(head);
                break;
            case 3:
                printf("you selected: find_waifu_by_id\n");
                printf("\n");

                id = get_int_input("enter the waifu id: ");

                waifu *found_waifu = find_waifu_by_id(head, id);

                if (found_waifu)
                {
                    printf("found waifu with id: %d\n", id);
                    printf("\n");
                    printf("id: %d\n", found_waifu->id);
                    printf("name: %s\n", found_waifu->name);
                    printf("age: %d\n", found_waifu->age);
                    printf("gender: %s\n", found_waifu->gender);
                    printf("profession: %s\n", found_waifu->profession);
                }
                else
                {
                    printf("waifu with id: %d not found.\n", found_waifu->id);
                    exit(0);
                }

                break;
            case 4:
                printf("you selected: find_waifu_by_name\n");
                printf("\n");

                get_string_input("enter the waifu name: ", name, sizeof(name));

                found_waifu = find_waifu_by_name(head, name);

                if (found_waifu)
                {
                    printf("found waifu with name: %s\n", name);
                    printf("\n");
                    printf("id: %d\n", found_waifu->id);
                    printf("name: %s\n", found_waifu->name);
                    printf("age: %d\n", found_waifu->age);
                    printf("gender: %s\n", found_waifu->gender);
                    printf("profession: %s\n", found_waifu->profession);
                }
                else
                {
                    printf("waifu with name: %s not found.\n",
                           found_waifu->name);
                    exit(0);
                }

                break;
            case 5:
                printf("thanks for using CWaifu program!\n");
                break;
            default:
                printf("invalid choice. please select a valid option (1-5).\n");
                break;
        }
    }
}

waifu *create_waifu(waifu **head, int id, char *name, int age, char *gender,
                    char *profession)
{
    waifu *new_waif = (waifu *) malloc(sizeof(waifu));
    if (new_waif == NULL)
    {
        printf("error allocating memory for new waifu.\n");
        return NULL;
    }
    // add some waifu

    new_waif->id         = id;
    new_waif->name       = strdup(name);
    new_waif->age        = age;
    new_waif->gender     = strdup(gender);
    new_waif->profession = profession;
    new_waif->next       = NULL;

    // conditional lists
    if (*head == NULL)
    {
        *head = new_waif;
    }
    else
    {
        // pointing next if waifu already exists
        waifu *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_waif;
    }

    return new_waif;
}

void print_waifu(waifu *node)
{
    if (node == NULL)
    {
        printf("waifu undefined. NULL.\n");
        return;
    }

    // print waifu while not NULL
    while (node != NULL)
    {
        printf("id: %d\n", node->id);
        printf("name: %s\n", node->name);
        printf("age: %d\n", node->age);
        printf("gender: %s\n", node->gender);
        printf("profession: %s\n", node->profession);
        printf("\n");

        node = node->next;
    }
}

waifu *find_waifu_by_id(struct Waifu *head, int id)
{
    // loops
    waifu *current = head;
    while (current != NULL)
    {
        // if id matched to current
        if (current->id == id)
        {
            return current;
        }
        current = current->next;
    }
    printf("waifu with id %d not found.\n", id);
    return NULL;
}

waifu *find_waifu_by_name(struct Waifu *head, char *name)
{
    waifu *current = head;

    // loops
    while (current != NULL)
    {
        // if current->name equals to name
        if (strcmp(current->name, name) == 0)
        {
            return current;
        }
        current = current->next;
    }
    printf("waifu with name '%s' not found.\n", name);
    return NULL;
}

void edit_waifu_by_id(struct Waifu *head, int id, char *new_name, int new_age,
                      char *new_gender, char *new_profession)
{
    waifu *waifu = find_waifu_by_id(head, id);
    // conditional
    // if waifu exists then edit existing
    if (waifu != NULL)
    {
        waifu->name       = new_name;
        waifu->age        = new_age;
        waifu->gender     = new_gender;
        waifu->profession = new_profession;
        printf("waifu with id %d has been updated.\n", id);
    }
    else
    {
        printf("failed to find waifu with id %d to edit.\n", id);
    }
}

void handle_signal(int sig)
{
    printf("%d\n", sig);
    printf("\nbye dawg...\n");
    exit(0);
}

int is_valid_string(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!(isalpha(str[i]) || str[i] == ' '))
        { // check if character is not a letter or space
            return 0;
        }
    }
    return 1;
}

int get_int_input(const char *prompt)
{
    char input[100];
    int  value;
    while (1)
    {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin))
        {
            input[strcspn(input, "\n")] = 0;
            char *endptr;
            value = strtol(input, &endptr, 10);
            if (*endptr == '\0' && strlen(input) > 0)
            {
                return value;
            }
        }
        printf("Invalid input. Please enter a valid number.\n");
    }
}

void get_string_input(const char *prompt, char *buffer, size_t size)
{
    while (1)
    {
        printf("%s", prompt);
        if (fgets(buffer, size, stdin))
        {
            buffer[strcspn(buffer, "\n")] = 0;
            if (strlen(buffer) > 0 && is_valid_string(buffer))
            {
                return;
            }
        }
        printf("Invalid input. Please enter a valid string.\n");
    }
}

int main(void)
{
    // handle signal (CTRL + C)
    signal(SIGINT, handle_signal);

    // entry program
    cwaifu_menu();

    return 0;
}
