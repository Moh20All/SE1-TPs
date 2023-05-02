#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//---------------------------------------------Main memory allocation-------------------------
typedef struct memory{
    int sz;
    char name;
    struct memory *next;
} mem;
// --------------------------------------------Program queue---------------------------------------
typedef struct programm{
    int name;
    int time;
    int size;
    struct programm *next;
}pgm;
//------------------------------------------------ Bit map ---------------------------------
typedef struct Bit_map{
    char stat[2];
    int st_add;
    int length;
    struct Bit_map *next;
}bm;
// -------------------------------------------- Variable Global ------------------------------
    pgm* tete=NULL;
    bm* bit_tete=NULL;
    mem* memory=NULL;
    int unit=0,main_m=0;
    void best_fit_memory(bm* BP);
//-----------------------------------calculate number of units of each programm------------------------
int pgm_units(pgm *T,int un){
    if(T->size%un==0){
        return T->size/un;
        }else{
        return (T->size/un)+1;
    }
}
//-----------------------------------calculate number of units of main memory--------------------
int memory_units(int mem,int un){
    if(mem%un==0){
        return mem/un;
        }else{
        return (mem/un)-1;
    }
}
// -------------------------------------- init memory ------------------------------------------
void init_memory(){

}
// -------------------------------------- init Bit-Map -----------------------------------------
void init_bit(int units){
    bm* HEAD=(bm*)malloc(sizeof(bm));
    HEAD->length=units;
    HEAD->stat[0]='H';
    HEAD->st_add=0;
    HEAD->next=NULL;
    bit_tete=HEAD;
}
// -------------------------------------- Get Programm -----------------------------------------
pgm *get_pgm(pgm * T){
    pgm *P=NULL;
    P=T;
    T=T->next;
    return P;
}
// -------------------------------------- Creation of bit map-----------------------------------
void best_fit(int un){
    int i=0,flag=-1,index=0;
    pgm* Q=NULL;
    bm* TEMP=NULL,*curr=NULL;
    bm* P=bit_tete;
    tete!=NULL? un=pgm_units(tete,un) : printf("There is no programms");
    if(tete==NULL)
        return;
    flag=-1;
    while(P!=NULL && tete!=NULL){// Test where is the fragmentationt
        if(un <= P->length && (un-P->length)<flag && P->stat[0]=='H'){//(TEST size && see if there less frag && check states)
            flag=((P->length)-(un));
            index=i;
        }
        P=P->next;
        i++;
    }
    if(flag==-1)
        printf("There is no place in the memory");
    else{
    i=0;
    P=bit_tete;

    while(i<index){
        i++;
        curr=P;
        P=P->next;
    }

    TEMP=(bm*)malloc(sizeof(bm));
    TEMP->st_add=P->st_add;
    TEMP->length=un;
    TEMP->stat[0]='P';
    P->st_add=(TEMP->st_add+TEMP->length)+1;
    P->length=P->length-TEMP->length;
    best_fit_memory(TEMP);
    //Link adresses
    if(curr==NULL){//if the hole is the first
    TEMP->next=P;
    bit_tete=TEMP;
    }else{ // if the hole is somewhere else
    TEMP->next=P;
    curr->next=TEMP;
    }
    Q=tete;
    tete=tete->next;
    free(Q);
    }
}
// --------------------------------------- Display ----------------------------------------------
void display(bm* M){
    int k=0;
    while(M!=NULL){

     for(int i=0;i<M->length;i++){
                 if(k==8){
            k=0;
            printf("\n");
        }
            if(M->stat[0]=='P')
                printf("1");
            else
                printf("0");
        k++;
        }
        M=M->next;
    }
}
// ---------------------------------------- Display nodes type -----------------------------
void display1(bm* M){
bm* P=M;
printf("\n\t\tStart adress->length->stat",P->st_add,P->length,P->stat[0]);
while(P!=NULL){
    printf("\n%d->%d->%c",P->st_add,P->length,P->stat[0]);
    P=P->next;
    }
}
// --------------------------------------- Programs Queue -----------------------------------------
pgm *creation(int n,int un)
{
    // La fonction de creation de "Nodes"
    pgm *HEAD = NULL;
    pgm *TEMP = NULL;
    pgm *P = NULL;
    char ch[4]={'A','B','C','D'};

    for (int i = 0; i < n; i++)
    {
        int sz=0;
        TEMP = (pgm *)malloc(sizeof(pgm));
        printf("Entrer le nom \n");
        scanf("%s",&TEMP->name);
        //TEMP->name='A'+i;
        printf("Entrer taille de programm\n");
        scanf("%d", &(TEMP->size));
        printf("Entrer le temps estimer\n");
        scanf("%d", &(TEMP->time));
        TEMP->next = NULL;

        if (HEAD == NULL)
        {
            HEAD = TEMP;
        }
        else
        {

            P = HEAD;
            while (P->next != NULL)
            {
                P = P->next;
            } // Loop
            P->next = TEMP;

        } // else
    }
    return HEAD;
}
//ADD a program
void append(){
    pgm* P=tete;
    pgm* TEMP=NULL;
        TEMP = (pgm *)malloc(sizeof(pgm));
        printf("-Entrer le nom \n");
        scanf("%s",&TEMP->name);
        printf("-Entrer taille de programm\n");
        scanf("%d", &(TEMP->size));
        printf("-Entrer le temps estimer\n");
        scanf("%d", &(TEMP->time));
        TEMP->next = NULL;
    if(tete==NULL)
        tete=TEMP;
    else{
                    P = tete;
            while (P->next != NULL)
            {
                P = P->next;
            } // Loop
            P->next = TEMP;
    }

}
// Affichage de liste
void display2()
{

    pgm *P = tete;
    printf("\nName->size->time\n");
    while (P != NULL)
    {
        printf("%c->%d->%d->\n",P->name,P->size,P->time);
        P = P->next;
    }
}
// --------------------------------------- Frag rate   -------------------------------------------
frag_calc(int uni,int memo){
float frag=0;
bm* P=bit_tete;
while(P!=NULL){
    if(P->stat[0]=='H'){
        frag=frag+P->length;
    }
    P=P->next;
}
frag=frag*uni;
frag=frag/memo;
frag!=0?printf("The rate of fragmentation : %f",frag):printf("Memory is full");
}
// ----------------------------------------- Search allocated pgm -----------------------------
int search_pgm(char ccm){
    int ttt;
    mem* temp=memory;
    while(temp!=NULL){
        if(temp->name==ccm){
            ttt=temp->sz;
            temp->sz=0;
            return ttt;
        }
        temp=temp->next;
    }
    return 0;
}
// ---------------------------------------- free programm -----------------------------------
void free_pgm(){
    int cc;
    int i=0,flag=-1,index=0;
    pgm* Q=NULL;
    bm* TEMP=NULL,*curr=NULL;
    bm* P=bit_tete;

    scanf("%s",&cc);
    flag=search_pgm(cc);
    while(P!=NULL){
        if(P->length== flag)
            break;
        curr=P;
        P=P->next;
    }
if(curr==NULL && P->next->stat[0]=='H'){
    P->next->length=P->next->length + P->length;
    P->next->st_add=0;
    bit_tete=P->next;
    return;
}
if(curr->stat[0]== 'H' && P->next->stat[0] =='P' && curr!=NULL){
    (curr->next)->stat[0] = 'H';
    curr->length=(curr->length) + P->length;
    curr->next = P->next;
    curr->next->st_add=curr->st_add+curr->length;
}
if(curr->stat[0]== 'P' && P->next->stat[0] =='H' && curr!=NULL){
     P->next->length=P->next->length + P->length;
     curr->next=P->next;
}
if(curr->stat[0]== 'H' && P->next->stat[0] =='H' && curr!=NULL){
    curr->length=P->length+curr->length+P->next->length;
    curr->next=P->next->next;
}
if(curr->stat[0]== 'P' && P->next->stat[0] =='P' && curr!=NULL){
    P->stat[0]='H';
}

}
// ---------------------------------------main programm -------------------------------------------
int main()
{
    int n_p=0,sw=0;
    printf("Enter The size of unit : ");
    scanf("%d",&unit);
    printf("Enter The size of Main memory : ");
    scanf("%d",&main_m);
    //memory units
    int mem_un=memory_units(main_m,unit);
    // programm units
    init_bit(mem_un);
    // program set
    printf("Enter number of programs : ");
    scanf("%d",&n_p);
    tete=creation(n_p,unit);
    //Menu suuuuuuuuuup
while(sw!=7){
     printf("\n\n\n------  ADD a program to queue....|1|\n");
     printf("\n------  Allocate The last node in queue....|2|\n");
     printf("\n------  Free Program from memory....|3|\n");
     printf("\n------  Display Queue of programs....|4|\n");
     printf("\n------  Display nodes type....|5|\n");
     printf("\n------  Display Bit table....|6|\n");
     printf("\n------  Calculate fragmentation rate....|7|\n");
     printf("\n------  Exit....|8|\n");
     scanf("%d",&sw);
     switch (sw)
     {
     case 1:
         append();
         break;
     case 2:
         best_fit(unit);
         break;
     case 3:
        printf("\nEnter Programm to Free.\n");
        free_pgm();
        break;
     case 4:
        display2();
        break;
     case 5:
        display1(bit_tete);
        break;
     case 6:
        display(bit_tete);
        break;
     case 7:
        frag_calc(unit,main_m);
        break;
     case 8:
         exit(0);
         return 0;
        break;
     default:
         break;
     }
}


    return 0;
}
void best_fit_memory(bm* BP){
    mem* temp=(mem*)malloc(sizeof(mem));
    mem* q=NULL;
    temp->sz=BP->length;
    temp->name=tete->name;
    temp->next=NULL;
    if(memory==NULL){
        memory=temp;
    }else{
        q=memory;
        while(q!=NULL){
            q=q->next;
        }
        q->next=temp;
    }
}
