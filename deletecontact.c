#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#include "addressbook.h"

void delete_contact(struct AddressBook *addressBook)
{
    int contact_number;
    int index;

    printf(YELLOW "\nAvailable Contacts:" RESET);
    list_contacts(addressBook);
   
    printf(BLUE "\nEnter the sl. number of the contact to delete: " RESET);
    scanf("%d", &contact_number);

    if (contact_number < 1 || contact_number > addressBook->contactCount)
    {
        printf(RED_BOLD "Invalid contact number.\n" RESET);
        return;
    }

    index = contact_number - 1;

    printf(YELLOW "\nContact selected for deletion:\n" RESET);

    printf(CYAN "Name  : %s\n", addressBook->contacts[index].name);
    printf("Phone : %s\n", addressBook->contacts[index].phone);
    printf("Email : %s\n" RESET, addressBook->contacts[index].email);

    printf(YELLOW "\nConfirm:" RESET);
    printf(CYAN "\n1. Yes");
    printf("\n2. No\n" RESET);

    int confirm = 0;

    do
    {
        printf(BLUE "Enter: " RESET);
        scanf("%d", &confirm);

        if(confirm == 2)
        {
            printf(RED "\nCancelled!!\n" RESET);
            return;
        }

        if(confirm != 1)
        {
            printf(RED_BOLD "Invalid input\n" RESET);
        }

    }while(confirm != 1);

    for (int i = index; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;

    printf(GREEN_BOLD "\nContact deleted successfully.\n" RESET);
    sleep(2);
    
    save_contacts(addressBook);
    printf(GREEN "Changes saved successfully.\n" RESET);
}