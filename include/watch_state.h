#ifndef WATCH_STATE_H_INCLUDED
#define WATCH_STATE_H_INCLUDED

/* An incomplete type for the state representation itself */
typedef struct tag_watch_state watch_state_t;

/* Function pointer to the implementation of the interface */
typedef void (*event_start_func_f)(watch_state_t *sw);
typedef void (*event_stop_func_f)(watch_state_t *sw);
typedef void (*event_split_func_f)(watch_state_t *sw);

typedef enum states_tag states_e;
enum states_tag { STOPPED, STARTED, SPLIT };

struct tag_watch_state {
	/* Events */
	event_start_func_f start;
	event_split_func_f split;
	event_stop_func_f stop;

	/* States */
	states_e current_state;

	int time;
};

void initialize(watch_state_t *state);
char* state_to_string(states_e state);

#endif /* WATCH_STATE_H_INCLUDED */
