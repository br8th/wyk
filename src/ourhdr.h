#include <stdio.h>
#include <stdlib.h>

// extern char *strchr(), *strdup();

#define demand(fact, remark)                                \
	{                                                       \
		if (!(fact))                                        \
		{                                                   \
			fprintf(stderr, "demand not met: %s\n", #fact); \
			fprintf(stderr, "%s\n", remark);                \
			abort();                                        \
			exit(1);                                        \
		}                                                   \
	}

#define FALSE 0
#define TRUE !FALSE