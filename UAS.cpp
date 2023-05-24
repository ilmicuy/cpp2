#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NAME_LENGTH 50
#define NIM_LENGTH 8

typedef struct
{
    char name[NAME_LENGTH+1], nim[NIM_LENGTH+1], ql;
    float quiz_score, task_score, uts_score,
        uas_score, final_score;
    struct student_node *next_node;
} student_node;

student_node *head_ptr = NULL;

void operation_menu();
void operation_determiner();
void operation_processor(int code);

void add_data();
void show_all_data();
void show_data_by_nim();
void update_data_by_name();
void delete_data();

void ginps(char message[], char *obj, int mxvl);
void ginpsc(char message[], char *obj);
void float_input(char *message, float *object);
float get_fs(student_node *);
char get_ql(float fs);
void print_single_data(student_node *);
void call_end();

// Driver program

int main()
{
    operation_menu();
    return 0;
}

// Operation Flow

void operation_menu() 
{
    puts("");
    puts("Pilih operasi yang akan dilakukan :");
    puts("1. Menambahkan data Mahasiswa");
    puts("2. Menampilkan seluruh data Mahasiswa");
    puts("3. Menampilkan data berdasarkan NIM");
    puts("4. Mengubah data berdasarkan nama");
    puts("5. Menghapus data");
    puts("6. Keluar");
    puts("");
    operation_determiner();
}

void operation_determiner()
{
    short int opt;
    printf("Pilihan: "); 
    scanf("%hd", &opt);
    fflush(stdin);
    puts("");
    operation_processor(opt);
}

void operation_processor(int code)
{
    switch(code) {
        case 1 : 
        {
            add_data();
            break;
        }
        case 2 : 
        {
            show_all_data();
            break;
        }
        case 3 : 
        {
            show_data_by_nim();
            break;
        }
        case 4 : 
        {
            update_data_by_name();
            break;
        }
        case 5 : 
        {
            delete_data();
            break;
        }
        case 6 : 
        {
            puts("Keluar.");
            exit(1);
            break;
        }
        default : 
        {
            puts("Pilihan tidak valid!!");
            puts("Ulangi pemasukan\n");
            operation_determiner();
            break;
        }
    }
}

// Implementation function

void add_data() 
{
    char answer;
    student_node *new_ptr;

    puts("Menabahkan data baru");

    do
    {

        new_ptr = (student_node *)malloc(sizeof(student_node));

        if (new_ptr)
        {
            ginpsc("\nNama           : ", new_ptr->name);
            ginpsc("NIM            : ", new_ptr->nim);
            float_input("Nilai Tugas    : ", &new_ptr->task_score);
            float_input("Nilai Quiz     : ", &new_ptr->quiz_score);
            float_input("Nilai UTS      : ", &new_ptr->uts_score);
            float_input("Nilai UAS      : ", &new_ptr->uas_score);
            new_ptr->final_score = get_fs(new_ptr);
            new_ptr->ql = get_ql(new_ptr->final_score);

            new_ptr->next_node = head_ptr;
            head_ptr = new_ptr;
        }
        else
        {
            puts("Memori tidak cukup..!");
        }

        printf("\nMasukkan data lagi? (Y/T) = ");
        scanf(" %c", &answer);

    } while (answer == 'Y');

    operation_menu();
}

void show_all_data()
{
    student_node *chc_ptr;
    chc_ptr = head_ptr;

    puts("\n--------------------------------------\n");

    while(chc_ptr)
    {
        print_single_data(chc_ptr);
        chc_ptr = chc_ptr->next_node;
    }

    puts("--------------------------------------\n");
    
    operation_menu();
}

void show_data_by_nim()
{
    char nim[NIM_LENGTH+1];

    student_node *chc_ptr;
    student_node *prv_chc_ptr;

    prv_chc_ptr = NULL;
    chc_ptr = head_ptr;

    ginpsc("Masukkan nim yang dicari   : ", nim);

    puts("\n--------------------------------------\n");

    while (chc_ptr)
    {
        if (strcmp(nim, chc_ptr->nim) != 0)
        {
            prv_chc_ptr = chc_ptr;
            chc_ptr = chc_ptr->next_node;
        }
        else
        {
            print_single_data(chc_ptr);
            break;
        }
    }

    puts("--------------------------------------\n");

    operation_menu();
}

