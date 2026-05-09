#include <stdio.h>
#include <string.h>
#include "hash.h"

void init_hash_table(Package table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].is_occupied = 0; // Başlangıçta tüm hücreler boş
    }
}

// Tip B Hash Fonksiyonu: Mod Alma
int hash_function_B(int key) {
    return key % TABLE_SIZE;
}

// Açık Adresleme (Linear Probing) ile Çakışma Çözümü
void insert_package(Package table[], int id, const char* details, int city_id) {
    int index = hash_function_B(id);
    int original_index = index;

    while (table[index].is_occupied) {
        printf("[Çakışma] Paket ID %d için %d indeksi dolu. Açık adresleme ile sonrakine bakılıyor...\n", id, index);
        index = (index + 1) % TABLE_SIZE;

        if (index == original_index) {
            printf("Hata: Hash tablosu tamamen dolu!\n");
            return;
        }
    }

    table[index].package_id = id;
    strcpy(table[index].details, details);
    table[index].current_city_id = city_id;
    table[index].is_occupied = 1;

    printf("Paket ID %d başarıyla %d indeksine yerleşti. Adres: %p\n", id, index, (void*)&table[index]);
}//
// Created by İsmail Gürbüz on 8.05.2026.
//