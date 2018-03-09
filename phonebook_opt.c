#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"


unsigned long hash(char *str)
{
    unsigned long hash = 0;
    //DJB2Hash
    /*
        hash = 5381;
        int c = 0;
        while (c = *str++)
            hash = ((hash << 5) + hash) + c; // hash * 33 + c
        return hash;
      */

    //BKDRHash
    /*
        unsigned int seed = 31; //SDBHash set seed as 65599
        while (*str) {
            hash = hash * seed + (*str++);
        }
        return hash;
    */
    /*
        //RSHHash
        unsigned int magic = 63689;
        int c = 0;
        while (c = *str++)
        {
            hash = hash * magic + c;
            magic *= 378551;
        }
    */
    //APHash
    int c = 0;
    long i = 0;
    for (i = 0; c = *str++; i++) {
        if((i & 1) == 0) {
            hash^= ((hash << 7) ^ c ^ (hash >> 3));
        } else {
            hash ^= (~((hash << 11) ^ c ^ (hash >> 5)));
        }
    }
    return hash;
}

entry *findName(char lastName[], entry *pHead)
{
    while (pHead != NULL) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}



