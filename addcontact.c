#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include "addressbook.h"

void get_valid_phone(struct AddressBook *addressBook, char *phone);
void get_valid_email(struct AddressBook *addressBook, char *email);


void add_contact(struct AddressBook *addressBook)
{
    printf(YELLOW "\nCreate contact" RESET);
    printf(BLUE "\nEnter the name: " RESET);
    while(getchar() != '\n');
    scanf(" %49[^\n]", addressBook->contacts[addressBook->contactCount].name);

    get_valid_phone(addressBook, addressBook->contacts[addressBook->contactCount].phone);
    get_valid_email(addressBook, addressBook->contacts[addressBook->contactCount].email);

    addressBook->contactCount++;
    
    save_contacts(addressBook);
    printf(GREEN_BOLD "\nContact Created Successfully!!\n" RESET);
    printf(GREEN "Returning to Menu..\n" RESET);

    sleep(1.5);
}

//Get Valid Phone Number
void get_valid_phone(struct AddressBook *addressBook, char *phone)
{
    int valid;

    do
    {
        while(getchar() != '\n');

        valid = 1;

        printf(BLUE "Enter phone number: " RESET);
        scanf("%10s", phone);

        if (strlen(phone) != 10)
        {
            valid = 0;
        }
        else
        {
            for (size_t i = 0; phone[i] != '\0'; i++)
            {
                if (!isdigit(phone[i]))
                {
                    valid = 0;
                    break;
                }
            }

            if (valid && (phone[0] < '6' || phone[0] > '9'))
            {
                valid = 0;
            }
        }

        if (!valid)
        {
            printf(RED_BOLD "Invalid phone number. Please enter a valid 10-digit number.\n" RESET);
            continue;
        }

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(!strcmp(phone, addressBook->contacts[i].phone))
            {
                printf(MAGENTA "Phone number already exists. Please enter unique number.\n" RESET);
                valid = 0;
                break;
            }
        }

    } while (!valid);
}

//Get Valid Email
void get_valid_email(struct AddressBook *addressBook, char *email)
{
    int valid;

    do
    {
        while(getchar() != '\n');
        
        valid = 1;

        printf(BLUE "Enter email: " RESET);
        scanf("%49s", email);

        int at_count = 0;
        int dot_count = 0;
        int at_position = -1;
        int dot_position = -1;

        char dotcom[] = {".com"};

        for (size_t i = 0; email[i] != '\0'; i++)
        {
            if (email[i] == '@')
            {
                at_count++;
                at_position = i;
            }
        

            if (email[i] == '.')
            {
                dot_count++;
                dot_position = i;
            }

            if (isspace(email[i]))
            {
                valid = 0;
            }
        }

        if (strcmp(&email[dot_position], dotcom))
        {
            valid = 0;
        }
    
        if (at_count != 1)
        {
            valid = 0;
        }

        if (dot_count < 1)
        {
            valid = 0;
        }

        if (at_position <= 0)
        {
            valid = 0;
        }

        if (dot_position <= at_position + 1)
        {
            valid = 0;
        }

        if (email[dot_position + 4] != '\0')
        {
            valid = 0;
        }

        if(valid)
        {
            for(int i = at_position; i < dot_position; i++)
            {
                if(isdigit(email[i]))
                {
                    valid = 0;
                }
            }
        }

        if (!valid)
        {
            printf(RED_BOLD "Invalid email. Please try again.\n" RESET);
            continue;
        }

        for(int i = 0; i < addressBook->contactCount; i++)
        {
            if(!strcmp(email, addressBook->contacts[i].email))
            {
                printf(MAGENTA "Email already exists. Please enter unique email.\n" RESET);
                valid = 0;
                break;
            }
        }

    } while (!valid);
}