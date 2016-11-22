#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "watch_state.h"
#include "started_state.h"

typedef struct tag_client_sw client_sw_t;
struct tag_client_sw {
	watch_state_t state;
};

client_sw_t* sw_create(void)
{
	client_sw_t *sw = malloc(sizeof *sw);

	memset(sw, 0, sizeof *sw);

	initialize(&sw->state);

	/* Next transition */
	sw->state.start = start;

	return sw;
}

void sw_destroy(client_sw_t *sw)
{
	free(sw);
}

void start_watch(client_sw_t *sw)
{
	sw->state.start(&sw->state);
}

void stop_watch(client_sw_t *sw)
{
	sw->state.stop(&sw->state);
}

void split_watch(client_sw_t *sw)
{
	sw->state.split(&sw->state);
}

int main(void)
{
	client_sw_t *sw = NULL;

	printf("Start your stop watch, extended version\n");

	sw = sw_create();

	stop_watch(sw);
	stop_watch(sw);
	split_watch(sw);

	start_watch(sw);
	start_watch(sw);

	split_watch(sw);
	split_watch(sw);

	stop_watch(sw);

	split_watch(sw);
	start_watch(sw);
	stop_watch(sw);

	sw_destroy(sw);

	printf("Terminate your stop watch\n");

	return 0;
}
