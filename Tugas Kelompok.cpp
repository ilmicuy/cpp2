#include <stdio.h>
#include <conio.h>
#include <string.h>
#define maks 3
struct TMhs

/**
*Menghitung Nilai Mahasiswa
*/

{
char NIM[9];
char Nama[21];
int NilaiUTS,NilaiUAS,NilaiQuis;
float NilaiAkhir;
char index;
};

main()
{
TMhs mhs[maks]; // array struct

int i;
for(i=0;i<maks;i++)

{
printf("\nPengisian Data Mahasiswa Ke-%i\n",i+1);
printf("NAMA : ");fflush(stdin);gets(mhs[i].Nama);
printf("NIM : ");fflush(stdin);gets(mhs[i].NIM);
printf("Nilai QUIZ : ");scanf("%d",&mhs[i].NilaiQuis);
printf("Nilai UTS : ");scanf("%d",&mhs[i].NilaiUTS);
printf("Nilai UAS : ");scanf("%d",&mhs[i].NilaiUAS);

mhs[i].NilaiAkhir=0.2*mhs[i].NilaiQuis+0.2*mhs[i].NilaiUTS+0.3*mhs[i].NilaiUAS+0.3;

if(mhs[i].NilaiAkhir>=80-100) mhs[i].index='A';
else

if(mhs[i].NilaiAkhir>=68-79) mhs[i].index='B';
else

if(mhs[i].NilaiAkhir>=45-67) mhs[i].index='C';
else

if(mhs[i].NilaiAkhir>=31-44) mhs[i].index='D';
else

if(mhs[i].NilaiAkhir>=0-30) mhs[i].index='E';
};
printf("Data yang telah dimasukan adalah : \n");
printf("---------------------------------------\n");
printf("| NIM | NAMA | QUIS | UTS | UAS | Nilai Akhir | INDEX |\n");
printf("---------------------------------------\n");

for(i=0;i<maks;i++)
{
printf("| %-3s | %-4s | %-4i | %3i | %3i | %11f | %5c |\n",
mhs[i].NIM,mhs[i].Nama,mhs[i].NilaiQuis,mhs[i].NilaiUTS,
mhs[i].NilaiUAS,mhs[i].NilaiAkhir,mhs[i].index);
}
printf("--------------------------------------\n");
getch();
return 0;
}
