
typedef struct IntNode
{
    int key;
    int value;
    struct IntNode *next;
} IntNode;

typedef struct IntDict
{
    IntNode **buckets;
} IntDict;

IntDict *create_int_dict();

void insert_int_node(IntDict *table, int key, int value);

int get_int_node(IntDict *table, int key);

void free_int_dict(IntDict *dict);