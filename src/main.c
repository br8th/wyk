#include <stdio.h>
#include <stdbool.h>
#include "ourhdr.h"

#define MINUSINFINITY -1
#define MAXHEAP 10

int findmin();
void insert(int value, int key);

int main()
{
	printf("Hello world!");
	insert(5, 4);
	printf("The smallest item inserted is: %d\n", findmin());
	insert(6, 3);
	printf("The smallest item inserted is: %d\n", findmin());
	insert(7, 2);
	printf("The smallest item inserted is: %d\n", findmin());
	insert(8, 0);
	printf("The smallest item inserted is: %d\n", findmin());
	return 0;
}

typedef struct heapslot heapslot;
struct heapslot
{
	int key;
	int value;
};

heapslot heap[MAXHEAP];
int heapnum;

// We use a sentinel value to simplify the implementation,
// and avoid and indexoutofbound
void initheap()
{
	heapnum = 0;
	heap[0].key = MINUSINFINITY;
}

static void swap(heapslot *s1, heapslot *s2)
{
	heapslot temp;
	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void insert(int value, int key)
{
	demand(heapnum < MAXHEAP, "heap overflow");

	// 1. Append our new item to the end of the array
	heapslot newEntry;
	newEntry.key = key;
	newEntry.value = value;

	heap[++heapnum] = newEntry;

	// 2. Bubble up the newly inserted entry until the heap property is restored.
	int cur, parent;
	cur = heapnum; // index of the newly created object.
	parent = cur / 2;

	// Because of our sentinel, our heap always contains atleast 1 item.
	while (heap[parent].key > heap[cur].key)
	{
		demand(parent > 0, "inserted item rising past root");
		swap(&heap[cur], &heap[parent]);
		cur = parent;
		parent = cur / 2; // Move up the tree.
	}
}

void deletemin()
{
}

int extractmin()
{
	// 1. Get the smallest entry (root), this is what we return
	int root = findmin();

	// 2. Get last entry in the heap, and insert it at the root
	heap[1] = heap[heapnum--];

	int cur = 1;
	int child = 2;

	// 3. Bubble-Down the last item removed.
	while (child <= heapnum)
	{
		// if the second child is smaller, swap with that one instead.
		if (child < heapnum && heap[child + 1].key < heap[child].key)
		{
			child++;
		}

		if (heap[cur].key > heap[child].key)
		{
			demand(child <= heapnum, "falling past leaves.");

			// swap
			swap(&heap[cur], &heap[child]);
			cur = child;
			child = 2 * cur;
		}
		else
		{
			break;
		}
	}

	return root;
}

bool empty()
{
	return heapnum == 0;
}

int findmin()
{
	demand(!empty(), "findmin not allowed on empty heap");
	return heap[1].value;
}
