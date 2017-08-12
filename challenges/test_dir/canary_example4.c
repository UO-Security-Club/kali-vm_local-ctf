#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
        char *info;
};

void foo1(char **dest)
{
        char buf[32];

        fgets(buf, 64, stdin);

        char *info = *dest;
        strcpy(info, buf);

        return;
}

void main()
{
        struct user *user1;
        user1 = malloc(sizeof(struct user));
        user1->info = malloc(32);

        char *local_ptr = user1->info;
        foo1(&local_ptr);

        printf("%s\n", user1->info);
	fflush(stdout);
        free(user1->info);
        free(user1);
        
        return;
}
