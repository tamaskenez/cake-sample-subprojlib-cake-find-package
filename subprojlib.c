#include <stdio.h>
#ifdef HAVE_ZLIB
#include <zlib.h>
#endif

void call_subprojlib() {
    printf("in call_subprojlib: ");
#ifdef HAVE_ZLIB
    printf("zlib version: %s\n", zlibVersion());
#else
    printf("subprojlib built without zlib\n");
#endif
}

