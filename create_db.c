#include "inverted_search.h"

char *fname;

void create_database(Flist *f_head, Wlist *head[]) {
    // traverse through the file linked list
     
    while (f_head) {
        read_datafile(f_head, head, f_head->file_name);
        f_head = f_head->link;
    }
}

// read content of file
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename) {
    // open the file in read mode
    FILE *fptr = fopen(filename, "r");
    if (!fptr) {
        perror("File opening failed");
        return NULL;
    }

    fname = filename;

    // declare an array to store words
    char word[WORD_SIZE];

    while (fscanf(fptr, "%s", word) != EOF) {
        // index
        int index = tolower(word[0]) % 97;

        // other than alphabet
        if (!(index >= 0 && index <= 25))
            index = 26;

        int flag = 1;  // reset flag for each new word

        // check if words are repeated
        if (head[index] != NULL) {
            Wlist *temp = head[index];
            // compare the words at each node with new word
            while (temp) {
                if (!strcmp(temp->word, word)) {
                    update_word_count(&temp, filename);
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }
        }

        if (flag == 1) {
            // words are not repeated
            insert_at_last(&head[index], word);
        }
    }

    fclose(fptr);  // close the file
    return NULL;
}

int update_word_count(Wlist **head, char *file_name) {
    Wlist *temp = *head;

    // Find the appropriate Wlist node for the given file_name
    while (temp != NULL && strcmp(temp->word, file_name) != 0) {
        temp = temp->link;
    }

    // If the file_name is not found in the Wlist, return with an error
    if (temp == NULL) {
        return -1;
    }

    Ltable *table = temp->Tlink;
    Ltable *prev = NULL;

    // Traversing through the Ltable linked list
    while (table != NULL) {
        prev = table;
        // If the file name matches, update the word count
        if (strcmp(table->file_name, file_name) == 0) {
            table->word_count++;
            return 0;
        }
        table = table->table_link;
    }

    // If the file name doesn't exist in the Ltable linked list, create a new entry
    Ltable *new = malloc(sizeof(Ltable));
    if (!new) {
        perror("Memory allocation failed");
        return -1;
    }
    strcpy(new->file_name, file_name);
    new->word_count = 1;
    new->table_link = NULL;
    if (prev) {
        prev->table_link = new;
    } else {
        temp->Tlink = new;
    }
    temp->file_count++;

    return 0;
}

