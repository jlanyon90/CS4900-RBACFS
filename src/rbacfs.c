#include <stdlib.h>
#include <stdio.h>
#include "parse/lib.h"
#include "fuse/lib.h"
#include "policy/lib.h"

/*
 * main
 *      DESCRIPTION: Program entrypoint. Coordinates the parse, policy, and
 *      fuse modules to coordinate reading and interpreting the rbac definition
 *      and then implementing it in a working filesystem.
 */
int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "usage: %s mount root rbac.defs\n", argv[0]);
        exit(1);
    }

    struct def *defs = rbac_parse_defs(argv[--argc]);
    if (!defs) {
        fprintf(stderr, "error: invalid definitions file: %s\n", argv[argc]);
        exit(1);
    }
    argv[argc] = NULL;

    struct policy policy = policy_build(defs);

    return fuse_start(argc, argv, policy);
}
