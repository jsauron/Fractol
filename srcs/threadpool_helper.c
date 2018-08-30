#include "../includes/threadpool.h"

t_threadpool    init_pool(t_threadpool *pool)
{
        pool->thread_count = 0;
        pool->queue_size = queue_size;
        pool->head = 0;
        pool->tail = 0;
        pool->count = 0;
        pool->shutdown = 0;
        pool->started = 0;
        pool->threads = (pthread_t *)malloc(sizeof(pthread_t) * thread_count);
        pool->queue = (t_threadpool_task *)malloc
                (sizeof(t_threadpool_task) * queue_size);
        if ((pthread_mutex_init(&(pool->lock), NULL)) ||
                (pthread_cond_init(&(pool->notify), NULL)) ||
                (pool->threads == NULL) ||(pool->queue == NULL))
                err_pool(pool);
}

void    *err_pool(t_threadpool *pool)
{
        if (pool)
                threadpool_free(pool);
        return NULL;
}

int     threadpool_free(t_threadpool *pool)
{
        if (pool == NULL || pool->started > 0)
                return -1;

        if (pool->threads)
        {
                free(pool->threads);
                free(pool->queue);
                pthread_mutex_lock(&pool->lock);
                pthread_mutex_destroy(&pool->lock);
                pthread_cond_destroy(&pool->notify);
        }
        free(pool);
        return (0);
}


