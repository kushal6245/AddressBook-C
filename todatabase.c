#include <stdio.h>
#include "addressbook.h"

//Get the contacts from .csv file
void load_contacts(struct AddressBook *addressBook)
{
    FILE *fp = fopen("database.csv", "r");

    if (fp == NULL)
    {
        printf("\nError opening file\n");
        addressBook->contactCount = 0;
        return;
    }

    char line[150];

    fgets(line, sizeof(line), fp);

    addressBook->contactCount = 0;

    while (addressBook->contactCount < 100 && fscanf(fp, "%49[^,],%10[^,],%49[^\n]\n",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3)
    {
        addressBook->contactCount++;
    }

    fclose(fp);
}

//To save the contacts to .csv file
void save_contacts(struct AddressBook *addressBook)
{
    FILE *fp = fopen("database.csv", "w");

    if (fp == NULL)
    {
        printf("\nError opening file\n");
        return;
    }

    fprintf(fp, "Name,Phone,Email\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fp);
}