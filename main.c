// ADT QUEUE
#include <stdio.h>
#include "ADT_queue.h"

typedef struct student {
	int id;
	int score;
} STD;

#define STD_N 20

int main() {

	int i;
	STD* std_ptr;

	// Creating Queue
	QUEUE* queue;
	queue = create_queue();

	// Allocating Memory
	STD* c[STD_N];
	for(i=0; i<STD_N; i++) {
		c[i] = (STD*)malloc(sizeof(STD));
	}

	// Data Preparing
	for(i=0; i<STD_N; i++) {
		c[i]->id	= i;
		c[i]->score	= i;
	}

	// Inserting Data into Queue
	for(i=0; i<STD_N; i++) {
		if(enqueue(queue, c[i])) {
			printf("Enqueue: %d\n", c[i]->id);
		} else {
			printf("Enqueue Failed!\n");
			return -1;
		}
	}

	// Extracting Data from Queue
	while(queue->count != 0) {
		std_ptr = (STD*)dequeue(queue);
		printf("Dequeue: %d\n", std_ptr->id);
	}

	// Re-inserting
	for(i=0; i<STD_N; i++) {
		if(enqueue(queue, c[i])) {
			printf("Enqueue: %d\n", c[i]->id);
		} else {
			printf("Enqueue Failed!\n");
			return -1;
		}
	}

	// destroying all queue and data
	destroy_queue(queue);

	return 0;
}
