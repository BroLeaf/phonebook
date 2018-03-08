#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"


unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c = 0;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

entry *findName(char lastName[], entry **pArr)
{
    entry *pHead = pArr[hash((unsigned char*)lastName) % HASH_SIZE];
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry **pArr)
{
    unsigned long index = hash((unsigned char*)lastName) % HASH_SIZE;
    entry *e = (entry *) malloc(sizeof(entry));
    e->pNext = pArr[index];
    pArr[index] = e;
    strcpy(e->lastName, lastName);

    return e;
}



