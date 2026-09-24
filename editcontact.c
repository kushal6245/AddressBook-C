#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include "addressbook.h"


void edit_contact(struct AddressBook *addressBook)
{
    int choice;
    int contact_number;

    printf(YELLOW "\nAvailable Contacts:" RESET);
    list_contacts(addressBook);

    printf(BLUE "\nEnter the sl. no. of the contact to edit: " RESET);
    scanf("%d", &contact_number);

    if (contact_number < 1 || contact_number > addressBook->contactCount)
    {
        printf(RED_BOLD "Invalid contact number.\n" RESET);
        return;
    }

    int index = contact_number - 1;

    printf(YELLOW "\nSelected Contact:\n" RESET);

    printf(CYAN "Name  : %s\n", addressBook->contacts[index].name);
    printf("Phone : %s\n", addressBook->contacts[index].phone);
    printf("Email : %s\n" RESET, addressBook->contacts[index].email);

    printf(MAGENTA "\nWhat do you want to edit?\n");

    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("4. Return to menu\n" RESET);

    printf(BLUE "\nEnter your choice: " RESET);
    scanf("%d", &choice);

    while (getchar() != '\n');

    switch (choice)
    {
        case 1:

            printf(BLUE "Enter new name: " RESET);

            scanf(" %49[^\n]", addressBook->contacts[index].name);

            printf(GREEN_BOLD "\nName updated successfully.\n" RESET);

            break;


        case 2:
        {
            char phone[11];
            int valid = 0;

            do
            {
                valid = 1;

                printf(BLUE "Enter new phone number: " RESET);
                scanf("%10s", phone);

                while(getchar() != '\n');

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
                    if(i == index)
                    {
                        continue;
                    }

                    if(!strcmp(phone, addressBook->contacts[i].phone))
                    {
                        printf(MAGENTA "Phone number already exists. Please enter unique number.\n" RESET);
                        valid = 0;
                        break;
                    }
                }

            } while (!valid);

            strcpy(addressBook->contacts[index].phone, phone);

            printf(GREEN_BOLD "\nPhone number updated successfully.\n" RESET);
            sleep(2);
            break;
        }
        
        case 3:
        {
            char email[50];
            int valid = 0;

            do
            {        
            
                valid = 1;

                printf(BLUE "Enter new email: " RESET);
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
                    if(i == index)
                    {
                        continue;
                    }

                    if(!strcmp(email, addressBook->contacts[i].email))
                    {
                        printf(MAGENTA "Email already exists. Please enter unique email.\n" RESET);
                        valid = 0;
                        break;
                    }
                }

            } while (!valid);

            strcpy(addressBook->contacts[index].email, email);

            printf(GREEN_BOLD "\nEmail updated successfully.\n" RESET);
            sleep(2);
            break;
        }

        case 4:

            printf(GREEN "\nReturning to menu...\n" RESET);
            sleep(2);
            return;


        default:

            printf(RED_BOLD "\nInvalid input.\n" RESET);
            sleep(2);
            return;
    }


    save_contacts(addressBook);

    printf(GREEN "\nChanges saved successfully.\n" RESET);
    sleep(2);
}