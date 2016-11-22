#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "stopped_state.h"
#include "started_state.h"

void stop(watch_state_t *state)
{
	unsigned int secs = 3;
	unsigned int i = 0;

	/* Do some work here to stop*/
	for(i = 0; i < secs; i++) {    
		sleep(1);
		printf("Stopping the stopwatch ...%u\n", i);
	}

	/* Initialize with default implementation */
	initialize(state);

	/* update current state */
	state->current_state = STOPPED;
	state->time = 0;

	/* Next transition state */
	state->start = start;

	printf("[ %s ] state [ %s ] time [ %d ]\n", __func__, state_to_string(state->current_state), state->time);
}
