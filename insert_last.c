#include "inverted_search.h"

extern char *fname;

int insert_at_last(Wlist **head, data_t *data) {
    // create a node
    Wlist *new = malloc(sizeof(Wlist));
    if (new == NULL)
        return FAILURE;

    // UPDATE
    new->file_count = 1;
    strcpy(new->word, data);
    new->Tlink = NULL;
    new->link = NULL;

    // call fun to update link table node
    update_link_table(&new);

    // check if Wlist is empty
    if (*head == NULL) {
        *head = new;
        return SUCCESS;
    }

    // non-empty, traverse through the list
    Wlist *temp = *head;
    while (temp->link) {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}

int update_link_table(Wlist **head) {
    // create a node
    Ltable *new = malloc(sizeof(Ltable));
    if (new == NULL)
        return FAILURE;

    // update
    new->word_count = 1;
    strcpy(new->file_name, fname);
    new->table_link = NULL;

    (*head)->Tlink = new;

    return SUCCESS;
}





















