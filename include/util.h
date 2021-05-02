/* See licenses/LIBSL file for copyright and license details. */

#ifndef _UTIL_H
#define _UTIL_H

#define MAX(A, B)               ((A) > (B) ? (A) : (B))
#define MIN(A, B)               ((A) < (B) ? (A) : (B))
#define BETWEEN(X, A, B)        ((A) <= (X) && (X) <= (B))

void *ecalloc(size_t nmemb, size_t size);
void die(const char *fmt, ...);

#endif
