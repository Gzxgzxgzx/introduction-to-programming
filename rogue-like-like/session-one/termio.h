#ifndef _TERMIO_
#define _TERMIO_

#ifdef __cplusplus
extern "C"
{
#endif

int termio_init();
void termio_clear();
char termio_getch();

#ifdef __cplusplus
}
#endif

#endif /* _TERMIO_ */
