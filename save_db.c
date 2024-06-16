#include "inverted_search.h"

 void save_database( Wlist *head[])
{
    //prompt the user for file

    int i;
    char file_name[FNAME_SIZE];

    printf("Enter the file name to save the database\n");
    scanf("%s" , file_name);

    //open file
    FILE *fptr = fopen(file_name , "w");
if (!fptr) {
    perror("Error opening file");
    return;
}


    for(i = 0; i < 27; i++)
    {
	if(head[i] != NULL)
	{
	    write_databasefile(head[i] , fptr);
	}
    }

    printf("Database saved\n");
}

void write_databasefile(Wlist *head, FILE* databasefile)
{
    while (head != NULL) {
        fprintf(databasefile, "#[%d]\nword is [%s]: file count is [%d]:file/s: ", tolower(head->word[0]) % 97, head->word, head->file_count);
        Ltable *Thead = head->Tlink;

        // traverse the Ltable linked list
        while (Thead != NULL) {
            fprintf(databasefile, "file is %s: word count is %d ", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
        }

        fprintf(databasefile, "\n");
        head = head->link;
    }
}

























