#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define PANJANG_NOMOR 5
#define PANJANG_NAMA 20
#define PANJANG_MAKS 3
#define ENTER 13
struct simpul_siswa
{
char nomor[PANJANG_NOMOR+1];
char nama[PANJANG_NAMA+1];
char huruf;
int ujian;

struct simpul_siswa *lanjutan;
};
struct simpul_siswa *ptr_kepala=NULL;
struct simpul_siswa *ptr_pos_data;
struct simpul_siswa *ptr_pendahulu;
void pemasukan_data(void);
void masukan_string(char *keterangan, char *masukan, int panjang_maks);
void tampilkan_data(void);
void menu_pilihan(void);
void edit_data(void);
void pencarian_data(void);
void hapus_data(void);//program utama
main()
{
for(;;)
{
 menu_pilihan();
}
}
void pemasukan_data(void)
{ char jawaban;
 struct simpul_siswa *ptr_baru;
 do
 {
 ptr_baru=(struct simpul_siswa *)malloc(sizeof(struct simpul_siswa));
 if (ptr_baru)
 {
 masukan_string("Nim Siswa  = ",ptr_baru->nomor,PANJANG_NOMOR);
 masukan_string("Nama Siswa = ",ptr_baru->nama,PANJANG_NAMA);
 printf("Masukan Nilai Ujian                  = "); scanf("%d",&ptr_baru->ujian); fflush(stdin);

    if (ptr_baru->ujian>=75)ptr_baru->huruf='A'; //lebih besar dari 75 (75-100)
    else if(ptr_baru->ujian>=65)ptr_baru->huruf='B'; //lebih besar dari 65 (65-75)
    else if(ptr_baru->ujian>=40)ptr_baru->huruf='C'; //lebih besar dari 45 (40-65)
    else if(ptr_baru->ujian>=23)ptr_baru->huruf='D'; //lebih besar dari 26 (23-40)
    else if (ptr_baru->ujian>=0)ptr_baru->huruf='E'; //lebih besar dari 0 (0-23)

    printf("Nilai Ujian        = %d Dengan Huruf Mutu %c\n", ptr_baru->ujian, ptr_baru->huruf);
    printf("Data Berhasil Ditambahkan!");

 ptr_baru->lanjutan=ptr_kepala;
 ptr_kepala=ptr_baru;
 printf("Memasukan data lagi (Y/T) ? ");
 do
 {
 jawaban=toupper(getche()); printf("\n");
 } while (!(jawaban=='Y' || jawaban=='T'));
 }
 else
 {
 puts("Memori tdk cukup..!");
 break;
 }
 } while (jawaban=='Y');
}
void masukan_string(char *keterangan, char *masukan, int panjang_maks)
{ char st[256];
 do
 {
 printf(keterangan);
 gets(st);
 if (strlen(st)>panjang_maks)
 printf("Terlalu panjang. Maks %d karakter\n",panjang_maks); //koreksi
 } while (strlen(st)>panjang_maks);
 strcpy(masukan,st);
}
void tampilkan_data(void){ struct simpul_siswa *ptr_sementara;
 puts("\nIsi LINKED LIST :");
 ptr_sementara=ptr_kepala;
 while (ptr_sementara)
 {
 printf("Nim = %s Nama = %s Nilai Ujian = %d Huruf Mutu = %c\n",ptr_sementara->nomor, ptr_sementara->nama, ptr_sementara->ujian, ptr_sementara->huruf);
 ptr_sementara=ptr_sementara->lanjutan;
 }
 printf("\n\nTEKAN ENTER untuk kembali ke Menu Pilihan...!");
 getch();
}
void cari_data(char *nama)
{
ptr_pendahulu=NULL;
ptr_pos_data=ptr_kepala;
while (ptr_pos_data)
{
 if (strcmp(nama,ptr_pos_data->nama)!=0)
 {
 ptr_pendahulu=ptr_pos_data;
 ptr_pos_data=ptr_pos_data->lanjutan;
 }
 else
 {
 break;
 }
}
}
void hapus_data(void)
{
char nama[21];
masukan_string("Masukan nama yang akan dihapus : ",nama,20);
cari_data(nama);
if (ptr_pos_data==NULL)
 puts("Nama tidak ditemukan...!");
else
{ //proses penghapusan
 if (ptr_pendahulu==NULL)
 //simpul ujung yg akan dihapus
 ptr_kepala=ptr_kepala->lanjutan;
 else
 //bukan simpul ujung yg akan dihapus
 ptr_pendahulu->lanjutan=ptr_pos_data->lanjutan;
 free(ptr_pos_data); //hapus yg ditunjuk olehptr_ pos_data
 puts("OK..penghapusan telah selesai..tekan ENTER...!");
 getch();
}
}
void menu_pilihan(void)
{ char pilihan;puts("MENU PILIHAN");
puts("1.Input Data");
puts("2.Menghapus Data");
puts("3.Menampilkan data");
puts("4.Mengedit Data");
puts("5.Mencari Data");
puts("6.Keluar");
printf("Pilihan 1/2/3/4/5/6 = ");
do
{
 pilihan=getche(); fflush(stdin); printf("\n");
}while (pilihan < '1' || pilihan > '6');
switch (pilihan)
{
 case '1' : pemasukan_data(); break;
 case '2' : hapus_data(); break;
 case '3' : tampilkan_data(); break;
 case '4' : edit_data(); break;
 case '5' : pencarian_data();break;
 case '6' : getch(); exit(1); break;
}
}
void edit_data(void)
{ char nama[256];
ptr_pendahulu=NULL;
ptr_pos_data=ptr_kepala;
printf("Masukan nama yang akan diedit : "); gets(nama);
while (ptr_pos_data)
{
 if (strcmp(nama,ptr_pos_data->nama)!=0)
 {
 ptr_pendahulu=ptr_pos_data;
 ptr_pos_data=ptr_pos_data->lanjutan;
 }
 else
 {
 puts("Ketemu...!");
 printf("Nim Siswa   = %s\n",ptr_pos_data->nomor);
 printf("Nama Siswa  = %s\n",ptr_pos_data->nama);
 printf("Nilai Ujian = %d\n",ptr_pos_data->ujian);
 printf("Huruf Mutu  = %c\n",ptr_pos_data->huruf);
 puts("------------------\n");
 puts("Silahkan Edit Data");
 printf("Nilai Ujian                   = "); scanf("%d",&ptr_pos_data->ujian); fflush(stdin);

    if (ptr_pos_data->ujian>=75)ptr_pos_data->huruf='A'; //lebih besar dari 75 (75-100)
    else if(ptr_pos_data->ujian>=65)ptr_pos_data->huruf='B'; //lebih besar dari 65 (65-75)
    else if(ptr_pos_data->ujian>=40)ptr_pos_data->huruf='C'; //lebih besar dari 45 (40-65)
    else if(ptr_pos_data->ujian>=25)ptr_pos_data->huruf='D'; //lebih besar dari 26 (25-44)
    else if (ptr_pos_data->ujian>=0)ptr_pos_data->huruf='E'; //lebih besar dari 0 (0-25)

    printf("Nilai Akhir        = %d Dengan Huruf Mutu %c\n", ptr_pos_data->ujian, ptr_pos_data->huruf);
    puts("Edit data berhasil dilakukan...!");
 getch();
 break;
 }
}
}

void pencarian_data(void)
{ char nomor[20];
    ptr_pendahulu=NULL;
    ptr_pos_data=ptr_kepala;
    printf("Masukan Nim Siswa untuk mencari = "); gets(nomor);
    while (ptr_pos_data)
{
    if (strcmp(nomor,ptr_pos_data->nomor)!=0)
 {
    ptr_pendahulu=ptr_pos_data;
    ptr_pos_data=ptr_pos_data->lanjutan;
 }
 else
 {
    printf("Nim Siswa   = %s\n",ptr_pos_data->nomor);
    printf("Nama Siswa  = %s\n",ptr_pos_data->nama);
    printf("Nilai Ujian = %d\n",ptr_pos_data->ujian);
    printf("Huruf Mutu  = %c\n",ptr_pos_data->huruf);
    puts  ("------------------\n");
 break;
 }
}
}
