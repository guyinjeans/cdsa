#include "list.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct List {

  Node* head;
  Node* tail;

} List;

typedef struct Node {

  void* data;
  struct Node* next;
  struct Node* prev;

} Node;

Node* createNode(void* data) {

  Node* node = malloc(sizeof(Node));

  node->data = data;
  node->next = NULL;
  node->prev = NULL;

  return node;

}

List* createList(void* data) {

  List* list = malloc(sizeof(List));
  Node* node = createNode(data);

  list->head = node;  
  list->tail = node;

  return list;

}

void insertAtHead(List* list, void* data) {

  Node* oldHead = list->head;   
  Node* newNode = createNode(data);

  list->head = newNode;
  newNode->next = oldHead;
  oldHead->prev = newNode;

}

void insertAtTail(List* list, void* data) {

  Node* newNode = createNode(data);

  list->tail->next = newNode;
  newNode->prev = list->tail;
  list->tail = newNode;

}

void forEachNode(List* list, void(*callback)(Node* node)) {
  Node* cursor = list->head; 
  while(cursor) {
    callback(cursor);
    cursor = cursor->next;
  }
}

void forEachNodeReverse(List* list, void(*callback)(Node* node)) {
  Node* cursor = list->tail;
  while(cursor) {
    callback(cursor);
    cursor = cursor->prev;
  }
}

void test(Node* node) {
  printf("%d\n", node->data);
}

int main() {
  List* list = createList(5); 
  insertAtHead(list, 3);
  insertAtTail(list, 1);
  forEachNode(list, test);
  forEachNodeReverse(list, test);
}
