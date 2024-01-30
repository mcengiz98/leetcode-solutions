typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct deque
{
    node *head;
    node *tail;
} deque;

void init(deque *d)
{
    d->head = NULL;
    d->tail = NULL;
}

void push_back(deque *d, int data)
{
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

int pop_back(deque *d)
{
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

int evalRPN(char **tokens, int tokensSize)
{
    char *token;
    deque *stack = (deque *)malloc(sizeof(deque));
    int t1, t2;

    init(stack);

    for (size_t i = 0; i < tokensSize; ++i)
    {
        token = tokens[i];
        if (strlen(token) == 1)
        {
            switch (*token)
            {
            case '+':
                t1 = pop_back(stack);
                t2 = pop_back(stack);
                push_back(stack, (t2 + t1));
                break;
            case '-':
                t1 = pop_back(stack);
                t2 = pop_back(stack);
                push_back(stack, (t2 - t1));
                break;
            case '*':
                t1 = pop_back(stack);
                t2 = pop_back(stack);
                push_back(stack, (t2 * t1));
                break;
            case '/':
                t1 = pop_back(stack);
                t2 = pop_back(stack);
                push_back(stack, (t2 / t1));
                break;
                break;
            default:
                push_back(stack, atoi(token));
            }
        }
        else
            push_back(stack, atoi(token));
    }

    return pop_back(stack);
}