#include "../inc/cub3d.h"

void raycast(t_hold *hold)
{
	if(hold->look[0] == 0)
	{
		hold->delta_dist[0] = INT32_MAX;
	}
	else
	{
		hold->delta_dist[0] = abs(1/ hold->look[0]);
	}
	if(hold->look[1] == 0)
	{
		hold->delta_dist[1] = INT32_MAX;
	}
	else
	{
		hold->delta_dist[1] = abs(1/ hold->look[1]);
	}

	// side dist for x
	if (hold->look[0] < 0)
	{
		hold->step[0] = -1;
		hold->side_dist[0] = (hold->pos[0] - hold->map_pos[0]) * hold->delta_dist[0];
	}
	else
	{
		hold->step[0] = 1;
		hold->side_dist[0] = (hold->map_pos[0] + 1.0 - hold->pos[0]) * hold->delta_dist[0];
	}

	// same for y
	if (hold->look[1] < 0)
	{
		hold->step[1] = -1;
		hold->side_dist[1] = (hold->pos[1] - hold->map_pos[1]) * hold->delta_dist[1];
	}
	else
	{
		hold->step[1] = 1;
		hold->side_dist[1] = (hold->map_pos[1] + 1.0 - hold->pos[1]) * hold->delta_dist[1];
	}
}


void dda(t_hold *hold)
{
	while (1)
	{
		if (hold->side_dist[0] < hold->side_dist[1])
		{
			hold->side_dist[0] += hold->delta_dist[0];
			hold->map_pos[0] += hold->step[0];
			hold->side = 0;
		}
		else
		{
			hold->side_dist[1] += hold->delta_dist[1];
			hold->map_pos[1] += hold->step[1];
			hold->side = 1;
		}
		if (hold->cub->map[hold->map_pos[1]][hold->map_pos[0]] == '1')
			break;
	}
}