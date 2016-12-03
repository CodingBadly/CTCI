#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

/* table entry */
struct nlist {
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};

static struct nlist *hashtable[HASHSIZE];

/*
 * Hash Function
 * - return the hash value (which is key or index of array) 
 */
unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + 31 * hashval;
    }

    return hashval % HASHSIZE;
}

/*
 * lookup
 * Look for s in hashtable
 */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtable[hash(s)]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            return np;
        }
    }
    return NULL;
}

/*
 * install
 * put (name, defn) in hashtab
 */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(*name)) == NULL) {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL) {
            return NULL;
        }
        np->name = strdup(name);
        if (np->name == NULL) {
            free(np);
            return NULL;
        }
        hashval = hash(name);
        np->next = hashtable[hashval];
        hashtable[hashval] = np;
    } else {
        free(np->defn);
    }

    if (np->defn == strdup(defn) == NULL) {
        return NULL;
    }

    return np;
}

int main()
{

}