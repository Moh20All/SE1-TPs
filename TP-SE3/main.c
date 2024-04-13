#include <stdio.h>
typedef struct list{
    int page;
    int count;
    struct list* next;
}node;
swap(struct list* a,struct list* b);
bubbleSort(struct list* head);
// --------------------------- Ajout au debut ---------------------------
void ajout_d(node* P,int i){
    node* Q = (node *)malloc(sizeof(node));
    Q=P;
    P=Q;
}
// ---------------------------- Ajout au fin -------------------------------
void ajout(node* P,int i){
    node* Q = (node *)malloc(sizeof(node));
    node *T=P;
    int k=0;
    while(T!=NULL){
        if(T->page==i){
            T->count++;
            break;
        }
        T=T->next;;
    }
    //if page does not exist == page fault
    if(T=NULL){
        Q->count=0;
        Q->page=i;
        T=Q;
    }

    trier(P);
}
//
int check(int pp,int f[],int m){
    for(int i=0;i<m;i++){
        if(f[i]==pp){
            return i;
        }
    }
}
int getpage(node* tt){
    node* T=tt,q=NULL;
    while(T->next!=NULL){
        T->count=0
        T=T->next;;
    }

}
// vars
node* Tete=NULL;
int main() {
    int n, m, i, j, hit, fault, min, min_idx, oldest;
    int *ref, *frames, *age;
    char *flag;

    printf("Enter the number of memory frames: ");
    scanf("%d", &m);

    printf("Enter the length of reference chain: ");
    scanf("%d", &n);

    ref = (int *) malloc(n * sizeof(int));
    frames = (int *) malloc(m * sizeof(int));
    age = (int *) malloc(m * sizeof(int));
    flag = (char *) malloc(m * sizeof(char));

    printf("Enter the reference chain:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &ref[i]);
    }

    for (i = 0; i < m; i++) {
        frames[i] = -1;
        age[i] = 0;
        flag[i] = 0;
    }

    hit = 0;
    fault = 0;
    oldest = 0;

    for (i = 0; i < n; i++) {
        min = n;
        min_idx = -1;
        for (j = 0; j < m; j++) {
            if (frames[j] == ref[i]) {//exist = ! page default
                age[j] = 0;
                flag[j] = 1;
                break;
            }
            if (frames[j] == -1) { // ! exist = page default
                fault++;
                frames[j] = ref[i];
                flag[j] = 1;
                break;
            }
            if (age[j] < min) {
                min = age[j];
                min_idx = j;
            }
        }
        if (j == m) {// no place in memory
                oldest=-1;
            int temp=getpage(Tete);
            Tete->count=0;
            trier(Tete);
            fault++;
            check(temp);
            oldest=check(temp,frames,m);
            frames[oldest] = ref[i];
        }
        ajout(Tete,ref[i]);
    }

    printf("Number of page faults: %d\n", fault);

    free(ref);
    free(frames);
    free(age);
    free(flag);

    return 0;
}



void swap(struct list* a, struct list* b) {
    int temp = a->count;
    a->count = b->count;
    b->count = temp;
}


void trier(struct list* head) {
    int swapped;
    node* current;
    node* last = NULL;


    if (head == NULL)
        return;

    do {
        swapped = 0;
        current = head;

        while (current->next != last) {
            if (current->count > current->next->count) {
                swap(current, current->next);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}
