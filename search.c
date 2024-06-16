#include "inverted_search.h"

void search( Wlist *head, char *word)
{
    //check empty or not
    if(head == NULL)
    {
	printf("Search not possible , as list is empty\n");
	return ;
    } 
//traverse through the Wlist
    while(head)
    {
	//compare each node word with search word 
	if(!strcmp(head->word , word))
	{
	    printf("word %s is present in %d file/s\n" , word , head->file_count);
	    Ltable *Thead = head->Tlink;
	    while(Thead)
	    {
		printf("In file : %s   %d time/s \n" , Thead->file_name , Thead->word_count);
		Thead = Thead->table_link;
	    }
	    printf("\n");
	    return;
	}
	head = head->link;
    }
    printf("Seach word not present in the lis\n");
}








