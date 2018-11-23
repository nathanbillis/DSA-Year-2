struct List;
struct List* listConstructor();
void listDestructior(struct List* list);
int listAdd(struct List* list, int entity);
void listDisplay(struct List* list);
int listRead(struct List* list, int index, int* entity);
int listSearch(struct List* list, int entity);
void listRemove(struct List* list, int index);
int listSize(struct List* list);
int listIsEmpty(struct List* list);

struct ListNode;
struct ListNode* listNodeConstructor(int value);
void listNodeDeconstructor(struct ListNode* node);
struct ListNode* ListGetNode(struct List* list, int index);

// sorting algorithms
void swap_pos(int* a, int* b);
void listBubbleSort(struct List* list);
int listAddOrdered(struct List* list, int entity);
int listAddindex(struct List* list, int entity, int index);
int listIsSorted(struct List* list);
void listInsertionSort(struct List* list);
int listBinarySearch(struct List* list, int target);
void listQuickSort(struct List* list);
void implementQuickSort(int* list_entities, int low, int high);
int partitionList(int* values, int low, int high);
