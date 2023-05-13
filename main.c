#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x) {
    struct Node* temp =
        (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(front == NULL && rear == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue() {
    struct Node* temp = front;
    if(front == NULL) {
        printf("Kuyruk bos!\n");
        return;
    }
    if(front == rear) {
        front = rear = NULL;
    }
    else {
        front = front->next;
    }
    free(temp);
}

void display() {
    struct Node* temp = front;
    if(front == NULL) {
        printf("Kuyruk bos!\n");
        return;
    }
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, x;
    while(1) {
        printf("1. Kuyrukta Eleman Ekle\n");
        printf("2. Kuyruktan Eleman Cikar\n");
        printf("3. Kuyruktaki Elemanlari Goster\n");
        printf("4. Cikis\n");
        printf("Secim yapiniz: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Eklenecek elemani girin: ");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Gecersiz secim!\n");
        }
    }
    return 0;
}
