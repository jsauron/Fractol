/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadpool.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 16:32:13 by jsauron           #+#    #+#             */
/*   Updated: 2018/09/16 16:32:16 by jsauron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADPOOL_H
# define THREADPOOL_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

# define MAX_THREADS 64
# define MAX_QUEUE 700000

typedef struct			s_threadpool_task
{
	void				(*function)(void *);
	void				*argument;

}						t_threadpool_task;

typedef struct			s_threadpool
{
	pthread_mutex_t		lock;
	pthread_cond_t		notify;
	pthread_t			*threads;
	t_threadpool_task	*queue;
	int					thread_count;
	int					queue_size;
	int					head;
	int					tail;
	int					count;
	int					shutdown;
	int					started;

}						t_threadpool;

typedef enum			e_threadpool_shutdown
{
	immediate_shutdown = 1,
	graceful_shutdown = 2

}						t_threadpool_shutdown;

typedef enum			e_threadpool_error
{
	threadpool_invalid = -1,
	threadpool_lock_failure = -2,
	threadpool_queue_full = -3,
	threadpool_shutdown = -4,
	threadpool_thread_failure = -5

}						t_threadpool_error;

typedef enum			e_threadpool_destroy_flags
{
	threadpool_graceful = 1

}						t_threadpool_destroy_flags;

/*
**	threadpool.c
*/

t_threadpool			*threadpool_create(int thread_count, int queue_size);
t_threadpool			*thread_c(t_threadpool *pool, int thread_count);
int						threadpool_add(t_threadpool *pool,
							void(*function)(void *), void *arg);

/*
**      threadpool_helper.c
*/

int						threadpool_destroy(t_threadpool *pool, int flags);
void					threadpool_dest_check(t_threadpool *pool,
														int flags, int err);
int						init_pool(t_threadpool *pool, int queue_size,
															int thread_count);
int						err_pool(t_threadpool *pool);
int						threadpool_free(t_threadpool *pool);

#endif
