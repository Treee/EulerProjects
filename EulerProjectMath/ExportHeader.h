#ifndef _ExportHeader_H_
#define _ExportHeader_H_
#ifdef EULERPROJECTMATH_EXPORTS
#define EULERMATH_SHARED __declspec (dllexport)
#else
#define EULERMATH_SHARED __declspec (dllimport)
#endif
#endif