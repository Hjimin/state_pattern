#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "split_state.h"
#include "stopped_state.h"

void split(watch_state_t *state)
{
	unsigned int secs = 5;
	unsigned int i = 0;

	/* Do some work here to stop*/
	for(i = 0; i < secs; i++) {    
		sleep(1);
		printf("Splitting the stopwatch ...%u\n", i);
	}

	/* Initialize with default implementation */
	initialize(state);

	state->current_state = SPLIT;
	state->time = secs;

	/* Next transition states */
	state->stop = stop;
	state->split = split;

	printf("[ %s ] state [ %s ] time [ %d ]\n", __func__, state_to_string(state->current_state), state->time);
}
