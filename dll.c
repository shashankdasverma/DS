#include <stdio.h>

#include <conio.h>

#include <stdlib.h>

struct node {
  int data;
  struct node * next;
  struct node * prev;
};
struct node * head;
void insertbeginning(int item) {
  struct node * ptr = (struct node * ) malloc(sizeof(struct node));
  if (head == NULL) {
    ptr -> next = NULL;
    ptr -> prev = NULL;
    ptr -> data = item;
    head = ptr;
  } else {
    ptr -> data = item;
    ptr -> prev = NULL;
    ptr -> next = head;
    head -> prev = ptr;
    head = ptr;
  }
}

void deleteSpecified() {
  struct node * ptr, * temp;
  int val;
  printf("Enter the value:");
  scanf("%d", & val);
  temp = head;
  while (temp -> data != val) temp = temp -> next;
  if (temp -> next == NULL) {
    printf("\nCan't delete\n");
  } else if (temp -> next -> next == NULL) {
    temp -> next = NULL;
    printf("\nNode Deleted\n");
  } else {
    ptr = temp -> next;
    temp -> next = ptr -> next;
    ptr -> next -> prev = temp;
    free(ptr);
    printf("\nNode Deleted\n");
  }
}

void display() {
  struct node * ptr;
  ptr = head;
  if (ptr == NULL) {
    printf("Empty ");
  } else {
    while (ptr != NULL) {
      printf("%d ", ptr -> data);
      ptr = ptr -> next;
    }
    printf("\n");
  }
}

int main() {
  int op = 0;
  int a;
  printf("\n1.Insert to the left\n2.Delete at specified position\n3.Display\n ");

  while (op != 4) {
    printf("\nEnter your choice : ");
    scanf("%d", & op);
    switch (op) {
    case 1:
      printf("\nEnter value to be inserted :");
      scanf("%d", & a);
      insertbeginning(a);
      break;
    case 2:
      deleteSpecified();
      break;
    case 3:
      display();
      break;

    }
  }
}
