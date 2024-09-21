#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node* addNode(Node *head, char *str, size_t len) {
    Node *new = (Node*)malloc(sizeof(Node));
    if(new == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    new->data = (char*)malloc(len);
    if(new->data == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        free(new);
        exit(1);
    }

    strncpy(new->data, str, len);
    new->next = NULL;

    if(head == NULL) {
        return new;
    }

    Node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new;

    return head;
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != NULL) {
        printf("%s", curr->data);
        curr = curr->next;
    }
}

void freeMem(Node *node) {
    Node *curr = node;
    while (curr != NULL) {
        Node *next = curr->next;
        free(curr->data);
        free(curr);
        curr = next;
    }
}

int main() {
    char str[5];
    char *data;
    Node *node = NULL;
    int flag = 0;

    while (1) {
        data = fgets(str, sizeof(str), stdin);
        size_t len = strlen(data) + 1;
        
        if(data[0] == '.' && !flag) {
            break;
        }

        if(data[len - 2] != '\n') {
            flag = 1;
        }
        
        else {
            flag = 0;
        }
      

        node = addNode(node, data, len);
    }

    printList(node);
    freeMem(node);
    
    return 0;
}
