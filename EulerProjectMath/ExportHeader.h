#pragma once

#ifdef EULERPROJECTTOOLS_EXPORTS
#define EulerTools_SHARED __declspec (dllexport)
#else
#define EulerTools_SHARED __declspec (dllimport)
#endif
