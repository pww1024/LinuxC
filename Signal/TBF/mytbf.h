/*
Token Bucket Filter
mytbf.h给用户,mytbf.c编译成静态库或动态库
*/

#ifndef MYTBF_H__
#define MYTBF_H__

#define MYTBF_MAX 1024

typedef void mytbf_t; // 将数据类型隐藏在mytbf.c中

mytbf_t * mytbf_init(int cps, int burst);

int mytbf_fetchtoken(mytbf_t *ptr, int size);

int mytbf_returntoken(mytbf_t *ptr, int size);

int mytbf_destroy(mytbf_t *ptr);

#endif
