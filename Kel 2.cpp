#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define PANJANG_NAMA 20
#define PANJANG_NIM 10
#define NILAI 10
#define ENTER 13
struct student
{
char Nama[PANJANG_NAMA+1];
char NIM[PANJANG_NIM+1];
float NA, score_tugas, score_quiz, score_uts, score_uas;
float a,b,c,d,e;
char Huruf;

struct student *lanjutan;
};
struct student *ptr_kepala=NULL;
struct student *ptr_pos_data;
struct student *ptr_pendahulu;
void input_data(void);
void masukan_string(char *keterangan, char *masukan, int panjang_maks);
void tampil_data(void);
void menu_pilihan(void);
void edit_data(void);
void hapus_data(void);
void score_akhir(void);
void cari_data(void);
char huruf_mutu(float NA);

main()
{
 menu_pilihan();
}


void input_data(void)
{ 
         char jawaban;
         struct student *ptr_baru;
 		do {
 			
         ptr_baru=(struct student *)malloc(sizeof(struct student));
 
          if (ptr_baru)
          {
            printf("NIM      		: "); scanf("%s",&ptr_baru->NIM);
            printf("Nama Mahasiswa		: "); scanf("%s",&ptr_baru->Nama);
            printf("Nilai Tugas     	: "); scanf("%f",&ptr_baru->score_tugas);
            printf("Nilai Quiz      	: "); scanf("%f",&ptr_baru->score_quiz);
            printf("Nilai UTS       	: "); scanf("%f",&ptr_baru->score_uts);
            printf("Nilai UAS      		: "); scanf("%f",&ptr_baru->score_uas);
 
            ptr_baru->NA=
            (0.2*ptr_baru->score_tugas)+
            (0.2*ptr_baru->score_quiz)+
            (0.3*ptr_baru->score_uts)+
            (0.3*ptr_baru->score_uas);
            printf("Nilai Akhir adalah : %.2f",ptr_baru->NA); 

			ptr_baru->Huruf=huruf_mutu(ptr_baru->NA);
          
            printf("\nIndeks Nilai Mahasiswa Atas Nama %s adalah  : %c",ptr_baru->Nama,ptr_baru->Huruf);

            ptr_baru->lanjutan=ptr_kepala;
            ptr_kepala=ptr_baru;
            printf("\nMemasukan data lagi (Y/T) ? ");
       do
            {
                jawaban=toupper(getche()); printf("\n");
            }   while (!(jawaban=='Y' || jawaban=='T'));
       }
   } while (jawaban=='Y');
	  menu_pilihan();
   }
      
char huruf_mutu(float NA)
{
	  		if (NA>=78) return 'A';    
            else if (NA>=65) return 'B';
            else if (NA>=45) return 'C';
            else if (NA>=26) return 'D';
            else return 'E';

  }  
		
void masukan_string(char *keterangan, char *masukan, int panjang_maks)
   {    char st[256];
        do
   {
        printf(keterangan);
        gets(st);
        if (strlen(st)>panjang_maks)
        printf("Terlalu panjang. Maks %d karakter\n",panjang_maks); 
   } while (strlen(st)>panjang_maks);
    strcpy(masukan,st);
   }
void tampil_data(void)
{ 
	struct student *ptr_sementara;
     puts("\nIsi LINKED LIST :");
     ptr_sementara=ptr_kepala;
     while (ptr_sementara)
   {
     printf("Nomor NIM      %s\n",ptr_sementara->NIM);
     printf("Nama Mahasiswa %s\n",ptr_sementara->Nama);
     printf("Nilai Tugas     %.2f\n",ptr_sementara->score_tugas);
     printf("Nilai Quiz    %.2f\n",ptr_sementara->score_quiz); 
     printf("Nilai UTS      %.2f\n",ptr_sementara->score_uts); 
     printf("Nilai UAS      %.2f\n",ptr_sementara->score_uas); 
     printf("Nilai Akhir    %.2f\n",ptr_sementara->NA); 
     printf("Huruf Mutu		%c\n",ptr_sementara->Huruf);
     ptr_sementara=ptr_sementara->lanjutan;
   }
     printf("\n\nTEKAN ENTER untuk kembali ke Menu Pilihan...!");
     menu_pilihan();
} 

