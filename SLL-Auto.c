#include <stdio.h>
#include <stdlib.h>

typedef struct simpul node;

struct simpul{
    int data;
    node *next;
};

void alokasi();
void tampil();
void bebas();
void menu();
void insertAwal();
void insertAkhir();
void insertAfter();
void insertBefore();
void deleteAwal();
void deleteAkhir();
void deleteAfter();
void deleteTertentu();

node *p=NULL;
node *head=NULL;
node *hapus=NULL;
node *after=NULL;
int belakang;
int depan;
char jwb;

int main()
{
    do{
        menu();
    }while(1);
    return 0;
}

void menu()
{
    char pilih;
    char jwb;
    printf("Menu : \n");
    printf("a. Tambah Data\n");
    printf("b. Hapus Data\n");
    printf("c. Selesai\n");
    printf("Silahkan pilih : ");
    pilih=getchar();
    fflush(stdin);
    if(pilih=='a')
    {
        alokasi();
        int data=p->data;
        if(head==NULL||data<=depan)
        {
            insertAwal();
            depan=data;
            if(belakang<depan)
            {
                belakang=data;
            }
        }
        else if(data>=belakang)
        {
            insertAkhir();
            belakang=data;
        }
        else
        {
            insertBefore();
        }
        tampil();
    }
    else if(pilih=='b')
    {
        if(head==NULL)
        {
            printf("Belum ada SLL, pilih tambah data dahulu\n\n");
            menu();
        }
        printf("\nMenu : \n");
        printf("a. Delete Awal\n");
        printf("b. Delete Akhir\n");
        printf("c. Delete Tertentu\n");
        printf("Silahkan pilih menu : ");
        jwb=getchar();
        fflush(stdin);
        switch(jwb)
        {
            case 'a':
                deleteAwal();
                tampil();
                break;
            case 'b':
                deleteAkhir();
                tampil();
                break;
            case 'c':
                deleteTertentu();
                tampil();
                break;
        }
    }
    else
        exit(0);

}

void alokasi()
{
    p=(node*)malloc(sizeof(node));
    if(p==NULL)
    {
        printf("Gagal");
        exit(0);
    }
    else
    {
        printf("Masukkan nilai : ");
        scanf("%d", &p->data);
        fflush(stdin);
        p->next=NULL;
    }
}

void insertAwal()
{
    if(head!=NULL)
        p->next=head;
    head=p;
}

void insertAkhir()
{
    node *tail=head;
    if(head==NULL)
    {
        head=p;
    }
    else
    {
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        tail->next=p;
    }
}

void insertBefore()
{
    node *before=head;
    node *prevbefore=head;
    while(before->data<p->data)
    {
        prevbefore=before;
        before=before->next;
    }
        prevbefore->next=p;
        p->next=before;
}

void deleteAwal()
{
    hapus=head;
    if(hapus->next==NULL)
        head=NULL;
    else
        head=hapus->next;
    bebas();
    printf("Data setelah di delete : \n");
}

void deleteAkhir()
{
    node *ph;
    hapus=head;
    if(hapus->next==NULL)
        head=NULL;
    else{
        while(hapus->next!=NULL)
        {
            ph=hapus;
            hapus=hapus->next;
        }
        ph->next=NULL;
    }
    bebas();
    printf("Data setelah di delete : \n");
}

void deleteTertentu()
{
    hapus=head;
    node *ph;
    int key;
    printf("Mau hapus apa? \n");
    scanf("%d", &key);
    fflush(stdin);
    while(hapus->data!=key)
    {
        if(hapus->next==NULL)
        {
            printf("Key tidak ada");
            exit(0);
        }
        else
        {
            ph=hapus;
            hapus=hapus->next;
        }
    }

    if(head->data==key)
    {
        head = hapus->next;
    }
    else
        ph->next=hapus->next;
    bebas();
    printf("Data setelah di delete : \n");
}

void tampil()
{
    if(head==NULL)
    {
        printf("Tidak ada data lagi\n\n");
        menu();
    }
    node *p=head;
    do
    {
        printf("%d\n", p->data);
        p=p->next;
    }while(p!=NULL);
    puts("");
    menu();
}

void bebas()
{
    free(hapus);
    hapus=NULL;
}
