/*#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data
{
	int				percent;
	const   char* message;
	int				x;
	int				time_to_sleep;
	pthread_mutex_t	protect;
}					t_data;

void	*progress_bar(void  *arg) {

	t_data *data;
	data = (t_data *)arg;

	pthread_mutex_lock(&data->protect);

	printf("\033[2J");

	printf("\033[H");

	int bar_width = 50;
	int num_bars = (data->percent * bar_width) / 100;

	for (int i = 0; i < num_bars; i++) {
		printf("\e[1;32m▇");
	}
	for (int i = num_bars; i < bar_width; i++) {
		printf(" ");
	}
	printf("  %d%%\n", data->percent);

	pthread_mutex_unlock(&data->protect);
	sleep(data->time_to_sleep);
	return (NULL);
}

void	*show_msg(void  *arg)
{
	t_data	*data2;

	data2 = (t_data *)arg;
	printf("%s", data2->message);
	if (data2->x % 4 == 0 && data2->x > 0)
	{
		printf(" \n");
	}
	if (data2->x % 4 == 1 && data2->x > 0)
	{
		printf(" .\n");
		usleep(data2->time_to_sleep);
	}
	else if (data2->x % 4 == 2 && data2->x > 0)
	{
		printf(" ..\n");
		usleep(data2->time_to_sleep);
	}
	else if (data2->x % 4 == 3 && data2->x > 0)
	{
		printf(" ...\n");
		usleep(data2->time_to_sleep);
	}
	return (NULL);
}

int	main(void) {
	int i;
	pthread_t th2, th3;
	t_data data;
	t_data data2;

	pthread_mutex_init(&data.protect, NULL);
	pthread_mutex_init(&data2.protect, NULL);
	i = 0;
	while (i <= 100)
	{
		data.percent = i;

		data2.message = "\nCompiling in progress";
		// data.x = i;
		data2.x = i;
		data.time_to_sleep = 3;
		data2.time_to_sleep = 10000000;
		pthread_create(&th2, NULL, &progress_bar, &data);

		pthread_create(&th3, NULL, &show_msg, &data2);
		i++;
	}

	return (0);
}
*/
