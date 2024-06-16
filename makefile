output.exe: main1.o create_db.o display_db.o file_validation.o insert_last.o save_db.o search.o update_db.o
		gcc -o output.exe main1.o create_db.o display_db.o file_validation.o insert_last.o save_db.o search.o update_db.o

main1.o: main1.c
		gcc -c main1.c

create_db.o: create_db.c
		gcc -c create_db.c

display_db.o: display_db.c
		gcc -c display_db.c

file_validation.o: file_validation.c
		gcc -c file_validation.c

insert_last.o: insert_last.c
		gcc -c insert_last.c

save_db.o: save_db.c
		gcc -c save_db.c

search.o: search.c
		gcc -c search.c

update_db.o: update_db.c
		gcc -c update_db.c

clean:
		rm *.exe *.o
