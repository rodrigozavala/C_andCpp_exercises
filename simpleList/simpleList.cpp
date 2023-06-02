#include <stdio.h>
#include <stdlib.h>
typedef struct s{
    char state;
    struct s *left;
    struct s *right;
}node;

node * newNode(char myState){
    node *q=(node *)malloc(sizeof(node));
    q->left=NULL;
    q->right=NULL;
    q->state=myState;
    return q;
    
}

void addLeftNode(node *q,node *l){
    q->left=l;
    l->right=q;
    return;
}

void addRightNode(node *q,node *r){
    q->right=r;
    r->left=q;
    return;
}

bool leftIsNull(node* q){
    if (q==NULL){
        return false;
    }else if((*q).left==NULL){
        return true;
    }
    return false;
}

bool rightIsNull(node *q){
    if (q==NULL){
        return false;
    }else if((*q).right==NULL){
        return true;
    }
    return false;
}

int length(node *q){
    if(&q==NULL){
        return 0;
    }
    int counter=1;
    node *finalNode=q;
    node *current=q;
    if(rightIsNull(current)){
        return counter;
    }
    current=current->right;
    counter++;
    while (current!=finalNode){
        current=current->right;
        counter++;
    }

    return counter;
}



void showRightCircularList(node *q){
    if(q==NULL){
        printf("No elements in this circular list");
        return;
    }
    node *finalNode=q;
    node *current=q;
    if(rightIsNull(current) || current==NULL){
        printf("Current value is %c \n",current->state);
        return;
    }
    printf("Current value is %c \n",current->state);
    current=current->right;
    while (current != finalNode){
        printf("Current value is %c \n",current->state);
        current=current->right;
    }
    return;

}


void showLeftCircularList(node *q){
    if(q==NULL){
        printf("No elements in this circular list");
        return;
    }
    node *finalNode=q;
    node *current=q;
    if(leftIsNull(current) || current==NULL){
        printf("Current value is %c \n",current->state);
        return;
    }
    printf("Current value is %c \n",current->state);
    current=current->left;
    while (current != finalNode){
        printf("Current value is %c \n",current->state);
        current=current->left;
    }
    return;

}




main (){
    printf("Hola \n");
    node *a,*b,*c,*d;
    printf("Hola2 \n");
    a=newNode('A');
    printf("Hola3 \n");
    b=newNode('B');
    c=newNode('C');
    d=newNode('D');
    addLeftNode(a,b);
    addLeftNode(b,c);
    addLeftNode(c,d);
    addLeftNode(d,a);
    printf("half way\n");
    showRightCircularList(a);
    printf(" hahaha\n");
    showLeftCircularList(a);
}