void update_data_by_name()
{
    char query[NAME_LENGTH+1];

    student_node *chc_ptr;
    student_node *prv_chc_ptr;

    prv_chc_ptr = NULL;
    chc_ptr = head_ptr;

    ginpsc("Masukkan nama yang dicari   : ", query);

    while (chc_ptr)
    {
        if (strcmp(query, chc_ptr->name) == 0)
        {
            printf("\nMasukkan data nilai terbaru\n");
            float_input("Nilai Tugas    : ", &chc_ptr->task_score);
            float_input("Nilai Quiz     : ", &chc_ptr->quiz_score);
            float_input("Nilai UTS      : ", &chc_ptr->uts_score);
            float_input("Nilai UAS      : ", &chc_ptr->uas_score);
            chc_ptr->final_score = get_fs(chc_ptr);
            chc_ptr->ql = get_ql(chc_ptr->final_score);
            printf("\nData telah diperbaharui\n");
            break;
        }
        else
        {
            prv_chc_ptr = chc_ptr;
            chc_ptr = chc_ptr->next_node;
        }
    }

    operation_menu();
}

void delete_data()
{
    char query[NAME_LENGTH+1];

    student_node *chc_ptr;
    student_node *prv_chc_ptr;

    prv_chc_ptr = NULL;
    chc_ptr = head_ptr;

    ginpsc("Masukkan nim atau nama yang dicari   : ", query);

    while (chc_ptr)
    {
        if ((strcmp(query, chc_ptr->nim) == 0) || (strcmp(query, chc_ptr->name) == 0))
        {
            if (prv_chc_ptr == NULL)
            {
                head_ptr = head_ptr->next_node;
                free(chc_ptr);
            }
            else
            {
                prv_chc_ptr->next_node = chc_ptr->next_node;
                free(chc_ptr);
            }
            printf("\nData telah dihapus\n");
            break;
        }
        else
        {
            prv_chc_ptr = chc_ptr;
            chc_ptr = chc_ptr->next_node;
        }
    }

    operation_menu();
}

// Helper function

void ginps(char message[], char *obj, int mxvl)
{
    char c; int i = 0, end = 0;
    printf("%s", message);
    fflush(stdin);
    do
    {
        c = getchar();
        if (c == '\n' || i > mxvl)
        {
            end++;
        }
        else
        {
            obj[i] = c;
            i++;
        }
    }
    while (end == 1);
}

void ginpsc(char message[], char *obj)
{
    printf("%s", message);
    scanf("%s", obj);
}

void float_input(char *message, float *object)
{
    printf("%s", message);
    scanf("%f", object);
}

float get_fs(student_node *data)
{
    return (0.2 * data->task_score) +
        (0.2 * data->quiz_score) +
        (0.3 * data->uts_score) +
        (0.3 * data->uas_score);
}

char get_ql(float fs)
{
    if (fs >= 78 && fs <= 100)
    {
        return 'A';
	}
	else if (fs >= 65 && fs <= 77.99 )
    {
		return 'B';
	} 
	else if (fs >= 45 && fs<= 64.99) 
    {
		return 'C';
	}
	else if (fs >= 26 && fs <= 44.99)
    {
		return 'D';
	}
	else if (fs >= 0 && fs <= 25.99)
    {
		return 'E';
	}
	else
	{
		return 'Z';
	}
}

void print_single_data(student_node *data)
{
    printf("Nama        : %s\n", data->name);
    printf("NIM         : %s\n", data->nim);
    printf("Nilai Tugas : %.2f\n", data->task_score);
    printf("Nilai Quiz  : %.2f\n", data->quiz_score);
    printf("Nilai UTS   : %.2f\n", data->uts_score);
    printf("Nilai UAS   : %.2f\n", data->uas_score);
    printf("Nilai Akhir : %.2f\n", data->final_score);
    printf("Huruf Mutu  : %c\n\n", data->ql);
}

void call_end()
{
    printf("\nTekan tombol apapun untuk kembali\n");
    getchar();
}

