#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "started_state.h"
#include "stopped_state.h"
#include "split_state.h"

void start(watch_state_t *state)
{
	unsigned int secs = 5;
	unsigned int i = 0;

	/* Do some work here to simulate stop*/
	for(i = 0; i < secs; i++) {    
		sleep(1);
		printf("Starting the stopwatch ...%u\n", i);
	}

	/* Initialize with default implementation */
	initialize(state);

	/* Update state */
	state->current_state = STARTED;
	state->time = 0;

	/* Next transition states */
	state->stop = stop;
	state->split = split;

	printf("[ %s ] state [ %s ] time [ %d ]\n", __func__, state_to_string(state->current_state), state->time);
}
