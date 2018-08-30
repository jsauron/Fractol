
#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

# define MAX_THREAD 64
# define MAX_QUEUE 65536

typedef struct 		s_threadpool_task
{
    void 		(*function)(void *);
    void 		*argument;

} 			t_threadpool_task;

typedef struct                  s_threadpool
{
        pthread_mutex_t         lock;
        pthread_cond_t          notify;
        pthread_t               *threads;
        t_threadpool_task       *queue;
        int                     thread_count;
        int                     queue_size;
        int                     head;
        int                     tail;
        int                     count;
        int                     shutdown;
        int                     started;

}                               t_threadpool;

typedef  enum	 		s_threadpool_shutdown
{
    immediate_shutdown = 1,
    graceful_shutdown  = 2

} 				t_threadpool_shutdown;

typedef	enum	 		s_threadpool_error
{
    threadpool_invalid        = -1,
    threadpool_lock_failure   = -2,
    threadpool_queue_full     = -3,
    threadpool_shutdown       = -4,
    threadpool_thread_failure = -5

} 				t_threadpool_error;

typedef enum			s_threadpool_destroy_flags
{
	threadpool_graceful = 1

}				t_threadpool_destroy_flags;

/*
**	threadpool.c
*/

t_threadpool	*threadpool_create(int thread_count, int queu_size, int flags);
int		threadpool_add(t_threadpool *pool, void (*routine)(void *),
				void *arg, int flags);
int		threadpool_destroy(t_threadpool *pool, int flags);
static void	*threadpool_thread(void *threadpool);

/*
**      threadpool_helper.c
*/

t_threadpool    init_pool(t_threadpool *pool);
void    *err_pool(t_threadpool *pool);
int     threadpool_free(t_threadpool *pool);

#endif 
