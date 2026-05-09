#include <stdio.h>
#include "hash.h"
#include "graph.h"

int main() {
    printf("=== Lojistik Agi ve Paket Yonetim Sistemi ===\n");

    // 1. Graf Yapısının Kurulumu
    City graph[MAX_CITIES];
    init_graph(graph);

    // Şehirleri ekliyoruz (Çerkezköy yerine Tekirdağ olarak düzeltildi)
    add_city(graph, 1, "Kirklareli");
    add_city(graph, 2, "Tekirdag");
    add_city(graph, 3, "Eskisehir");
    add_city(graph, 4, "Konya");

    // Şehirleri birbirine bağlıyoruz (Mesafeler örnek olarak verilmiştir)
    add_edge(graph, 1, 2, 120); // Kırklareli -> Tekirdağ
    add_edge(graph, 2, 3, 350); // Tekirdağ -> Eskişehir
    add_edge(graph, 3, 4, 300); // Eskişehir -> Konya
    add_edge(graph, 1, 3, 450); // Kırklareli -> Eskişehir (Alternatif yol)

    printf("\n=== DFS Gezinme Testi ===\n");
    int visited[MAX_CITIES] = {0};
    DFS(graph, 1, visited); // Kırklareli'den başlayarak derinlemesine ara

    // 2. Hash Tablosu (Paket Yönetimi)
    printf("\n=== Paket Indeksleme (Tip B & Acik Adresleme) ===\n");
    Package hash_table[TABLE_SIZE];
    init_hash_table(hash_table);

    // Aynı indekse denk gelip çakışma (collision) yaratacak ID'ler (Mod 10'a göre)
    // Şehir ID'lerini de yeni yapıya göre güncelledim
    insert_package(hash_table, 105, "Elektronik Parca", 2); // İndeks: 5 (Hedef: Tekirdağ)
    insert_package(hash_table, 215, "Tibbi Malzeme", 3);    // İndeks: 5 (Çakışır, 6'ya geçer. Hedef: Eskişehir)
    insert_package(hash_table, 305, "Tekstil Urunu", 4);    // İndeks: 5 (Çakışır, 7'ye geçer. Hedef: Konya)

    return 0;
}