#ifndef CONTACT_H
#define CONTACT_H
#include <stdio.h>


struct Contact{
    char name[50];
    char phone[11];
    char email[50];
};

struct AddressBook {
    struct Contact contacts[100];
    int contactCount;
    int index_record[100];
    int ir_size;
};

void load_contacts(struct AddressBook *addressBook);
void save_contacts(struct AddressBook *addressBook);

void add_contact(struct AddressBook *addressBook);
int search_contact(struct AddressBook *addressBook, int select);
void edit_contact(struct AddressBook *addressBook);
void delete_contact(struct AddressBook *addressBook);
void list_contacts(struct AddressBook *addressBook);

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[3;33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RED_BOLD    "\033[1;31m"
#define GREEN_BOLD  "\033[3;32m"
#define RESET       "\033[0m"

#endif