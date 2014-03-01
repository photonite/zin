#ifndef ZIN_DATA_H
#define ZIN_DATA_H

typedef int zint;
typedef char zchar;
typedef unsigned int ztype;
typedef unsigned int zsize;

// Head: [type]
typedef struct {
    ztype type;
} zhead;

typedef zhead *pzdata;

// Int: [head] [int]
typedef struct {
    zhead head;
    zint data;
} zdint;

// Str: [head] [memsize] [realsize] [char] ...
typedef struct {
    zhead head;
    zsize memsize;
    zsize realsize;
    zchar data[];
} zdstr;

// Arr: [head] [memsize] [realsize] [ptr] ...
typedef struct {
    zhead head;
    zsize memsize;
    zsize realsize;
    pzdata data[];
} zdarr;

// Code nil: [head]
typedef struct {
    zhead head;
} zdcodenil;

// Code mono: [head] [ptr]
typedef struct {
    zhead head;
    pzdata data;
} zdcodemono;

// Code bi: [head] [l] [r]
typedef struct {
    zhead head;
    pzdata ldata;
    pzdata rdata;
} zdcodebi;

// Node of dict
typedef struct {
    pzdata index;
    pzdata data;
} zddictnode;

// Dict: [head] [bitsize] [realsize] [ptr] ...
typedef struct {
    zhead head;
    zsize bitsize;
    zsize realsize;
    zddictnode node[];
} zddict;

#endif