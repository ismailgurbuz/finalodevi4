# Lojistik Ağı ve Paket Yönetim Sistemi (LojistikProje)

Bu proje, Kırklareli Üniversitesi Veri Yapıları ve Algoritmalar dersi kapsamında geliştirilmiş, şehirler arası bağlantıların ve kargo indeksleme süreçlerinin simüle edildiği hibrit bir C projesidir. Sistem, graf teorisi ve hash tablosu algoritmalarının entegre çalışmasını temel alır.

## 1. Proje Hakkında
Sistem, bir lojistik firmasının iki temel ihtiyacını karşılamak üzere tasarlanmıştır:
* Şehirler arası mesafelerin ve rotaların bellek dostu bir şekilde tutulması.
* Depoya giren paketlerin zaman karmaşıklığı O(1) olacak şekilde hızlıca aranıp bulunması.

Proje, tek bir monolitik dosya yerine; `main`, `graph` ve `hash` olmak üzere mantıksal katmanlara ayrılmıştır.

## 2. Öğrenci Numarasına Göre Uygulanan Algoritmalar
Bu projedeki veri yapıları algoritmaları, proje isterleri doğrultusunda **1250505033** numaralı öğrenci ID'sine göre spesifik olarak kurgulanmıştır:

| Kriter | Seçilen Yöntem | Açıklama |
| :--- | :--- | :--- |
| **Hash Fonksiyonu** | Tip B (Division Method) | Gelen ID değerinin modüler aritmetik (`ID % SIZE`) ile tabloya yerleştirilmesi. |
| **Çakışma (Collision)** | Açık Adresleme | İndeks doluysa `(index + 1) % SIZE` formülü ile doğrusal yoklama (Linear Probing) yapılması. |
| **Graf Gezinme** | DFS (Derinlemesine Arama) | `visited` dizisi kullanılarak özyinelemeli (recursive) yöntemle haritada gezinilmesi. |

## 3. Sistem Bileşenleri ve Modüler Yapı

Proje dizini aşağıdaki mantıksal katmanlardan oluşmaktadır:
* **`graph.h` / `graph.c` :** Komşuluk Listesi (Adjacency List) kullanılarak grafın dinamik bellek (`malloc`) ile oluşturulduğu modül.
* **`hash.h` / `hash.c` :** Paket sorgulama, hash fonksiyonu hesaplama ve çakışma durumunda verilerin bellekte doğrusal kaydırıldığı modül.
* **`main.c` :** Sistemin test verileri ile (Kırklareli, Tekirdağ, Eskişehir, Konya) başlatıldığı ve işlemlerin konsola yansıtıldığı ana kontrol dosyası.

## 4. Bellek Yönetimi ve İzleme Raporu
Projenin en kritik özelliklerinden biri dinamik bellek yönetimidir. Statik diziler yerine, işaretçiler (pointers) aracılığıyla çalışma zamanında bellek tahsisi yapılmıştır. 

Program çalıştırıldığında;
* Graf düğümlerinin (`City`) ve bağlantı yollarının (`Edge`) bellekteki yerleşim adresleri (Hexadecimal: `0x...`),
* Çakışma (collision) anında paketlerin açık adresleme ile bellekteki doğrusal kaymaları anlık olarak konsola dökülmektedir.

Bu RAM dökümleri, projenin "Bellek İzleme Raporu" gereksinimini tam olarak karşılamaktadır.

## 5. Derleme ve Çalıştırma Yönergeleri

Proje `gcc` veya `clang` derleyicileri ile uyumludur. Terminal üzerinden derlemek ve çalıştırmak için proje dizininde aşağıdaki komutları sırasıyla çalıştırınız:

### Derleme:
```bash
gcc main.c graph.c hash.c -o LojistikProje


### Çalıştırma:
```bash
./LojistikProje
