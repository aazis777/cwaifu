#include "cwaifu.h"
#include <ctype.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  // handle signal (CTRL + C)
  signal(SIGINT, handle_signal);

  // entry program
  cwaifu_menu();

  return 0;
}

void cwaifu_menu(void) {

  // initialize
  waifu *head = NULL;
  int id;
  char name[100];
  int age;
  char gender[50];
  char profession[100];

  char input[100];
  int choice = 0;

  // add some waifu
  create_waifu(&head, 1, "Yukinoshita Yukino", 19, "Female", "Student");
  create_waifu(&head, 2, "Mikasa Ackerman", 20, "Female", "Soldier");
  create_waifu(&head, 3, "Rem", 14, "Female", "Maid");

  // program loops
  while (choice != 5) {
    printf("\n");
    printf("welcome to CWaifu!\n");
    printf("there is some options you can use:\n");
    printf("1. create_waifu       - create your own waifu (trust me)\n");
    printf("2. print_waifu        - displaying all current waifu\n");
    printf("3. find_waifu_by_id   - search waifu by its id\n");
    printf("4. find_waifu_by_name - search waifu by its name\n");
    printf("5. exit               - exit from the program \n");
    printf("\n");

    printf("enter your choice: ");

    // input validation
    if (fgets(input, sizeof(input), stdin)) {
      input[strcspn(input, "\n")] = 0;

      if (strlen(input) == 0) {
        printf("input could not be empty.\n");
        break;
      }

      char *endptr;

      choice = strtol(input, &endptr, 10);

      if (*endptr != '\0') {
        printf("input must be a valid number.\n");
        continue;
        ;
      }

      // switch statements
      switch (choice) {
      case 1:
        printf("\nyou selected: \'create_waifu\'\n");

        printf("\nenter id              : ");
        if (scanf("%d", &id) != 1) {
          printf("id must be a number.\n");

          while (getchar() != '\n')
            ;
          exit(0);
        }

        while (getchar() != '\n')
          ;

        printf("enter the name: ");

        if (fgets(name, sizeof(name), stdin)) {
          name[strcspn(name, "\n")] = 0;

          if (strlen(name) == 0) {
            printf("name could not be empty.\n");
            exit(0);
          }

          if (!is_valid_string(name)) {
            printf("name must only contain letters.\n");
            exit(0);
          }
        }

        printf("enter the age: ");

        if (fgets(input, sizeof(input), stdin)) {
          input[strcspn(input, "\n")] = 0;

          if (strlen(input) == 0) {
            printf("age could not be empty.\n");
            exit(0);
          }

          char *endptr;

          age = strtol(input, &endptr, 10);

          if (*endptr != '\0') {
            printf("age must be a valid number.\n");
            exit(0);
          }

          printf("enter the gender: ");

          if (fgets(gender, sizeof(gender), stdin)) {
            gender[strcspn(gender, "\n")] = 0;

            if (strlen(gender) == 0) {
              printf("gender could not be empty.\n");
              exit(0);
            }

            if (!is_valid_string(gender)) {
              printf("gender must only contain letters.\n");
              exit(0);
            }
          }

          printf("enter the profession: ");
          if (fgets(profession, sizeof(profession), stdin)) {
            profession[strcspn(profession, "\n")] = 0;

            if (strlen(profession) == 0) {
              printf("profession could not be empty.\n");
              exit(0);
            }

            if (!is_valid_string(profession)) {
              printf("profession must only contain letters.\n");
              exit(0);
            }
          }

          create_waifu(&head, id, name, age, gender, profession);

          printf("\ncreate_waifu success!\nchoose option: \'print_waifu\' to displaying the waifu.\n");
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
          printf("enter the waifu id: ");

          if (scanf("%d", &id) != 1) {
            printf("id must be a number.\n");

            while (getchar() != '\n')
              exit(0);
          }

          while (getchar() != '\n')
            ;

          waifu *found_waifu = find_waifu_by_id(head, id);

          if (found_waifu) {
            printf("found waifu with id: %d\n", id);
            printf("\n");
            printf("id: %d\n", found_waifu->id);
            printf("name: %s\n", found_waifu->name);
            printf("age: %d\n", found_waifu->age);
            printf("gender: %s\n", found_waifu->gender);
            printf("profession: %s\n", found_waifu->profession);
          } else {
            printf("waifu with id: %d not found.\n", found_waifu->id);
            exit(0);
          }

          break;
        case 4:
          printf("you selected: find_waifu_by_name\n");
          printf("\n");
          printf("enter the name waifu name: ");

          if (fgets(name, sizeof(name), stdin)) {
            name[strcspn(name, "\n")] = 0;

            if (strlen(name) == 0) {
              printf("name could not be empty.\n");
              exit(0);
            }

            if (!is_valid_string(name)) {
              printf("name must only contain letters.\n");
              exit(0);
            }
          }

          found_waifu = find_waifu_by_name(head, name);

          if (found_waifu) {
            printf("found waifu with name: %s\n", name);
            printf("\n");
            printf("id: %d\n", found_waifu->id);
            printf("name: %s\n", found_waifu->name);
            printf("age: %d\n", found_waifu->age);
            printf("gender: %s\n", found_waifu->gender);
            printf("profession: %s\n", found_waifu->profession);
          } else {
            printf("waifu with name: %s not found.\n", found_waifu->name);
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
  }
}

waifu *create_waifu(waifu **head, int id, char *name, int age, char *gender, char *profession) {
  waifu *new_waif = (waifu *)malloc(sizeof(waifu));
  if (new_waif == NULL) {
    printf("error allocating memory for new waifu.\n");
    return NULL;
  }
  // add some waifu

  new_waif->id = id;
  new_waif->name = strdup(name);
  new_waif->age = age;
  new_waif->gender = strdup(gender);
  new_waif->profession = profession;
  new_waif->next = NULL;

  // conditional lists
  if (*head == NULL) {
    *head = new_waif;
  } else {
    // pointing next if waifu already exists
    waifu *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_waif;
  }

  return new_waif;
}

void print_waifu(waifu *node) {
  if (node == NULL) {
    printf("waifu undefined. NULL.\n");
    return;
  }

  // print waifu while not NULL
  while (node != NULL) {
    printf("id: %d\n", node->id);
    printf("name: %s\n", node->name);
    printf("age: %d\n", node->age);
    printf("gender: %s\n", node->gender);
    printf("profession: %s\n", node->profession);
    printf("\n");

    node = node->next;
  }
}

waifu *find_waifu_by_id(struct Waifu *head, int id) {
  // loops
  waifu *current = head;
  while (current != NULL) {
    // if id matched to current
    if (current->id == id) {
      return current;
    }
    current = current->next;
  }
  printf("waifu with id %d not found.\n", id);
  return NULL;
}

waifu *find_waifu_by_name(struct Waifu *head, char *name) {
  waifu *current = head;

  // loops
  while (current != NULL) {
    // if current->name equals to name
    if (strcmp(current->name, name) == 0) {
      return current;
    }
    current = current->next;
  }
  printf("waifu with name '%s' not found.\n", name);
  return NULL;
}

void edit_waifu_by_id(struct Waifu *head, int id, char *new_name, int new_age, char *new_gender, char *new_profession) {
  waifu *waifu = find_waifu_by_id(head, id);
  // conditional
  // if waifu exists then edit existing
  if (waifu != NULL) {
    waifu->name = new_name;
    waifu->age = new_age;
    waifu->gender = new_gender;
    waifu->profession = new_profession;
    printf("waifu with id %d has been updated.\n", id);
  } else {
    printf("failed to find waifu with id %d to edit.\n", id);
  }
}

void handle_signal(int sig) {
  printf("%d\n", sig);
  printf("\nbye dawg...\n");
  exit(0);
}

int is_valid_string(const char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (!(isalpha(str[i]) || str[i] == ' ')) { // check if character is not a letter or space
      return 0;
    }
  }
  return 1;
}
