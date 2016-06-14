#ifndef _DEBUGMEMORY_H_
#define _DEBUGMEMORY_H_
#include <crtdbg.h>

#ifdef _DEBUG
//define a macro that shows the file, line where the memory leak is happening
#define DEBUG_CLIENTBLOCK  new( _CLIENT_BLOCK, __FILE__, __LINE__)
#define new DEBUG_CLIENTBLOCK
#else
#define DEBUG_CLIENTBLOCK
#endif // _DEBUG

#endif