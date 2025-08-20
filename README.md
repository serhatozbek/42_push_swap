## 🤖 push_swap | Ecole 42

Bu repository, 42 müfredatının en zorlayıcı algoritmik projelerinden biri olan push_swap'ı içerir. Projenin temel amacı, A ve B adında iki yığın (stack) ve sınırlı sayıda komut kullanarak, verilen bir sayı dizisini en az hamleyle sıralamaktır.

---

#### 🚀 Projenin Amacı

push_swap, sıralama algoritmalarının temellerini, veri yapısı olarak yığınların (stack) verimli kullanımını ve en önemlisi, karmaşık bir problemi optimize edilmiş adımlarla çözme yeteneğini öğretmeyi hedefler. Amaç sadece sıralamak değil, bunu mümkün olan en az komutla başarmaktır.

**🧠 Kullanılan Sıralama Algoritması**: Radix Sort (Taban Sıralaması)
Bu projedeki sıralama mantığı, büyük veri setleri için oldukça verimli olan Radix Sort algoritmasına dayanmaktadır.

**Algoritma genel olarak şu adımları izler:**

+ Normalleştirme (Indexing): İlk olarak, verilen sayılar sıralanarak onlara bir "indeks" atanır. Örneğin, -50, 10, 0 sayıları 0, 2, 1 olarak indekslenir. Bu, sayıların değerlerinden bağımsız, sadece sıralamadaki yerlerine göre işlem yapmayı sağlar.

Bit Tabanlı Sıralama:

+ Algoritma, indekslenmiş sayıların ikili (binary) gösterimindeki en anlamsız bitten (en sağdaki bit) başlayarak çalışır.

+ A yığınındaki her sayı kontrol edilir. Eğer sayının o anki biti 0 ise B yığınına atılır (pb). Eğer bit 1 ise A yığınında kalır ve yığın döndürülür (ra).

+ A yığınındaki tüm sayılar kontrol edildikten sonra, B yığınındaki tüm sayılar geri A yığınına atılır (pa).

+ Tekrarlama: Bu işlem, sayıların en anlamlı bitine (en soldaki bit) ulaşılana kadar her bir bit pozisyonu için tekrarlanır.

**Sonuç**: Tüm bitler işlendiğinde, A yığınındaki sayılar tamamen sıralanmış olur.

Bu yöntem, özellikle yüzlerce veya binlerce sayı içeren büyük dizilerde komut sayısını dramatik bir şekilde azaltır. 3 ve 5 gibi küçük sayı dizileri için ise özel olarak optimize edilmiş daha basit sıralama metotları kullanılır.

---

#### 🛠️ Kullanılabilen Komutlar

Sıralama işlemi için sadece aşağıdaki 11 komuta izin verilmektedir:


- sa	a yığınının ilk iki elemanını takas eder.
- sb	b yığınının ilk iki elemanını takas eder.
- ss	sa ve sb komutlarını aynı anda çalıştırır.
- pa	b'nin en üstündeki elemanı a'nın en üstüne taşır.
- pb	a'nın en üstündeki elemanı b'nin en üstüne taşır.
- ra	a yığınındaki tüm elemanları bir sıra yukarı kaydırır.
- rb	b yığınındaki tüm elemanları bir sıra yukarı kaydırır.
- rr	ra ve rb komutlarını aynı anda çalıştırır.
- rra	a yığınındaki tüm elemanları bir sıra aşağı kaydırır.
- rrb	b yığınındaki tüm elemanları bir sıra aşağı kaydırır.
- rrr	rra ve rrb komutlarını aynı anda çalıştırır.

---

#### ⚙️ Nasıl Kullanılır?

**Derleme**

Projeyi derlemek için Makefile'ı kullanın. Bu komut push_swap programını oluşturacaktır.

```Bash
make
```

##### push_swap Kullanımı

Program, argüman olarak sıralanacak sayıları alır ve standart çıktıya (stdout) bu sayıları sıralamak için gereken komut listesini yazar.

```Bash

# Örnek kullanım

./push_swap 4 67 3 -1 0

# Çıktı:

pb
rra
pb
sa
rra
pa
pa
```

---

### ⚠️ Sorumluluk Reddi

 Bu repository'deki çözümler tamamen eğitim ve portföy amaçlıdır. 42'nin onur kuralları (honour code) gereği, Common Core sürecindeki öğrencilerin çözümleri kopyalaması kesinlikle yasaktır. Buradaki kodlar, repodaki projeyi tamamlamış biri olarak gelişimimi göstermek ve gelecekteki projelerim için bir referans noktası oluşturmak amacıyla paylaşılmıştır.

---
