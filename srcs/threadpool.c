/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadpool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:41:45 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/04 15:51:28 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/threadpool.h"
#include <stdio.h>

static void		*threadpool_thread(void *threadpool)
{
	t_threadpool		*pool;
	t_threadpool_task	task;

	pool = (t_threadpool *)threadpool;
	while (1)
	{
		pthread_mutex_lock(&(pool->lock));
		while ((pool->count == 0) && (!pool->shutdown))
			pthread_cond_wait(&(pool->notify), &(pool->lock));
		if ((pool->shutdown == immediate_shutdown) ||
				((pool->shutdown == graceful_shutdown) &&
				(pool->count == 0)))
			break ;
		task.function = pool->queue[pool->head].function;
		task.argument = pool->queue[pool->head].argument;
		pool->head = (pool->head + 1) % pool->queue_size;
		pool->count -= 1;
		pthread_mutex_unlock(&pool->lock);
		(*(task.function))(task.argument);
	}
	pool->started--;
	pthread_mutex_unlock(&(pool->lock));
	pthread_exit(NULL);
	return (NULL);
}

t_threadpool	*threadpool_create(int thread_count, int queue_size)
{
	t_threadpool	*pool;
	int				i;

	i = 0;
	if (thread_count <= 0 || thread_count > MAX_THREADS ||
			queue_size <= 0 || queue_size > MAX_QUEUE)
		return (NULL);
	if (!(pool = (t_threadpool *)malloc(sizeof(t_threadpool))))
		err_pool(pool);
	if (init_pool(pool, queue_size, thread_count) == 0)
		return (NULL);
	while (i < thread_count)
	{
		if (pthread_create(&(pool->threads[i]), NULL,
					threadpool_thread, (void*)pool) != 0)
		{
			threadpool_destroy(pool, 0);
			return (NULL);
		}
		pool->thread_count++;
		printf("thread_count = %d\n", pool->thread_count);
		printf("started = %d\n", pool->started);
		pool->started++;
		i++;
	}
	return (pool);
}

int				threadpool_add(t_threadpool *pool,
								void (*function)(void *), void *argument)
{
	int		err;
	int		next;

	err = 0;
	if (pool == NULL || function == NULL)
		return (threadpool_invalid);
	if (pthread_mutex_lock(&(pool->lock)))
		return (threadpool_lock_failure);
	next = (pool->tail + 1) % pool->queue_size;
	if (pool->count == pool->queue_size)
		err = threadpool_queue_full;
	else if (pool->shutdown)
		err = threadpool_shutdown;
	else
	{
		pool->queue[pool->tail].function = function;
		pool->queue[pool->tail].argument = argument;
		pool->tail = next;
		pool->count += 1;
		if (pthread_cond_signal(&(pool->notify)))
			err = threadpool_lock_failure;
	}
	if (pthread_mutex_unlock(&pool->lock))
		err = threadpool_lock_failure;
	return (err);
}

int				threadpool_destroy(t_threadpool *pool, int flags)
{
	int		i;
	int		err;

	i = 0;
	err = 0;
	if (pool == NULL)
		return (threadpool_invalid);
	if (pthread_mutex_lock(&(pool->lock)))
		return (threadpool_lock_failure);
	if (pool->shutdown)
		err = threadpool_shutdown;
	else
	{
		pool->shutdown = (flags & threadpool_graceful) ?
			graceful_shutdown : immediate_shutdown;
		if ((pthread_cond_broadcast(&(pool->notify))) ||
			(pthread_mutex_unlock(&(pool->lock))))
			err = threadpool_lock_failure;
		while (i < pool->thread_count)
		{
			if (pthread_join(pool->threads[i], NULL))
				err = threadpool_thread_failure;
			i++;
		}
	}
	if (!err)
		threadpool_free(pool);
	return (err);
}
