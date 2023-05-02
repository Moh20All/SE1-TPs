#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define sz 10
// La structure de programm
typedef struct program
{
    char name[2];
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
    int tim;
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
    char ch[4]={'A','B','C','D'};

    for (int i = 0; i < n; i++)
    {

        TEMP = (program *)malloc(sizeof(program));
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

//Ajout un program
program *append(program* Tete){
    program* P=Tete;
    program* TEMP=Tete;
        TEMP = (program *)malloc(sizeof(program));
        printf("-Entrer le nom \n");
        scanf("%s",&TEMP->name[0]);
        printf("-Entrer taille de programm\n");
        scanf("%d", &(TEMP->size));
        printf("-Entrer le temps estimer\n");
        scanf("%d", &(TEMP->time));
        TEMP->next = NULL;
    if(Tete==NULL)
        Tete=TEMP;
    else{
                    P = Tete;
            while (P->next != NULL)
            {
                P = P->next;
            } // Loop
            P->next = TEMP;
    }
return Tete;
}

// Affichage de liste
void display(program *HEAD)
{

    program *P = NULL;
    P = HEAD;
    printf("\nName-size-time\n");
    while (P != NULL)
    {
        printf("%s-%d-%d->\n",P->name,P->size,P->time);
        P = P->next;
    }
}

// Delete allocated programm
program* delet(program *HEAD){

    program* P=HEAD;
    HEAD=HEAD->next;
    free(P);
    return HEAD;
}
// Search Free zone
void Free(pdt t[],mem memory[],int n,program *Tete,int tim[]){
    int jj=0;
        for(int i=0;i<n;i++){
        if((Tete->size)<=(t[i].size)&&(t[i].stat=='F')){
            t[i].stat='A';
            memory[i].name=Tete->name[0];
            t[i].tim=Tete->time;
            Tete=delet(Tete);
            jj=1;
        }
}
if(jj==0)
    printf("\n\tCant allocate memory Full...!");

    }
// Reset all elements(initialize)
void reset(int n,mem memory[],pdt t[]){
    for(int i=0; i<n;i++){
        memory[i].name='/';
        memory[i].num=i;

        t[i].stat='F';
        t[i].tim=9999;
        printf("Donner la taille de partition n=%d : \n",i);
        scanf("%d",&t[i].size);
    }
  }
// Memory affichage
void affich(pdt t[],mem uwu[],int n){
    printf("\n------------Affichage------------\n");
     printf("Mem_name->Mem_num\n\n");
    for(int i=0;i<=n-1;i++){
        printf("--Partition_n=---%d->%c\n",uwu[i].num,uwu[i].name);
    }
}
// Delete programm
void delete_prog(mem memory[],pdt t[],int dd){
        int i=0,jj=0,min=999999,index=0;
        char sup;

        while(i<dd){
            if(t[i].tim<min && min!=0){
                index=i;
                min = t[i].tim;
                jj=1;
            }
        i++;
        }
        if(jj==1){
        t[index].tim=9999;
        memory[index].name='/';
        t[index].stat='F';
        }
        if(jj==0)
    printf("\nCant Found program....!\n");
        else
     printf("\nIts Done.....\n");

  }
  affich_pdt(pdt t[],int dd){
      int i=0;
      printf("Num->size->stat\n");
      while(i<dd){
        printf("--Partition_n=---%d->%d->%c\n",t[i].num,t[i].size,t[i].stat);
        i++;
      }
  }
  //minimizer
int min(int t[],int n){
    int i=0,min=999999;
    min=t[0];
    while(i<n){
        if(t[i]<min && t[i]!=0){
            break;
        }
        i++;
    }
return i;
}
// Root
int main(){
//Declaration
    program *Tete;
    mem MEM[sz];
    pdt PDT[sz];
    int tm[sz];
    int n = 0,i,dumb=0,sw=0;
    char sup;
// Les program
        printf("-----------Entrer Le nombre de programms-------------\n");
        scanf("%d", &n);
        dumb=n;
        Tete=creation(n);
        display(Tete);
// Les partition
        printf("\n------------Entrer le nombre de partition------------\n");
        scanf("%d",&n);
        dumb=n;
//Reset All array elements
        reset(n,MEM,PDT);

//Search free zone

        Free(PDT,MEM,n,Tete,tm);

// Affiche la table

        affich(PDT,MEM,n);
// ----------- //

// Menu
while(sw!=7){
     printf("\n\n\n------  ADD a program to queue....|1|\n");
     printf("\n------  Allocate The last node in queue....|2|\n");
     printf("\n------  Free Program from memory....|3|\n");
     printf("\n------  Display Queue of programs....|4|\n");
     printf("\n------  Display Memory status....|5|\n");
     printf("\n------  Display PDT table....|6|\n");
     printf("\n------  Exit....|7|\n");
     scanf("%d",&sw);
     switch (sw)
     {
     case 1:
         append(Tete);
         break;
     case 2:
         Free(PDT,MEM,n,Tete,tm);
         break;
     case 3:
        printf("\nEnter Programm to Free.\n");
        delete_prog(MEM,PDT,dumb);
        break;
     case 4:
        display(Tete);
        break;
     case 5:
        affich(PDT,MEM,n);
        break;
     case 6:
         affich_pdt(PDT,n);
        break;
     case 7:
         exit(0);
         return 0;
        break;
     default:
         break;
     }
}



return 0;
}
