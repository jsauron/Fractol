/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadpool_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:51:41 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/04 15:53:31 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"

int		init_pool(t_threadpool *pool, int queue_size, int thread_count)
{
	pool->thread_count = 0;
	pool->queue_size = queue_size;
	pool->head = 0;
	pool->tail = 0;
	pool->count = 0;
	pool->shutdown = 0;
	pool->started = 0;
	pool->threads = (pthread_t *)malloc(sizeof(pthread_t) * thread_count);
	pool->queue =
		(t_threadpool_task *)malloc(sizeof(t_threadpool_task) * queue_size);
	if ((pthread_mutex_init(&(pool->lock), NULL)) ||
			(pthread_cond_init(&(pool->notify), NULL)) ||
			(pool->threads == NULL) || (pool->queue == NULL))
		err_pool(pool);
	return (1);
}

int		err_pool(t_threadpool *pool)
{
	if (pool)
		threadpool_free(pool);
	return (0);
}

int		threadpool_free(t_threadpool *pool)
{
	if (pool == NULL || pool->started > 0)
		return (-1);
	if (pool->threads)
	{
		free(pool->threads);
		free(pool->queue);
		pthread_mutex_lock(&(pool->lock));
		pthread_mutex_destroy(&(pool->lock));
		pthread_cond_destroy(&(pool->notify));
	}
	free(pool);
	return (0);
}
