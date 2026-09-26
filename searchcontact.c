#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "addressbook.h"

void search_list(struct AddressBook *addressBook);

int search_contact(struct AddressBook *addressBook, int select)
{
    int find;
    char search[50];
    char *type[] = {"", "name", "phone", "email"};

    printf(YELLOW "\nSearch contact\n" RESET);
	printf(CYAN "1. By name\n");
    printf("2. By phone\n");
	printf("3. By email\n");
    printf("4. Return to menu\n" RESET);

    do
    {
	    printf(BLUE "\nEnter the search option: " RESET);
	    scanf("%d", &find);

        if(find < 1 || find > 4)
        {
            printf(RED_BOLD "\nInvalid input. Please try again\n" RESET);
            while(getchar() != '\n');
        } 

    } while(find < 1 || find > 4);

    //Return to menu
    if (find == 4)
    {
        printf(GREEN "\nReturning to menu...\n" RESET);
        return -1;
    }
    
    printf(BLUE "Enter %s: " RESET, type[find]);
    scanf(" %49[^\n]", search);
    
    addressBook->ir_size = 0;

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        int match = 0;

        switch (find)
        {
            case 1:
                if (strcmp(addressBook->contacts[i].name, search) == 0)
                    match = 1;
                break;

            case 2:
                if (strcmp(addressBook->contacts[i].phone, search) == 0)
                    match = 1;
                break;

            case 3:
                if (strcmp(addressBook->contacts[i].email, search) == 0)
                    match = 1;
                break;
        }

        if (match)
        {
            addressBook->index_record[addressBook->ir_size] = i;
            addressBook->ir_size++;
        }
    }

    if (addressBook->ir_size == 0)
    {
        printf(RED "\nContact not found!!..\n" RESET);
        return -1;
    }

    if (select == 2)
    {
        search_list(addressBook);
  
        printf(GREEN "\nReturning to menu...\n" RESET);
        sleep(1);
        return -1;
    }

    search_list(addressBook);
    
    int contact_number;

    printf(BLUE "\nEnter the sl. no. of the contact: " RESET);
    scanf("%d", &contact_number);

    if (contact_number < 1 || contact_number > addressBook->ir_size)
    {
        printf(RED_BOLD "Invalid number.\n" RESET);
        while(getchar() != '\n');
        return -1;
    }

    return addressBook->index_record[contact_number - 1];
}


// Function to print found contacts.
void search_list(struct AddressBook *addressBook)
{
    printf(YELLOW "\nSearch Results: %d %s found." RESET, addressBook->ir_size, addressBook->ir_size == 1 ? "contact" : "contacts");

    printf("\n+---------+-------------------+------------------+--------------------------------+\n");

    printf("|"CYAN" %-7s "RESET"|"CYAN" %-17s "RESET"|"CYAN" %-16s "RESET"|"CYAN" %-30s "RESET"|\n", "Sl. No.", "Name", "Phone Number", "Email");

    printf("+---------+-------------------+------------------+--------------------------------+\n");

    for (int i = 0; i < addressBook->ir_size; i++)
    {
        int index = addressBook->index_record[i];

        printf("|"GREEN" %-7d "RESET"|"GREEN" %-*.*s "RESET"|"GREEN" +91 %-*.*s "RESET"|"GREEN" %-*.*s "RESET"|\n",
               i + 1,

               17,
               (int)strcspn(addressBook->contacts[index].name, "\n"),
               addressBook->contacts[index].name,

               12,
               (int)strcspn(addressBook->contacts[index].phone, "\n"),
               addressBook->contacts[index].phone,

               30,
               (int)strcspn(addressBook->contacts[index].email, "\n"),
               addressBook->contacts[index].email);
    }

    printf("+---------+-------------------+------------------+--------------------------------+\n");
}