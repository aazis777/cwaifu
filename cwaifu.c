#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Waifu {
  int id;
  char *name;
  int age;
  char *gender;
  char *profession;
  struct Waifu *next;
};

// typedef for waifu structure
typedef struct Waifu waifu;

void cwaifu_menu();
// create waifu function prototype
waifu *create_waifu(waifu **head, int id, char *name, int age, char *gender, char *profession);

// search waifu based on ID function prototype
waifu *find_waifu_by_id(waifu *head, int id);

// search waifu based on name function prototype
waifu *find_waifu_by_name(waifu *head, char *name);

// edit waifu based on ID function prototype
void edit_waifu_by_id(waifu *head, int id, char *new_name, int new_age, char *new_gender, char *new_profession);

// print waifu node function prototype
void print_waifu(waifu *node);

int main(void)
{
  waifu *head = NULL;  // Pointer for waifu's collection (linked list)

  // Add some waifu
  create_waifu(&head, 1, "Yukino", 19, "Female", "Student");
  create_waifu(&head, 2, "Mikasa", 20, "Female", "Soldier");
  create_waifu(&head, 3, "Rem", 12, "Female", "Maid");

  // Print all waifus
  print_waifu(head);

  // Search waifu based on ID
  waifu *found_waifu = find_waifu_by_id(head, 2);
  if (found_waifu) {
    printf("Found Waifu by ID 2: %s\n", found_waifu->name);
  }

  // Search waifu based on name
  found_waifu = find_waifu_by_name(head, "Rem");
  if (found_waifu) {
    printf("Found Waifu by Name: %s\n", found_waifu->name);
  }

  // Edit waifu based on ID
  edit_waifu_by_id(head, 2, "Mikasa Ackerman", 21, "Female", "Captain");
  printf("After editing:\n");
  print_waifu(head);

  return 0;
}

waifu *create_waifu(waifu **head, int id, char *name, int age, char *gender, char *profession)
{
  waifu *new_waif = (waifu*)malloc(sizeof(waifu));
  if (new_waif == NULL) {
    printf("Error allocating memory for new waifu.\n");
    return NULL;
  }
  // Add some waifu

  new_waif->id = id;
  new_waif->name = name;
  new_waif->age = age;
  new_waif->gender = gender;
  new_waif->profession = profession;
  new_waif->next = NULL;

  // Conditional lists
  if (*head == NULL) {
    *head = new_waif;
  } else {
    // Pointing next if waifu already exists
    waifu *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_waif;
  }

  return new_waif;
}

void print_waifu(waifu *node)
{
  if (node == NULL) {
    printf("Waifu undefined. NULL.\n");
    return;
  }

  // Print waifu while not NULL
  while (node != NULL) {
    printf("ID: %d\n", node->id);
    printf("Name: %s\n", node->name);
    printf("Age: %d\n", node->age);
    printf("Gender: %s\n", node->gender);
    printf("Profession: %s\n", node->profession);
    printf("\n");

    node = node->next;
  }
}

waifu *find_waifu_by_id(struct Waifu *head, int id)
{
  // Loops
  waifu *current = head;
  while (current != NULL) {
    // if id matched to current
    if (current->id == id) {
      return current;
    }
    current = current->next;
  }
  printf("Waifu with ID %d not found.\n", id);
  return NULL;
}

waifu *find_waifu_by_name(struct Waifu *head, char *name)
{
  waifu *current = head;

  // Loops
  while (current != NULL) {
    // if current->name equals to name
    if (strcmp(current->name, name) == 0) {
      return current;
    }
    current = current->next;
  }
  printf("Waifu with name '%s' not found.\n", name);
  return NULL;
}

void edit_waifu_by_id(struct Waifu *head, int id, char *new_name, int new_age, char *new_gender, char *new_profession)
{
  waifu *waifu = find_waifu_by_id(head, id);
  // Conditional
  // If waifu exists then edit existing
  if (waifu != NULL) {
    waifu->name = new_name;
    waifu->age = new_age;
    waifu->gender = new_gender;
    waifu->profession = new_profession;
    printf("Waifu with ID %d has been updated.\n", id);
  } else {
    printf("Failed to find waifu with ID %d to edit.\n", id);
  }
}
