/*
mytbf.h给用户,mytbf.c编译成静态库或动态库
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#include "mytbf.h"

static struct mytbf_st *job[MYTBF_MAX];

struct mytbf_st
{
    int cps;
    int burst;
    int token;
    int pos;
};

int get_free_pos(void)
{
    int i;
    for (i = 0; i < MYTBF_MAX; i++)
    {
        if (job[i] == NULL)
            return i;
    }
    return -1;
}

mytbf_t * mytbf_init(int cps, int burst)
{
    int pos;
    struct mytbf_st *me;

    pos = get_free_pos();
        if (pos < 0)
        return NULL;

    me = malloc(sizeof(*me));
    if (me == NULL)
        return NULL;

    me->cps = cps;
    me->burst = burst;
    me->token = 0;
    me->pos = pos;

    job[pos] = me;

    return me;
}

int mytbf_fetchtoken(mytbf_t *ptr, int size) // fetch 实际获取的token数
{
    struct mytbf_st *me = ptr;
    int n;

    if (size <= 0)
        return -EINVAL;

    while (me->token<=0)
        pause();

    n = me->token < size ? me->token : size;
    me->token -= n;

    return n;
}

int mytbf_returntoken(mytbf_t *ptr, int size)
{
    struct mytbf_st *me = ptr;

    if (size <= 0)
        return -EINVAL;

    me->token += size;
    if (me->token > me->burst)
        me->token = me->burst;

    return size;
}

int mytbf_destroy(mytbf_t *ptr)
{
    struct mytbf_st *me = ptr;
    job[me->pos] = NULL;
    free(ptr);    
    return 0;
}
