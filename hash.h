#ifndef FINALODEVI4_HASH_H
#define FINALODEVI4_HASH_H

#define TABLE_SIZE 10

typedef struct {
    int package_id;
    char details[50];
    int current_city_id;
    int is_occupied; // Açık adresleme için hücrenin dolu olup olmadığını kontrol eder
} Package;

void init_hash_table(Package table[]);
int hash_function_B(int key);
void insert_package(Package table[], int id, const char* details, int city_id);
void print_hash_table(Package table[]);

#endif