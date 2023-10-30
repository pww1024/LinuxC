# CFLAGS+=-D_FILE_OFFSET_BITS=64 -D_GNU_SOURCE
CFLAGS+= -D_FILE_OFFSET_BITS=64
CFLAGS+= -Wall

LDFLAGS+= -lcrypt # 链接内容要放在源文件之后

checkpass: checkpass.c
	cc $(CFLAGS) checkpass.c -o checkpass $(LDFLAGS)