void hapus_data(void)
{
	char nama[20];
	printf("\nMasukan Nama yang akan dihapus : "); scanf("%s",nama);
	struct student *ptr_pos_data;
	struct student *ptr_pendahulu;
	ptr_pendahulu=NULL;
	ptr_pos_data=ptr_kepala;
	while (ptr_pos_data){
		if (strcmp(nama,ptr_pos_data->Nama)!=0)
		{
			ptr_pendahulu=ptr_pos_data;
			ptr_pos_data=ptr_pos_data->lanjutan;
		} else {
			if (ptr_pendahulu==NULL){
				ptr_kepala=ptr_kepala->lanjutan; free (ptr_pos_data);
			} else {
				ptr_pendahulu->lanjutan=ptr_pos_data->lanjutan;
				free(ptr_pos_data);
				
			}
			puts("PENGHAPUSAN DATA BERHASIL!");
			puts("---TEKAN ENTER---");
			getch();
			break;
		}
	}
	main();
}

void cari_data(void)
{
	char nim[20];
	ptr_pendahulu=NULL;
	ptr_pos_data=ptr_kepala;
	printf("Masukan NIM yang ingin ditampilkan : "); gets(nim);
	while (ptr_pos_data)
	{
		if (strcmp(nim,ptr_pos_data->NIM)!=0)
		{
			ptr_pendahulu=ptr_pos_data;
			ptr_pos_data=ptr_pos_data->lanjutan;
		}
		else
		{
			printf("Nomor NIM			:      %s\n",ptr_pos_data->NIM);
     		printf("Nama Mahasiswa		: %s\n",ptr_pos_data->Nama);
     		printf("Nilai Tugas			:     %.2f\n",ptr_pos_data->score_tugas);
     		printf("Nilai Quiz			:    %.2f\n",ptr_pos_data->score_quiz); 
     		printf("Nilai UTS			:      %.2f\n",ptr_pos_data->score_uts); 
     		printf("Nilai UAS			:      %.2f\n",ptr_pos_data->score_uas); 
     		printf("Nilai Akhir			:    %.2f\n",ptr_pos_data->NA); 
     		printf("Huruf Mutu			:		%c\n",ptr_pos_data->Huruf);
     		getch();
     		break;
		}
	}
	
}

void menu_pilihan(void)
   { char pilihan;
     puts("MENU PILIHAN");
     puts("1.Input Data");
     puts("2.Menampilkan Data");
     puts("3.Menghapus Data");
     puts("4.Mengedit Data");
     puts("5.Mencari Data");
     puts("6.SELESAI");
     printf("Pilihan 1/2/3/4/5/6 = ");
     do
   {
     pilihan=getche(); fflush(stdin); printf("\n");
   }while (pilihan < '1' || pilihan > '6');
    switch (pilihan)
   {
    case '1' : input_data(); break;
    case '2' : tampil_data(); break;
    case '3' : hapus_data(); break;
    case '4' : edit_data(); break;
    case '5' : cari_data(); break;
    case '6' : 
   {
    printf("\n\nTEKAN ENTER UNTUK KEMBALI KE PROGRAM...!");
    getch(); exit(0);
   }
 }
}


void edit_data(void)
    { char Nama[256];
    ptr_pendahulu=NULL;
    ptr_pos_data=ptr_kepala;
    printf("Masukan Nama yang akan diedit : "); gets(Nama);
    while (ptr_pos_data)
   {
        if (strcmp(Nama,ptr_pos_data->Nama)!=0)
  {
      ptr_pendahulu=ptr_pos_data;
      ptr_pos_data=ptr_pos_data->lanjutan;
  }else
 {
   puts("Ketemu...!");
   printf("Nilai Tugas Menjadi  : ");
   scanf("%f", &ptr_pos_data->score_tugas);
   printf("Nilai Quiz Menjadi : ");
   scanf("%f", &ptr_pos_data->score_quiz);
   printf("Nilai UTS Menjadi   : ");
   scanf("%f", &ptr_pos_data->score_uts);
   printf("Nilai UAS Menjadi   : ");
   scanf("%f", &ptr_pos_data->score_uas);
   ptr_pos_data->NA=
            (0.2*ptr_pos_data->score_tugas)+
            (0.2*ptr_pos_data->score_quiz)+
            (0.3*ptr_pos_data->score_uts)+
            (0.3*ptr_pos_data->score_uas);
            ptr_pos_data->Huruf=huruf_mutu(ptr_pos_data->NA);
   puts("Edit data berhasil dilakukan...!");
   getch();
   break;
  }
 }
 menu_pilihan();
}

