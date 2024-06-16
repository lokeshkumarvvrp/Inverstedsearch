/*
Name: Lokeshkumar P
Date: 07/06/2024
Description: Inverted Search 
*/
#include "inverted_search.h"

int main(int argc, char *argv[])
{
    system("clear");
    Wlist *head[27] = {NULL};

// Validate CLA
if (argc <= 1) {
    printf("Enter the valid no. of arguments\n");
    printf("./a.out file1.txt file2.txt.......\n");
    return 0;
}

// Create the file linked list
Flist *f_head = NULL;

// Validate the files
file_validation_n_file_list(&f_head, argv);

if (f_head == NULL) {
    printf("No files are available in the file linked list\n");
    printf("Hence the process is terminated\n");
    return 0;
}

int choice;
do {
    // Prompt the user for choice
    printf("\nSelect your choice among the following options:\n");
    printf("1. Create DATABASE\n");
    printf("2. Display Database\n");
    printf("3. Update DATABASE\n");
    printf("4. Search\n");
    printf("5. Save Database\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Create database
            create_database(f_head, head);
            break;
        case 2:
            // Display database
            display_database(head);
            break;
        case 3:
            // Update database
            update_database(head,&f_head);
            break;
        case 4: {
            // Search
            char word[WORD_SIZE];
            printf("Enter the word to search: ");
            scanf("%s", word);
            int index = tolower(word[0]) % 97;
            if (!(index >= 0 && index <= 25))
                index = 26;
            search(head[index], word);
            break;
        }
        case 5:
            // Save database
            save_database(head);
            break;
        case 6:
            // Exit
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
} while (choice != 6);

return 0;
}
