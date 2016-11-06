#ifndef _DEBUG_
#define _DEBUG_

#ifdef DEBUG
	#define LOG(msg) printf("\e[1;31m%s:%s@%d\e[0m %s\n", __FILE__, __FUNCTION__, __LINE__, msg);
	#define PRINT(...) printf(__VA_ARGS__)
#else
	#error
	#define PRINT(...) (void) 0;
#endif

#define DELETE(ptr) delete ptr; ptr = NULL

#endif /* _DEBUG_ */
