# SoalShift_modul3_C16

1. Buatlah program C yang bisa menghitung faktorial secara parallel lalu menampilkan hasilnya secara berurutan

Contoh:

	./faktorial 5 3 4
  
	3! = 6
  
	4! = 24
  
	5! = 120

#### Jawaban :
Di soal ini, kami membutuhkan 2 fungsi yang akan dipanggil dalam fungsi `main()`.


Fungsi pertama adalah fungsi `fact()` yang digunakan untuk menghitung faktorial itu sendiri.

Perhitungan faktorial dimulai di dalam while :
```
while(i<=n)
        {
            hasil=hasil*i; //counting factorial
			++i;
        }
	
```
Fungsi kedua adalah fungsi `sort()` yang berguna untuk menyeleksi bilangan agar berurut.

Di dalam fungsi `sort()` ini juga terdapat variable `swap` untuk menukar posisi bilangan setelah input.

Swap (penukaran) tersebut terjadi saat :
```
for (i=0; i<a; i++){
    	for (j=0; j<a-i; j++){
    		if (temp[j] < temp[j-1]){
    		swap = temp[j-1];
    		temp[j-1]= temp[j];
    		temp[j]= swap;
			}	
		}
	}
	
```
Lalu, pemanggilan kedua fungsi tersebut terjadi di dalam fungsi `main()` dengan parameter `int argc, char* argv[]`

Di dalam fungsi `main()` sendiri terdapat pengonversian string `ptr` menjadi integer pada saat :
```
for (i=0; i<argc-1; i++){
		konv=strtol(argv[i + 1], &ptr, 10);
		temp[i]=konv;
	}
```
Serta pemanggilan fungsi `sort()` :
```
sort(temp, argc);
```
Juga terdapat pembuatan thread yang memeliki parameter berupa fungsi `fact` sendiri.

Thread tersebut juga berguna untuk mengecek error atau tidak.
```
for(b=0;b<argc-1;b++)
	{ 
		err = pthread_create(&(tid[b]),NULL,&fact,NULL); //making thread
		if(err!=0) //error checking
		{
			
		}
		else
		{

		}
		pthread_join(tid[b],NULL);

	}
```



2. Pada suatu hari ada orang yang ingin berjualan 1 jenis barang secara private, dia memintamu membuat program C dengan spesifikasi sebagai berikut:

a. Terdapat 2 server: server penjual dan server pembeli

b. 1 server hanya bisa terkoneksi dengan 1 client

c. Server penjual dan server pembeli memiliki stok barang yang selalu sama

d. Client yang terkoneksi ke server penjual hanya bisa menambah stok

   - Cara menambah stok: client yang terkoneksi ke server penjual mengirim string “tambah” ke server lalu stok bertambah 1
   
e. Client yang terkoneksi ke server pembeli hanya bisa mengurangi stok

   - Cara mengurangi stok: client yang terkoneksi ke server pembeli mengirim string “beli” ke server lalu stok berkurang 1
   
f. Server pembeli akan mengirimkan info ke client yang terhubung dengannya apakah transaksi berhasil atau tidak berdasarkan ketersediaan stok

   - Jika stok habis maka client yang terkoneksi ke server pembeli akan mencetak “transaksi gagal”
   
   - Jika stok masih ada maka client yang terkoneksi ke server pembeli akan mencetak “transaksi berhasil”
   
g. Server penjual akan mencetak stok saat ini setiap 5 detik sekali

**h. Menggunakan thread, socket, shared memory**

#### Jawaban :






3. Agmal dan Iraj merupakan 2 sahabat yang sedang kuliah dan hidup satu kostan, sayangnya mereka mempunyai gaya hidup yang berkebalikan, dimana Iraj merupakan laki-laki yang sangat sehat,rajin berolahraga dan bangun tidak pernah kesiangan sedangkan Agmal hampir menghabiskan setengah umur hidupnya hanya untuk tidur dan ‘ngoding’. Dikarenakan mereka sahabat yang baik, Agmal dan iraj sama-sama ingin membuat satu sama lain mengikuti gaya hidup mereka dengan cara membuat Iraj sering tidur seperti Agmal, atau membuat Agmal selalu bangun pagi seperti Iraj. Buatlah suatu program C untuk menggambarkan kehidupan mereka dengan spesifikasi sebagai berikut:

