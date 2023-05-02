#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sz 10
// La structure de programm
typedef struct program
{
    char name;
    int size;
    int time;
    struct program *next;
}program;

// La structure de memory
typedef struct mem{
    int num;
    char name;
} mem;

//La structure de PDT
typedef struct pdt
{
    int num;
    int size;
    char stat;
} pdt;

// creation de list
program *creation(int n)
{
    // La fonction de creation de "Nodes"
    program *HEAD = NULL;
    program *TEMP = NULL;
    program *P = NULL;


    for (int i = 0; i < n; i++)
    {

        TEMP = (program *)malloc(sizeof(program));
        printf("Entrer le nom \n");

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
// Affichage de liste
void display(program *HEAD)
{

    program *P = NULL;
    P = HEAD;
    while (P != NULL)
    {
        printf("%c-%d-%d->",P->name,P->size,P->time);
        P = P->next;
    }
}
program* delet(program *HEAD){

    program* P=HEAD;
    HEAD=HEAD->next;
    free(P);
    return HEAD;
}
int main(){

program *Tete;
mem MEM[sz];
pdt PDT[sz];
int n = 0,i;
// Les program
printf("-----------Entrer Le nombre de programms-------------\n");
scanf("%d", &n);
Tete=creation(n);
// Les partition
printf("------------Entrer le nombre de partition------------\n");
scanf("%d",&n);
for(i=0; i<=n;i++){
    MEM[i].num=i;
    PDT[i].num=i;
    PDT[i].stat='F';
    printf("Donner la taille de partition n=%d : \n",i);
    scanf("%d",PDT[i].size);
}
// Affiche la table
printf("------------Affichage------------\n");
for(i=0;i<=n;i++){
    printf("%d-%",MEM[i].num,MEM[i].name);
}

display(Tete);
return 0;
}
