#include <malloc.h>
#include "telbook.h"
#include "structs.h"


void run(){
    telbook *contactbook = malloc(sizeof(contactbook));
    int command;
    printf("Enter your command(Enter '9' to see a list of commands\n");
    scanf("%d", &command);
    while (command != 0) {
        switch (command) {
            case 1 :{
                char name[count_number_of_letters_in_name()];
                char last_name[count_number_of_letters_in_lastname()];
                int telephone_number;
                printf("Enter number for your new contact\n");
                scanf("%d", &telephone_number);
                create_record(telephone_number, name, last_name);
                break;
            }
            case 2 :{
                print_all_contacts(contactbook);
                break;
            }
            case 3 :{
                find_record_using_name(contactbook);
                break;
            }
            case 4 :{
                int phone_number;
                printf("Enter phone number\n");
                scanf("%d", &phone_number);
                find_record_using_number(phone_number, contactbook);
                break;
            }
            case 5 :{
                delete_using_name(contactbook);
                break;
            }
            case 9 :{
                printf("'1' - add new contact\n");
                printf("'2' - print all contacts\n");
                printf("'3' - find record using name\n");
                printf("'4' - find record using number\n");
                printf("'5' - delete using name\n");
                break;
            }
            default :{
                printf("Incorrect command\n");
                break;
            }
        }
        scanf("%d", &command);
    }
}
