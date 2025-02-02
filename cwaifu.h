#ifndef CWAIFU_H
#define CWAIFU_H

#include <stddef.h>

struct Waifu
{
  int           id;
  char         *name;
  int           age;
  char         *gender;
  char         *profession;
  struct Waifu *next;
};

// typedef for waifu structure
typedef struct Waifu waifu;

// cwaifu_menu function prototype
void cwaifu_menu(void);
// create waifu function prototype
waifu *create_waifu(waifu **head, int id, char *name, int age, char *gender,
                    char *profession);

// search waifu based on ID function prototype
waifu *find_waifu_by_id(waifu *head, int id);

// search waifu based on name function prototype
waifu *find_waifu_by_name(waifu *head, char *name);

// edit waifu based on ID function prototype
void edit_waifu_by_id(waifu *head, int id, char *new_name, int new_age,
                      char *new_gender, char *new_profession);

// print waifu node function prototype
void print_waifu(waifu *node);

// handle_signal function prototype
void handle_signal(int sig);

// handle input string function prototype
int is_valid_string(const char *str);

// handle get int input function prototype
int get_int_input(const char *prompt);

// handle get string input function prototype
void get_string_input(const char *prompt, char *buffer, size_t size);

#endif // CWAIFU_H
