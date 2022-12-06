#ifndef __AST_H__
#define __AST_H__

#include "loc.h"
#include <stdint.h>

/* It's just for reference,
 * you can design your own
 * struct or class to impl inheritance in c/cpp */

typedef enum{ ProgNode, /* types */ } NodeType;

typedef struct NodeTag{
  NodeType nt;
  LocType  loc;
  /* some fields */
} *Node, NodeStr;

#define Obj void*

typedef struct ConsTag{
  Obj car;
  struct ConsTag *cdr;
} *Cons, ConsStr;

#endif
