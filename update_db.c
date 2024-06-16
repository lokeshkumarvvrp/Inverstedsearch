#include "inverted_search.h"

void update_database(Wlist *head[], Flist **f_head) {
    // Prompt the user for a new file to update the database
    char file_name[FNAME_SIZE];
    printf("Enter the new file: ");
    scanf("%s", file_name);

    // Validate the file
    FILE *fptr = fopen(file_name, "r");
    if (!fptr) {
        perror("File opening failed");
        return;
    }
    fclose(fptr);

        int empty = isFileEmpty(file_name);

        if(empty == FILE_NOTAVAILABLE)
        {
            printf("File : %s is not available\n", file_name);
            printf("Hence we are not adding that file\n");
        }
        else if(empty == FILE_EMPTY)
        {
            printf("File : %s is not having any content \n", file_name);
            printf("Hence we are not adding that file\n");
        }
        else
        {
            // add files to file LL
            int ret = to_create_list_of_files(f_head, file_name);
            if(ret == SUCCESS)
            {
                printf("Successfull : Inserting the file : %s into file LL\n", file_name);
            }
            else if (ret == REPEATATION)
            {
                printf("This file name : %s is repeated. Hence we are not adding that file\n", file_name);
            }
            else
            {
                printf("Failure\n");
            }
        }

    if (*f_head == NULL) {
        printf("No files are available in the file linked list\n");
        printf("Hence the process is terminated\n");
        return;
    }

    // Create a pointer to traverse the file list
    Flist *temp = *f_head;
    printf("Traversing the file list\n");

    // Traverse through the file linked list
    while (temp) {
        printf("Checking file: %s\n", temp->file_name);
        // Check if the file name matches the user-provided file name
        if (!strcmp(temp->file_name, file_name)) {
            // Read the data from the new file and update the database
            printf("File matched: %s\n", file_name);
            read_datafile(temp, head, file_name);
            break;
        }
        // Move to the next file in the list
        temp = temp->link;
    }
printf("Finished updating database\n");
}
