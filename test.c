#include <stdio.h>
#include "rtk/midi.h"

RTK_MIDI * midi = NULL;

int main(int argc, char * argv[])
{
	int i, j;

	if(argc < 2)
	{
		printf("Usage: test <filename>\n");
		return -1;
	}
	midi = rtk_load_midi(argv[1]);
	if(midi)
	{
		printf("MIDI Loaded!\n");
		printf("Divisions = %d\n", midi->raw_data->divisions);
		printf("Tracks =    %d\n\n", midi->raw_data->tracks);
		for(i = 0; i < midi->tracks; i++)
		{
			printf("Track %d (%s) Events (%d)\n\n", i, midi->track[i]->name, midi->track[i]->events);
			for(j = 0; j < midi->track[i]->events; j++)
			{
//				printf("\tEvent %3d - %6d %d %d %d %s %s %d %d %d\n", j, midi->track[i]->event[j]->tick, midi->track[i]->event[j]->type, midi->track[i]->event[j]->channel, midi->track[i]->event[j]->text, midi->track[i]->event[j]->data, midi->track[i]->event[j]->data_i[0], midi->track[i]->event[j]->data_i[1], midi->track[i]->event[j]->data_i[2]);
				printf("\tEvent %3d - %6d 0x%2X %3d 0x%02X %6lu %6lu %6lu\n", j, midi->track[i]->event[j]->tick, midi->track[i]->event[j]->type, midi->track[i]->event[j]->channel, midi->track[i]->event[j]->meta_type, midi->track[i]->event[j]->data_i[0], midi->track[i]->event[j]->data_i[1], midi->track[i]->event[j]->data_i[2]);
			}
		}
		printf("Tempo Events = %d\n\n", midi->tempo_events);
		for(i = 0; i < midi->tempo_events; i++)
		{
			printf("\tEvent %3d - %6d (%3.2f) %6lu\n", i, midi->tempo_event[i]->tick, midi->tempo_event[i]->pos_sec, midi->tempo_event[i]->data_i[0]);
		}
		rtk_destroy_midi(midi);
	}
	return 0;
}
