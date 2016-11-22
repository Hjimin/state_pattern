#include <stdio.h>
#include "watch_state.h"
#include "started_state.h"
#include "stopped_state.h"
#include "split_state.h"

static void default_start(watch_state_t *state);
static void default_split(watch_state_t *state);
static void default_stop(watch_state_t *state);

void initialize(watch_state_t *state)
{
	state->start = default_start;
	state->split = default_split;
	state->stop = default_stop;
	state->current_state = STOPPED;
	state->time = 0;
}

char* state_to_string(states_e state)
{
	switch(state) {
		case STOPPED:
			return "STOPPED";

		case STARTED:
			return "STARTED";

		case SPLIT:
			return "SPLIT";

		default:
			return "UNKNOWN";
	}
}

static void default_start(watch_state_t *state)
{
	printf("[ %s ] State [ %s ] time [ %d ] start event isn't supported in the concrete state\n",
			__func__, state_to_string(state->current_state), state->time);
}

static void default_split(watch_state_t *state)
{
	printf("[ %s ] State [ %s ] time [ %d ] split event isn't supported in the concrete state\n",
			__func__, state_to_string(state->current_state), state->time);
}

static void default_stop(watch_state_t *state)
{
	printf("[ %s ] State [ %s ] time [ %d ] stop event isn't supported in the concrete state\n",
			__func__, state_to_string(state->current_state), state->time);
}
