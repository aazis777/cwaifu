#ifndef CWAIFU_H
#define CWAIFU_H

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


#endif // CWAIFU_H
