#pragma once

#include <cstdlib>

#ifdef _DEBUG
#define ASSERT(x) do { if (!(x)) { logError( #x, __FILE__, __LINE__ ); } } while(0)
#endif