a. Terdapat 2 karakter Agmal dan Iraj

b. Kedua karakter memiliki status yang unik
   - Agmal mempunyai WakeUp_Status, di awal program memiliki status 0
   - Iraj memiliki Spirit_Status, di awal program memiliki status 100
   - Terdapat 3 Fitur utama
     - All Status, yaitu menampilkan status kedua sahabat
       Ex: Agmal WakeUp_Status = 75 
       Iraj Spirit_Status = 30
     - “Agmal Ayo Bangun” menambah WakeUp_Status Agmal sebesar 15 point
     - “Iraj Ayo Tidur” mengurangi Spirit_Status Iraj sebanyak 20 point
   - Terdapat Kasus yang unik dimana:
     - Jika Fitur “Agmal Ayo Bangun” dijalankan sebanyak 3 kali, maka Fitur “Iraj Ayo Tidur” Tidak bisa dijalankan selama 10 detik        (Dengan mengirim pesan ke sistem “Fitur Iraj Ayo Tidur disabled 10 s”)
     - Jika Fitur “Agmal Ayo Bangun” dijalankan sebanyak 3 kali, maka Fitur “Iraj Ayo Tidur” Tidak bisa dijalankan selama 10 detik (Dengan mengirim pesan ke sistem “Fitur Iraj Ayo Tidur disabled 10 s”)
   - Program akan berhenti jika Salah Satu :
     - WakeUp_Status Agmal >= 100 (Tampilkan Pesan “Agmal Terbangun,mereka bangun pagi dan berolahraga”)
     - Spirit_Status Iraj <= 0 (Tampilkan Pesan “Iraj ikut tidur, dan bangun kesiangan bersama Agmal”)
   - **Syarat Menggunakan Lebih dari 1 Thread**

#### Jawaban :







4. Buatlah sebuah program C dimana dapat menyimpan list proses yang sedang berjalan (ps -aux) maksimal 10 list proses. Dimana awalnya list proses disimpan dalam di 2 file ekstensi .txt yaitu  SimpanProses1.txt di direktori /home/Document/FolderProses1 dan SimpanProses2.txt di direktori /home/Document/FolderProses2 , setelah itu masing2 file di  kompres zip dengan format nama file KompresProses1.zip dan KompresProses2.zip dan file SimpanProses1.txt dan SimpanProses2.txt akan otomatis terhapus, setelah itu program akan menunggu selama 15 detik lalu program akan mengekstrak kembali file KompresProses1.zip dan KompresProses2.zip 
**Dengan Syarat:**

- Setiap list proses yang di simpan dalam masing-masing file .txt harus berjalan bersama-sama

- Ketika mengkompres masing-masing file .txt harus berjalan bersama-sama

- Ketika Mengekstrak file .zip juga harus secara bersama-sama

- Ketika Telah Selesai melakukan kompress file .zip masing-masing file, maka program akan memberi pesan “Menunggu 15 detik untuk mengekstrak kembali”

- Wajib Menggunakan Multithreading

- Boleh menggunakan system

#### Jawaban :







5. Angga, adik Jiwang akan berulang tahun yang ke sembilan pada tanggal 6 April besok. Karena lupa menabung, Jiwang tidak mempunyai uang sepeserpun untuk membelikan Angga kado. Kamu sebagai sahabat Jiwang ingin membantu Jiwang membahagiakan adiknya sehingga kamu menawarkan bantuan membuatkan permainan komputer sederhana menggunakan program C. Jiwang sangat menyukai idemu tersebut. Berikut permainan yang Jiwang minta. 

