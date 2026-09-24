#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include "addressbook.h"

void list_contacts(struct AddressBook *addressBook)
{
    if(addressBook->contactCount == 0)
    {
        printf(RED "\nNo Contacts Found!!\n" RESET);
        return;
    }


    printf(YELLOW "\nTotal %d %s." RESET, addressBook->contactCount, addressBook->contactCount == 1 ? "contact" : "contacts");
    printf("\n+---------+-------------------+------------------+--------------------------------+\n");

        printf("|"CYAN" %-7s "RESET"|"CYAN" %-17s "RESET"|"CYAN" %-16s "RESET"|"CYAN" %-30s "RESET"|\n", "Sl. No.", "Name", "Phone Number", "Email");

    printf("+---------+-------------------+------------------+--------------------------------+\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("|"GREEN" %-7d "RESET"|"GREEN" %-*.*s "RESET"|"GREEN" +91 %-*.*s "RESET"|"GREEN" %-*.*s "RESET"|\n",
               i + 1,

               17, (int)strcspn(addressBook->contacts[i].name, "\n"), addressBook->contacts[i].name,

               12, (int)strcspn(addressBook->contacts[i].phone, "\n"), addressBook->contacts[i].phone,

               30, (int)strcspn(addressBook->contacts[i].email, "\n"), addressBook->contacts[i].email);
    }

    printf("+---------+-------------------+------------------+--------------------------------+\n");

    printf(GREEN "Returning to menu...\n" RESET);

    sleep(1);
}