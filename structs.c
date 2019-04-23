#include <glob.h>
#include <malloc.h>
#include "structs.h"

typedef struct record{
    int phone_number;
    char *first_name;
    char *last_name;
} record;

typedef struct telbook {
    size_t size_now;
    size_t size_max;
    record **contact;
} telbook;


int count_number_of_letters_in_name(){
    char name[100] = {'0'};
    printf("Enter a name of new contact\n");
    fgets(name, 100, stdin);
    int number_of_symbols = 0;
    for(int i = 0; i < 100; i++){
        if(name[i] != '0'){
            number_of_symbols++;
        }
    }
    return number_of_symbols;
}

size_t get_size_now(telbook *book){
    return book->size_now;
}

void print_all_contacts(telbook *book){
    size_t size_now = get_size_now(book);
    for(int i = 0; i < size_now; i++){
        printf("%d\n", book->contact[i]->phone_number);
        printf("%s\n", book->contact[i]->first_name);
        printf("%s\n", book->contact[i]->last_name);
    }
}

void find_record_using_number(int phone_number, telbook *book){
    size_t size_now = get_size_now(book);
    for(int i = 0; i < size_now; i++){
        if(book->contact[i]->phone_number == phone_number){
            printf("%s", book->contact[i]->last_name);
            printf("%s", book->contact[i]->first_name);
        }
    }
}

void delete_using_name(telbook *book){
    char name[100];
    char last_name[100];
    printf("Enter name of a contact\n");
    scanf("%s", name);
    size_t size_now = get_size_now(book);
    for(int i = 0; i < size_now; i++){
        if (book->contact[i]->first_name == fgets(name, 100, stdin)){
            if (book->contact[i]->last_name == fgets(last_name, 100, stdin)){
                free(book->contact[i]);
                size_now -= 1;
            }
        }
    }
}

void find_record_using_name(telbook *book) {
    char name[100] = {'0'};
    char last_name[100] = {'0'};
    size_t size_now = get_size_now(book);
    printf("Enter name of record\n");
    for (int i = 0; i < size_now; i++) {
        if (book->contact[i]->first_name == fgets(name, 100, stdin))
            if (book->contact[i]->last_name == fgets(last_name, 100, stdin)) {
                printf("%d\n", book->contact[i]->phone_number);
                break;
            }
    }
    printf("Incorrect name!\n");
}

int count_number_of_letters_in_lastname(){
    char lastname[100] = {'0'};
    printf("Enter a lastname of new contact\n");
    fgets(lastname, 100, stdin);
    int number_of_symbols = 0;
    for(int i = 0; i < 100; i++){
        if(lastname[i] != '0'){
            number_of_symbols++;
        }
    }
    return number_of_symbols;
}

void set_phone_number(record *rec, int phone_number){
    rec->phone_number = phone_number;
}

void set_first_name(record *rec, char *first_name){
    rec->first_name = first_name;
}

void set_last_name(record *rec, char *last_name){
    rec->last_name = last_name;
}

record *create_record(int phone_number, char *first_name, char *last_name){
    record *rec = malloc(sizeof(record));
    set_phone_number(rec, phone_number);
    set_first_name(rec, first_name);
    set_last_name(rec, last_name);
}

void add_record(telbook *book, int phone_number, char *first_name, char *last_name){
    record *rec = create_record(phone_number, first_name, last_name);
    book->contact[book->size_now] = rec;
    control(book->size_now, book->size_max, book);
}

void control(int size_now, int size_max, telbook *book){
    int tresshold = 10;
    if(size_now > size_max){
        size_max *= 2;
        book = realloc(book, sizeof(telbook)*size_max);
    }
}

