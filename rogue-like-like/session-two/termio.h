#ifndef _TERMIO_
#define _TERMIO_

#ifdef __cplusplus
extern "C"
{
#endif

int 	termio_init();
void	termio_destroy();

void 	termio_clear();
char 	termio_getch();

void termio_print(int r, int c, const char *fmt, ...);
void termio_swap();

int 	termio_rows();
int 	termio_cols();


#ifdef __cplusplus
}
#endif

#endif /* _TERMIO_ */
