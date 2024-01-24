// Deque is a linked list that can be accessed from both ends
// It is a double ended queue

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct deque {
    node *head;
    node *tail;
} deque;

void init(deque *d) {
    d->head = NULL;
    d->tail = NULL;
}

void push_front(deque *d, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = d->head;
    new_node->prev = NULL;
    if (d->head != NULL)
        d->head->prev = new_node;
    d->head = new_node;
    if (d->tail == NULL)
        d->tail = new_node;
}

void push_back(deque *d, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = d->tail;
    if (d->tail != NULL)
        d->tail->next = new_node;
    d->tail = new_node;
    if (d->head == NULL)
        d->head = new_node;
}

int pop_front(deque *d) {
    if (d->head == NULL)
        return -1;
    node *temp = d->head;
    int data = temp->data;
    d->head = d->head->next;
    if (d->head != NULL)
        d->head->prev = NULL;
    else
        d->tail = NULL;
    free(temp);
    return data;
}

int pop_back(deque *d) {
    if (d->tail == NULL)
        return -1;
    node *temp = d->tail;
    int data = temp->data;
    d->tail = d->tail->prev;
    if (d->tail != NULL)
        d->tail->next = NULL;
    else
        d->head = NULL;
    free(temp);
    return data;
}

int peek_front(deque *d) {
    if (d->head == NULL)
        return -1;
    return d->head->data;
}

int peek_back(deque *d) {
    if (d->tail == NULL)
        return -1;
    return d->tail->data;
}

int is_empty(deque *d) {
    return d->head == NULL;
}

