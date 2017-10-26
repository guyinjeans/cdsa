typedef struct queue_t Queue;

int queue_size(struct queue_t* self);
int push(struct queue_t* self);
int pop(struct queue_t* self);
int head(struct queue_t* self);
int back(struct queue_t* self);
