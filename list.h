typedef struct List List;
typedef struct Node Node;

Node* createNode(void* data);
List* createList(void* data);
void insertAtHead(List* list, void* data);
void insertAtTail(List* list, void* data);

void forEachNode(List*, void (*callback)(Node*));
void forEachNodeReverse(List*, void (*callback)(Node*));
