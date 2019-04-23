#pragma once

typedef struct record record;
typedef struct telbook telbook;
int count_number_of_letters_in_name();
void set_phone_number(record *rec, int phone_number);
void set_first_name(record *rec, char *first_name);
void set_last_name(record *rec, char *last_name);
record *create_record(int phone_number, char *first_name, char *last_name);
void add_record(telbook *book, int phone_number, char *first_name, char *last_name);
int count_number_of_letters_in_lastname();
void print_all_contacts(telbook *book);
void delete_using_name(telbook *book);
void find_record_using_name(telbook *book);
void find_record_using_number(int phone_number, telbook *book);
size_t get_size_now(telbook *book);
void control(int size_now, int size_max, telbook *book);