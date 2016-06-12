#ifndef _ExportHeader_H_
#define _ExportHeader_H_
#ifdef EULERPROJECTTOOLS_EXPORTS
#define EulerTools_SHARED __declspec (dllexport)
#else
#define EulerTools_SHARED __declspec (dllimport)
#endif
#endif