a. Pemain memelihara seekor monster lucu dalam permainan. Pemain dapat  memberi nama pada monsternya.

b. Monster pemain memiliki hunger status yang berawal dengan nilai 200 (maksimalnya) dan nanti akan berkurang 5 tiap 10 detik.Ketika hunger status mencapai angka nol, pemain akan kalah. Hunger status dapat bertambah 15 apabila pemain memberi makan kepada monster, tetapi banyak makanan terbatas dan harus beli di Market.

c. Monster pemain memiliki hygiene status yang berawal dari 100 dan nanti berkurang 10 tiap 30 detik. Ketika hygiene status mencapai angka nol, pemain akan kalah. Hygiene status' dapat bertambah 30 hanya dengan memandikan monster. Pemain dapat memandikannya setiap 20 detik(cooldownnya 20 detik).

d. Monster pemain memiliki health status yang berawal dengan nilai 300. Variabel ini bertambah (regenerasi)daa 5 setiap 10 detik ketika monster dalam keadaan standby.

e. Monster pemain dapat memasuki keadaan battle. Dalam keadaan ini, food status(fitur b), hygiene status'(fitur c), dan ‘regenerasi’(fitur d) tidak akan berjalan. Health status dari monster dimulai dari darah saat monster pemain memasuki battle. Monster pemain akan bertarung dengan monster NPC yang memiliki darah 100. Baik monster pemain maupun NPC memiliki serangan sebesar 20. Monster pemain dengan monster musuh akan menyerang secara bergantian. 

f. Fitur shop, pemain dapat membeli makanan sepuas-puasnya selama stok di toko masih tersedia.

- Pembeli (terintegrasi dengan game)
  - Dapat mengecek stok makanan yang ada di toko.
  - Jika stok ada, pembeli dapat membeli makanan.

- Penjual (terpisah)
  - Bisa mengecek stok makanan yang ada di toko
  - Penjual dapat menambah stok makanan.

Spesifikasi program:

A. Program mampu mendeteksi input berupa key press. (Program bisa berjalan tanpa perlu menekan tombol enter)

B. Program terdiri dari 3 scene yaitu standby, battle, dan shop.

C. Pada saat berada di standby scene, program selalu menampilkan health status, hunger status, hygiene status, stok makanan tersisa, dan juga status kamar mandi (“Bath is ready” jika bisa digunakan, “Bath will be ready in [bath cooldown]s” jika sedang cooldown). Selain itu program selalu menampilkan 5 menu, yaitu memberi makan, mandi, battle, shop, dan exit. 

Contoh :

Standby Mode

Health : [health status]

Hunger : [hunger status]

Hygiene : [hygiene status]

Food left : [your food stock]

Bath will be ready in [cooldown]s

Choices

1. Eat

2. Bath

3. Battle

4. Shop

5. Exit

D. Pada saat berada di battle scene, program selalu menampilkan health status milik pemain dan monster NPC. Selain itu, program selalu menampilkan 2 menu yaitu serang atau lari. 

Contoh :

Battle Mode

Monster’s Health : [health status]

Enemy’s Health : [enemy health status]

Choices

1. Attack

2. Run

E. Pada saat berada di shop scene versi pembeli, program selalu menampilkan food stock toko dan milik pemain. Selain itu, program selalu menampilkan 2 menu yaitu beli dan kembali ke standby scene. 

Contoh :

Shop Mode

Shop food stock : [shop food stock]

Your food stock : [your food stock]

Choices

1. Buy

2. Back

F. Pada program penjual, program selalu menampilkan food stock toko. Selain itu, program juga menampilkan 2 menu yaitu restock dan exit. 

Contoh :

Shop

Food stock : [shop food stock]

Choices

1. Restock

2. Exit

G. Pastikan terminal hanya mendisplay status **detik ini** sesuai scene terkait (hint: menggunakan system(“clear”))

#### Jawaban :









