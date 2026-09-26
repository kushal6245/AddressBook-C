#include <stdio.h>
#include <unistd.h>

#include "addressbook.h"

int main() 
{
    int choice, search;

    struct AddressBook addressBook;
    addressBook.contactCount = 0;
    addressBook.ir_size = 0;

	load_contacts(&addressBook);

    do 
    {
		printf(YELLOW "\nAddress Book Menu:\n\n" RESET);

		sleep(1);
		printf(CYAN "1. Add/Create contact\n");
		printf("2. Search contact\n");
		printf("3. Edit contact\n");
		printf("4. Delete contact\n");
		printf("5. List all contacts\n");
        printf("6. Refresh\n");
		printf("7. Save and Exit\n" RESET);
        
		sleep(1);
		printf(BLUE "\nEnter your choice: " RESET);

		if(scanf("%d", &choice) != 1)
        {
            printf(RED_BOLD "Invalid input. Please try again.\n" RESET);
            while(getchar() != '\n');
            continue;
        }

		switch (choice) 
		{
	    	case 1:

                if(addressBook.contactCount >= 100)
                {
                    printf(RED "\nAddress Book is full.\n" RESET);
                    break;
                }

				add_contact(&addressBook);
				break;

	    	case 2:
                
                if(addressBook.contactCount <= 0)
                {
                    printf(RED "\nAddress book is empty.\n" RESET);
                    break;
                }

				search_contact(&addressBook, choice);
				break;

	    	case 3:

                if(addressBook.contactCount <= 0)
                {
                    printf(RED "\nAddress book is empty.\n" RESET);
                    break;
                }

				edit_contact(&addressBook);
				break;

	    	case 4:

                if(addressBook.contactCount <= 0)
                {
                    printf(RED "\nNo contact to delete.\n" RESET);
                    break;
                }

				delete_contact(&addressBook);
				break;

	    	case 5:
                
                if(addressBook.contactCount <= 0)
                {
                    printf(RED "\nAddress book is empty.\n" RESET);
                    break;
                }

				list_contacts(&addressBook);
				break;

            case 6:
                
                load_contacts(&addressBook);
                printf(GREEN_BOLD "\nRefreshed!!\n" RESET);
                sleep(2);
                break;
                
	    	case 7:

				printf(GREEN_BOLD "Saving...\n" RESET);
				sleep(2);
				printf(GREEN_BOLD "Saved Successfully!!\n\n" RESET);
				break;

	    	default:

			    printf(RED_BOLD "Invalid input. Please try again.\n" RESET);
                while(getchar() != '\n');
		}

    } while (choice != 7);

    return 0;
}