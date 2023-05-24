#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAKS 10
void input_bilangan(void);
void baca_file(void);
void cari_bilangan(void);
FILE *PF, *PR; int bil,jb;
main()
{
	input_bilangan();
	baca_file();
	cari_bilangan();
	getch();
}

void input_bilangan(void);
{	int x=0
	do
	{
		system cls();
		printf("Jumlah bilangan yang akan diinput [maks 10] ? ");
		scanf("%d", &jb); fflush(stdin);
		if (jb>10) puts("Maksimal bilangan yang akan diinput hanya 10 bilangan...!");
	} while (jb>MAKS);

if((PF=fopen("TES1.DAT","wb"))== NULL) //ciptakan file biner
{
	puts("file gagal diciptakan!");
	exit(1);
}

do
{
	x++;printf("Bilangan ke-%d= ",x);
	scanf("%d", &bil);
	putw(bil,PF); //tulis bil ke file biner
} while (x<jb);
fclose(PF); //menutup file
}


